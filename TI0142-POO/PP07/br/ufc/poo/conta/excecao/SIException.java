package br.ufc.poo.conta.excecao;

public class SIException extends Exception {
  private double saldo;
  private String numero;

  public SIException(double saldo, String numero) {
    super("Saldo Insuficiente na conta " + numero);
    this.saldo = saldo;
    this.numero = numero;
  }

  public double getSaldo() {
    return saldo;
  }

  public String getNumero() {
    return numero;
  }
}