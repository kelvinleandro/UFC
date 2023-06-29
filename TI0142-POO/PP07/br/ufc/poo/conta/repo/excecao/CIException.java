package br.ufc.poo.conta.repo.excecao;

public class CIException extends Exception {
  private String numero;

  public CIException(String numero) {
    super("Conta " + numero + " nao existe no repositorio");
    this.numero = numero;
  }

  public String getNumero() {
    return numero;
  }
}