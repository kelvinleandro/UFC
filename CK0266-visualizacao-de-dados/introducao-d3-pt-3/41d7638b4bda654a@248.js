import define1 from "./e93997d5089d7165@2303.js";

function _1(md){return(
md`# Introdução ao D3 (Parte 3) - Updates e Transições

## Scatterplot

Vejamos um exemplo de scatterplot simples, com suporte a alguns eventos e entradas do usuário`
)}

function _dataset(generateRandomDataset){return(
generateRandomDataset(50)
)}

function _scatter1(d3,DOM,totalwidth,totalheight,margin,dataset,xScale,yScale,svgheight,xAxis,svgwidth,yAxis)
{
  
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const outersvg = d3.select(DOM.svg(totalwidth, totalheight))
  // Depois adicionamos um elemento g no svg que vai transladar a origem 
  // do gráfico como sendo a origem da área útil do gráfico
  const svg = outersvg.append('g')
                       .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
   
  // Depois adicione os elementos círculos
    svg.selectAll("circle")
        .data(dataset)
        .enter()
        .append("circle")
        .attr("cx", d => xScale(d[0]))
        .attr("cy", d => yScale(d[1]))
        .attr("r", 4)
   
  // Depois adicione os eixos e os labels
    svg.append("g")
       .attr("transform", "translate(0," + svgheight + ")")
       .attr("class", "x axis")
       .call(xAxis)

    svg.append("text")             
        .attr("transform", "translate(" + (svgwidth/2) + "," + (svgheight + margin.bottom) + ")")
        .attr("class", "label")
        .text("Eixo X")

    svg.append("g")
       .attr("class", "y axis")
       .call(yAxis)

    svg.append("text")
        .attr("class", "label")
        .attr("transform", "rotate(-90)")
        .attr("y", 0 - margin.left)
        .attr("x",0 - (svgheight / 2))
        .attr("dy", "10")
        .text("Eixo Y")
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return outersvg.node()
}


function _margin()
{
  return {top: 40, right: 40, bottom: 40, left: 40}
}


function _totalwidth(){return(
800
)}

function _totalheight(){return(
200
)}

function _svgwidth(totalwidth,margin){return(
totalwidth - margin.left - margin.right
)}

function _svgheight(totalheight,margin){return(
totalheight - margin.top - margin.bottom
)}

function _xScale(d3,dataset,svgwidth){return(
d3.scaleLinear()
           .domain([0, d3.max(dataset, d => d[0])])
           .range([0, svgwidth])
)}

function _yScale(d3,dataset,svgheight){return(
d3.scaleLinear()
           .domain([0, d3.max(dataset, d => d[1])])
           .range([svgheight, 0])
)}

function _xAxis(d3,xScale){return(
d3.axisBottom()
          .scale(xScale)
          .ticks(5)
)}

function _yAxis(d3,yScale){return(
d3.axisLeft()
          .scale(yScale)
          .ticks(5)
)}

function _generateRandomDataset(){return(
function(numDataPoints) {
        let dataset = []
        let xRange = Math.random() * 1000
        let yRange = Math.random() * 1000

        for (let i=0; i < numDataPoints; i++) {
            let newNumber1 = Math.floor(Math.random() * xRange)
            let newNumber2 = Math.floor(Math.random() * yRange)
            dataset.push([newNumber1, newNumber2])
        }
        return dataset;
    }
)}

function _15(md){return(
md`## Updates mais complexos
Para tratar updates mais complexos, precisamos separar o código em inicialização`
)}

function _scatter2(d3,DOM,totalwidth,totalheight)
{
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const outersvg = d3.select(DOM.svg(totalwidth, totalheight))
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return outersvg.node()
}


function _vis(d3,scatter2,margin,svgheight,xAxis,svgwidth,yAxis)
{
  // Inicialização da Visualização
  d3.select(scatter2).select("#chart").remove()
  // Depois adicionamos um elemento g no svg que vai transladar a origem 
  // do gráfico como sendo a origem da área útil do gráfico
  let svg = d3.select(scatter2).append('g')
              .attr("id", "chart")
              .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
  
  svg.append("g")
       .attr("transform", "translate(0," + svgheight + ")")
       .attr("class", "x axis")
       .call(xAxis)
  svg.append("text")             
        .attr("transform", "translate(" + (svgwidth/2) + "," + (svgheight + margin.bottom) + ")")
        .attr("class", "label")
        .text("Eixo X")

   svg.append("g")
       .attr("class", "y axis")
       .call(yAxis)

    svg.append("text")
        .attr("class", "label")
        .attr("transform", "rotate(-90)")
        .attr("y", 0 - margin.left)
        .attr("x",0 - (svgheight / 2))
        .attr("dy", "10")
        .text("Eixo Y")
  return svg
}


function _d3(require){return(
require('d3')
)}

function _20(md){return(
md`Abaixo está uma célula com os estilos usados no notebook:`
)}

function _21(html){return(
html`<style>
p {
    font-family: Optima, Futura, sans-serif;
}
.axis path,
.axis line {
    stroke: dimgray;
    shape-rendering: crispEdges;
}

.axis text {
    font-family: Optima, Futura, sans-serif;
    font-weight: bold;
    font-size: 12px;
    fill: dimgray;
}

.label {
    font-family: Optima, Futura, sans-serif;
    font-weight: bold;
    font-size: 14px;
    fill: dimgray;
    text-anchor: middle;
}
</style>`
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("dataset")).define("dataset", ["generateRandomDataset"], _dataset);
  main.variable(observer("scatter1")).define("scatter1", ["d3","DOM","totalwidth","totalheight","margin","dataset","xScale","yScale","svgheight","xAxis","svgwidth","yAxis"], _scatter1);
  main.variable(observer("margin")).define("margin", _margin);
  main.variable(observer("totalwidth")).define("totalwidth", _totalwidth);
  main.variable(observer("totalheight")).define("totalheight", _totalheight);
  main.variable(observer("svgwidth")).define("svgwidth", ["totalwidth","margin"], _svgwidth);
  main.variable(observer("svgheight")).define("svgheight", ["totalheight","margin"], _svgheight);
  main.variable(observer("xScale")).define("xScale", ["d3","dataset","svgwidth"], _xScale);
  main.variable(observer("yScale")).define("yScale", ["d3","dataset","svgheight"], _yScale);
  main.variable(observer("xAxis")).define("xAxis", ["d3","xScale"], _xAxis);
  main.variable(observer("yAxis")).define("yAxis", ["d3","yScale"], _yAxis);
  main.variable(observer("generateRandomDataset")).define("generateRandomDataset", _generateRandomDataset);
  main.variable(observer()).define(["md"], _15);
  main.variable(observer("scatter2")).define("scatter2", ["d3","DOM","totalwidth","totalheight"], _scatter2);
  main.variable(observer("vis")).define("vis", ["d3","scatter2","margin","svgheight","xAxis","svgwidth","yAxis"], _vis);
  main.variable(observer("d3")).define("d3", ["require"], _d3);
  const child1 = runtime.module(define1);
  main.import("button", child1);
  main.variable(observer()).define(["md"], _20);
  main.variable(observer()).define(["html"], _21);
  return main;
}
