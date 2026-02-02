import define1 from "./26670360aa6f343b@226.js";

function _1(md){return(
md`# Vega-Lite Api - Exercícios - 2025.2`
)}

function _2(md){return(
md`Você vai criar uma outra versão dos gráficos do [notebook passado](https://observablehq.com/@vis-ufc/introducao-ao-d3-exercicios-2025-2), agora usando a API Vega-Lite. 

A tabela abaixo cria e mostra o dataset abaixo consiste em um conjunto de dados sobre o estilo de vida e saúde de 100 indivíduos. Você pode acessar os dados através da variável \`life_style_data_sample\`.`
)}

function _3(md){return(
md`Faça um fork deste notebook e responda as questões abaixo.`
)}

function _life_style_data_sample(__query,FileAttachment,invalidation){return(
__query(FileAttachment("life_style_data_sample.csv"),{from:{table:"life_style_data_sample"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:null}},invalidation)
)}

function _5(life_style_data_sample){return(
life_style_data_sample
)}

function _6(md){return(
md`## Exercício 1

Escolha uma variável quantitativa do dataset dentr crie um gráfico de barras agregadas que mostra o valor médio dessa variável por \`Workout_Type\` em ordem decrescente. Veja a documentação do método [\`sort\`](https://vega.github.io/vega-lite/docs/sort.html) para ajudar na ordenação e este [exemplo](https://observablehq.com/@uwdata/data-transformation?collection=@uwdata/visualization-curriculum#cell-138) de utilização.`
)}

function _bar_chart(vl,life_style_data_sample,width)
{
  const quantVar = 'Calories_Burned';
  const catVar = 'Workout_Type';
  return vl.markBar()
  .data(life_style_data_sample)
  .encode(
    vl.x().mean(quantVar).title(quantVar.replace('_', ' ')),
    vl.y().fieldN(catVar)
      .sort(vl.mean(quantVar).order('descending')).title(catVar.replace('_', ' '))
  )
  .width(width * 0.7)
  .height(width * 0.2)
  .title(`Media de ${quantVar.replace('_', ' ')} por ${catVar.replace('_', ' ')}`)
  .render()
}


function _8(md){return(
md`## Exercício 2
Faça um scatterplot, usando duas variáveis quantitativas do dataset. Cada ponto deve representar um indivíduo. Você deve exibir dois scatterplots, um ao lado do outro, um para os homens e outro para as mulheres. Para facilitar, veja a documentação sobre [filtros](https://vega.github.io/vega-lite-api/api/filter) e o método [\`vl.column()\`](https://vega.github.io/vega-lite-api/api/column). Também veja um exemplo de utilização nesse [link](https://observablehq.com/@uwdata/multi-view-composition#cell-144).`
)}

function _scatter_plot(vl,life_style_data_sample,width)
{
  const quantVarX = 'Avg_BPM';
  const quantVarY = 'Calories_Burned';
  const catVar = 'Gender';

  return vl.markPoint({ filled: true, opacity: 1 })
    .data(life_style_data_sample)
    .encode(
      vl.x().fieldQ(quantVarX).scale({ zero: false })
        .title(quantVarX.replace('_', ' ')),
      
      vl.y().fieldQ(quantVarY).scale({ zero: false })
        .title(quantVarY.replace('_', ' ')),
      
      vl.column().fieldN(catVar)
        .title(catVar.replace('_', ' ')),
      
      vl.color().fieldN(catVar).title('Gênero').scale({domain: ['Male', 'Female'], range: ['steelblue', 'darkred']}),
      vl.tooltip([quantVarX, quantVarY, catVar, 'Age', 'Workout_Type'])
    )
    .width(width * 0.35)
    .height(width * 0.3)
    .title(`Relação entre ${quantVarY.replace('_', ' ')} e ${quantVarX.replace('_', ' ')} por Gênero`)
    .render();
}


function _10(md){return(
md`## Exercício 3
Para finalizar, exporte os dois gráficos para uma página no seu GitHub Pages. Você pode exportar usando a funcionalidade embed do Observable ou através do vega-embed.
[Aqui](https://observablehq.com/@vis-ufc/exemplo-de-exportar-uma-celula-vega-lite) está um passo-a-passo para exportar uma célula do Observable.

Coloque o link para o github pages na célula abaixo.
`
)}

function _11(md){return(
md`https://kelvinleandro.github.io/datavis2025/`
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["life_style_data_sample.csv", {url: new URL("./files/44e861968a5c7a81b976f2cda539d090881d340ca7bbec199b8a441ca95d69e68a086d3bf74a39b9d62d5b2f4793c8c58c0075a01eea3f3ff335c584a024e677.csv", import.meta.url), mimeType: "text/csv", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer()).define(["md"], _3);
  main.variable(observer("life_style_data_sample")).define("life_style_data_sample", ["__query","FileAttachment","invalidation"], _life_style_data_sample);
  main.variable(observer()).define(["life_style_data_sample"], _5);
  main.variable(observer()).define(["md"], _6);
  main.variable(observer("bar_chart")).define("bar_chart", ["vl","life_style_data_sample","width"], _bar_chart);
  main.variable(observer()).define(["md"], _8);
  main.variable(observer("scatter_plot")).define("scatter_plot", ["vl","life_style_data_sample","width"], _scatter_plot);
  main.variable(observer()).define(["md"], _10);
  main.variable(observer()).define(["md"], _11);
  const child1 = runtime.module(define1);
  main.import("vl", child1);
  return main;
}
