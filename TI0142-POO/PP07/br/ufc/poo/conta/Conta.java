package br.ufc.poo.conta;

import br.ufc.poo.conta.excecao.*;

public class Conta extends ContaAbstrata {

  public Conta(String numero) {
    super(numero);
  }

  public void debitar(double valor) throws SIException, VNException {
    if (valor < 0) {
      throw new VNException(numero, valor);
    }

    if (this.saldo < valor) {
      throw new SIException(valor, numero);
    }
    this.saldo = this.saldo - valor;
  }
}