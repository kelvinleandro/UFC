public class Conta {
  private String numero;
  private double saldo;

  public Conta(String numero) {
    this.numero = numero;
    this.saldo = 0;
  }

  public void creditar(double valor) {
    saldo += valor;
  }

  public void debitar(double valor) {
    saldo -= valor;
  }

  public String getNumero() {
    return this.numero;
  }

  public double getSaldo() {
    return this.saldo;
  }

}