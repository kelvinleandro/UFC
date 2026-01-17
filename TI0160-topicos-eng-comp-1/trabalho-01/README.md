# Sistema Bancário

- **Objetivo**: Simular contas bancárias com operações básicas.

- **Classes**: Conta, Cliente, Banco.

- **Modularização**:

  - Conta.h / Conta.cpp → saldo, número da conta, métodos depositar(), sacar().

  - Cliente.h / Cliente.cpp → dados pessoais, contas associadas.

  - Banco.h / Banco.cpp → conjunto de clientes e contas.

- **Construtores**: inicializar contas já com saldo e número.

- **Destrutores**: liberar memória de contas dinâmicas ou registros de clientes.

-> **Exemplo de operação**: criar cliente, abrir conta, transferir dinheiro entre
contas.
