public class ContaImposto extends ContaAbstrata {
  private double taxa = 0.001;

  public ContaImposto(String numero) {
    super(numero);
  }

  public void debitar(double valor) {
    if (valor >= 0 && (valor + (valor * this.taxa) <= saldo))
      this.saldo -= (valor + (valor * this.taxa));
  }

  public double getTaxa() {
    return this.taxa;
  }

  public void setTaxa(double valor) {
    if (taxa >= 0)
      this.taxa = valor;
  }
}