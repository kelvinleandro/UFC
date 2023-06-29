public class VentiladorTeste {

  public void testeSetLigado(){
    Ventilador ventilador = new Ventilador();
    ventilador.setLigado();
    if(ventilador.getLigado() == true){
      System.out.println("passou");
    }
    else
      System.out.println("falhou");
  }

  public void testeAumentaVelocidade(){
    Ventilador ventilador = new Ventilador();
    ventilador.aumentaVelocidade();
    ventilador.setLigado();
    ventilador.aumentaVelocidade();
    ventilador.aumentaVelocidade();
    if(ventilador.getVelocidade() == 3){
      System.out.println("passou");
    }
    else
      System.out.println("falhou");
  }

  public void testeDiminuiVelocidade(){
    Ventilador ventilador = new Ventilador();
    ventilador.diminuiVelocidade();
    ventilador.setLigado();
    ventilador.aumentaVelocidade();
    ventilador.aumentaVelocidade();
    ventilador.diminuiVelocidade();
    if(ventilador.getVelocidade() == 2){
      System.out.println("passou");
    }
    else
      System.out.println("falhou");
  }

  public void testeSetRotacaoHabilitada(){
    Ventilador ventilador = new Ventilador();
    ventilador.setRotacaoHabilitada();
    if(ventilador.getRotacaoHabilitada() == true){
      System.out.println("passou");
    }
    else
      System.out.println("falhou");
  }

}