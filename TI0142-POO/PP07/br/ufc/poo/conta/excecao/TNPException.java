package br.ufc.poo.conta.excecao;

public class TNPException extends Exception {
  private String numero;
  private double taxa;

  public TNPException(String numero, double taxa) {
    super("Erro na operacao com a conta poupanca " + numero + ": taxa negativa " + taxa);
    this.taxa = taxa;
    this.numero = numero;
  }

  public double getTaxa() {
    return taxa;
  }

  public String getNumero() {
    return numero;
  }
}