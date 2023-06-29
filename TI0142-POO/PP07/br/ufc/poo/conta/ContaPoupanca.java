package br.ufc.poo.conta;

import br.ufc.poo.conta.excecao.VNException;
import br.ufc.poo.conta.excecao.TNPException;

public class ContaPoupanca extends Conta {

  public ContaPoupanca(String numero) {
    super(numero);
  }

  public void renderJuros(double taxa) throws VNException, TNPException {
    if (taxa < 0) {
      throw new TNPException(numero, taxa);
    }
    super.creditar(getSaldo() * taxa);
  }

}