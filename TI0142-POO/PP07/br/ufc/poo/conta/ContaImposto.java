package br.ufc.poo.conta;

import br.ufc.poo.conta.excecao.*;

public class ContaImposto extends ContaAbstrata {
  private double taxa = 0.001;

  public ContaImposto(String numero) {
    super(numero);
  }

  public void debitar(double valor) throws SIException, VNException {
    if (valor >= 0.0) {
      double valorAcrescidoTaxa = (valor + (valor * this.taxa));
      if (this.saldo < valorAcrescidoTaxa) {
        throw new SIException(valor, numero);
      }
      this.saldo = this.saldo - valorAcrescidoTaxa;
    } else {
      throw new VNException(numero, valor);
    }
  }

  public double getTaxa() {
    return this.taxa;
  }

  public void setTaxa(double taxa) throws TNIException {
    if (taxa < 0.0) {
      throw new TNIException(numero, taxa);
    }
    this.taxa = taxa;
  }
}