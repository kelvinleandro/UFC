function _1(md){return(
md`# Introdução ao D3 com Observable
Nesse notebook iremos aprender como usar o D3.
## Visão geral
D3 ou d3.js é uma biblioteca JavaScript declarativa para criação de visualizações cujo foco está nos dados.
É interativa, rápida e flexível. No entanto todo esse poder do D3 exige que tenhamos conhecimento de detalhes de HTML, CSS e JavaScript. Mesmo que você ainda não tenha muito conhecimento, pode copiar e colar vários exemplos de códigos disponíveis na Web.

O D3 facilita a vinculação de dados de entrada a elementos do DOM.`
)}

function _2(md){return(
md`## d3js.org
* Autor principal: Mike Bostock.
* Open source e também disponível no [GitHub](https://github.com/d3/d3).
* Grande comunidade de usuários e muitos exemplos de aplicação.
* Apresentada oficialmente na InfoVis 2011, com o artigo [D3: Data-Driven Documents](http://idl.cs.washington.edu/papers/d3).

## O que o D3 faz

* **Carrega** dados na memória do browser.
* **Vincula** dados a elementos dentro do documento, criando novos elementos quando necessário.
* **Transforma** os elementos interpretando o valor do dado associado ao elemento e alterando as suas propriedades visuais.
* **Transiciona** elementos entre estados em resposta a entrada do usuário.

## O que o D3 não faz
**Não é uma biblioteca de gráficos (barras, pizza, linhas, etc).**

* Não suporta browsers antigos.
* Não esconde os seus dados originais.
 *  Os dados são enviados para o browser do cliente.
 *  Se os seus dados não podem ser compartilhados, não use D3.`
)}

function _3(md,key){return(
md`## Como usar esse Notebook
* Comece **"forking"** esse notebook pelo botão no topo da página à direita. Isso irá permitir que você salve as alterações feitas nesse notebook.

### Células

Para ver o código ou o markdown por trás de um célula, clique nos três pontinhos do lado esquerdo de uma célula e clique em **edit**. Experimente com a célula abaixo.

*Sempre que modificar o código, pressione ${key(
  "Shift-Enter"
)} para executar o código. Você precisará fazer isso para que a maioria das visualizações apareça*`
)}

function _4(){return(
10 * 5 * 2
)}

function _5(md,greypin){return(
md` 
Clique o ${greypin} no lado esquerdo da célula para manter a janela de código aberta, mesmo que você não esteja com a seção selecionada.

Células podem ter nomes. Isso permite que o valor de uma célula seja referenciado por outras células.`
)}

function _comida(){return(
"chocolate"
)}

function _7(md,comida){return(
md`E quem não gosta de ${comida}?`
)}

function _8(md,key){return(
md`** Células seguem o modelo de execução de dataflow.**
  
Uma célula referenciando outra célula é avaliada novamente automaticamente quando o valor da referência é alterado. Por exemplo, altere a definição da variável \`comida\` acima e pressione pressione ${key(
  "Shift-Enter"
)} para avaliá-la novamente.

Células podem gerar elementos DOM (HTML, SVG, Canvas, WebGL, etc.). Você pode usar a API DOM padrão como \`document.createElement\`, ou usar o template literal built-in \`html\`:`
)}

function _9(html){return(
html`<span style="background:salmon;">
  Esse é o template literal <i>HTML</i>.<br> 
  Ele é usado para criar células com HTML.
</span>`
)}

function _10(md){return(
md`
*Essa foi apenas uma pequena introdução a notebooks Observable. Para saber mais, veja os links no final desse notebook.*

---
## Elementos básicos de D3

O **operando** básico do d3 é uma **seleção**.
 * Conjunto selecionado de elementos consultados a partir do documento atual.

**Operadores** atuam em seleções, modificando conteúdo.

**Data joins** vinculam dados a elementos, produzindo subseleções **enter** e **exit** para criação e destruição de elementos correspondendo a dados.

**Transições** animadas interpolam atributos e estilos em função do tempo.

**Event handlers** para lidar com ações do usuário.

**Módulos** simplificando algumas tarefas de visualização.`
)}

function _11(md){return(
md`## Seleções

O D3 adota a API de seletores da W3C (a mesma utilizada pelo CSS e pelo jQuery) para identificar elementos para seleção:

\`\`\`
pela tag ("tag")
pela classe (".class")
pelo identificador ("#id")
pela tag com identificador ("tag#id")…
\`\`\`

O namespace global d3 possui métodos \`\`select\`\` e \`\`selectAll\`\` para obter as seleções e aceitam os seletores acima.`
)}

function _12(md){return(
md`### Selecionando um único elemento
No exemplo abaixo, iremos adicionar um elemento parágrafo (p) ao **div**. 

Primeiro selecionamos o div pelo seu id (parent), depois adicionamos o elemento p e por fim o texto “Hello world” é adicionado a ele, através do operador **.text().**`
)}

function _13(html){return(
html`
<div><p>Escreva Hello World abaixo:</p></div>
<div id="parent">
  
</div>
`
)}

function _14(d3)
{
  d3.select("#parent")
    .append("p")
    .text("Hello World!");
}


function _15(md){return(
md`### Encadeando métodos

D3 usa com frequência uma técnica chamada “chain syntax” (sintaxe de cadeia), na qual os métodos são encadeados com pontos “.”. Isso permite executar várias operações em um único comando:
\`\`\`javascript
d3.select("#parent")
    .append("p")
    .text("Hello World!");
\`\`\`
`
)}

function _16(md){return(
md`### Operadores

Além de **.text()**, outros operadores:

* Configurando atributos: **.attr()**
* Estilos: **.style()**
* Propriedades: **.property()**
* HTML: **.html()**

Exemplos:
* Configurar o atributo foo com o valor bar no elemento p
\`\`\`javascript
d3.select("p").attr("foo", "bar")
\`\`\`
 
* Obter o atributo foo no elemento p
\`\`\`javascript
d3.select("p").attr("foo")
\`\`\`
* Altera o tamanho da fonte do estilo do elemento p
\`\`\`javascript
d3.select("p").style("font-size", "10px")
\`\`\`

Além de constantes, valores de operadores também podem ser funções:
\`\`\`javascript
d3.select("p").style("font-size", function(){
         return normalFontSize + 10;});
\`\`\`
`
)}

function _17(md){return(
md`## Exercício
Modifique o código html da célula abaixo usando d3 na célula seguinte para:
Adicionar um novo elemento \`\`div\`\` ao \`\`div\`\` com id *exercicio* contendo o seguinte estilo:
\`\`\`
border: 1px black solid
background-color: LightYellow
font-size: 24px
\`\`\`
O novo div deve possuir id igual a **newDiv**.

Depois adicione o parágrafo com o texto “Novo parágrafo!” ao elemento div com id newDiv.
O resultado deve ser como o mostrado abaixo:

![Novo parágrafo](https://emanueles.github.io/datavis-course/assets/images/observable/intro1_exercicio1.png)`
)}

function _18(html){return(
html`
<div id="exercicio">
   <p>Célula html</p>
</div>`
)}

function _19(d3)
{
  // escreva seu código aqui
  d3.select("#exercicio")
    .append("div")
      .attr("id", "newDiv")
      .style("border", "1px black solid")
      .style("background-color", "LightYellow")
      .style("font-size", "24px")
    .append("p").text("Novo parágrafo!")
}


function _20(md){return(
md`## Selecionando múltiplos elementos
Podemos selecionar mais de um elemento de uma vez:
\`\`\`javascript
d3.selectAll("rect") 
  .attr("width", "200"); 
\`\`\` 

## Adicionando elementos
O operador \`\`.append()\`\` cria um novo elemento com o nome dado e o adiciona como último filho de cada elemento da seleção.

Esse operador retorna uma nova seleção contendo o elemento recém adicionado.`
)}

function _21(html){return(
html`
<div class="selectall-example">
  <svg width="800" height="300"></svg>
</div>
<style>
  .selectall-example {
    border: 1px solid black;
    display: inline-block;
  }
</style>`
)}

function _22(d3)
{
  // retorna uma seleção d3 do elemento svg dentro do elemento de classe selectall-example
  const svg = d3.select('.selectall-example').select("svg") 
  
   svg.append('rect')
      .attr("x", "50")
      .attr("y", "50")
   svg.append('rect')
      .attr("x", "300")
      .attr("y", "50")
   svg.append('rect')
      .attr("x", "550")
      .attr("y", "50")
   svg.selectAll('rect')
      .attr("width", "200")
      .attr("height", "200")
      .style('fill', 'SkyBlue')
      .style('stroke', '#777')
      .style('stroke-width', '1')
}


function _23(md){return(
md`## Lidando com dados

Em Visualização de Dados, nós mapeamos **dados** a **elementos visuais**.
Em D3, nós vinculamos **dados de entrada** a elementos no **DOM**.
Usamos o operador \`\`.data()\`\` (mais detalhes à frente).

D3 consegue lidar com diferentes tipos de dados:
* Qualquer array de números, strings ou objetos; 
* Arquivos JSON (e GeoJSON);
* Arquivos CSV;
* Arquivos Texto;
* Arquivos XML e 
* Arquivos HTML.`
)}

function _24(md){return(
md`## O Padrão enter-update-exit

É usado para definir a conexão entre dados e sua representação visual.

![enter-exit-update](https://emanueles.github.io/datavis-course/assets/images/observable/intro1_enter_exit_update.png)

Dados ainda não vinculados produzem a seleção enter (**selection.enter**).

Itens de dados vinculados a elementos existentes produzem a seleção update (**selection.data**).

Elementos ainda não vinculados produzem a seleção exit (**selection.exit**).`
)}

function _25(md){return(
md`## Vinculando um vetor a dados
Usamos o operador \`\`.data()\`\`.

Podemos calcular os parâmetros da visualização a partir dos dados.

No exemplo abaixo, as barras estão com altura fixa, mas vamos usar os próprios valores do vetor para calcular a altura da barra. Podemos usar algo como:
\`\`\`javascript
.attr('height', (d) => d*2) // Configura a altura da barra usando o próprio valor do dado
\`\`\` 

Também iremos ajustar a escala para posicionar as barras de forma correta e acrescentar labels com o valor de cada barra para ficar como a figura abaixo:
![first bar chart](https://emanueles.github.io/datavis-course/assets/images/observable/intro1_barras1.png)`
)}

function _barras1(d3,DOM)
{
  const width = 700
  const height = 200
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const svg = d3.select(DOM.svg(width, height))
  const arrayOfNumbers = [10, 15, 30, 50, 80, 65, 55, 30, 20, 10, 8]

  svg.selectAll('rect') // Seleciona todos os retângulos filhos de svg (nesse caso, uma seleção vazia)
    .data(arrayOfNumbers) // Vincula arrayOfNumbers com DOM elementos <rect/>, produzindo seleções .enter(),.exit()
    .enter()// Retorna a parte dos dados que é nova ("entering") e ainda não está vinculada aos elementos DOM
      .append('rect') // Para cada item de dado, adiciona um <rect /> ao svg selecionado
      .attr('x', (d, i) => i * 30 + 20) // Configura a posição x de acordo com o índice do vetor
      .attr('y', d => height - d * 2) // Configura a posição y de cada barra1
      .attr('width', 20) //Configura a largura de cada barra
      .attr('height', d => d * 2) // Configura a altura de cada barra
      .attr('fill', "DarkSlateGrey") // Configura a cor de preenchimento de cada barra

  svg.selectAll("text")
    .data(arrayOfNumbers)
    .enter()
      .append("text")
      .attr("x", (d, i) => i * 30 + 20 + 10)
      .attr("y", d => height - d * 2 - 5)
      .style("font-family", "Arial")
      .style("font-size", "14px")
      .style("text-anchor", "middle")
      .text(d => d)
 
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _27(md){return(
md`## Vinculando um vetor de objetos

Quando temos um vetor de objetos, podemos acessar os atributos de cada item de dado diretamente:
\`\`\`javascript
.attr('height', (d) => d.height*2) // Configura a altura da barra usando o próprio valor do dado
\`\`\`
Iremos modificar o exemplo abaixo para alterar a altura e a cor das barras de acordo com a figura abaixo:

![second bar chart](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/images/observable/intro1_barras2.png)
`
)}

function _barras2(d3,DOM)
{
  const width = 700
  const height = 200
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const svg = d3.select(DOM.svg(width, height))
  const dataset = [ 
        {height: 10, color: 23},{height: 15, color: 33},
        {height: 30, color: 40},{height: 50, color: 60},
        {height: 80, color: 22},{height: 65, color: 10},
        {height: 55, color: 5},{height: 30, color: 30},
        {height: 20, color: 60},{height: 10, color: 90},
        {height: 8, color: 10}]
  
  let colorScale = d3.scaleLinear()
        .domain([0, 100])
        .range(["Khaki", "Gold"]); // Escala de cor

  
  svg.selectAll('rect') // Seleciona todos os retângulos filhos de svg (nesse caso, uma seleção vazia)
    .data(dataset) // Vincula arrayOfNumbers com DOM elementos <rect/>, produzindo seleções .enter(),.exit()
    .enter()// Retorna a parte dos dados que é nova ("entering") e ainda não está vinculada aos elementos DOM
      .append('rect') // Para cada item de dado, adiciona um <rect /> ao svg selecionado
      .attr('x', (d, i) => i * 30 + 20) // Configura a posição x de acordo com o índice do vetor
      .attr('y', d => height - d.height * 2) // Configura a posição y de cada barra
      .attr('width', 20) //Configura a largura de cada barra
      .attr('height', d => d.height * 2) // Configura a altura de cada barra
      .attr('fill', d => colorScale(d.color)) // Configura a cor de preenchimento de cada barra

  svg.selectAll("text")
    .data(dataset)
    .enter()
      .append("text")
      .attr("x", (d, i) => i * 30 + 20 + 10)
      .attr("y", d => height - 5 - d.height * 2)
      .style("font-family", "sans-serif")
      .style("font-size", "14px")
      .style("text-anchor", "middle")
      .text(d => d.height)
  
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _29(md){return(
md`## Funções úteis para lidar com vetores de dados

A seguir estão funções para: 
* Ordenar vetores
* Calcular o mínimo e o máximo
* Calcular média, mediana, somatório, etc.`
)}

function _30(html){return(
html`
<div class="array-utils">
<div>const array = [3, 2, 11, 7, 6, 4, 10, 8, 15];</div>
<div>d3.min => <span id="min"></span></div>
<div>d3.max => <span id="max"></span></div>
<div>d3.extent => <span id="extent"></span></div>
<div>d3.sum => <span id="sum"></span></div>
<div>d3.median => <span id="median"></span></div>
<div>d3.mean => <span id="mean"></span></div>
<div>array.sort(d3.ascending) => <span id="asc"></span></div>
<div>array.sort(d3.descending) => <span id="desc"></span></div>
<div>d3.quantile(array.sort(d3.ascending), 0.25) => <span id="quantile"></span></div>
</div>`
)}

function _31(d3)
{
  const array = [3, 2, 11, 7, 6, 4, 10, 8, 15];
  const div = d3.select(".array-utils")
  div.select("#min").text(d3.min(array))
  div.select("#max").text(d3.max(array));
  div.select("#extent").text(d3.extent(array));
  div.select("#sum").text(d3.sum(array));
  div.select("#median").text(d3.median(array));
  div.select("#mean").text(d3.mean(array));
  div.select("#asc").text(array.sort(d3.ascending));
  div.select("#desc").text(array.sort(d3.descending));
  div.select("#quantile").text(
    d3.quantile(array.sort(d3.ascending), 0.25)
  );
}


function _32(md){return(
md`## Carregando dados de arquivo

O d3 possui diversas funções para carregar arquivos. Por exemplo, para ler um arquivo JSON, usamos d3.json:`
)}

function _dataset(d3){return(
d3.json('https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/files/observable/data.json')
)}

function _34(md){return(
md`Para mais informações sobre carregar arquivos no Observable, veja [Introduction to data](https://observablehq.com/@observablehq/introduction-to-data).

Abaixo vamos visualizar esse dataset com um gráfico de barras horizontal semelhante à figura mostrada abaixo.

![third bar chart](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/images/observable/intro_barras3.png)

`
)}

function _barras3(d3,DOM,dataset)
{
  const width = 600
  const height = 400
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const svg = d3.select(DOM.svg(width, height))
  svg.selectAll('rect') // Seleciona todos os retângulos filhos de svg (nesse caso, uma seleção vazia)
    .data(dataset) // Vincula arrayOfNumbers com DOM elementos <rect/>, produzindo seleções .enter(),.exit()
    .enter()// Retorna a parte dos dados que é nova ("entering") e ainda não está vinculada aos elementos DOM
      .append('rect') // Para cada item de dado, adiciona um <rect /> ao svg selecionado
      .attr('x', 10) // Configura a posição x de acordo com o índice do vetor
      .attr('y', (d, i) => i * 30 + 20) // Configura a posição y de cada barra de acordo com o índice do vetor
      .attr('height', 20) //Configura a largura de cada barra
      .attr('width', d => d.despesa * 2) // Configura a altura de cada barra
      .attr('fill', "DarkCyan") // Configura a cor de preenchimento de cada barra

  svg.selectAll("text")
    .data(dataset)
    .enter()
      .append("text")
      .attr("x", d => d.despesa * 2 + 15)
      .attr("y", (d, i) => i * 30 + 20 + 15)
      .style("font-family", "sans-serif")
      .style("font-size", "14px")
      .text(d => `${d.despesa}: ${d.categoria}`)
 
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _36(md){return(
md`## Ordenando dados

Criamos uma função para comparar valores:`
)}

function _comparePorDespesa(){return(
(a, b) => a.despesa - b.despesa
)}

function _sorteddata(d3){return(
d3.json('https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/files/observable/data.json')
)}

function _39(md){return(
md`Depois usamos essa função para ordenar os dados, dentro da célula que gera a visualização como mostrado na figura aboixo:

![fourth bar chart](https://raw.githubusercontent.com/emanueles/datavis-course/master/assets/images/observable/intro_barras4.png)
`
)}

function _barras4(d3,DOM,sorteddata,comparePorDespesa)
{
  const width = 600
  const height = 400
  // DOM.svg() é um método específico do Observable para criar um elemento DOM SVG. 
  const svg = d3.select(DOM.svg(width, height))
  
  sorteddata.sort(comparePorDespesa) //aqui os dados são ordenados
  svg.selectAll('rect') // Seleciona todos os retângulos filhos de svg (nesse caso, uma seleção vazia)
    .data(sorteddata) // Vincula arrayOfNumbers com DOM elementos <rect/>, produzindo seleções .enter(),.exit()
    .enter()// Retorna a parte dos dados que é nova ("entering") e ainda não está vinculada aos elementos DOM
      .append('rect') // Para cada item de dado, adiciona um <rect /> ao svg selecionado
      .attr('x', 10) // Configura a posição x de acordo com o índice do vetor
      .attr('y', (d, i) => i * 30 + 20) // Configura a posição y de cada barra de acordo com o índice do vetor
      .attr('height', 20) //Configura a largura de cada barra
      .attr('width', d => d.despesa * 2) // Configura a altura de cada barra
      .attr('fill', "DarkCyan") // Configura a cor de preenchimento de cada barra

  svg.selectAll("text")
    .data(sorteddata)
    .enter()
      .append("text")
      .attr("x", d => 10 + d.despesa * 2 + 5)
      .attr("y", (d, i) => i * 30 + 20 + 15)
      .style("font-family", "sans-serif")
      .style("font-size", "14px")
      .text(d => `${d.despesa}: ${d.categoria}`)
 
  // Once we append the vis elments to it, we return the DOM element for Observable to display above.
  return svg.node()
}


function _41(md){return(
md` Ao concluir os exercícios, publique o seu fork, usando o botão **Publish** no topo direito da página.`
)}

function _42(md){return(
md`## Para aprender mais sobre Observable

Para aprender mais sobre Observable, recomendo os seguintes notebooks:
* [Manual do Usuário](https://observablehq.com/@observablehq/user-manual): *A seção **Start here** é obrigatória. Ela contém todos os notebooks relevantes para usar notebooks Observable.*
* Uma série de [tutoriais em 3 partes](https://observablehq.com/@observablehq/tutorial)
* Toda a [coleção introdutória de tutoriais](https://observablehq.com/collection/@observablehq/introduction).`
)}

function _43(md){return(
md `### Importar a biblioteca D3 como um único objeto Javascript 
Isso é possível no final de um notebook Observable, mas não em Javascript puro.`
)}

function _d3(require){return(
require('d3')
)}

function _45(md){return(
md`Outras utilidades para o tutorial:`
)}

function _key(html){return(
c =>
  html`<span style='border-radius:5px;background:#ddf;display:inline-block;padding:0 4px;'>${c}</span>`
)}

function _greypin(html){return(
html`<svg style='vertical-align:middle' viewBox="0 0 16 16" fill='#999999' stroke=none viewBox="0 0 16 16" width=16 height=16>
    <path d="M8 1h3v1l-1 1v4l2 .875V9H9v5.125L8 15l-1-.875V9H4V7.875L6 7V3L5 2V1z" />
  </svg>`
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["md"], _2);
  main.variable(observer()).define(["md","key"], _3);
  main.variable(observer()).define(_4);
  main.variable(observer()).define(["md","greypin"], _5);
  main.variable(observer("comida")).define("comida", _comida);
  main.variable(observer()).define(["md","comida"], _7);
  main.variable(observer()).define(["md","key"], _8);
  main.variable(observer()).define(["html"], _9);
  main.variable(observer()).define(["md"], _10);
  main.variable(observer()).define(["md"], _11);
  main.variable(observer()).define(["md"], _12);
  main.variable(observer()).define(["html"], _13);
  main.variable(observer()).define(["d3"], _14);
  main.variable(observer()).define(["md"], _15);
  main.variable(observer()).define(["md"], _16);
  main.variable(observer()).define(["md"], _17);
  main.variable(observer()).define(["html"], _18);
  main.variable(observer()).define(["d3"], _19);
  main.variable(observer()).define(["md"], _20);
  main.variable(observer()).define(["html"], _21);
  main.variable(observer()).define(["d3"], _22);
  main.variable(observer()).define(["md"], _23);
  main.variable(observer()).define(["md"], _24);
  main.variable(observer()).define(["md"], _25);
  main.variable(observer("barras1")).define("barras1", ["d3","DOM"], _barras1);
  main.variable(observer()).define(["md"], _27);
  main.variable(observer("barras2")).define("barras2", ["d3","DOM"], _barras2);
  main.variable(observer()).define(["md"], _29);
  main.variable(observer()).define(["html"], _30);
  main.variable(observer()).define(["d3"], _31);
  main.variable(observer()).define(["md"], _32);
  main.variable(observer("dataset")).define("dataset", ["d3"], _dataset);
  main.variable(observer()).define(["md"], _34);
  main.variable(observer("barras3")).define("barras3", ["d3","DOM","dataset"], _barras3);
  main.variable(observer()).define(["md"], _36);
  main.variable(observer("comparePorDespesa")).define("comparePorDespesa", _comparePorDespesa);
  main.variable(observer("sorteddata")).define("sorteddata", ["d3"], _sorteddata);
  main.variable(observer()).define(["md"], _39);
  main.variable(observer("barras4")).define("barras4", ["d3","DOM","sorteddata","comparePorDespesa"], _barras4);
  main.variable(observer()).define(["md"], _41);
  main.variable(observer()).define(["md"], _42);
  main.variable(observer()).define(["md"], _43);
  main.variable(observer("d3")).define("d3", ["require"], _d3);
  main.variable(observer()).define(["md"], _45);
  main.variable(observer("key")).define("key", ["html"], _key);
  main.variable(observer("greypin")).define("greypin", ["html"], _greypin);
  return main;
}
