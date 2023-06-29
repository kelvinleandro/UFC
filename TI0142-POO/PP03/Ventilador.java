public class Ventilador {
  private boolean ligado;
  private int velocidade;
  private boolean rotacaoHabilitada;

  public Ventilador() {
    this.ligado = false;
    this.rotacaoHabilitada = false;
    this.velocidade = 0;
  }

  public void setLigado() {
    if (ligado)
      this.velocidade = 0;
    else
      this.velocidade = 1;
    ligado = !ligado;
  }

  public void aumentaVelocidade() {
    if (ligado && this.velocidade < 5)
      velocidade++;
  }

  public void diminuiVelocidade() {
    if (ligado && this.velocidade > 1)
      velocidade--;
  }

  public void setRotacaoHabilitada() {
    rotacaoHabilitada = !rotacaoHabilitada;
  }

  public boolean getLigado() {
    return this.ligado;
  }

  public int getVelocidade() {
    return this.velocidade;
  }

  public boolean getRotacaoHabilitada() {
    return this.rotacaoHabilitada;
  }
}