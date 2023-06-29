import java.util.Scanner;

public class P3 {

  public void run() {
    // escreva o código da resposta aqui.
    Scanner scan = new Scanner(System.in);
    float n1, n2;
    String op;
    n1 = scan.nextFloat();
    n2 = scan.nextFloat();
    op = scan.next();
    switch(op){
      case "+":
        System.out.println(n1 + n2);
        break;
      
      case "-":
        System.out.println(n1 - n2);
        break;
      
      case "*":
        System.out.println(n1 * n2);
        break;
      
      case "/":
        System.out.println(n1 / n2);
        break;
      
      default:
        System.out.println("Opcao invalida");
    }
  }

}