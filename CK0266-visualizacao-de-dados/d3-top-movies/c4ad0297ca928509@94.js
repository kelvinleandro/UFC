import define1 from "./20978dd5673da577@196.js";

function _1(md){return(
md`# Top 100 IMDB Movies
*Using D3 Charts' ForceGraph, Disjoint*

Data from [IMDB](https://www.imdb.com/chart/top) as of May 18, 2025.

# Exercício

Construa uma visualização da rede de filmes, diretores e atores dos top 100 filmes do IMDB e que utilize atributos pré-atentivos (**tamanho, cor**) e **tooltips** para responder as seguintes perguntas:
- Que diretor dirigiu mais filmes no dataset? Quantos e quais filmes ele dirigiu?
- Que ator participou de mais filmes no dataset? Quantos e de quais filmes ele participou?  `
)}

function _chart(d3,scaleCount,data,processedNodes,invalidation)
{
  // Specify the dimensions of the chart.
  const width = 928;
  const height = 680;

  // Specify the color scale.
  const color = d3.scaleOrdinal(d3.schemeCategory10);

  // etapa 4:
  // somente o raio dos nós do tipo ator/diretor
  // será com base na escala. Filmes terá valor fixo.
  const MOVIE_RADIUS = 4;
  const nodeRadius = (d) => {
    if (d.group === "Movie") {
      return MOVIE_RADIUS;
    } else {
      return scaleCount(d.count);
    }
  };

  // The force simulation mutates links and nodes, so create a copy
  // so that re-evaluating this cell produces the same result.
  const links = data.links.map(d => ({...d}));
  const nodes = processedNodes.map(d => ({...d}));

  // Create a simulation with several forces.
  const simulation = d3.forceSimulation(nodes)
      .force("link", d3.forceLink(links).id(d => d.id))
      .force("charge", d3.forceManyBody())
      .force("x", d3.forceX())
      .force("y", d3.forceY());

  // Create the SVG container.
  const svg = d3.create("svg")
      .attr("width", width)
      .attr("height", height)
      .attr("viewBox", [-width / 2, -height / 2, width, height])
      .attr("style", "max-width: 100%; height: auto;");

  // Add a line for each link, and a circle for each node.
  const link = svg.append("g")
      .attr("stroke", "#999")
      .attr("stroke-opacity", 0.6)
    .selectAll("line")
    .data(links)
    .join("line")
      .attr("stroke-width", d => Math.sqrt(d.value));

  const node = svg.append("g")
      .attr("stroke", "#fff")
      .attr("stroke-width", 1.5)
    .selectAll("circle")
    .data(nodes)
    .join("circle")
      .attr("r", nodeRadius)
      .attr("fill", d => color(d.group));

  // node.append("title")
  //     .text(d => d.id);

  // etapa 5: renderiza o tooltip com
  // nome do ator/diretor + número de filmes.
  node.append("title")
      .text(d => {
        if (d.group === "Movie") {
          return `Movie: ${d.id}`;
        } else if (d.group === "Director") {
          return `Director: ${d.id}\nNo. of Movies: ${d.count}`;
        } else if (d.group === "Actor") {
          return `Actor: ${d.id}\nNo. of Movies: ${d.count}`;
        }
        return d.id;
      });

  // Add a drag behavior.
  node.call(d3.drag()
        .on("start", dragstarted)
        .on("drag", dragged)
        .on("end", dragended));
  
  // Set the position attributes of links and nodes each time the simulation ticks.
  simulation.on("tick", () => {
    link
        .attr("x1", d => d.source.x)
        .attr("y1", d => d.source.y)
        .attr("x2", d => d.target.x)
        .attr("y2", d => d.target.y);

    node
        .attr("cx", d => d.x)
        .attr("cy", d => d.y);
  });

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

  // When this cell is re-run, stop the previous simulation. (This doesn’t
  // really matter since the target alpha is zero and the simulation will
  // stop naturally, but it’s a good practice.)
  invalidation.then(() => simulation.stop());

  return Object.assign(svg.node(), {scales: {color}});
}


function _data(FileAttachment){return(
FileAttachment("imdb_data_100_2025_2.json").json()
)}

function _counts(data)
{
  const counts = new Map();
  data.links.forEach(link => {
    const personId = link.target; 
    counts.set(personId, (counts.get(personId) || 0) + 1);
  });

  return counts;
}


function _processedNodes(data,counts)
{
  return data.nodes.map(node => {
    if (node.group === "Director" || node.group === "Actor") {
        node.count = counts.get(node.id) || 0;
    }
    return node;
  });
}


function _scaleCount(d3,counts){return(
d3.scaleLinear().domain(d3.extent(counts.values())).range([4, 25])
)}

function _tempActor(processedNodes)
{
  return processedNodes.filter(item => item.group === "Actor")
    .sort((a, b) => b.count - a.count)[0]
}


function _tempDirector(processedNodes)
{
  return processedNodes.filter(item => item.group === "Director")
    .sort((a, b) => b.count - a.count)[0]
}


export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["imdb_data_100_2025_2.json", {url: new URL("./files/3c313358ad27598034e68b6f1a0831a7ca5db12407dbfe7150fc076ba5960aa365d0bf6a5fb08a1a759b8c37db661806a92fee0d8d3a64851f5c12bf0eb775d4.json", import.meta.url), mimeType: "application/json", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("chart")).define("chart", ["d3","scaleCount","data","processedNodes","invalidation"], _chart);
  main.variable(observer("data")).define("data", ["FileAttachment"], _data);
  main.variable(observer("counts")).define("counts", ["data"], _counts);
  main.variable(observer("processedNodes")).define("processedNodes", ["data","counts"], _processedNodes);
  main.variable(observer("scaleCount")).define("scaleCount", ["d3","counts"], _scaleCount);
  main.variable(observer("tempActor")).define("tempActor", ["processedNodes"], _tempActor);
  main.variable(observer("tempDirector")).define("tempDirector", ["processedNodes"], _tempDirector);
  const child1 = runtime.module(define1);
  main.import("ForceGraph", child1);
  return main;
}
