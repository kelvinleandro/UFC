#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Cliente.h"
#include "Conta.h"

class Banco
{
private:
  std::string nome;
  std::vector<std::unique_ptr<Cliente>> clientes;
  std::map<int, Conta *> contas;

public:
  Banco(const std::string &nome);

  Conta *abrirConta(const std::string &cpfCliente, int numeroConta, double saldoInicial);
  Conta *buscarConta(int numeroConta);

  void adicionarCliente(const std::string &nome, const std::string &cpf);
  Cliente *buscarCliente(const std::string &cpf);

  bool transferir(int numContaOrigem, int numContaDestino, double valor);
};

#endif // BANCO_H