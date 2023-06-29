public class Calculadora {

  public Calculadora() {
  
  }
  
  public double adicionar(double operandoA, double operandoB) {
    return operandoA + operandoB;
  }
  
  public double subtrair(double operandoA, double operandoB) {
    return operandoA - operandoB;
  }
  
  public double multiplicar(double operandoA, double operandoB) {
    return operandoA * operandoB;
  }
  
  public double dividir(double operandoA, double operandoB) {
    return operandoA / operandoB;
  }
  
  public double potencia(double base, int expoente) {
    return Math.pow(base,expoente);
  }
  
  public double raiz(double valor) {
    return Math.sqrt(valor);
  }
  
  public double seno(double angulo) {
    return Math.sin(angulo);
  }
  
  public double cosseno(double angulo) {
    return Math.cos(angulo);
  }
  
  public double tangente(double angulo) {
    return Math.tan(angulo);
  }
}