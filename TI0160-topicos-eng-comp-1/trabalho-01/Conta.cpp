#include "Conta.h"
#include <iostream>
#include <stdexcept>

// Implementação do construtor
Conta::Conta(int numero, double saldoInicial) : numeroConta(numero), saldo(saldoInicial)
{
  if (saldoInicial < 0)
  {
    throw std::invalid_argument("O saldo inicial não pode ser negativo.");
  }
}

// Implementação do método depositar
void Conta::depositar(double valor)
{
  if (valor > 0)
  {
    saldo += valor;
    std::cout << "Depósito de R$ " << valor << " realizado com sucesso na conta " << numeroConta << ".\n";
  }
  else
  {
    std::cout << "Valor de depósito inválido.\n";
  }
}

// Implementação do método sacar
bool Conta::sacar(double valor)
{
  if (valor <= 0)
  {
    std::cout << "Valor de saque inválido.\n";
    return false;
  }
  if (saldo >= valor)
  {
    saldo -= valor;
    std::cout << "Saque de R$ " << valor << " realizado com sucesso da conta " << numeroConta << ".\n";
    return true;
  }
  else
  {
    std::cout << "Saldo insuficiente na conta " << numeroConta << " para sacar R$ " << valor << ".\n";
    return false;
  }
}

// Implementação dos getters
double Conta::getSaldo() const
{
  return saldo;
}

int Conta::getNumeroConta() const
{
  return numeroConta;
}