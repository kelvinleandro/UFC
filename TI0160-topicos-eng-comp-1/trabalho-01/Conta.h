#ifndef CONTA_H
#define CONTA_H

class Conta
{
private:
  int numeroConta;
  double saldo;

public:
  Conta(int numero, double saldoInicial);

  void depositar(double valor);
  bool sacar(double valor);

  double getSaldo() const;
  int getNumeroConta() const;
};

#endif // CONTA_H