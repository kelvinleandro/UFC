import define1 from "./cc6863a92d3c907e@240.js";

function _1(md){return(
md`# Taxa de desemprego nos EUA em 2008 (Vega-Lite)

As [escalas em Vega-Lite](https://vega.github.io/vega-lite/docs/scale.html) são derivadas das escalas em D3, então todos os conceitos que aprendemos no [notebook Cores em D3](https://observablehq.com/@emanueles/cores-em-d3) se aplicam a Vega-Lite, com algumas pequenas modificações de sintaxe.

Nós iremos partir de [um exemplo de choropleth já feito em Vega-Lite](https://observablehq.com/@uwdata/cartographic-visualization?collection=@uwdata/visualization-curriculum#cell-22) e modificá-lo para ficar como a figura abaixo. Para isso, iremos acrescentar uma [escala quantize](https://vega.github.io/vega-lite/docs/scale.html#type) para mostrar as taxas de desemprego entre 1% e 19% com o esquema \`yellowgreenblue\` com 9 níveis diferentes. Observe que as taxas de desemprego estão em um dataset separado chamado \`unemployment\`.

Observe também no exemplo, que como são necessárias duas fontes de dados, é preciso estender o binding de dados com a outra fonte usando o método [transform lookup](https://vega.github.io/vega-lite/docs/lookup.html).`
)}

function _2(FileAttachment){return(
FileAttachment("Screen Shot 2021-12-05 at 11.02.37 PM.png").image()
)}

function _3(md){return(
md`# Taxa de desemprego nos EUA em 2008`
)}

function _choromap(vl,usa,unemployment){return(
vl.markGeoshape({stroke: '#aaa', strokeWidth: 0.25})
  .data(vl.topojson(usa).feature('counties'))
  .transform(
    vl.lookup('id').from(vl.data(unemployment).key('id').fields('rate'))
  )
  .encode(
    vl.color().fieldQ('rate').scale({domain: [0.01, 0.19], clamp: true, type: 'quantize', scheme: {name: 'yellowgreenblue', count: 9}}).legend({format: '%', title: 'Taxa'}),
    vl.tooltip().fieldQ('rate').format('.0%')
  )
  .project(vl.projection('albersUsa'))
  .width(890).height(500)
  .config({view: {stroke: null}})
  .render()
)}

function _unemployment(d3,datasets){return(
d3.tsv(datasets['unemployment.tsv'].url)
)}

function _usa(datasets){return(
datasets['us-10m.json']()
)}

function _scale(d3){return(
d3.scaleQuantile()
  .domain([0,1,5,6,2,4,6,2,4,6,7,8]).range(d3.schemeBlues[9])
)}

function _datasets(require){return(
require('vega-datasets')
)}

function _10(md){return(
md`# Choropleth usando Plot e D3

Para outros exemplos de mapa choropleth, veja [este notebook que usa D3](https://observablehq.com/@d3/choropleth/2?intent=fork) e [este outro notebook que usa Plot](https://observablehq.com/@observablehq/plot-choropleth?intent=fork).
`
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["Screen Shot 2021-12-05 at 11.02.37 PM.png", {url: new URL("./files/1dcac4699707d67e40a30c301b90ac9b4898aae0195c0b29856abfcd8abb5f390fce5521b923565c9fe6b0b1a72e15670d30b61903261849c3625cc092c98b60.png", import.meta.url), mimeType: "image/png", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["FileAttachment"], _2);
  main.variable(observer()).define(["md"], _3);
  main.variable(observer("choromap")).define("choromap", ["vl","usa","unemployment"], _choromap);
  main.variable(observer("unemployment")).define("unemployment", ["d3","datasets"], _unemployment);
  main.variable(observer("usa")).define("usa", ["datasets"], _usa);
  main.variable(observer("scale")).define("scale", ["d3"], _scale);
  const child1 = runtime.module(define1);
  main.import("vl", child1);
  main.variable(observer("datasets")).define("datasets", ["require"], _datasets);
  main.variable(observer()).define(["md"], _10);
  return main;
}
