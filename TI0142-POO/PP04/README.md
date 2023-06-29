# Instruções  

## Visão Geral

Nessa prática de programação, cada questão (descrita em cada passo da próxima seção) deve ser implementada nas classes especificadas. Existem testes automatizados para todas as classes a serem implementadas, portanto, você não deve alterar nem o nome e nem a assinatura dos métodos já fornecidos, sejam os completamente implementados ou na forma de stubs (sem implementação funcional de fato).

## Passos

1. Altere a implementação da classe `Conta` (arquivo `Conta.java`) para que atenda aos seguintes requisitos: (i) não permitir que o saldo de uma conta fique negativo; (ii) não permitir operações de crédito com valores negativos; e (iii)  não permitir operações de débito com valores negativos.

2. Implemente a classe `ContaPoupanca` (arquivo `ContaPoupanca.java`), aprensetada no arquivo **Nota de Aula 07**, disponível no SIGAA. Lembre-se de atender ao seguinte requisito: não permitir aplicação de taxa de correção com valores negativos.
  
3. Modifique a classe `BancoArray` para que seja possível render juros de uma poupança, isto é, implemente o método  `public void renderJuros(String numero)`. A taxa de correção da poupança deve ser guardada no atributo `private double taxaPoupanca` da classe `BancoArray`. Essa taxa pode ser alterada via chamadas ao método `public void setTaxaPoupanca(double valor)` da classe `BancoArray`. Reflita: Foi necessário alterar algum outro código existente?

4. Implemente a classe `ContaEspecial` (arquivo `ContaEspecial.java`), aprensetada no arquivo **Nota de Aula 07**, disponível no SIGAA. Lembre-se de atender ao seguinte requisito: não permitir atribuição de percentagem de bonus com valores negativos.

5. Modifique as classes `BancoArray` para que seja possível computar o bônus de uma conta especial, isto é, implemente o método `public void renderBonus(String numero)` da classe `BancoArray`. A percentagem de bonus da conta especial deve ser guardada no atributo `private double bonusPercentagem` da classe `BancoArray`. Essa percentagem  pode ser alterada via chamadas ao método `public void setBonusPercentagem(double valor)` da classe `BancoArray`. Lembre-se de atender aos seguintes requisitos: (i) toda vez que um objeto da classe `ContaEspecial` for cadastrado no `BancoArray`, deve ser atribuída a ele a percentagem de bonus do banco (i.e., o conteúdo do atributo `bonusPercentagem`); e (ii) toda vez que a percentagem de bonus for alterada via chamada ao método `public void setBonusPercentagem(double valor)` da classe `BancoArray`, a percentagem de bonus de todos os objetos do tipo `ContaEspecial` cadastrados no banco deve ser alterada chamando o método `setBonusPercentagem(double percentagem)` da classe `ContaEspecial`.

6. [**DESAFIO**] A classe `Vector` do pacote `java.util` da biblioteca de classes do Java provê uma implementação de array expansível de objetos. Como um array, ele contém componentes que podem ser acessados usando um índice inteiro. No entanto, o tamanho de um `Vector` pode aumentar ou diminuir conforme necessário para acomodar a adição e remoção de itens após a criação do `Vector`. Além disso, um `Vector` disponibiliza uma série de métodos para manipular o conteúdo do array, veja mais detalhes na [documentação oficial do Java](https://docs.oracle.com/javase/8/docs/api/java/util/Vector.html). Nessa questão, você deve implementar um novo banco, o `BancoVector` (no arquivo `BancoVector.java`), usando como estrutura de dados a classe `Vector`. O `BancoVector` deve possuir a mesma interface (i.e., mesmo conjunto de métodos, com a mesma assinatura) do `BancoArray`. A seguir são apresentadas formas de uso de um `Vector` para ajudá-lo na tarefa. 


Instanciando um vetor de strings.
```
Vector<String> vectorDeStrings = new Vector<String>();
```

Adicinando elementos ao vetor usando o método `add()`.
```
vectorDeStrings.add("Primeira String");
vectorDeStrings.add("Segunda String");
vectorDeStrings.add("Terceira String");
vectorDeStrings.add("Quarta String");
```

Imprimindo o tamanho de um vetor.
```
System.out.println(vectorDeStrings.size())
```

Recuperando um elemento de uma posição específica do vetor.
```
String conteudo = vectorDeStrings.get(0);
System.out.println(conteudo)
```

Removendo um elemento de uma posição específica do vetor.
```
String conteudo = vectorDeStrings.remove(0);
System.out.println(conteudo)
System.out.println(vectorDeStrings.size())
```

Removendo um objeto recuperado do vetor.
```
String conteudo = vectorDeStrings.get(0);
vectorDeStrings.remove(conteudo);
System.out.println(conteudo);
System.out.println(vectorDeStrings.size())
```

Interando em um vetor via laço `for`.
```
for(int i = 0; i < vectorDeStrings.size(); i++) {
  String conteudo = vectorDeStrings.get(i);
  System.out.println(conteudo);
}
```

Interando em um vetor via laço `for-each`.
```
for(String conteudo : vectorDeStrings) {
  System.out.println(conteudo)
}
```