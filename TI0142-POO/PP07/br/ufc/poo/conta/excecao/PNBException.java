package br.ufc.poo.conta.excecao;

public class PNBException extends Exception {
  private String numero;
  private double percentagem;

  public PNBException(String numero, double percentagem) {
    super("Erro na operacao com a conta especial " + numero + ": percentagem negativa = " + percentagem);
    this.percentagem = percentagem;
    this.numero = numero;
  }

  public double getPercentagem() {
    return percentagem;
  }

  public String getNumero() {
    return numero;
  }
}