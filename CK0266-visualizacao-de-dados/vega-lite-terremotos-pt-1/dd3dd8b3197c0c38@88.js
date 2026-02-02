function _1(md){return(
md`# Visualizando dados de terremoto usando a API Vega-Lite (Parte 1)`
)}

function _2(md){return(
md`Você vai criar uma visualização de dados de terremotos usando o arquivo csv em anexo. Os dados foram extraídos de [GeoNet Quake Search](https://quakesearch.geonet.org.nz/). 

Ao final ela deve ficar semelhante à imagem abaixo. Não se esqueça de colocar os títulos e referenciar a fonte dos dados abaixo da tabela.`
)}

function _earthquakes(FileAttachment){return(
FileAttachment("earthquakes2025_11_01_area.csv").csv({typed: true})
)}

function _4(vl,earthquakes,width)
{
  const magHist = vl.markBar({ tooltip: true })
    .data(earthquakes)
    .encode(
      vl.x().fieldQ('magnitude').bin({ maxbins: 35 }).title('Magnitude'),
      vl.y().count().title('Number of Events')
    )
    .width(width * 0.45)
    .height(200)
    .title('Number of Events by Magnitude');

  const depthHist = vl.markBar({ tooltip: true })
    .data(earthquakes)
    .encode(
      vl.x().fieldQ('depth').bin({ maxbins: 20 }).title('Depth (km)'),
      vl.y().count().title('Number of Events')
    )
    .width(width * 0.45)
    .height(200)
    .title('Number of Events by Depth');

  const evtPerHour = vl.markLine()
    .data(earthquakes)
    .encode(
      vl.x().timeUnit('monthdatehours').fieldT('origintime').title('Date'),
      vl.y().count().title(null)
    )
    .width(width)
    .height(200)
    .title('Events per Hour')

  return vl.vconcat(vl.hconcat(magHist, depthHist), evtPerHour)
    .title('Earthquakes in New Zealand')
    .render();
}


function _5(__query,earthquakes,invalidation){return(
__query(earthquakes,{from:{table:"earthquakes"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:["origintime","longitude","latitude","magnitude","eventtype","depth"]}},invalidation,"earthquakes")
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["earthquakes2025_11_01_area.csv", {url: new URL("./files/8e87af96c64a63086f7323b4b950ac93a5324037d9794771d97932509c220e0757c96340ce0adb9f28b9c2a91ff6262209ecb37daacee1316a91cbb47397d6a5.csv", import.meta.url), mimeType: "text/csv", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer("earthquakes")).define("earthquakes", ["FileAttachment"], _earthquakes);
  main.variable(observer()).define(["vl","earthquakes","width"], _4);
  main.variable(observer()).define(["__query","earthquakes","invalidation"], _5);
  return main;
}
