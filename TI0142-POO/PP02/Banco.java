public class Banco {

  private Conta[] contas;
  private int indice = 0;

  public Banco() {
    this.contas = new Conta[100];
  }

  public void cadastrar(Conta conta) {
    contas[indice] = conta;
    indice++;
  }

  private Conta procurar(String numero) {
    int i = 0; 
    boolean achou = false;
  
    while ((!achou) && (i < indice)) {
      if (contas[i].getNumero().equals(numero)) { 
        achou = true;
      } else { 
        i++;
      }
    }

    if (achou == true)
      return contas[i];
    else 
      return null;

  }

  public void creditar(String numero, double valor) {
    Conta conta;
    conta = procurar(numero);
    if (conta != null) {
      conta.creditar(valor);
    } else {
      System.out.println("Conta Inexistente!");
    }
  }  

  public void debitar(String numero, double valor) {
    Conta conta;
    conta = procurar(numero);
    if (conta != null) {
      conta.debitar(valor);
    } else {
      System.out.println("Conta Inexistente!");
    }
  }
  
  public double saldo(String numero) {
    Conta conta;
    conta = procurar(numero);
    if (conta != null) {
      return conta.getSaldo();
    } else {
      System.out.println("Conta Inexistente!");
    }
    return -1;
  }

  public void transferir(String origem, String destino, double valor) {
    Conta contaOrigem, contaDestino;
    contaOrigem = procurar(origem);
    contaDestino = procurar(destino);
    if (contaOrigem != null && contaDestino != null && contaOrigem.getSaldo() >= valor) {
      contaOrigem.debitar(valor);
      contaDestino.creditar(valor);
    } else {
      System.out.println("Erro na operação!");
    }
  }
  
}