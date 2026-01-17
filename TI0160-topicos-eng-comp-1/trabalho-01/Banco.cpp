#include "Banco.h"
#include <iostream>
#include <algorithm>

Banco::Banco(const std::string &nome) : nome(nome) {}

void Banco::adicionarCliente(const std::string &nome, const std::string &cpf)
{
  auto novoCliente = std::make_unique<Cliente>(nome, cpf);
  clientes.push_back(std::move(novoCliente));

  std::cout << "Cliente " << nome << " adicionado ao banco.\n";
}

Conta *Banco::abrirConta(const std::string &cpfCliente, int numeroConta, double saldoInicial)
{
  if (contas.count(numeroConta))
  {
    std::cout << "Erro: O número de conta " << numeroConta << " já existe.\n";
    return nullptr;
  }

  Cliente *cliente = buscarCliente(cpfCliente);
  if (!cliente)
  {
    std::cout << "Erro: Cliente com CPF " << cpfCliente << " não encontrado.\n";
    return nullptr;
  }

  Conta *novaContaPtr = cliente->adicionarConta(numeroConta, saldoInicial);

  if (novaContaPtr)
  {
    this->contas[numeroConta] = novaContaPtr;
    std::cout << "Conta " << numeroConta << " registrada com sucesso no sistema do banco.\n";
  }

  return novaContaPtr;
}

Cliente *Banco::buscarCliente(const std::string &cpf)
{
  auto it = std::find_if(clientes.begin(), clientes.end(),
                         [&](const std::unique_ptr<Cliente> &c)
                         {
                           return c->getCpf() == cpf;
                         });

  if (it != clientes.end())
  {
    return it->get();
  }
  return nullptr;
}

Conta *Banco::buscarConta(int numeroConta)
{
  auto it = contas.find(numeroConta);
  if (it != contas.end())
  {
    return it->second;
  }
  return nullptr;
}

bool Banco::transferir(int numContaOrigem, int numContaDestino, double valor)
{
  Conta *origem = buscarConta(numContaOrigem);
  Conta *destino = buscarConta(numContaDestino);

  if (!origem || !destino)
  {
    std::cout << "Erro: Uma ou ambas as contas não existem.\n";
    return false;
  }

  if (valor <= 0)
  {
    std::cout << "Erro: O valor da transferência deve ser positivo.\n";
    return false;
  }

  std::cout << "\n--- Tentando transferir R$ " << valor << " da conta " << numContaOrigem << " para " << numContaDestino << " ---\n";

  if (origem->sacar(valor))
  {
    destino->depositar(valor);
    std::cout << "--- Transferência concluída com sucesso! ---\n";
    return true;
  }
  else
  {
    std::cout << "--- Transferência falhou. Saldo insuficiente na conta de origem. ---\n";
    return false;
  }
}