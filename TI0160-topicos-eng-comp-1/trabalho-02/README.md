# Trabalho 2 - Sistema Acadêmico

O exercício integra:

- Sobrecarga de construtores
- Sobrecarga de operadores
- Uso de classes aninhadas com operador de escopo (::)

## Classe `Escola`

- Atributo: nome (string)
- Construtores:
  - Padrão: nome = 'Sem Nome'
  - Parametrizado: recebe string
- Método mostrarEscola() definido fora da classe

## Classe `Turma` (aninhada)

- Atributo: serie (string)
- Construtores: padrão e parametrizado
- Método mostrarTurma()
- Definição de métodos fora da classe com (::)

## Classe `Aluno` (aninhada)

- Atributos: nomeAluno (string), nota (double)
- Construtores:
  - Padrão: nomeAluno = 'Sem Nome', nota = 0
  - Parametrizado: nome e nota
- Método mostrarAluno()
- Sobrecarga do operador + : média de notas
- Sobrecarga do operador << : impressão formatada
