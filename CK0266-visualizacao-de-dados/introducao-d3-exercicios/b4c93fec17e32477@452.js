function _1(md){return(
md`# Introdução ao D3: Exercícios 2025.2

Neste notebook iremos praticar o que estudamos nos notebooks:

- [Introdução ao D3 (Parte 1)](https://observablehq.com/@vis-ufc/introducao-ao-d3-com-observable-parte-1)
- [Introdução ao D3 (Parte 2) - Escalas e Eixos](https://observablehq.com/@vis-ufc/introducao-ao-d3-parte-2-escalas-e-eixos)
- [Introdução ao D3 (Parte 3) - Updates e Transições](https://observablehq.com/@vis-ufc/introducao-ao-d3-parte-3-updates-e-transicoes)`
)}

function _2(md){return(
md`O dataset abaixo consiste em um conjunto de dados sobre o estilo de vida e saúde de 100 indivíduos.`
)}

function _life_style_data(FileAttachment){return(
FileAttachment("life_style_data_sample.csv").csv({typed: true})
)}

function _4(md){return(
md`## Exercício 1

Escolha uma variável quantitativa do dataset e crie um gráfico de barras que mostra o valor dessa variável por indivídulo em ordem crescente.`
)}

function _barras_horizontais(life_style_data,d3,DOM)
{
  const width = 800;
  const height = 650;
  const margin = { 
    top: 40, right: 40, bottom: 40, left: 120
  };

  const quantVar = "Avg_BPM";
  
  life_style_data.sort((a, b) => d3.ascending(a[quantVar], b[quantVar]))

  const scaleX = d3.scaleLinear()
    .domain([0, d3.max(life_style_data, d => d[quantVar])])
    .range([margin.left, width - margin.right])

  const scaleY = d3.scaleBand()
    .domain(d3.range(1, life_style_data.length + 1))
    .range([margin.top, height - margin.bottom])
    .padding(0.2)

  const svg = d3.select(DOM.svg(width, height))

  svg.append("g")
    .attr("transform", `translate(0,${height - margin.bottom})`)
    .call(d3.axisBottom(scaleX))

  svg.append("g")
    .attr("transform", `translate(${margin.left},0)`)
    .call(d3.axisLeft(scaleY)
      .tickValues(scaleY.domain().filter((d) => d % 5 === 0))
    )
  
  svg.append("g")
    .selectAll("rect")
    .data(life_style_data)
    .join("rect")
      .attr("x", scaleX(0))
      .attr("y", (_, i) => scaleY(i + 1))
      .attr("width", d => scaleX(d[quantVar]) - scaleX(0))
      .attr("height", scaleY.bandwidth())
      .attr("fill", "#7875CB")

  svg.append("text")
    .attr("x", width / 2)
    .attr("y", margin.top - 15)
    .attr("text-anchor", "middle")
    .attr("font-size", 16)
    .attr("font-weight", "bold")
    .text(`${quantVar} por Pessoa`);
  
 
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _6(md){return(
md`## Exercício 2
Faça um scatterplot, usando duas variáveis quantitativas do dataset. Existe alguma correlação entre essas variáveis? Existem outliers? Quais são?

**Observação: Tente responder apenas observando o gráfico gerado. Você não precisa implementar uma função de detecção de outliers para responder.**`
)}

function _scatterplot(d3,life_style_data,DOM)
{
  const width = 700;
  const height = 500;
  const margin = { top: 40, right: 40, bottom: 50, left: 60 };

  const xVar = "BMI";
  const yVar = "Fat_Percentage";

  const scaleX = d3.scaleLinear()
    .domain(d3.extent(life_style_data, d => d[xVar]))
    .nice()
    .range([margin.left, width - margin.right]);

  const scaleY = d3.scaleLinear()
    .domain(d3.extent(life_style_data, d => d[yVar]))
    .nice()
    .range([height - margin.bottom, margin.top]);

  const svg = d3.select(DOM.svg(width, height))
    .style("font-family", "sans-serif");

  svg.append("g")
    .attr("transform", `translate(0,${height - margin.bottom})`)
    .call(d3.axisBottom(scaleX));

  svg.append("g")
    .attr("transform", `translate(${margin.left},0)`)
    .call(d3.axisLeft(scaleY));

  svg.append("g")
    .selectAll("circle")
    .data(life_style_data)
    .join("circle")
      .attr("cx", d => scaleX(d[xVar]))
      .attr("cy", d => scaleY(d[yVar]))
      .attr("r", 5)
      .attr("fill", "#0000ff")
      .attr("opacity", 0.8);

  svg.append("text")
    .attr("x", width / 2)
    .attr("y", height - 10)
    .attr("text-anchor", "middle")
    .attr("font-size", 12)
    .text(xVar);

  svg.append("text")
    .attr("x", -height / 2)
    .attr("y", 20)
    .attr("transform", "rotate(-90)")
    .attr("text-anchor", "middle")
    .attr("font-size", 12)
    .text(yVar);

  svg.append("text")
    .attr("x", width / 2)
    .attr("y", margin.top - 15)
    .attr("text-anchor", "middle")
    .attr("font-size", 16)
    .attr("font-weight", "bold")
    .text(`${yVar} vs ${xVar}`);

  return svg.node();
}


function _8(md){return(
md`Há uma correlação positiva entre o IMC (**BMI**) e o percentual de gordura (**Fat_Percentage**), indicando que indivíduos com maior IMC também apresentam maior acúmulo de gordura. **Não foram observados outliers**, visto que todos os pontos seguem o padrão de tendência`
)}

function _d3(require){return(
require('d3')
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
  main.variable(observer("life_style_data")).define("life_style_data", ["FileAttachment"], _life_style_data);
  main.variable(observer()).define(["md"], _4);
  main.variable(observer("barras_horizontais")).define("barras_horizontais", ["life_style_data","d3","DOM"], _barras_horizontais);
  main.variable(observer()).define(["md"], _6);
  main.variable(observer("scatterplot")).define("scatterplot", ["d3","life_style_data","DOM"], _scatterplot);
  main.variable(observer()).define(["md"], _8);
  main.variable(observer("d3")).define("d3", ["require"], _d3);
  return main;
}
