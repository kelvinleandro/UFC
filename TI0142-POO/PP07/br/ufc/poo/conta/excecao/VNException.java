package br.ufc.poo.conta.excecao;

public class VNException extends Exception {
  private String numero;
  private double valor;

  public VNException(String numero, double valor) {
    super("Erro na operacao com a conta " + numero + ": valor negativo na operacao");
    this.valor = valor;
    this.numero = numero;
  }

  public double getValor() {
    return valor;
  }

  public String getNumero() {
    return numero;
  }
}