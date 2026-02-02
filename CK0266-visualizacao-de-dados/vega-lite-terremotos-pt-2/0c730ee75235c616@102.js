function _1(md){return(
md`# Visualizando dados de terremoto usando a API Vega-Lite (Parte 2)`
)}

function _2(md){return(
md`Você vai criar uma visualização de dados de terremotos usando o arquivo csv em anexo. Os dados foram extraídos de [GeoNet Quake Search](https://quakesearch.geonet.org.nz/). 

Ao final ela deve ficar semelhante à imagem abaixo. Não se esqueça de colocar os títulos e referenciar a fonte dos dados abaixo da tabela.`
)}

function _earthquakes(FileAttachment){return(
FileAttachment("earthquakes2025_11_01_area.csv").csv({typed: true})
)}

function _topo(FileAttachment){return(
FileAttachment("nz-topo.json").json()
)}

function _5(vl,earthquakes,width,map_view)
{
  const magBarChart = vl.markBar({ tooltip: true })
    .data(earthquakes)
    .encode(
      vl.x().fieldQ('magnitude').bin({ maxbins: 35 }).title('Magnitude'),
      vl.y().count().title(null)
    )
    .width(width * 0.30)
    .height(200)
    .title('Number of Events by Magnitude');

  const depthBarChart = vl.markBar({ tooltip: true })
    .data(earthquakes)
    .encode(
      vl.x().fieldQ('depth').bin({ maxbins: 35 }).title('Depth'),
      vl.y().count().title(null)
    )
    .width(width * 0.30)
    .height(200)
    .title('Number of Events by Depth (km)');

  const eventsPerHour = vl.markLine()
    .data(earthquakes)
    .encode(
      vl.x().timeUnit('monthdatehours').fieldT('origintime').title('Date'),
      vl.y().count().title(null)
    )
    .width(width)
    .height(200)
    .title('Events per Hour')

  return vl.vconcat(
    vl.hconcat(
      vl.vconcat(magBarChart, depthBarChart),
      map_view
    ),
    eventsPerHour)
    .resolve({scale: {size: 'independent'}})
    .title('Earthquakes in New Zealand')
    .render();
}


function _6(__query,earthquakes,invalidation){return(
__query(earthquakes,{from:{table:"earthquakes"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:["origintime","longitude","latitude","magnitude","eventtype","depth"]}},invalidation,"earthquakes")
)}

function _map_view(vl,topo,earthquakes,width)
{
  const map = vl.markGeoshape({fill: "#ddd", stroke: "#fff", strokeWidth: 1})
    .data(vl.topojson(topo).feature("nzl_subunits"))

  const circles = vl.markCircle({
    fillOpacity: 0.3,
    color: '#54E1AE',
    stroke: '#008246',
    strokeWidth: 1,
    strokeOpacity: 0.7
  })
    .data(earthquakes)
    .encode(
      vl.latitude().fieldQ('latitude'),
      vl.longitude().fieldQ('longitude'),
      vl.size()
        .fieldQ('magnitude')
          .scale({type: 'pow', range: [0, 700]}).legend({title: 'Magnitude'})
    )

  return vl.layer(map, circles)
    .project(
      vl.projection('transverseMercator').rotate([188, 40.5])
    )
    .width(width * 0.60)
    .height(500)
    // .render()
}


export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["earthquakes2025_11_01_area.csv", {url: new URL("./files/8e87af96c64a63086f7323b4b950ac93a5324037d9794771d97932509c220e0757c96340ce0adb9f28b9c2a91ff6262209ecb37daacee1316a91cbb47397d6a5.csv", import.meta.url), mimeType: "text/csv", toString}],
    ["nz-topo.json", {url: new URL("./files/2292f2ab563c6618994bac9916763ab369b250dcd0ae906a219ba02587665cf6e722ef43abe824fcc827fa1223e5bfe88a7d104a8595cb3a653d91ff24d36563.json", import.meta.url), mimeType: "application/json", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer("earthquakes")).define("earthquakes", ["FileAttachment"], _earthquakes);
  main.variable(observer("topo")).define("topo", ["FileAttachment"], _topo);
  main.variable(observer()).define(["vl","earthquakes","width","map_view"], _5);
  main.variable(observer()).define(["__query","earthquakes","invalidation"], _6);
  main.variable(observer("map_view")).define("map_view", ["vl","topo","earthquakes","width"], _map_view);
  return main;
}
