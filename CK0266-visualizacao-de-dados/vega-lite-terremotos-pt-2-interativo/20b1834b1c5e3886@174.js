import define1 from "./cc6863a92d3c907e@240.js";

function _1(md){return(
md`# Visualizando dados de terremoto usando a API Vega-Lite (Parte 2) com Interação`
)}

function _2(md){return(
md`Abaixo está a visualização de dados de terremotos criada em aulas anteriores acrescida de interação. O que iremos fazer neste notebook é melhorar a experiência da interação. O que ainda falta ser feito:
1. Filtrar também o mapa.
2. Acrescentar um tooltip no mapa que mostra o timestamp, magnitude e depth de cada terremoto.
3. Permitir aplicar o brush nos dois gráficos de barra.
4. Atualizar a tabela de acordo com os dados filtrados nos gráficos.`
)}

function _3(md){return(
md`## Earthquakes in New Zealand`
)}

function _dashboard(vl,brush,width,earthquakes,map_view)
{
  const magBarChart = vl.markBar()
    .encode(
      vl.x().fieldQ("magnitude").bin({ maxbins: 30 }).title("Magnitude"),
      vl.y().count().title(null)
    )

  const magBarChartLayer = vl.layer(
      magBarChart.params(brush).encode(vl.color().value('lightgrey')),
      magBarChart.transform(vl.filter(brush))
    )
    .width(width * 0.3).height(200)
    .title("Number of Events by Magnitude")
    .data(earthquakes)

  const depthBarChart = vl
    .markBar()
    .encode(
      vl.x().fieldQ("depth").bin({ maxbins: 30 }).title("Depth"),
      vl.y().count().title(null)
    )

  const depthBarChartLayer = vl.layer(
      depthBarChart.params(brush).encode(vl.color().value('lightgrey')),
      depthBarChart.transform(vl.filter(brush))
    )
    .width(width * 0.3).height(200)
    .title("Events by Depth (km)")
    .data(earthquakes)

  const eventsPerHour = vl
    .markLine()
    .title("Events per Hour")
    .data(earthquakes)
    .transform(vl.filter(brush))
    .encode(
      vl.x().fieldT("origintime").timeUnit("hoursdatemonth").title("Date"),
      vl.y().count().title(null)
    )
    .width(width - 40)
    .height(150);

  return vl
    .vconcat(vl.hconcat(
      vl.vconcat(magBarChartLayer, depthBarChartLayer), map_view), eventsPerHour)
    .resolve({scale: {size: 'independent'}})
    .render();
}


function _5(__query,earthquakes,invalidation){return(
__query(earthquakes,{from:{table:"earthquakes"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:["origintime","magnitude","depth","latitude","longitude","eventtype"]}},invalidation,"earthquakes")
)}

function _6(md){return(
md`*Fonte: [GeoNet Quake Search](https://quakesearch.geonet.org.nz/)*`
)}

function _map_view(vl,topo,earthquakes,brush,width)
{
  // base map of New Zealand
  const map = vl.markGeoshape({fill: '#ddd', stroke: '#fff', strokeWidth: 1})
    .data(vl.topojson(topo).feature('nzl_subunits'))

  const circles = vl.markCircle({
    fillOpacity: 0.30,
    color: "#54E1AE",
    stroke: "#008246",
    strokeWidth: 1,
    strokeOpacity: 0.7
  })
    .data(earthquakes).transform(vl.filter(brush))
    .encode(
      vl.latitude().fieldQ('latitude'),
      vl.longitude().fieldQ('longitude'),
      vl.size().fieldQ('magnitude').scale({type: 'pow', range:[0,700]}).legend({title: 'Magnitude'}),

      vl.tooltip([
        { field: "origintime", type: "temporal", title: "Timestamp" },
        { field: "magnitude", type: "quantitative", title: "Magnitude" },
        { field: "depth", type: "quantitative", title: "Depth (km)" }
      ])
    )
  
  return vl.layer(map, circles)
    .project(
      vl.projection('transverseMercator').rotate([188, 40.5])
    )
    .width(width*0.45)
    .height(500)
}


function _brush(vl){return(
vl.selectInterval().encodings('x').name('brush').resolve('intersect')
)}

function _signal(){return(
'brush'
)}

function _selected(Generators,earthquakes,dashboard,signal){return(
Generators.observe((notify) => {
  const selected = (selection, predicates) => {
    const within = earthquakes.filter(d => {
      for (const [key, [min, max]] of Object.entries(predicates))
        if (isNaN(+d[key]) || d[key] < min || d[key] > max)
          return false;
      return true;
    })
    notify(within);
  }
  dashboard.addSignalListener(signal, selected);
  return () => dashboard.removeEventListener(signal, selected);
})
)}

function _11(md){return(
md`# Referências
- [Conteúdo básico sobre interação com vega-lite](https://observablehq.com/@uwdata/interaction?collection=@uwdata/visualization-curriculum)
- [Documentação sobre as limitações do brush com dados agregados](https://vega.github.io/vega-lite/docs/selection.html#current-limitations)
- [Acessando dados do vega-lite](https://observablehq.com/@visnup/vega-lite-data-out)`
)}

function _topo(FileAttachment){return(
FileAttachment("nz-topo.json").json()
)}

function _earthquakes(FileAttachment){return(
FileAttachment("earthquakes2025_11_01_area.csv").csv({typed: true})
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["nz-topo.json", {url: new URL("./files/bbc5966ab81dfb0da14984a11c57c711a67e26593baceab024f230457a82eb33ea9390d96c9307b474faa3030a4c3a701277c297f07ccd64ec016871463f963d.json", import.meta.url), mimeType: "application/json", toString}],
    ["earthquakes2025_11_01_area.csv", {url: new URL("./files/8e87af96c64a63086f7323b4b950ac93a5324037d9794771d97932509c220e0757c96340ce0adb9f28b9c2a91ff6262209ecb37daacee1316a91cbb47397d6a5.csv", import.meta.url), mimeType: "text/csv", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer()).define(["md"], _3);
  main.variable(observer("viewof dashboard")).define("viewof dashboard", ["vl","brush","width","earthquakes","map_view"], _dashboard);
  main.variable(observer("dashboard")).define("dashboard", ["Generators", "viewof dashboard"], (G, _) => G.input(_));
  main.variable(observer()).define(["__query","earthquakes","invalidation"], _5);
  main.variable(observer()).define(["md"], _6);
  main.variable(observer("map_view")).define("map_view", ["vl","topo","earthquakes","brush","width"], _map_view);
  main.variable(observer("brush")).define("brush", ["vl"], _brush);
  main.variable(observer("signal")).define("signal", _signal);
  main.variable(observer("selected")).define("selected", ["Generators","earthquakes","dashboard","signal"], _selected);
  main.variable(observer()).define(["md"], _11);
  main.variable(observer("topo")).define("topo", ["FileAttachment"], _topo);
  main.variable(observer("earthquakes")).define("earthquakes", ["FileAttachment"], _earthquakes);
  const child1 = runtime.module(define1);
  main.import("vl", child1);
  return main;
}
