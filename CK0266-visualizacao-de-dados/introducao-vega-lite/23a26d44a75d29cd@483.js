import define1 from "./26670360aa6f343b@226.js";

function _1(md){return(
md`# Introdução a Vega-lite e Vega-lite-api
## Criando visualizações interativas rapidamente`
)}

async function _2(FileAttachment,htl){return(
htl.html`<!-- Click the paperclip on the right sidebar to replace the image -->
<figure style="max-width: 100%;">
  <img src=${await FileAttachment("vega-lite-header.png").url()}>
  <figcaption><span> <a href="https://vega.github.io/vega-lite/examples/">Galeria de Exemplos</a> <a href="https://vega.github.io/vega-lite/">Vega-Lite</a></span></figcaption>
</figure>`
)}

function _3(md){return(
md`---
## O que é Vega-Lite?`
)}

function _4(md){return(
md`[**Vega-Lite**](https://vega.github.io/vega-lite) é uma linguagem declarativa, criada pelo grupo [Interactive Data Lab na Universidade de Washington](https://idl.cs.washington.edu/), para a criação de visualizações de dados interativas. Vega-Lite oferece uma gramática de visualização poderosa e concisa para rapidamente construir uma grande variedade de gráficos.`
)}

function _5(md){return(
md`O fato de ser *declarativa* significa que você pode fornecer uma especificação em alto nível daquilo (*o quê*) que você gostaria que a visualização incluísse, em termos de *dados, marcas gráficas e canais de codificação*, em vez de dizer *como* a visualização deve ser implementada em termos de laços-for, comandos de desenho em baixo nível, etc. `
)}

function _6(md){return(
md`Na prática, ao usar vega-lite, nós podemos definir uma visualização, usando um arquivo [JavaScript Object Notation (JSON)](https://en.wikipedia.org/wiki/JSON). Abaixo está um [exemplo de um simples gráfico de barras usando vega-lite](https://vega.github.io/vega-lite/examples/bar.html):`
)}

async function _7(FileAttachment,htl){return(
htl.html`<!-- Click the paperclip on the right sidebar to replace the image -->
<figure style="max-width: 100%;">
  <img src=${await FileAttachment("vega-lite-bar-chart.png").url()}>
  <figcaption><span> <a href="https://vega.github.io/vega-lite/examples/bar.html">Simple Bar Chart</a> </span></figcaption>
</figure>`
)}

function _8(md){return(
md`No entanto, à medida que os gráficos tornam-se mais complexos, descrevê-los nessa linguagem declarativa fica cada vez menos intuitivo,  como pode ser visto nesse [exemplo](https://vega.github.io/vega-lite/examples/interactive_global_development.html). Assim, para criar as visualizações de modo mais conveniente e programático, nós iremos utilizar a [API Vega-Lite](https://observablehq.com/@vega/vega-lite-api-v5), um conjunto de métodos em JavaScript que produzem especificações JSON Vega-Lite como saída.`
)}

function _9(md){return(
md`Criar visualizações com a API Vega-Lite é bem mais rápido do que criar visualizações do zero em D3. `
)}

function _10(md){return(
md`Este notebook pressupõe que você já saiba o básico de JavaScript e Notebooks Observable. Se você precisar de uma introdução rápida a esses dois conceitos, veja o notebook *[A Minimal Introduction to JavaScript and Observable](https://observablehq.com/@uwdata/a-minimal-introduction-to-javascript-and-observable)* (em Inglês).`
)}

function _11(md){return(
md`## Imports
Para começar, iremos importar a api vega-lite, versão 5:`
)}

function _13(md){return(
md`... o repositório de conjuntos de dados da biblioteca vega:`
)}

function _data(require){return(
require('vega-datasets')
)}

function _15(md){return(
md`## Dados`
)}

function _16(md){return(
md`Os dados a serem carregados em Vega-lite devem estar formatados como uma tabela de dados (ou um data frame) consistindo em um conjunto de colunas nomeadas. As colunas podem ser referenciadas como campos (*fields*). Uma vez carregada, a representação padrão da tabela é um vetor de objetos JavaScript.

Vejamos como carregar o dataset \`cars\` do repositório que carregamos acima:`
)}

function _cars(data){return(
data['cars.json']()
)}

function _18(md){return(
md`Vamos usar a célula especial do Observable (\`Data table\`) para exibir os dados da tabela bem formatados e interativos, com histogramas dos valores das colunas.`
)}

function _19(__query,cars,invalidation){return(
__query(cars,{from:{table:"cars"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:null}},invalidation,"cars")
)}

function _20(md){return(
md`Todos os conjuntos de dados do repositório vega também estão acessíveis por uma URL:`
)}

function _21(data){return(
data['cars.json'].url
)}

function _22(data,md){return(
md`Você pode abrir a [URL acima](${data['cars.json'].url}) numa janela separada para examinar os dados brutos.`
)}

function _23(md){return(
md`Também podemos carregar os dados de forma convencional, por exemplo, usando o próprio d3 e exibi-los usando uma \`Data table\`:`
)}

function _nycweather(d3){return(
d3.json("https://gist.githubusercontent.com/emanueles/c628da6486ccb5059c091d9a13285cff/raw/8136ef5bc833ce6266e22ab0a8487c71bdb67bc2/nyc_weather_data.json")
)}

function _25(__query,nycweather,invalidation){return(
__query(nycweather,{from:{table:"nycweather"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:null}},invalidation,"nycweather")
)}

function _26(md){return(
md`## Dados Climáticos`
)}

function _27(md){return(
md`A visualização de dados em Vega-Lite supõe que os data frames sejam ***[tidy](https://vita.had.co.nz/papers/tidy-data.pdf)***. Para demonstrar os conceitos de Vega-Lite, iremos criar um data frame simples (\`df\`) que contém a precipitação média (\`precip\`) para uma dada cidade (\`city\`) e mês (\`month\`) - escrito no formato JSON:`
)}

function _df(){return(
[
  {"city": "Seattle",  "month": "Apr", "precip": 2.68},
  {"city": "Seattle",  "month": "Aug", "precip": 0.87},
  {"city": "Seattle",  "month": "Dec", "precip": 5.31},
  {"city": "New York", "month": "Apr", "precip": 3.94},
  {"city": "New York", "month": "Aug", "precip": 4.13},
  {"city": "New York", "month": "Dec", "precip": 3.58},
  {"city": "Chicago",  "month": "Apr", "precip": 3.62},
  {"city": "Chicago",  "month": "Aug", "precip": 3.98},
  {"city": "Chicago",  "month": "Dec", "precip": 2.56},
]
)}

function _29(md){return(
md`Ou, num formato mais amigável:`
)}

function _30(__query,df,invalidation){return(
__query(df,{from:{table:"df"},sort:[],slice:{to:null,from:null},filter:[],select:{columns:null}},invalidation,"df")
)}

function _31(md){return(
md`## Marcas e Codificações`
)}

function _32(md){return(
md`Usando os dados climáticos definidos acima, nós podemos especificar como os dados serão visualizados em Vega-Lite. Primeiramente nós indicamos que tipo de marca gráfica (forma geométrica) nós queremos usar para representar os dados. Nós podemos criar uma nova instância de uma marca Vega-Lite usando os métodos \`vl.mark*\`.

Por exemplo, podemos criar uma marca **ponto** usando \`vl.markPoint()\` e então passar os dados para o método \`data()\` (semelhante ao binding que fizemos em seleções d3). Por fim, nós chamamos o método \`render()\`para desenhar o gráfico:`
)}

function _33(vl,df){return(
vl.markPoint()
  .data(df)
  .render()
)}

function _34(md){return(
md`No exemplo acima, a renderização consiste em um ponto para cada linha do dataset, todos desenhados um em cima do outro, pois não especificamos ainda as posições para cada ponto.

Para separar os pontos visualmente, nós podemos mapear vários canais de codificação aos campos (\`field\`) no conjunto de dados. Por exemplo, nós podemos codificar o campo \`city\` usando o canal de posição \`y\`, que representa a posição dos pontos no eixo-y. Para fazer isso, usa-se o método \`encode()\`, passando para ele as definições de canais específicos.`
)}

function _35(vl,df){return(
vl.markPoint()
  .data(df)
  .encode(vl.y().field('city').type('nominal'))
  .render()
)}

function _36(md){return(
md`O método \`encode()\` constrói um mapeamento entre canais de codificação (tais como, \`x\`, \`y\`, \`color\`, \`shape\`, \`size\`, etc.) e campos no conjunto de dados, acessados pelo nome do campo. Fornecemos um canal usando os métodos \`vl.<nome_do_canal>\`, juntamente com um tipo de dados para guiar o design da visualização. No exemplo acima, codificamos o campo \`city\` como um tipo \`nominal\`, indicando que os valores são categóricos, sem ordem definida.

Para simplificar, podemos usar o método abreviado \`fieldN()\` para especificar um nome de campo e o tipo como \`nominal\` ao mesmo tempo:`
)}

function _37(vl,df){return(
vl.markPoint()
  .data(df)
  .encode(vl.y().fieldN('city'))
  .render()
)}

function _38(md){return(
md`Apesar de termos agora separado os dados por um atributo, ainda temos múltiplos pontos sobrepondo-se dentro de cada categoria. Vamos separar ainda mais esses pontos adicionando um canal \`x\` mapeado ao campo quantitativo \`precip\`:`
)}

function _39(vl,df){return(
vl.markPoint()
  .data(df)
  .encode(
    vl.x().fieldQ('precip'),
    vl.y().fieldN('city')
  )
  .render()
)}

function _40(md){return(
md`> *Observe que Seattle exibe tanto o mês que menos chove quanto o mês que mais chove!*`
)}

function _41(md){return(
md`Acima usamos o método \`fieldQ\` para instruir que Vega-Lite trate \`precip\` como um campo quantitativo (isto é, um número real). Percebe-se que linhas de grade e títulos dos eixos são também adicionados automaticamente.`
)}

function _42(md){return(
md`Até agora, vimos tipos nominais (\`fieldN\`) e quantitativos (\`fieldQ\`). O conjunto completo de métodos de tipos de campos é o seguinte:
- fieldN() indica tipo *nominal* (dados categóricos, sem ordem definida)
- fieldO() indica tipo *ordinal* (dados ordenados)
- fieldQ() indica tipo *quantitativo* (magnitudes numéricas)
- fieldT() indica tipo *temporal* (correspondendo a valores de data - [Date](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Date))`
)}

function _43(md){return(
md`O que você acha que vai acontecer ao nosso gráfico se tratarmos \`precip\` como uma variável nominal ou ordinal em vez de uma variável quantitativa? Experimente na célula abaixo para descobrir (copie a célula de código acima para começar e depois faça a modificação).`
)}

function _44(vl,df){return(
vl.markPoint()
  .data(df)
  .encode(
    vl.x().fieldN('precip'),
    vl.y().fieldN('city')
  )
  .render()
)}

function _45(md){return(
md`## Transformação de dados: Agregação`
)}

function _46(md){return(
md`Para permitir uma maior flexibilidade no modo como os dados são visualizados, Vega-Lite possui uma sintaxe padrão para a agregação de dados. Por exemplo, podemos calcular a média de todos os valores especificando uma função de agregação juntamente como o nome do campo:`
)}

function _47(vl,df){return(
vl.markPoint()
  .data(df)
  .encode(
    vl.x().average('precip'),
    vl.y().fieldN('city')
  )
  .render()
)}

function _48(md){return(
md`Agora dentro de cada eixo-x de uma categoria, vemos um ponto refletindo a média dos valores dentro de cada categoria. Como estamos calculando uma média, a api Vega-Lite automaticamente supõe que o resultado é uma variável quantitativa. No entanto, você pode adicionar uma chamada a um método \`type()\` para especificar um tipo diferente, se desejar.`
)}

function _49(md){return(
md`> *Seattle realmente possui a menor média de precipitação dessas 3 cidades? (Sim!) Mesmo assim, como este gráfico pode estar enganando as pessoas? Que meses estão incluídos nos dados? O que está sendo considerado como precipitação?*`
)}

function _50(md){return(
md`Vega-Lite suporta uma variedade de funções de agregação, incluindo \`count\` (contagem), \`min\` (mínimo), \`max\` (máximo), \`average\` (média), \`median\` (mediana), e \`stdev\` (desvio padrão). `
)}

function _51(md){return(
md`## Alterando o Tipo de Marca`
)}

function _52(md){return(
md`Suponha que queiramos representar nossos valores agregados usando barras retangulares no lugar de pontos circulares. Fazemos isso substituindo \`vl.markPoint\` por \`vl.markBar\`:`
)}

function _53(vl,df){return(
vl.markBar()
  .data(df)
  .encode(
    vl.x().average('precip'),
    vl.y().fieldN('city')
  )
  .render()
)}

function _54(md){return(
md`Como o campo nominal \`city\` está mapeado ao eixo-y, o resultado é um gráfico de barras horizontais. Para obter um gráfico de barras verticais, podemos trocar as atribuições dos eixos x e y:`
)}

function _55(vl,df){return(
vl.markBar()
  .data(df)
  .encode(
    vl.y().average('precip'),
    vl.x().fieldN('city')
  )
  .render()
)}

function _56(md){return(
md`## Customizando uma Visualização`
)}

function _57(md){return(
md`Por padrão, Vega-Lite toma algumas decisões sobre as propriedades da visualização, mas que podem ser modificadas usando métodos para customizar a aparência da visualização. Por exemplo, nós podemos modificar as propriedades de escala usando a propriedade \`scale\`, configurar títulos usando a propriedade \`title\`, e podemos especificar a cor da marca passando um objeto para o método \`mark*\` com uma propriedade \`color\` contendo uma [string de cor CSS](https://developer.mozilla.org/en-US/docs/Web/CSS/color_value) válida: `
)}

function _58(vl,df){return(
vl.markPoint({color: 'firebrick'})
  .data(df)
  .encode(
    vl.x().fieldQ('precip').scale({type: 'log'}).title('Log-Scaled Precipitation'),
    vl.y().fieldN('city').title('City')
  )
  .render()
)}

function _59(md){return(
md`## Visões Múltiplas`
)}

function _60(md){return(
md`Como vimos acima, uma visualização básica Vega-Lite representa um gráfico com um único tipo de marca. Que tal diagramas mais complicados, envolvendo múltiplos gráficos ou camadas? Usando um conjunto de operadores de composição de visões, Vega-Lite pode aceitar múltiplas definições e combiná-las para criar visões mais complexas.

Como ponto de partida, vamos plotar o conjunto de dados de carros (\`cars\`), que carregamos no início deste notebook, mostrando a autonomia média (\`Miles_per_Gallon\`) por ano de fabricação: `
)}

function _61(vl,cars){return(
vl.markLine()
  .data(cars)
  .encode(
    vl.x().fieldT('Year'),
    vl.y().average('Miles_per_Gallon')
  )
  .render()
)}

function _62(md){return(
md`Para aumentar esse gráfico, nós podemos adicionar marcas círculos para cada ponto de dado com a média.

> *Observação: A marca \`circle\` é uma abreviação para marcas pontos com círculos preenchidos.*

Podemos começar definindo cada gráfico separadamente: primeiro um gráfico de linhas, depois um gráfico de pontos. Depois usamos o operador \`layer\` para combinar os dois em um único gráfico sobreposto.`
)}

function _63(vl,cars)
{
  const line = vl.markLine().data(cars).encode(
    vl.x().fieldT('Year'),
    vl.y().average('Miles_per_Gallon')
  );

  const point = vl.markCircle().data(cars).encode(
    vl.x().fieldT('Year'),
    vl.y().average('Miles_per_Gallon')
  );
  
  return vl.layer(line, point).render();
}


function _64(md){return(
md`Nós também podemos criar esse gráfico reutilizando uma definição prévia de gráfico. Então, em vez de reescrever o gráfico do zero, podemos já começar com o gráfico de linhas e só alterar o tipo de marca, usando o método \`mark\`:`
)}

function _65(vl,cars)
{
  const mpg = vl.markLine().data(cars).encode(
    vl.x().fieldT('Year'),
    vl.y().average('Miles_per_Gallon')
  );

  return vl.layer(mpg, mpg.markCircle()).render();
}


function _66(md){return(
md`> Como a necessidade de se adicionar pontos em gráficos de linha é bastante comum, a marca \`line\` também inclui um atalho para gerar uma camada de pontos. Experimente passando \`{point:true}\` para o método \`markLine\`!`
)}

function _67(vl,cars){return(
vl.markLine({point: true})
  .data(cars)
  .encode(
    vl.x().fieldT('Year'),
    vl.y().average('Miles_per_Gallon')
  )
  .render()
)}

function _68(md){return(
md`Agora, se quisermos ver esse gráfico lado-a-lado com outros gráficos, como por exemplo a potência média (\`horsepower\`) ao longo do tempo?

Nós podemos usar operadores de concatenação para posicionar múltiplos gráficos um ao lado do outro, tanto verticalmente quanto horizontalmente. Abaixo utilizaremos o método \`hconcat\` para realizar uma concatenação horizontal de dois gráficos:`
)}

function _69(vl,cars)
{
  const mpg = vl.markLine().data(cars).encode(
    vl.x().fieldT('Year'),
    vl.y().average('Miles_per_Gallon')
  );
  
  const hp = mpg.encode(vl.y().average('Horsepower'));

  return vl.hconcat(
    vl.layer(mpg, mpg.markCircle()),
    vl.layer(hp, hp.markCircle())
  ).render();
}


function _70(md){return(
md`> *Podemos ver nos gráficos desse conjunto de dados, que a autonomia dos modelos aumentou ao longo dos anos 70 e início dos anos 80, mas em compensação, a potência média diminuiu.*`
)}

function _71(md){return(
md`## Interatividade`
)}

function _72(md){return(
md`Além da composição de visões, outra característica muito interessante de Vega-Lite é o suporte a interatividade. Exploraremos a interatividade com mais profundidade em notebooks futuros, mas só para termos um gostinho, vejamos como colocar tooltips em um scatterplot, usando o canal \`tooltip\`:`
)}

function _scatter(vl,cars){return(
vl.markPoint().data(cars).encode(
  vl.x().fieldQ('Horsepower'),
  vl.y().fieldQ('Miles_per_Gallon'),
  vl.color().fieldN('Origin'),
  vl.tooltip(['Name', 'Origin']) // show the Name and Origin fields in a tooltip
).render()
)}

function _74(md){return(
md`Para interações mais complexas, tais como visões coordenadas e cross-filtering, Vega-Lite fornece uma abstração seleção para definir seleções interativas e então vinculá-las a componentes de um gráfico. Isso é coberto em um outro notebook.

Abaixo está um exemplo mais complexo. O histograma superior mostra a contagem de carros por ano e usa uma seleção interativa para modificar a opacidade dos pontos no scatterplot abaixo, que exibe autonomia (\`mpg\`) por potência (\`horsepower\`).

> Arraste um intervalo no gráfico superior e veja como isso afeta os pontos no scatterplot. Conforme você examina o código, **não se preocupe se ainda não consegue entender o que ele faz!** Esse é um exemplo de inspiração. Existem vários outros notebooks (veja a lista ao final deste notebook) que abordam todos os detalhes para a criação de uma visualização como esta.`
)}

function _75(vl,cars)
{
  // create an interval selection over an x-axis encoding
  const brush = vl.selectInterval().encodings('x');
  
  // determine opacity based on brush
  const opacity = vl.opacity().if(brush, vl.value(0.9)).value(0.1);

  // an overview histogram of cars per year
  // add the interval brush to select cars over time
  const overview = vl.markBar()
    .encode(
      vl.x().fieldO('Year').timeUnit('year')  // extract year unit, treat as ordinal
        .axis({title: null, labelAngle: 0}),  // no title, no label angle
      vl.y().count().title(null),             // counts, no axis title
      opacity  // modulate bar opacity based on the brush selection
    )
    .params(brush) // add interval brush selection to the chart
    .width(400)    // use the full default chart width
    .height(50);   // set chart height to 50 pixels
  
  // a detail scatterplot of horsepower vs. mileage
  const detail = vl.markPoint()
    .encode(
      vl.x().fieldQ('Horsepower'),
      vl.y().fieldQ('Miles_per_Gallon'),
      opacity  // modulate point opacity based on the brush selection
    );

  // vertically concatenate (vconcat) charts
  return vl.data(cars).vconcat(overview, detail).render();
}


function _76(md){return(
md`## Opcional: Examinando a saída JSON`
)}

function _77(md){return(
md`A API Vega-Lite converte as especificações de gráficos para um formato compatível [JSON](https://en.wikipedia.org/wiki/JSON) conforme o esquema Vega-Lite. Usando o método \`toObject()\`, podemos inspecionar a especificação que é enviada para a Vega-Lite:`
)}

function _78(vl,html)
{
  const plot = vl.markCircle().encode(
    vl.x().average('precip'),
    vl.y().fieldN('city')
  );
  
  return html`<pre>${JSON.stringify(plot.toObject(), 0, 2)}</pre>`; // format JSON data
}


function _79(md){return(
md`Observe que \`vl.x().average('precip')\` foi expandida para uma estrutura com um nome de campo (\`field\`), um tipo para os dados (escolhido automaticamente para corresponder a médias), e inclui um campo agregado (\`aggregate\`).

De modo semelhante, o comando \`vl.y().fieldN('city')\` também foi expandido.

Um adendo: a API Vega-Lite além de fornecer métodos convenientes para especificar as visualizações, também pode aceitar objetos JavaScript diretamente: Por exemplo, abaixo está o mesmo gráfico acima, mas com as codificações fornecidas diretamente no formato JSON Vega-Lite:`
)}

function _80(vl,html)
{
  const plot = vl.markCircle().encode({
    x: {field: 'precip', type: 'quantitative', aggregate: 'average'},
    y: {field: 'city', type: 'nominal'}
  });
  
  return html`<pre>${JSON.stringify(plot.toObject(), 0, 2)}</pre>`; // format JSON data
}


function _81(md){return(
md`## Exportando e Publicando uma Visualização`
)}

function _82(md){return(
md`Depois que você visualizar os seus dados, talvez você queira publicar a sua visualização em algum lugar na web. Para salvar uma imagem exportada, você pode simplesmente clicar uma visualização com o botão direito e selecionar "Save Image As..." a partir do menu de contexto, supondo que o modo de renderização [canvas](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API) é utilizado. `
)}

function _83(md){return(
md`> *Experimente essa funcionalidade, rolando a barra de rolagem para cima e salve uma das visualizações anteriores!*`
)}

function _84(md){return(
md`A maneira mais fácil para incluir uma Visualização Vega-Lite em uma de suas GitHub Pages, é seguindo as instruções que estão no notebook:

- [Exemplo de exportar uma célula Vega-Lite](https://observablehq.com/@vis-ufc/exemplo-de-exportar-uma-celula-vega-lite)

Outra maneira de incluir uma visualização Vega-Lite, principalmente quando você já tem uma string JSON Vega-Lite da sua visualização, é utilizando o [pacote JavaScript vega-embed](https://github.com/vega/vega-embed). 

Para isso, use a string JSON Vega-Lite exportada e a incorpore numa página web que importa vega-embed. Abaixo está um template básico, em que a especificação JSON para o seu gráfico produzida pela chamada \`chart.toObject()\` deve ser armazenada na variável JavaScript \`spec\`:

\`\`\`html
<!DOCTYPE html>
<html>
  <head>
    <script src="https://cdn.jsdelivr.net/npm/vega@5"></script>
    <script src="https://cdn.jsdelivr.net/npm/vega-lite@5"></script>
    <script src="https://cdn.jsdelivr.net/npm/vega-embed@6"></script>
  </head>
  <body>
    <div id="vis"></div>
    <script type="text/javascript">
    const spec = {};  /* JSON output for your chart's specification */
    const opt = {renderer: "canvas", actions: false};  /* Options for the embedding */
    vegaEmbed("#vis", spec, opt);
    </script>
  </body>
</html>
\`\`\`

Para mais informações sobre como embutir Vega-Lite em outras páginas, veja a [documentação vega-embed](https://github.com/vega/vega-embed).`
)}

function _85(md){return(
md`## Aprofunde os seus conhecimentos

Continue o seu aprendizado usando Vega-Lite e a API Vega-Lite, seguindo os seguintes notebooks (todos em Inglês):
- [Data Types, Graphical Marks, and Visual Encoding Channels](https://observablehq.com/@uwdata/data-types-graphical-marks-and-visual-encoding-channels)
- [Data Transformation](https://observablehq.com/@uwdata/data-transformation)
- [Scales, Axes, and Legends](https://observablehq.com/@uwdata/scales-axes-and-legends)
- [Multi-View Composition](https://observablehq.com/@uwdata/multi-view-composition)
- [Interaction](https://observablehq.com/@uwdata/interaction)
- [Cartographic Visualization](https://observablehq.com/@uwdata/cartographic-visualization)`
)}

function _86(md){return(
md`## Créditos

Esse notebook é basicamente uma tradução do notebook [Introduction to Vega-lite](https://observablehq.com/@uwdata/introduction-to-vega-lite) com algumas alterações para deixar o conteúdo mais adequado ao curso de Visualização de Dados da Universidade Federal do Ceará.`
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  function toString() { return this.url; }
  const fileAttachments = new Map([
    ["vega-lite-header.png", {url: new URL("./files/4834997d2b762b320df8aa744137fc34481c189dcbaf7ffd8b3698ec5ac00e0cdbfd1a3c4472dcfd867ec9f835f2353380b0977ed3245bc18562abc34a61c00c.png", import.meta.url), mimeType: "image/png", toString}],
    ["vega-lite-bar-chart.png", {url: new URL("./files/7a8d2c8a62fc5b800c55fda3aebceedd8493e076c6b3f656ff714d1cf96a62af8e7da0c728b79e21a1026f5c9499a9177b71ea759416a23dbd677cca88dc5236.png", import.meta.url), mimeType: "image/png", toString}]
  ]);
  main.builtin("FileAttachment", runtime.fileAttachments(name => fileAttachments.get(name)));
  main.variable(observer()).define(["md"], _1);
  main.variable(observer()).define(["FileAttachment","htl"], _2);
  main.variable(observer()).define(["md"], _3);
  main.variable(observer()).define(["md"], _4);
  main.variable(observer()).define(["md"], _5);
  main.variable(observer()).define(["md"], _6);
  main.variable(observer()).define(["FileAttachment","htl"], _7);
  main.variable(observer()).define(["md"], _8);
  main.variable(observer()).define(["md"], _9);
  main.variable(observer()).define(["md"], _10);
  main.variable(observer()).define(["md"], _11);
  const child1 = runtime.module(define1);
  main.import("vl", child1);
  main.variable(observer()).define(["md"], _13);
  main.variable(observer("data")).define("data", ["require"], _data);
  main.variable(observer()).define(["md"], _15);
  main.variable(observer()).define(["md"], _16);
  main.variable(observer("cars")).define("cars", ["data"], _cars);
  main.variable(observer()).define(["md"], _18);
  main.variable(observer()).define(["__query","cars","invalidation"], _19);
  main.variable(observer()).define(["md"], _20);
  main.variable(observer()).define(["data"], _21);
  main.variable(observer()).define(["data","md"], _22);
  main.variable(observer()).define(["md"], _23);
  main.variable(observer("nycweather")).define("nycweather", ["d3"], _nycweather);
  main.variable(observer()).define(["__query","nycweather","invalidation"], _25);
  main.variable(observer()).define(["md"], _26);
  main.variable(observer()).define(["md"], _27);
  main.variable(observer("df")).define("df", _df);
  main.variable(observer()).define(["md"], _29);
  main.variable(observer()).define(["__query","df","invalidation"], _30);
  main.variable(observer()).define(["md"], _31);
  main.variable(observer()).define(["md"], _32);
  main.variable(observer()).define(["vl","df"], _33);
  main.variable(observer()).define(["md"], _34);
  main.variable(observer()).define(["vl","df"], _35);
  main.variable(observer()).define(["md"], _36);
  main.variable(observer()).define(["vl","df"], _37);
  main.variable(observer()).define(["md"], _38);
  main.variable(observer()).define(["vl","df"], _39);
  main.variable(observer()).define(["md"], _40);
  main.variable(observer()).define(["md"], _41);
  main.variable(observer()).define(["md"], _42);
  main.variable(observer()).define(["md"], _43);
  main.variable(observer()).define(["vl","df"], _44);
  main.variable(observer()).define(["md"], _45);
  main.variable(observer()).define(["md"], _46);
  main.variable(observer()).define(["vl","df"], _47);
  main.variable(observer()).define(["md"], _48);
  main.variable(observer()).define(["md"], _49);
  main.variable(observer()).define(["md"], _50);
  main.variable(observer()).define(["md"], _51);
  main.variable(observer()).define(["md"], _52);
  main.variable(observer()).define(["vl","df"], _53);
  main.variable(observer()).define(["md"], _54);
  main.variable(observer()).define(["vl","df"], _55);
  main.variable(observer()).define(["md"], _56);
  main.variable(observer()).define(["md"], _57);
  main.variable(observer()).define(["vl","df"], _58);
  main.variable(observer()).define(["md"], _59);
  main.variable(observer()).define(["md"], _60);
  main.variable(observer()).define(["vl","cars"], _61);
  main.variable(observer()).define(["md"], _62);
  main.variable(observer()).define(["vl","cars"], _63);
  main.variable(observer()).define(["md"], _64);
  main.variable(observer()).define(["vl","cars"], _65);
  main.variable(observer()).define(["md"], _66);
  main.variable(observer()).define(["vl","cars"], _67);
  main.variable(observer()).define(["md"], _68);
  main.variable(observer()).define(["vl","cars"], _69);
  main.variable(observer()).define(["md"], _70);
  main.variable(observer()).define(["md"], _71);
  main.variable(observer()).define(["md"], _72);
  main.variable(observer("scatter")).define("scatter", ["vl","cars"], _scatter);
  main.variable(observer()).define(["md"], _74);
  main.variable(observer()).define(["vl","cars"], _75);
  main.variable(observer()).define(["md"], _76);
  main.variable(observer()).define(["md"], _77);
  main.variable(observer()).define(["vl","html"], _78);
  main.variable(observer()).define(["md"], _79);
  main.variable(observer()).define(["vl","html"], _80);
  main.variable(observer()).define(["md"], _81);
  main.variable(observer()).define(["md"], _82);
  main.variable(observer()).define(["md"], _83);
  main.variable(observer()).define(["md"], _84);
  main.variable(observer()).define(["md"], _85);
  main.variable(observer()).define(["md"], _86);
  return main;
}
