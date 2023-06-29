package br.ufc.poo.conta.repo.excecao;

public class CEException extends Exception {
  private String numero;

  public CEException(String numero) {
    super("Conta " + numero + " ja existe no repositorio");
    this.numero = numero;
  }

  public String getNumero() {
    return numero;
  }
}