import java.util.Vector;

public class BancoVector {
  private Vector<Conta> contas;
  private double taxaPoupanca = 0.01;
  private double bonusPercentagem = 0.01;

  public BancoVector() {
    contas = new Vector<Conta>();
  }

  public void cadastrar(Conta conta) {
    if (existe(conta.getNumero()))
      return;
    contas.add(conta);
    if (conta instanceof ContaEspecial)
      ((ContaEspecial) conta).setBonusPercentagem(bonusPercentagem);
  }

  private Conta procurar(String numero) {
    for (int i = 0; i < contas.size(); i++) {
      if (contas.get(i).getNumero().equals(numero)) {
        return contas.get(i);
      }
    }
    return null;
  }

  public boolean existe(String numero) {
    return procurar(numero) != null;
  }

  public void creditar(String numero, double valor) {
    Conta conta = procurar(numero);
    if (conta != null) {
      conta.creditar(valor);
    } else {
      System.out.println("Conta Inexistente!");
    }
  }

  public void debitar(String numero, double valor) {
    Conta conta = procurar(numero);
    if (conta != null) {
      conta.debitar(valor);
    } else {
      System.out.println("Conta Inexistente!");
    }
  }

  public double saldo(String numero) {
    Conta conta = procurar(numero);
    if (conta != null) {
      return conta.getSaldo();
    } else {
      System.out.println("Conta Inexistente!");
    }
    return 0;
  }

  public void transferir(String origem, String destino, double valor) {
    Conta contaOrigem = procurar(origem);
    if (contaOrigem != null) {
      Conta contaDestino = procurar(destino);
      if (contaDestino != null) {
        if (contaOrigem.getSaldo() > valor) {
          contaOrigem.debitar(valor);
          contaDestino.creditar(valor);
        } else {
          System.out.println("Saldo Insuficiente!");
        }
      } else {
        System.out.println("Conta Destino nº " + destino + " Inexistente!");
      }
    } else {
      System.out.println("Conta Origem nº " + origem + " Inexistente!");
    }
  }

  public void renderJuros(String numero) {
    if (existe(numero)) {
      Conta conta = procurar(numero);
      ((ContaPoupanca) conta).renderJuros(taxaPoupanca);
    }
  }

  public void renderBonus(String numero) {
    if (existe(numero)) {
      Conta conta = procurar(numero);
      ((ContaEspecial) conta).renderBonus();
    }
  }

  public void setTaxaPoupanca(double valor) {
    this.taxaPoupanca = valor;
  }

  public double getTaxaPoupanca() {
    return this.taxaPoupanca;
  }

  public void setBonusPercentagem(double valor) {
    this.bonusPercentagem = valor;
    for (Conta conta : contas) {
      if (conta instanceof ContaEspecial)
        ((ContaEspecial) conta).setBonusPercentagem(valor);
    }
  }

  public double setBonusPercentagem() {
    return this.bonusPercentagem;
  }

  public int quantidade() {
    return this.contas.size();
  }
}