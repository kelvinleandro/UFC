#include <iostream>
#include <iomanip>
#include "Banco.h"
#include "Cliente.h"
#include "Conta.h"

void imprimirSaldos(Banco &banco, int num1, int num2)
{
  Conta *conta1 = banco.buscarConta(num1);
  Conta *conta2 = banco.buscarConta(num2);

  std::cout << std::fixed << std::setprecision(2);
  if (conta1)
  {
    std::cout << "Saldo atual da conta " << num1 << ": R$ " << conta1->getSaldo() << std::endl;
  }
  if (conta2)
  {
    std::cout << "Saldo atual da conta " << num2 << ": R$ " << conta2->getSaldo() << std::endl;
  }
  std::cout << "--------------------------------------------------\n";
}

int main()
{
  Banco meuBanco("Banco POO Moderno");
  std::cout << "Bem-vindo ao Banco POO Moderno!\n\n";

  meuBanco.adicionarCliente("Alice Silva", "111.222.333-44");
  meuBanco.adicionarCliente("Beto Costa", "555.666.777-88");
  std::cout << "\n";

  meuBanco.abrirConta("111.222.333-44", 1001, 1500.50);
  meuBanco.abrirConta("555.666.777-88", 2001, 300.00);
  std::cout << "\n";

  imprimirSaldos(meuBanco, 1001, 2001);

  meuBanco.transferir(1001, 2001, 250.25);
  imprimirSaldos(meuBanco, 1001, 2001);

  meuBanco.transferir(2001, 1001, 1000.00);
  imprimirSaldos(meuBanco, 1001, 2001);

  std::cout << "\n--- Realizando depósito ---\n";
  Conta *contaBetoPtr = meuBanco.buscarConta(2001);
  if (contaBetoPtr)
  {
    contaBetoPtr->depositar(800.00);
  }
  imprimirSaldos(meuBanco, 1001, 2001);

  meuBanco.transferir(2001, 1001, 1000.00);
  imprimirSaldos(meuBanco, 1001, 2001);

  return 0;
}