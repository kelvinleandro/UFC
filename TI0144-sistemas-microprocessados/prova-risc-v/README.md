# Prova Assembly RISC-V

## Questão 1

Implementar um algoritmo que calcula os 10 primeiros termos da sequência de Fibonacci no assembly do RISC V.

## Questão 2

Leia o site abaixo.

https://www.geeksforgeeks.org/fast-fourier-transformation-poynomial-multiplication/

Considere dois polinômios cujos coeficientes são os dígitos de sua matrícula e outro o polinômio 2x³ + x² + 3x + 1. Implemente um código que calcule o produto desses polinômios em assembly do RISC V.

## Questão 3

Faça um programa em assembly do RISC V que calcula os números felizes entre 1 e 50 e salva em um array iniciado na posição 0x100 da memória. Números felizes são números cuja soma sucessiva do quadrado de seus dígitos converge para 1.

Por exemplo o número 7:

7 -> 7² = 49

49 -> 4² + 9² = 97

97 -> 9² + 7² = 130

130 -> 1² + 3² + 0² = 10

10 -> 1² + 0² = 1

Como a sequência resultou em 1 então 7 é um número feliz.

Números infelizes resultaram em algum momento nos números 4, 16, 37, 58, 89, 145, 42 e 20 de forma cíclica. Então esses números foram usados como condições de saída da função feliz.