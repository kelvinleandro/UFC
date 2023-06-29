import java.util.Scanner;

public class P1 {

  public void run() {
    // escreva o código da resposta aqui.
    Scanner scan = new Scanner(System.in);
    int n1, n2;
    do{
      n1 = scan.nextInt();
      n2 = scan.nextInt();
    } while (n1 == n2);

    if(n1 > n2)
      System.out.println(n1);
    else
      System.out.println(n2);
  }

}