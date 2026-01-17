#include "Cliente.h"
#include <iostream>

Cliente::Cliente(const std::string &nome, const std::string &cpf) : nome(nome), cpf(cpf) {}

Conta *Cliente::adicionarConta(int numeroConta, double saldoInicial)
{
  auto novaConta = std::make_unique<Conta>(numeroConta, saldoInicial);
  Conta *contaPtr = novaConta.get();

  contas.push_back(std::move(novaConta));

  std::cout << "Conta " << numeroConta << " aberta para o cliente " << this->nome << ".\n";

  return contaPtr;
}

std::string Cliente::getNome() const
{
  return nome;
}

std::string Cliente::getCpf() const
{
  return cpf;
}