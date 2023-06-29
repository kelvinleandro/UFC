# Instruções  

## Visão Geral

Nessa prática de programação, cada questão (descrita em cada passo da próxima seção) deve ser implementada nas classes especificadas. Você deverá melhorar os testes automatizados já disponíveis na classe `Main.java`.
   
## Passos

1.Você deve fazer com que as classes de conta bancária seja passiveis de serialização. Para isso você verá alterar a declaração das classes necessárias para que elas implementem a interface `Serializable` do pacote `java.io`. Nota! Lembre-se de criar um atributo estático `private static final long serialVersionUID` e atribuir um valor inicial para ele. [Veja mais sobre isso no site oficial do Java.](https://www.oracle.com/br/technical-resources/articles/java/serialversionuid.html)

2. Você deverá prover implementação para os métodos `private void serializar()` e `private void desserializar()` da classe `VectorContaArquivo` que tem por objetivo manter a sincronia entre os objetos de conta bancária guardados no `Vector` e o arquivo `./arquivo/contas.bin`. O método `private void serializar()` tem como objetivo persistir o vector de objetos de contas bancárias no arquivo, já o método `private void desserializar()` tem objetivo contrário, isto é, carregar o conteúdo do arquivo para dentro do vector de objetos de contas bancárias. Veja a implementação da Nota de Aula 11.
  
3. Lembre-se que a sincronização deve ocorrer sempre que possível, para garantir que os dados que estão em memória e os que estão persistidos em arquivos sejam os mesmos. Estratégia ingênua: a cada chamada de método da classe `VectorContaArquivo`, avalie a necessidade de fazer a sincronia.
   
4. **DESAFIO** Estrégia de sincronização temporal (por agendamento), como a descrita  site da [DevMedia.](https://www.devmedia.com.br/agendando-tarefas-em-java-com-quartz-scheduler-e-timertask/32466)


