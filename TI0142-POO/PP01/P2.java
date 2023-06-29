import java.util.Scanner;

public class P2 {

  public void run() {
    // escreva o código da resposta aqui.
    Scanner scan = new Scanner(System.in);
    float n1, n2;
    String op;
    n1 = scan.nextFloat();
    n2 = scan.nextFloat();
    op = scan.next();

    if (op.equals("+"))
      System.out.println(n1 + n2);
    else if (op.equals("-"))
      System.out.println(n1 - n2);
    else if (op.equals("*"))
      System.out.println(n1 * n2);
    else if (op.equals("/"))
      System.out.println(n1 / n2);
  }

}