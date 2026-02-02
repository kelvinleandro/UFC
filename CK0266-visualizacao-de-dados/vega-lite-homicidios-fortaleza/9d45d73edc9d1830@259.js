function _1(md){return(
md`# Taxa de Homicídios em Fortaleza em 2012 (Vega-Lite)`
)}

function _2(md){return(
md`## Melhore o mapa de crimes de Fortaleza

O mapa de crimes de Fortaleza possui alguns problemas. Um desses problemas é que os dados não levam em consideração a população do bairro, normalmente a taxa de homicídios é mostrada em número de homicídios por 100000 habitantes. 

O dataset \`homicides\` contém o total de homicídios e a população de cada bairro. Use a população para calcular a taxa de homicídios por 100.000 habitantes. Modifique o mapeamento de cores para usar a taxa calculada e mostre esse valor com até uma casa decimal no tooltip. Qual o bairro com maior taxa de homicídios em Fortaleza em 2012? Adicione uma célula de texto abaixo com a resposta.`
)}

function _3(md){return(
md`# Homicídios em Fortaleza em 2012`
)}

function _mapchoro2(vl,bairros,homicides)
{
  return vl.markGeoshape({stroke: '#888', strokeWidth: 0.25})
  .data(vl.topojson(bairros).feature('POLIGONAIS'))
  .transform(
      vl.lookup('properties.Name').from(vl.data(homicides).key('Bairro').fields('Bairro', 'Número de Homicidios', 'População')),
      vl.calculate('datum.População && datum.População > 0 ? (datum["Número de Homicidios"] / datum.População * 100000) : 0')
        .as('Taxa100k')
    )
    .encode(
        vl.color().fieldQ('Taxa100k').scale({type: 'quantize', clamp: true, scheme: {name: 'blues', count: 5}}),
        vl.tooltip([
          { field: 'Bairro', type: 'nominal' },
          { field: 'Taxa100k', type: 'quantitative', format: '.1f', title: 'Taxa por 100 mil' }
        ])
      )
  .project(vl.projection('mercator'))
  .width(850).height(500)
.render()
}


function _5(homicides){return(
homicides.filter(el => !el['População'])
)}

function _homicides(d3){return(
d3.csv("https://gist.githubusercontent.com/emanueles/71de6a2f858ec1f2f4da47c45883cbf8/raw/144ec4a088d33b2adb44d38740831542a6b2b096/FortalezaHomicidiosPopulacao2012.csv", d3.autoType)
)}

function _bairros(d3){return(
d3.json("https://gist.githubusercontent.com/emanueles/eddad5e0733eb4391e2650d74f492319/raw/a84dfbda335cf4921b48f91f5096469ffd4c8dea/bairros.topojson")
)}

function _8(md){return(
md`O bairro com maior taxa de homicídio é **Sabiaguaba**, com a taxa de **425.1**`
)}

function _9(md){return(
md`# Versão Alternativa com D3 e Leaflet
Para uma versão alternativa usando D3 e Leaflet consulte este [notebook](https://observablehq.com/@vis-ufc/homicidios-em-fortaleza-em-2012).`
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer()).define(["md"], _3);
  main.variable(observer("mapchoro2")).define("mapchoro2", ["vl","bairros","homicides"], _mapchoro2);
  main.variable(observer()).define(["homicides"], _5);
  main.variable(observer("homicides")).define("homicides", ["d3"], _homicides);
  main.variable(observer("bairros")).define("bairros", ["d3"], _bairros);
  main.variable(observer()).define(["md"], _8);
  main.variable(observer()).define(["md"], _9);
  return main;
}
