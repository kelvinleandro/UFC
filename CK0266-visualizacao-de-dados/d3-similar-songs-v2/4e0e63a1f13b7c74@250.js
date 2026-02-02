function _1(md){return(
md`# Similar Song Network 2.0

This notebook uses simulated forces with [d3-force](https://d3js.org/d3-force), based on [Force-directed graph](https://observablehq.com/@d3/force-directed-graph/2?intent=fork) example.

Songs similar to one another according to [last.fm](http://www.last.fm/api) are linked together. Song nodes are sized based on playcounts, and colored by artist.

Data from [last.fm](http://www.last.fm/api/show/track.getSimilar). Some songs include additional links for effect.<br/>Popular songs are defined as those with playcounts above the median for all songs in network. This example is a simpler version of the [tutorial](http://flowingdata.com/2012/08/02/how-to-make-an-interactive-network-visualization/)</a> by [Jim Vallandingham](http://vallandingham.me/).`
)}

function _chart(d3,data,scale,invalidation)
{
  // Specify the dimensions of the chart.
  const width = 928;
  const height = 800;

  let selectedNode = null;
  const nodeStroke = '#fff';
  const nodeStrokeWidth = 1.5;
  const nodeStrokeOpacity = 1;
  const linkOpacity = 0.6;
  const nodeDeselectOpacity = 0.4;
  const linkDeselectOpacity = 0.2;
  const nodeHighlightStroke = '#ffd700';
  const nodeHighlightStrokeWidth = 2.0;

  // Specify the color scale.
  const color = d3.scaleOrdinal(d3.schemeCategory10);

  // The force simulation mutates links and nodes, so create a copy
  // so that re-evaluating this cell produces the same result.
  const links = data.links.map(d => ({...d}));
  const nodes = data.nodes.map(d => ({...d}));

  const nodeDistanceMax = 270;
  const nodeStrength = -50;
  const linkDistance = 50;
  const forceNode = d3.forceManyBody();
  const forceLink = d3.forceLink(links).id(d => d.id);
  forceNode.strength(nodeStrength);
  forceNode.distanceMax(nodeDistanceMax);
  forceLink.distance(linkDistance);

  // Create a simulation with several forces.
  const simulation = d3.forceSimulation(nodes)
      .force("link", forceLink)
      .force("charge", forceNode)
      .force("center", d3.forceCenter(width / 2, height / 2))
      .on("tick", ticked);

  // Create the SVG container.
  const svg = d3.create("svg")
      .attr("width", width)
      .attr("height", height)
      .attr("viewBox", [0, 0, width, height])
      .attr("style", "max-width: 100%; height: auto;");

  svg.on('click', deselect_node)

  // Add a line for each link, and a circle for each node.
  const link = svg.append("g")
      .attr("stroke", "#999")
      .attr("stroke-opacity", 0.6)
    .selectAll()
    .data(links)
    .join("line")
      .attr("stroke-width", d => Math.sqrt(d.value));

  const node = svg.append("g")
      .attr("stroke", "#fff")
      .attr("stroke-width", 1.5)
    .selectAll()
    .data(nodes)
    .join("circle")
      .attr("r", d => scale(d.playcount))
      .attr("fill", d => color(d.group))
      .on('click', clicked);

  node.append("title")
      .text(d => `${d.name}: ${d.artist}`);

  // Add a drag behavior.
  node.call(d3.drag()
        .on("start", dragstarted)
        .on("drag", dragged)
        .on("end", dragended));

  // Set the position attributes of links and nodes each time the simulation ticks.
  function ticked() {
    link
        .attr("x1", d => d.source.x)
        .attr("y1", d => d.source.y)
        .attr("x2", d => d.target.x)
        .attr("y2", d => d.target.y);

    node
        .attr("cx", d => d.x)
        .attr("cy", d => d.y);
  }

  // Reheat the simulation when drag starts, and fix the subject position.
  function dragstarted(event) {
    if (!event.active) simulation.alphaTarget(0.3).restart();
    event.subject.fx = event.subject.x;
    event.subject.fy = event.subject.y;
  }

  // Update the subject (dragged node) position during drag.
  function dragged(event) {
    event.subject.fx = event.x;
    event.subject.fy = event.y;
  }

  // Restore the target alpha so the simulation cools after dragging ends.
  // Unfix the subject position now that it’s no longer being dragged.
  function dragended(event) {
    if (!event.active) simulation.alphaTarget(0);
    event.subject.fx = null;
    event.subject.fy = null;
  }

  function clicked(event, d){
    event.stopPropagation()
    
    const allNodes = svg.selectAll('circle')
      .attr('stroke', nodeStroke)
      .attr('stroke-width', nodeStrokeWidth)
      .attr('stroke-opacity', nodeDeselectOpacity)
      .attr('fill-opacity', nodeDeselectOpacity)

    const allLinks = svg.selectAll('line')
      .attr('stroke-opacity', linkDeselectOpacity)

    const currentNode = d3.select(this)
      .attr('stroke', nodeHighlightStroke)
      .attr('stroke-width', nodeHighlightStrokeWidth)
      .attr('stroke-opacity', nodeStrokeOpacity)
      .attr('fill-opacity', nodeStrokeOpacity)

    selectedNode = d;
    svg.property("value", Object.assign(svg.node(),
                                        {selectedNode: d})).dispatch("input");
  }

  function deselect_node(event){
    
    const allNodes = svg.selectAll('circle')
      .attr('stroke', nodeStroke)
      .attr('stroke-width', nodeStrokeWidth)
      .attr('stroke-opacity', nodeStrokeOpacity)
      .attr('fill-opacity', nodeStrokeOpacity)

    const allLinks = svg.selectAll('line')
      .attr('stroke-opacity', linkOpacity)

    selectedNode = null;
    svg.property('value', Object.assign(svg.node(),
                                        {selectedNode: null})).dispatch('input')
  }

  // When this cell is re-run, stop the previous simulation. (This doesn’t
  // really matter since the target alpha is zero and the simulation will
  // stop naturally, but it’s a good practice.)
  invalidation.then(() => simulation.stop());

  return Object.assign(svg.node(), {selectedNode: selectedNode});
}


function _displayInfo(chart)
{
  let text = "None selected";
  if(chart.selectedNode){
    text = `${chart.selectedNode.name} by ${chart.selectedNode.artist}`;
  }
  return text
}


function _data0(FileAttachment){return(
FileAttachment("miserables.json").json()
)}

function _data(d3){return(
d3.json("https://gist.githubusercontent.com/emanueles/7b7723386677bb13763208216fd89c1f/raw/d09478158ba0fe8aa616deee8bcfe908bba17f15/songs.json")
)}

function _scale(d3,data)
{
  return d3.scaleSqrt()
  .domain(d3.extent(data.nodes, d => d.playcount))
  .range([2, 20]);
}


function _7(scale){return(
scale.domain()
)}

function _8(scale){return(
scale.range()
)}

function _9(scale){return(
scale(10846704)
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["miserables.json", {url: new URL("./files/31d904f6e21d42d4963ece9c8cc4fbd75efcbdc404bf511bc79906f0a1be68b5a01e935f65123670ed04e35ca8cae3c2b943f82bf8db49c5a67c85cbb58db052.json", import.meta.url), mimeType: "application/json", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("viewof chart")).define("viewof chart", ["d3","data","scale","invalidation"], _chart);
  main.variable(observer("chart")).define("chart", ["Generators", "viewof chart"], (G, _) => G.input(_));
  main.variable(observer("displayInfo")).define("displayInfo", ["chart"], _displayInfo);
  main.variable(observer("data0")).define("data0", ["FileAttachment"], _data0);
  main.variable(observer("data")).define("data", ["d3"], _data);
  main.variable(observer("scale")).define("scale", ["d3","data"], _scale);
  main.variable(observer()).define(["scale"], _7);
  main.variable(observer()).define(["scale"], _8);
  main.variable(observer()).define(["scale"], _9);
  return main;
}
