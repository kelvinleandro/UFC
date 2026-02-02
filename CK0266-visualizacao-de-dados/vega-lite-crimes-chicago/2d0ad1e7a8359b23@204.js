import define1 from "./cc6863a92d3c907e@240.js";

function _1(md){return(
md`# Visualização de Crimes em Chicago usando Vega-Lite - 2025.2`
)}

function _2(md){return(
md`O arquivo \`chicago_crimes_october_2025.csv\` em anexo possui os crimes (HOMICIDE, BURGLARY e ROBBERY) que ocorreram em [Chicago](https://data.cityofchicago.org/Public-Safety/Crimes-2025/t7ek-mgzi/about_data) durante o mês de **outubro de 2025**.

Faça um fork deste notebook e visualize os crimes no mapa topojson fornecido (\`chicagoNeighborhoods.json\`).

Crie um gráfico de barras para mostrar os totais de crimes para cada **tipo de crime** e um gráfico de linhas (uma linha para cada tipo de crime) mostrando crimes por **dia**. Veja esse [exemplo](https://observablehq.com/@uwdata/multi-view-composition?collection=@uwdata/visualization-curriculum#cell-206) como base. A sua visualização deve ser semelhante à figura mais abaixo.

Não se preocupe se as cores não ficarem exatamente como as mostradas. Nós iremos trabalhar melhor com cores em módulos futuros.`
)}

function _topo(FileAttachment){return(
FileAttachment("chicagoNeighborhoods.json").json()
)}

function _crimes(FileAttachment,d3){return(
FileAttachment("chicago_crimes_october_2025@1.csv").csv({typed: true}).then(function (data) {
  // The date has a special formating not automatically detected by d3,
  // so we need to parse it using UTC rather than local time
  const parseDate = d3.utcParse("%m/%d/%Y %I:%M:%S %p");
  data.forEach(function(d) {
   d.Date = parseDate(d.Date);
   // adicionei a linha abaixo para pegar somente a data, sem timestamp
   d.day = new Date(d.Date).toISOString().split("T")[0]; 
  });
  return data;
})
)}

function _5(FileAttachment){return(
FileAttachment("Screenshot 2025-11-09 at 11.45.33 AM.png").image()
)}

function _6(vl,topo,crimes,width)
{
  const crimeTypes = ['BURGLARY', 'HOMICIDE', 'ROBBERY'];
  const typeColors = ['gold', 'red', 'steelblue'];

  const colorScale = vl.color().fieldN('Primary Type')
    .scale({ 
      domain: crimeTypes, 
      range: typeColors
    });

  const mapLayer = vl.markGeoshape({fill: "#ddd", stroke: "#fff", strokeWidth: 0.5})
    .data(vl.topojson(topo).feature('chicago_neighborhoods'));

  const pointsLayer = vl.markCircle({opacity: 0.7, stroke: 'black', strokeWidth: 0.3})
    .data(crimes)
    .encode(
      vl.longitude().fieldQ('Longitude'),
      vl.latitude().fieldQ('Latitude'),
      colorScale.legend({title: 'Crime Type'}),
      vl.tooltip([
        vl.fieldN('Primary Type'),
        vl.fieldN('Description'),
        vl.fieldT('Date', {timeUnit: 'monthdate', title: 'Date'})
      ])
    );

  const crimeMap = vl.layer(mapLayer, pointsLayer)
    .project(vl.projection('albersUsa')) 
    .width(width * 0.40)
    .height(450);

  const barChart = vl.markBar({ tooltip: true })
    .data(crimes)
    .encode(
      vl.x().count().title(null).axis({ tickCount: 5 }), 
      vl.y().fieldN('Primary Type').title("Primary Type"), 
      colorScale.legend({title: 'Crime Type'}),
      vl.tooltip([vl.fieldN('Primary Type'), vl.count()])
    )
    .width(width * 0.35)
    .height(150)
    .title('Number of Crimes by Type');

  const lineChart = vl.markLine({ tooltip: true })
    .data(crimes)
    .encode(
      vl.x()
        .fieldT("day")
        .axis({
          format: "%b %d",
        })
        .title('Date (month-date)'),
      vl.y().count().title(null),
      colorScale.legend({title: 'Crime Type'}),
      vl.tooltip([
        vl.fieldT("day", { timeUnit: "yearmonthdate", title: "Date" }),
        vl.fieldN("Primary Type"),
        vl.count()
      ])
    )
    .width(width * 0.35)
    .height(200)
    .title("Number of Crimes by Day");

  const rightPanel = vl.vconcat(barChart, lineChart);

  return vl.hconcat(crimeMap, rightPanel)
    .resolve({ scale: { color: 'shared' } })
    .title({
      text: 'Crimes in Chicago in October 2025',
      fontSize: 28
    })
    .render();
}


export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["chicagoNeighborhoods.json", {url: new URL("./files/6222e42a1809ea3715edc47bce0903ee173208a83ee48cd424c1a50e841cbc53aaaff0a9475e371a0539428c49605eeb9c76a9a4054fb3ea62a24256431a0010.json", import.meta.url), mimeType: "application/json", toString}],
    ["chicago_crimes_october_2025@1.csv", {url: new URL("./files/6ec29fabbc3eb4ea1b45d319fb2529bd0d0c5676f694cedd41c450fdb94378388bbbbf96bd8346402804fbfbc0e3513e5204d5ef5f255bc976b811b55883ed1f.csv", import.meta.url), mimeType: "text/csv", toString}],
    ["Screenshot 2025-11-09 at 11.45.33 AM.png", {url: new URL("./files/5e838cac71cc45ff2a01cc3811b304a502b180b628a8e68d16799fc23447629d55fe3d7a788a940b89de2423017da8409d3c1f808a5ca347c2192f6d83fb9b0b.png", import.meta.url), mimeType: "image/png", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer("topo")).define("topo", ["FileAttachment"], _topo);
  main.variable(observer("crimes")).define("crimes", ["FileAttachment","d3"], _crimes);
  main.variable(observer()).define(["FileAttachment"], _5);
  main.variable(observer()).define(["vl","topo","crimes","width"], _6);
  const child1 = runtime.module(define1);
  main.import("vl", child1);
  return main;
}
