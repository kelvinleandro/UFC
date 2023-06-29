package br.ufc.poo.conta.excecao;

public class TNIException extends Exception {
  private String numero;
  private double taxa;

  public TNIException(String numero, double taxa) {
    super("Erro na operacao com a conta imposto " + numero + ": taxa negativa = " + taxa);
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