function _1(md){return(
md`# Introdução ao D3 (Parte 2) - Escalas e Eixos 

Neste notebook iremos nos aprofundar na criação de Visualizações Web usando D3.
Aprenderemos a usar escalas e eixos, construindo um scatterplot.`
)}

function _2(md){return(
md`## Um Primeiro Scatterplot

Scatterplots são uma maneira de compararmos dois atributos quantitativos em dois eixos diferentes, horizontal e vertical, ou **x** e **y**.

Na célula abaixo iremos criar um scatterplot. Complete-o de acordo com as instruções em sala (veja os comentários na célula). O resultado final deve ser como o mostrado abaixo:

![scatterplot1](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/images/observable/intro2_scatter1.png)`
)}

function _dataset(){return(
[ [5, 20], [480, 90], [250, 50],
            [100, 33], [330, 95], [410, 12], 
            [475, 44], [25, 67], [85, 21],
            [220, 88], [650, 100] ]
)}

function _svgwidth(margin){return(
800 - margin.left - margin.right
)}

function _svgheight(margin){return(
200 - margin.top - margin.bottom
)}

function _scatter1(d3,DOM,svgwidth,svgheight,dataset)
{
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const svg = d3.select(DOM.svg(svgwidth, svgheight))
  // Usando a variável svg, faça a vinculação com o dataset, criando círculos para a seleção enter
  // Veja o notebook da aula da semana passada para relembrar como fazer isso
  // O centro de cada círculo, atributos cx e cy deve ser posicionado de acordo com as 
  // coordenadas do vetor d[0] e d[1]. O raio de cada círculo (r) deve ser 5.

  svg.selectAll("circle")
    .data(dataset)
    .enter()
    .append("circle")
    .attr("cx", d => d[0])
    .attr("cy", d => d[1])
    .attr("r", 5)
  
  
  // A partir da variável svg,faça novamente a vinculação com o dataset, criando elementos de texto
  // nas mesmas posições dos centros dos círculos. Cada texto mostrará as coordenadas do seu ponto
  // correspondente.

  svg.selectAll("text")
    .data(dataset)
    .enter()
    .append("text")
    .attr("x", d => d[0])
    .attr("y", d => d[1])
    .attr("font-family", "sans-serif")
    .attr("font-size", "11px")
    .attr("fill", "red")
    .text(d => d[0] + "," + d[1])
  
  
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _7(md){return(
md`## Escalas

A ideia básica de escalas é transformar um número em um certo intervalo (chamado **domain**) em um número em um outro intervalo (chamado **range**):

![d3_scale](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/images/observable/d3_scale.png)`
)}

function _scale(d3){return(
d3.scaleLinear()
              .domain([25,85]) 
              .range([0,120])
)}

function _9(scale){return(
scale(90)
)}

function _10(md){return(
md`### Escalas quantitativas

* Escalas lineares (linear, quantize e quantile)
* Escalas logarítmicas
* Escalas potenciais (incluindo raiz quadrada)

Neste notebook, trabalharemos apenas com a escala [linear](https://github.com/d3/d3/blob/master/API.md#scales-d3-scale).

### Domain e Range
Para todas as escalas com exceção de quantize e quantile, domain e range funcionam da mesma maneira:
domain e range aceitam um vetor como parâmetro. 

\`\`\`javascript
let scale = d3.scaleLinear()
              .range([0,120])
              .domain([25,85])
\`\`\`

Ou seja, os vetores definem os limites do intervalo que será transformado.
Normalmente são dois números, mas podem ser mais de dois, veja o exemplo a seguir.

![d3_scale2](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/images/observable/d3_scale2.png)

Se o parâmetro for um vetor com mais de dois números, então estamos falando de escalas segmentadas:`
)}

function _scale2(d3){return(
d3.scaleLinear().domain([25, 45, 85]).range([0, 80, 120])
)}

function _12(md){return(
md`
> ** Atenção**: domain e range devem ter os mesmos números de segmentos.

### Clamping

O que acontece se a escala é usada para processar um número fora do domínio? Esse comportamento é controlado pelo método clamping.

Se ele for *true*, os valores fora do domínio são truncados para o mínimo e máximo da escala. Se for *false* a transformação é feita normalmente e retornará um valor fora do range.`
)}

function _13(scale){return(
scale(100)
)}

function _value(scale)
{
  scale.clamp(true); // set clamp to true
  return scale(100); //retorna 120
}


function _15(md){return(
md`## Usando escalas

Tipicamente nós chamaremos a função de escala de dentro de um método \\\`.attr()\\\` ou similar.

\`\`\`javascript
.attr("cy", scale(d[1]))
\`\`\`

Vamos aplicar escalas ao nosso scatterplot.`
)}

function _16(md){return(
md `
Modifique o scatterplot acima na célula abaixo para que utilize uma escala linear horizontal e uma vertical.`
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

function _scatter2(d3,DOM,svgwidth,svgheight,dataset,xScale,yScale)
{
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const svg = d3.select(DOM.svg(svgwidth, svgheight)) 
  
  // Usando a variável svg, faça a vinculação com o dataset, criando círculos para a seleção enter
  // Veja o notebook da aula da semana passada para relembrar como fazer isso
  // O centro de cada círculo, atributos cx e cy deve ser posicionado de acordo com as 
  // coordenadas do vetor d[0] e d[1] na escala de eixos. O raio de cada círculo deve ser 5. 
  
  
  // A partir da variável svg,faça novamente a vinculação com o dataset, criando elementos de texto
  // nas mesmas posições dos centros dos círculos. Cada texto mostrará as coordenadas do seu ponto
  // correspondente.

  svg.selectAll("circle")
    .data(dataset)
    .enter()
    .append("circle")
    .attr("cx", d => xScale(d[0]))
    .attr("cy", d => yScale(d[1]))
    .attr("r", 5)

  svg.selectAll("text")
    .data(dataset)
    .enter()
    .append("text")
    .attr("x", d => xScale(d[0]))
    .attr("y", d => yScale(d[1]))
    .attr("font-family", "sans-serif")
    .attr("font-size", "11px")
    .attr("fill", "red")
    .text(d => d[0] + "," + d[1])
  
  
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _20(md){return(
md`## Refinando o scatterplot

### Utilizando Margens
Observe na célula abaixo como são definidas as margens de acordo com [esta convenção](https://observablehq.com/@d3/margin-convention).

Depois copie a parte do código referente à criação das escalas (com a escala vertical invertida), dos círculos e
dos labels da célula acima para a célula abaixo e veja o resultado.

Depois siga as instruções para a criação de eixos que estão no PDF.
`
)}

function _margin()
{
  //Definimos o objeto margin
  let margin = {top: 40, right: 40, bottom: 40, left: 40};
  return margin;
}


function _xAxis(d3,xScale){return(
d3.axisBottom().scale(xScale).ticks(5)
)}

function _yAxis(d3,yScale){return(
d3.axisLeft().scale(yScale)
)}

function _24(md){return(
md`

Depois definimos \`svgwidth\` e \`svgheight\` como as dimensões internas da área do gráfico (área útil).
Modifique as células  \`svgwidth\` e \`svgheight\` para ficarem como mostrado abaixo:

\`\`\`javascript
svgwidth = 800 - margin.left - margin.right

svgheight = 200 - margin.top - margin.bottom
\`\`\``
)}

function _scatter3(d3,DOM,svgwidth,margin,svgheight,dataset,xScale,yScale,xAxis,yAxis)
{ 
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const outersvg = d3.select(DOM.svg(svgwidth + margin.left + margin.right,
                                svgheight + margin.top + margin.bottom))
  // Depois adicionamos um elemento g no svg que vai transladar a origem 
  // do gráfico como sendo a origem da área útil do gráfico
  const svg = outersvg.append('g')
                       .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
 
  
  // Usando a variável svg, faça a vinculação com o dataset, criando círculos para a seleção enter
  // Veja o notebook da aula da semana passada para relembrar como fazer isso
  // O centro de cada círculo, atributos cx e cy deve ser posicionado de acordo com as 
  // coordenadas do vetor d[0] e d[1] na escala de eixos. O raio de cada círculo deve ser 5. 

  svg.selectAll("circle")
    .data(dataset)
    .enter()
    .append("circle")
    .attr("cx", d => xScale(d[0]))
    .attr("cy", d => yScale(d[1]))
    .attr("r", 5)
  
  
  // A partir da variável svg,faça novamente a vinculação com o dataset, criando elementos de texto
  // nas mesmas posições dos centros dos círculos. Cada texto mostrará as coordenadas do seu ponto
  // correspondente.

  svg.selectAll("text")
    .data(dataset)
    .enter()
    .append("text")
    .attr("x", d => xScale(d[0]))
    .attr("y", d => yScale(d[1]))
    .attr("font-family", "sans-serif")
    .attr("font-size", "11px")
    .attr("fill", "red")
    .text(d => d[0] + "," + d[1])
  
  // Chamadas para desenhar os eixos
  svg.append('g')
    .attr('transform', 'translate(0,' + svgheight + ')')
    .call(xAxis)

  svg.append('g')
    .call(yAxis)

  svg.append("text")
    .attr("transform", "translate(" + (svgwidth/2) + "," + (svgheight + margin.bottom) + ")")
    .style("text-anchor", "middle")
    .attr("font-family", "sans-serif")
    .attr("font-size", "12px")
    .text("Eixo X");
  
  svg.append("text")
    .attr("transform", "rotate(-90)")
    .attr("y", 0 - margin.left)
    .attr("x", 0 - (svgheight / 2))
    .attr("dy", "1em")
    .style("text-anchor", "middle")
    .attr("font-family", "sans-serif")
    .attr("font-size", "12px")
    .text("Eixo Y");
  
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return outersvg.node()
}


function _26(md){return(
md`## Exercício
Carregue os dados do arquivo [movies.json](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/files/observable/movies.json) e construa um scatterplot comparando bilheteria
(Worldwide_Gross_M) e orçamento (Budget_M). Existe alguma correlação entre essas variáveis? Existem outliers? Quais são?`
)}

function _moviesdataset(d3){return(
d3.json('https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/files/observable/movies.json')
)}

function _xScale2(d3,moviesdataset,svgwidth){return(
d3.scaleLinear()
          .domain([0, d3.max(moviesdataset, d => d.Budget_M)])
          .range([0, svgwidth])
)}

function _yScale2(d3,moviesdataset,svgheight){return(
d3.scaleLinear()
          .domain([0, d3.max(moviesdataset, d => d.Worldwide_Gross_M)])
          .range([svgheight, 0])
)}

function _xAxis2(d3,xScale2){return(
d3.axisBottom().scale(xScale2)
)}

function _yAxis2(d3,yScale2){return(
d3.axisLeft().scale(yScale2).ticks(5)
)}

function _movies(d3,DOM,svgwidth,margin,svgheight,moviesdataset,xScale2,yScale2,xAxis2,yAxis2)
{
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const outersvg = d3.select(DOM.svg(svgwidth + margin.left + margin.right,
                                svgheight + margin.top + margin.bottom))
  // Depois adicionamos um elemento g no svg que vai transladar a origem 
  // do gráfico como sendo a origem da área útil do gráfico
  const svg = outersvg.append('g')
                       .attr("transform", "translate(" + margin.left + "," + margin.top + ")")
  
  // Escreva aqui o código

  const maiorBilheteria = d3.max(moviesdataset, d => d.Worldwide_Gross_M)
  
  svg.selectAll("circle")
    .data(moviesdataset)
    .enter()
    .append("circle")
    .attr("cx", d => xScale2(d.Budget_M))
    .attr("cy", d => yScale2(d.Worldwide_Gross_M))
    .attr("r", 5)

  // destacando filme com maior bilheteria
  svg.selectAll("text")
    .data(moviesdataset)
    .enter()
    .append("text")
    .attr("x", d => xScale2(d.Budget_M) + 7)
    .attr("y", d => yScale2(d.Worldwide_Gross_M))
    .attr("font-family", "sans-serif")
    .attr("font-size", "11px")
    .attr("fill", "red")
    .text(d => d.Worldwide_Gross_M === maiorBilheteria ? `${d.Film} (${d.Worldwide_Gross_M} M)` : "")

  // desenhando eixos
  svg.append('g')
    .attr('transform', 'translate(0,' + svgheight + ')')
    .call(xAxis2)

  svg.append('g')
    .call(yAxis2)

  svg.append("text")
    .attr("transform", "translate(" + (svgwidth/2) + "," + (svgheight + margin.bottom) + ")")
    .style("text-anchor", "middle")
    .attr("font-family", "sans-serif")
    .attr("font-size", "12px")
    .text("Budget (M)");
  
  svg.append("text")
    .attr("transform", "rotate(-90)")
    .attr("y", 0 - margin.left)
    .attr("x", 0 - (svgheight / 2))
    .attr("dy", "1em")
    .style("text-anchor", "middle")
    .attr("font-family", "sans-serif")
    .attr("font-size", "12px")
    .text("Worldwide Gross (M)");
  
 
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return outersvg.node()
}


function _33(md){return(
md`Escreva sua resposta aqui.`
)}

function _d3(require){return(
require('d3')
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer("dataset")).define("dataset", _dataset);
  main.variable(observer("svgwidth")).define("svgwidth", ["margin"], _svgwidth);
  main.variable(observer("svgheight")).define("svgheight", ["margin"], _svgheight);
  main.variable(observer("scatter1")).define("scatter1", ["d3","DOM","svgwidth","svgheight","dataset"], _scatter1);
  main.variable(observer()).define(["md"], _7);
  main.variable(observer("scale")).define("scale", ["d3"], _scale);
  main.variable(observer()).define(["scale"], _9);
  main.variable(observer()).define(["md"], _10);
  main.variable(observer("scale2")).define("scale2", ["d3"], _scale2);
  main.variable(observer()).define(["md"], _12);
  main.variable(observer()).define(["scale"], _13);
  main.variable(observer("value")).define("value", ["scale"], _value);
  main.variable(observer()).define(["md"], _15);
  main.variable(observer()).define(["md"], _16);
  main.variable(observer("xScale")).define("xScale", ["d3","dataset","svgwidth"], _xScale);
  main.variable(observer("yScale")).define("yScale", ["d3","dataset","svgheight"], _yScale);
  main.variable(observer("scatter2")).define("scatter2", ["d3","DOM","svgwidth","svgheight","dataset","xScale","yScale"], _scatter2);
  main.variable(observer()).define(["md"], _20);
  main.variable(observer("margin")).define("margin", _margin);
  main.variable(observer("xAxis")).define("xAxis", ["d3","xScale"], _xAxis);
  main.variable(observer("yAxis")).define("yAxis", ["d3","yScale"], _yAxis);
  main.variable(observer()).define(["md"], _24);
  main.variable(observer("scatter3")).define("scatter3", ["d3","DOM","svgwidth","margin","svgheight","dataset","xScale","yScale","xAxis","yAxis"], _scatter3);
  main.variable(observer()).define(["md"], _26);
  main.variable(observer("moviesdataset")).define("moviesdataset", ["d3"], _moviesdataset);
  main.variable(observer("xScale2")).define("xScale2", ["d3","moviesdataset","svgwidth"], _xScale2);
  main.variable(observer("yScale2")).define("yScale2", ["d3","moviesdataset","svgheight"], _yScale2);
  main.variable(observer("xAxis2")).define("xAxis2", ["d3","xScale2"], _xAxis2);
  main.variable(observer("yAxis2")).define("yAxis2", ["d3","yScale2"], _yAxis2);
  main.variable(observer("movies")).define("movies", ["d3","DOM","svgwidth","margin","svgheight","moviesdataset","xScale2","yScale2","xAxis2","yAxis2"], _movies);
  main.variable(observer()).define(["md"], _33);
  main.variable(observer("d3")).define("d3", ["require"], _d3);
  return main;
}
