import java.util.Scanner;

public class P4 {

  public void run() {
    // escreva o código da resposta aqui.
    Scanner scan = new Scanner(System.in);
    double a, b, c, delta, x1 = 0d, x2 = 0d;
    a = scan.nextDouble();
    b = scan.nextDouble();
    c = scan.nextDouble();
    delta = Math.pow(b, 2) - (4 * a * c);

    if (delta < 0)
      System.out.println("nao existe raiz real");
    else {
      x1 = (-b + Math.sqrt(delta)) / (2 * a);
      x2 = (-b - Math.sqrt(delta)) / (2 * a);
      System.out.println("X1 = " + x1);
      System.out.println("X2 = " + x2);
    }

  }

}