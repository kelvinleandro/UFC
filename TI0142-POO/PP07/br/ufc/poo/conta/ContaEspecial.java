package br.ufc.poo.conta;

import br.ufc.poo.conta.excecao.VNException;
import br.ufc.poo.conta.excecao.PNBException;

public class ContaEspecial extends Conta {
  private double bonus;
  private double percentagem = 0.01;

  public ContaEspecial(String numero) {
    super(numero);
    this.bonus = 0.0;
  }

  public void renderBonus() throws VNException {
    super.creditar(this.bonus);
    this.bonus = 0.0;
  }

  public void creditar(double valor) throws VNException {
    if (valor < 0) {
      throw new VNException(numero, valor);
    }
    this.bonus = this.bonus + (valor * this.percentagem);
    super.creditar(valor);
  }

  public double getBonus() {
    return this.bonus;
  }

  public double getBonusPercentagem() {
    return this.percentagem;
  }

  public void setBonusPercentagem(double percentagem) throws PNBException {
    if (percentagem < 0) {
      throw new PNBException(numero, percentagem);
    }
    this.percentagem = percentagem;
  }
}