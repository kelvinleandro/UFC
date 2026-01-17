#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include <memory>
#include "Conta.h"

class Cliente
{
private:
  std::string nome;
  std::string cpf;
  std::vector<std::unique_ptr<Conta>> contas;

public:
  Cliente(const std::string &nome, const std::string &cpf);

  Conta *adicionarConta(int numeroConta, double saldoInicial);

  std::string getNome() const;
  std::string getCpf() const;
};

#endif // CLIENTE_H