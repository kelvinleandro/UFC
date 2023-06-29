import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Escolha a opção desejada:\n 1) Testa Calculadora\n 2) Testa Conta \n 3) Testa Banco");
    int opcao = scanner.nextInt();
    switch (opcao) {
      case 1:
        testaCalculadora();
        break;

      case 2:
        testaConta();
        break;

      case 3:
        testaBanco();
        break;

      default:
        System.out.println("Opção inexistente!");
        break;
    }
  }

  public static void testaCalculadora() {
    // escreva o código de teste aqui
    Calculadora calculadora = new Calculadora();
    System.out.println(calculadora.adicionar(2, 3));
    System.out.println(calculadora.subtrair(5, 2));
    System.out.println(calculadora.multiplicar(2, 3));
    System.out.println(calculadora.dividir(12, 3));
    System.out.println(calculadora.potencia(2, 3));
    System.out.println(calculadora.raiz(7));
    System.out.println(calculadora.seno(Math.PI / 2));
    System.out.println(calculadora.cosseno(Math.PI / 2));
    System.out.println(calculadora.tangente(Math.PI / 4));
  }

  public static void testaConta() {
    // escreva o código de teste aqui
    Conta conta = new Conta("1234");
    conta.creditar(300);
    conta.debitar(100);
    System.out.println(conta.getSaldo());
    System.out.println(conta.getNumero());
  }

  public static void testaBanco() {
    // escreva o código de teste aqui
    Banco banco = new Banco();

    Conta conta1 = new Conta("1234");
    Conta conta2 = new Conta("5678");

    banco.cadastrar(conta1);
    banco.cadastrar(conta2);

    banco.creditar("1234", 300);
    banco.creditar("5678", 50);
    banco.debitar("1234", 100);
    banco.transferir("1234", "5678", 50);
    
    System.out.println(banco.saldo("1234"));
    System.out.println(banco.saldo("5678"));
  }

}