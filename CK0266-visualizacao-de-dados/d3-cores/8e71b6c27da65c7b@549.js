import define1 from "./a33468b95d0b15b0@817.js";

function _1(md){return(
md`# Cores em D3`
)}

function _palette(build_palette,d3){return(
build_palette(d3.scaleSequential(d3.interpolateViridis), d3.ticks(0, 1, 10), 70)
)}

function _3(md){return(
md`O objetivo desse notebook é aprofundar o uso de escalas em D3 para criar mapas de cores a aplicá-los em Visualizações.

## [Escalas](https://github.com/d3/d3-scale) utilizadas em mapas de cores

* Escalas quantize, quantile e threshold
* Escalas ordinais
* Escalas sequenciais e divergentes

### Quantize

Escalas [quantize](https://github.com/d3/d3-scale#quantize-scales) são semelhantes a escalas lineares, mas com um range discreto (em vez de um range contínuo).

Quantizar significa agrupar valores com incrementos discretos — como expressar uma lista de números de ponto flutuante com uma casa decimal ou arredondar o tempo para o minuto mais próximo. É o intervalo de saída que é discretizado, e essa escala permite transformar um intervalo contínuo inicial em um conjunto discreto de classes.

O domínio é contínuo e o mapeamento é linear. O domínio é mapeado em segmentos uniformes baseados no número de valores do range de saída:`
)}

function _q(d3){return(
d3.scaleQuantize()
      .domain([10,100])
      .range([1,2,4])
)}

function _5(q,md){return(
md`q(20) = ${q(20)}, q(50) =${q(50)} e q(80) = ${q(80)}. 

No exemplo acima, os valores entre 10 e 100 são mapeados linearmente em três valores: 1, 2 e 4.`
)}

function _6(md){return(
md`Usando uma escala quantize para criar um colormap:`
)}

function _colorz(d3){return(
d3.scaleQuantize()
            .domain([0,1])
            .range(["brown", "steelblue"])
)}

function _8(build_palette,colorz){return(
build_palette(colorz, [0.49, 0.51], 70)
)}

function _9(md){return(
md`Podemos ver os limiares da escala quantize usando o método \`threshods()\`:`
)}

function _10(colorz){return(
colorz.thresholds()
)}

function _11(md){return(
md`O número de limites retornados é um a menos que o comprimento do intervalo: valores menores que o primeiro limite recebem o primeiro elemento do intervalo, enquanto valores maiores ou iguais ao último limite recebem o último elemento do intervalo.`
)}

function _12(md){return(
md`### Quantile
[Quantile](https://github.com/d3/d3-scale#quantile-scales) mapeia valores amostrados no domínio para um range discreto. 

O domínio é considerado contínuo e, portanto, a escala aceitará qualquer valor de entrada razoável; no entanto, o domínio é especificado como um conjunto discreto de valores amostrados.

Os valores do domínio são mapeados ao seu respectivo percentil (*quantile*, em português: quantil). 

Quantis, em estatística, são definidos ao separar uma população em intervalos de tamanhos semelhantes (por exemplo, 10% mais pobres, 1% mais ricos, etc.)

Uma escala quantile é definida pelo seu domínio, que é um conjunto fixo de valores. Quando ela é aplicada a um novo valor, a escala calcula o ranking desse valor com relação à distribuição inicial, e mapeia o ranking para o range de saída.

O número de quantis é especificado pelo range.`
)}

function _colort(d3){return(
d3.scaleQuantile()
  .domain([0,1,5,6,2,4,6,2,4,6,7,8])
  .range([0,100])
)}

function _14(md){return(
md`Por exemplo, na escala acima, como o range possui dois valores, haverá apenas um limiar (mediana). Lembre-se que a mediana é calculada após a ordenação dos elementos do domínio e tomando-se o elemento da metade do vetor, se o número de elementos for ímpar, ou a média aritmética dos dois valores da metade do vetor, caso o número de elementos seja par.`
)}

function _15(){return(
[0,1,5,6,2,4,6,2,4,6,7,8].sort()
)}

function _16(md){return(
md`\`colort.quantiles()\`  retorna apenas um quantile [4.5] - a mediana:
`
)}

function _17(colort){return(
colort.quantiles()
)}

function _18(md){return(
md`Qualquer valor menor que a mediana será mapeado em 0 e valores maiores ou iguais à mediana serão mapeados em 100 (mesmo fora do domínio):
\`\`\`javascript
colort(4.499); // 0
colort(4.5); // 100 -> maior ou igual a mediana
colort(5); // 100
colort(10000); // 100

\`\`\``
)}

function _19(colort){return(
colort(4.499)
)}

function _20(colort){return(
colort(10000)
)}

function _21(md){return(
md`Vamos criar outra escala com outro range:`
)}

function _colort2(d3){return(
d3.scaleQuantile().domain([0,1,5,6,2,4,6,2,4,6,7,8]).range([25,50,75,100])
)}

function _23(md){return(
md`\`\`\`javascript
colort2.quantiles(); // [2, 4.5, 6];
colort2(0); // 25 
colort2(2); // 50 -> maior ou igual ao primeiro limiar de quantile
colort2(3); // 50
colort2(4); // 50
colort2(5); // 75
colort2(6); // 100
colort2(10000); // 100
\`\`\``
)}

function _24(colort2){return(
colort2.quantiles()
)}

function _25(colort2){return(
colort2(4)
)}

function _26(md){return(
md`Usando uma escala quantile para criar um colormap:`
)}

function _colort3(d3){return(
d3.scaleQuantile()
  .domain([0,1,5,6,2,4,6,2,4,6,7,8]).range(d3.schemeBlues[5])
)}

function _28(build_palette,colort3){return(
build_palette(colort3, [0,2,4,5.6,6], 70)
)}

function _29(md){return(
md`### Escalas threshold

As escalas [threshold](https://d3js.org/d3-scale/threshold) são semelhantes às escalas quantize com a diferença de permitirem especificar diretamente os valores de corte de separação das classes. 

O domínio de entrada ainda é contínuo e dividido em fatias com base em um conjunto de valores limiares (_threshold_).
`
)}

function _colorh(d3){return(
d3.scaleThreshold([0,1], ["red", "white", "blue"])
)}

function _31(build_palette,colorh){return(
build_palette(colorh, [-1,0,1], 70)
)}

function _32(md){return(
md`\`\`\`javascript
colorh(-1); // "red"
colorh(0); // "white"
colorh(0.5); // "white"
colorh(1); // "blue"
colorh(1000); // "blue"
\`\`\``
)}

function _33(md){return(
md`### Escalas ordinais
As escalas [ordinais](https://github.com/d3/d3-scale#ordinal-scales) possuem um domínio e um range discretos.

Elas transformam um número limitado de valores em algum outro valor, sem considerar os valores intermediários.`
)}

function _colord(d3){return(
d3.scaleOrdinal()
        .domain(["HOMICIDE", "ROBBERY", "BURGLARY"])
        .range(["#ca0020", "#0571b0", "#fdae61"])
        .unknown(null)
)}

function _35(build_palette,colord){return(
build_palette(colord, ["HOMICIDE", "ROBBERY", "BURGLARY"], 100)
)}

function _36(colord){return(
colord("HOMICIDE")
)}

function _37(md){return(
md`Se o valor de entrada não estiver no domínio, o valor configurado como \`unknown(value)\` será retornado:`
)}

function _38(colord){return(
colord("Not Found")
)}

function _39(md){return(
md`### Escalas sequenciais e divergentes

De modo semelhante às escalas lineares, as escalas [sequenciais](https://github.com/d3/d3-scale#sequential-scales) e [divergentes](https://github.com/d3/d3-scale#diverging-scales) mapeiam um domínio numérico contínuo para um range contínuo.

A diferença é que nas escalas sequenciais e divergentes, o domínio e o range sempre possuem dois elementos, e o range normalmente é definido por um interpolador.`
)}

function _rainbow(d3){return(
d3.scaleSequential(d3.interpolateRainbow)
)}

function _41(md){return(
md`Como vimos em sala, a escala de cores rainbow não deve ser utilizada. Veja que valores mínimo e máximo são mapeados para a mesma cor:`
)}

function _42(build_palette,rainbow,d3){return(
build_palette(rainbow, d3.ticks(0, 1, 9), 70)
)}

function _spectral(d3){return(
d3.scaleDiverging(d3.interpolateSpectral)
)}

function _44(build_palette,spectral,d3){return(
build_palette(spectral, d3.ticks(0, 1, 10), 70)
)}

function _45(md){return(
md`## Esquemas de Cores

### [d3-scale-chromatic](https://github.com/d3/d3-scale-chromatic)

D3 provê esquemas de cores sequenciais, divergentes e categóricos para serem usados em conjunto com as escalas sequenciais, divergentes e ordinais.
A maioria dos esquemas é derivada a partir do [ColorBrewer](colorbrewer2.org).

### [Esquemas categóricos](https://github.com/d3/d3-scale-chromatic#categorical)

\`\`\`javascript
d3.schemeCategory10
\`\`\`
Um vetor de 10 cores categóricas representadas como strings RGB hexadecimais.`
)}

function _catcolor(d3){return(
d3.scaleOrdinal(d3.schemeCategory10)
)}

function _47(build_palette,catcolor,d3){return(
build_palette(catcolor, d3.ticks(1, 10, 10), 70)
)}

function _48(md){return(
md`
\`\`\`javascript
d3.schemeAccent
\`\`\`
Um vetor de 8 cores categóricas representadas como strings RGB hexadecimais.
`
)}

function _accent(d3){return(
d3.scaleOrdinal(d3.schemeAccent)
)}

function _50(build_palette,accent,d3){return(
build_palette(accent, d3.ticks(1, 8, 8), 70)
)}

function _51(md){return(
md`\`\`\`javascript
d3.schemeDark2
\`\`\`
Um vetor de 8 cores categóricas representadas como strings RGB hexadecimais.`
)}

function _dark2(d3){return(
d3.scaleOrdinal(d3.schemeDark2)
)}

function _53(build_palette,dark2,d3){return(
build_palette(dark2, d3.ticks(1, 8, 8), 70)
)}

function _54(md){return(
md`Veja outros esquemas [na documentação do d3](https://github.com/d3/d3-scale-chromatic#categorical).`
)}

function _55(md){return(
md`### [Esquemas divergentes](https://github.com/d3/d3-scale-chromatic#diverging)

Estão disponíveis como interpoladores contínuos (usados com \\\`d3.scaleSequential\\\`) e esquemas discretos (usados com \\\`d3.scaleOrdinal\\\`).

Cada esquema discreto é representado por um vetor de vetores de tamanho k, onde k varia de 3 a 11.`
)}

function _56(md){return(
md`\`\`\`javascript
d3.interpolatePiYG
d3.schemePiYG[k]
\`\`\`
Dado um número n no intervalo [0,1], retorna a cor correspondente do esquema de cor divergente "PiYG" representada como uma string RGB.`
)}

function _cpiyg(d3){return(
d3.scaleSequential(d3.interpolatePiYG)
)}

function _58(build_continuous,cpiyg,d3){return(
build_continuous(cpiyg, d3.ticks(0, 1, 200), 4)
)}

function _dpiyg(d3){return(
d3.scaleOrdinal(d3.schemePiYG[9])
)}

function _60(build_palette,dpiyg){return(
build_palette(dpiyg, [-4,-3,-2,-1,0,1,2,3,4], 70)
)}

function _61(md){return(
md`Veja outros exemplos de esquemas divergentes na [documentação do D3](https://github.com/d3/d3-scale-chromatic#diverging).`
)}

function _62(md){return(
md`### [Esquemas sequenciais (matiz único)](https://github.com/d3/d3-scale-chromatic#sequential-single-hue)

Estão disponíveis como interpoladores contínuos (usados com \\\`d3.scaleSequential\\\`) e esquemas discretos (usados com \\\`d3.scaleOrdinal\\\`).

Cada esquema discreto é representado por um vetor de vetores de tamanho k, onde k varia de 3 a 9. `
)}

function _63(md){return(
md`\`\`\`javascript
d3.interpolateBlues
d3.schemeBlues[k]
\`\`\`
Dado um número n no intervalo [0,1], retorna a cor correspondente do esquema de cor sequencial "Blues" representada como uma string RGB.`
)}

function _cblues(d3){return(
d3.scaleSequential(d3.interpolateBlues)
)}

function _65(build_continuous,cblues,d3){return(
build_continuous(cblues, d3.ticks(0, 1, 200), 4)
)}

function _dblues(d3){return(
d3.scaleOrdinal(d3.schemeBlues[8])
)}

function _67(build_palette,dblues){return(
build_palette(dblues, [1,2,3,4,5,6,7,8], 70)
)}

function _68(md){return(
md`Veja outros exemplos de esquemas sequenciais de matiz único na [documentação do D3](https://github.com/d3/d3-scale-chromatic#sequential-single-hue).`
)}

function _69(md){return(
md`### [Esquemas sequenciais (múltiplos matizes)](https://github.com/d3/d3-scale-chromatic#sequential-multi-hue)

As escalas abaixo são perceptivamente uniformes`
)}

function _70(md){return(
md`
\`\`\`javascript
d3.interpolateViridis
\`\`\`
`
)}

function _71(build_continuous,d3){return(
build_continuous(d3.scaleSequential(d3.interpolateViridis),  d3.ticks(0, 1, 200), 4)
)}

function _72(md){return(
md`\`\`\`javascript
d3.interpolateInferno
\`\`\``
)}

function _73(build_continuous,d3){return(
build_continuous(d3.scaleSequential(d3.interpolateInferno),  d3.ticks(0, 1, 200), 4)
)}

function _74(md){return(
md`## Espaços de cores

D3 permite manipular [cores](https://github.com/d3/d3-color) em diversos espaços de cores:

* RGB: d3.rgb(color)
* HSL: d3.hsl(color)
* LAB: d3.lab(color)
* HCL: d3.hcl(color)

O parâmetro \`color\` pode estar em diversos formatos. Veja alguns exemplos:
* rgb(255, 255, 255)
* rgb(10%, 20%, 30%)
* rgba(255, 255, 255, 0.4)
* rgba(10%, 20%, 30%, 0.4)
* hsl(120, 50%, 20%)
* hsla(120, 50%, 20%, 0.4)
* #ffeeaa
* #fea
* #ffeeaa22
* #fea2
* steelblue`
)}

function _c(d3){return(
d3.color("steelblue")
)}

function _76(d3,c){return(
d3.rgb(c)
)}

function _77(d3,c){return(
d3.hsl(c)
)}

function _78(d3,c){return(
d3.lab(c)
)}

function _79(md){return(
md`Uma vez o objeto criado, você pode manipular a cor de diversas maneiras:`
)}

function _c2(d3){return(
d3.rgb("violet")
)}

function _81(c2){return(
c2.toString()
)}

function _82(c2){return(
c2.formatHex()
)}

function _83(c2){return(
c2.darker().toString()
)}

function _84(c2){return(
c2.darker(2).toString()
)}

function _85(c2){return(
c2.brighter().toString()
)}

function _86(md){return(
md`# Criando Legendas
Para criar legendas para escalas de cores, recomendo utilizar a função [Legend](https://observablehq.com/@d3/color-legend?collection=@d3/d3-scale) criada por Mike Bostock:

\`\`\`javascript
import {Legend, Swatches} from "@d3/color-legend"
\`\`\``
)}

function _87(Legend,d3){return(
Legend(d3.scaleSequential([0, 100], d3.interpolateViridis), {
  title: "Temperature (°F)"
})
)}

function _88(md){return(
md`## Usando mapas de cores em choropleth
Faça os exercícios no notebook abaixo:

* [Taxa de desemprego nos EUA em 2008 (Vega-Lite)](https://observablehq.com/@vis-ufc/taxa-de-desemprego-nos-eua-em-2008-vega-lite)`
)}

function _89(md){return(
md`## Para saber mais

- [Introduction to D3's scales](https://observablehq.com/@d3/introduction-to-d3s-scales?collection=@d3/d3-scale)
- [Quantile, Quantize and Threshold scales](https://observablehq.com/@d3/quantile-quantize-and-threshold-scales?collection=@d3/d3-scale)
- [Sequential scales](https://observablehq.com/@d3/sequential-scales?collection=@d3/d3-scale)
- [Continuous scales](https://observablehq.com/@d3/continuous-scales?collection=@d3/d3-scale)
- [Color legend](https://observablehq.com/@d3/color-legend?collection=@d3/d3-scale)
  `
)}

function _build_palette(d3,DOM,width){return(
(colorscale, data, w) => {
  const svg = d3.select(DOM.svg(width, 70))
  svg.selectAll('rect')
    .data(data)
    .enter()
    .append('rect')
    .attr('x', (d,i) => 25 + i * w)
    .attr('y', 5)
    .attr('width', w)
    .attr('height', 35)
    .attr('fill', (d) => colorscale(d));
  svg.selectAll('text')
    .data(data)
    .enter()
    .append('text')
    .attr('x', (d,i) => 25 + w/2 + i * w)
    .attr('text-anchor', 'middle')
    .attr('y', 60)
    .text(d => d)

  return svg.node()
}
)}

function _build_continuous(d3,DOM,width){return(
(colorscale, data, w) => {
  const svg = d3.select(DOM.svg(width, 70))
  svg.selectAll('rect')
    .data(data)
    .enter()
    .append('rect')
    .attr('x', (d,i) => 25 + i * w)
    .attr('y', 5)
    .attr('width', w)
    .attr('height', 35)
    .attr('fill', (d) => colorscale(d));
  return svg.node()
}
)}

export default function define(runtime, observer) {
  const main = runtime.module();
  main.variable(observer()).define(["md"], _1);
  main.variable(observer("palette")).define("palette", ["build_palette","d3"], _palette);
  main.variable(observer()).define(["md"], _3);
  main.variable(observer("q")).define("q", ["d3"], _q);
  main.variable(observer()).define(["q","md"], _5);
  main.variable(observer()).define(["md"], _6);
  main.variable(observer("colorz")).define("colorz", ["d3"], _colorz);
  main.variable(observer()).define(["build_palette","colorz"], _8);
  main.variable(observer()).define(["md"], _9);
  main.variable(observer()).define(["colorz"], _10);
  main.variable(observer()).define(["md"], _11);
  main.variable(observer()).define(["md"], _12);
  main.variable(observer("colort")).define("colort", ["d3"], _colort);
  main.variable(observer()).define(["md"], _14);
  main.variable(observer()).define(_15);
  main.variable(observer()).define(["md"], _16);
  main.variable(observer()).define(["colort"], _17);
  main.variable(observer()).define(["md"], _18);
  main.variable(observer()).define(["colort"], _19);
  main.variable(observer()).define(["colort"], _20);
  main.variable(observer()).define(["md"], _21);
  main.variable(observer("colort2")).define("colort2", ["d3"], _colort2);
  main.variable(observer()).define(["md"], _23);
  main.variable(observer()).define(["colort2"], _24);
  main.variable(observer()).define(["colort2"], _25);
  main.variable(observer()).define(["md"], _26);
  main.variable(observer("colort3")).define("colort3", ["d3"], _colort3);
  main.variable(observer()).define(["build_palette","colort3"], _28);
  main.variable(observer()).define(["md"], _29);
  main.variable(observer("colorh")).define("colorh", ["d3"], _colorh);
  main.variable(observer()).define(["build_palette","colorh"], _31);
  main.variable(observer()).define(["md"], _32);
  main.variable(observer()).define(["md"], _33);
  main.variable(observer("colord")).define("colord", ["d3"], _colord);
  main.variable(observer()).define(["build_palette","colord"], _35);
  main.variable(observer()).define(["colord"], _36);
  main.variable(observer()).define(["md"], _37);
  main.variable(observer()).define(["colord"], _38);
  main.variable(observer()).define(["md"], _39);
  main.variable(observer("rainbow")).define("rainbow", ["d3"], _rainbow);
  main.variable(observer()).define(["md"], _41);
  main.variable(observer()).define(["build_palette","rainbow","d3"], _42);
  main.variable(observer("spectral")).define("spectral", ["d3"], _spectral);
  main.variable(observer()).define(["build_palette","spectral","d3"], _44);
  main.variable(observer()).define(["md"], _45);
  main.variable(observer("catcolor")).define("catcolor", ["d3"], _catcolor);
  main.variable(observer()).define(["build_palette","catcolor","d3"], _47);
  main.variable(observer()).define(["md"], _48);
  main.variable(observer("accent")).define("accent", ["d3"], _accent);
  main.variable(observer()).define(["build_palette","accent","d3"], _50);
  main.variable(observer()).define(["md"], _51);
  main.variable(observer("dark2")).define("dark2", ["d3"], _dark2);
  main.variable(observer()).define(["build_palette","dark2","d3"], _53);
  main.variable(observer()).define(["md"], _54);
  main.variable(observer()).define(["md"], _55);
  main.variable(observer()).define(["md"], _56);
  main.variable(observer("cpiyg")).define("cpiyg", ["d3"], _cpiyg);
  main.variable(observer()).define(["build_continuous","cpiyg","d3"], _58);
  main.variable(observer("dpiyg")).define("dpiyg", ["d3"], _dpiyg);
  main.variable(observer()).define(["build_palette","dpiyg"], _60);
  main.variable(observer()).define(["md"], _61);
  main.variable(observer()).define(["md"], _62);
  main.variable(observer()).define(["md"], _63);
  main.variable(observer("cblues")).define("cblues", ["d3"], _cblues);
  main.variable(observer()).define(["build_continuous","cblues","d3"], _65);
  main.variable(observer("dblues")).define("dblues", ["d3"], _dblues);
  main.variable(observer()).define(["build_palette","dblues"], _67);
  main.variable(observer()).define(["md"], _68);
  main.variable(observer()).define(["md"], _69);
  main.variable(observer()).define(["md"], _70);
  main.variable(observer()).define(["build_continuous","d3"], _71);
  main.variable(observer()).define(["md"], _72);
  main.variable(observer()).define(["build_continuous","d3"], _73);
  main.variable(observer()).define(["md"], _74);
  main.variable(observer("c")).define("c", ["d3"], _c);
  main.variable(observer()).define(["d3","c"], _76);
  main.variable(observer()).define(["d3","c"], _77);
  main.variable(observer()).define(["d3","c"], _78);
  main.variable(observer()).define(["md"], _79);
  main.variable(observer("c2")).define("c2", ["d3"], _c2);
  main.variable(observer()).define(["c2"], _81);
  main.variable(observer()).define(["c2"], _82);
  main.variable(observer()).define(["c2"], _83);
  main.variable(observer()).define(["c2"], _84);
  main.variable(observer()).define(["c2"], _85);
  main.variable(observer()).define(["md"], _86);
  main.variable(observer()).define(["Legend","d3"], _87);
  main.variable(observer()).define(["md"], _88);
  main.variable(observer()).define(["md"], _89);
  main.variable(observer("build_palette")).define("build_palette", ["d3","DOM","width"], _build_palette);
  main.variable(observer("build_continuous")).define("build_continuous", ["d3","DOM","width"], _build_continuous);
  const child1 = runtime.module(define1);
  main.import("Legend", child1);
  main.import("Swatches", child1);
  return main;
}
