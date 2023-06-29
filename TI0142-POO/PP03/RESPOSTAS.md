# Classe
Ventilador

## Atributos

- boolean ligado
- int velocidade
- boolean rotacaoHabilitada

## Métodos

- void setLigado()
- void aumentaVelocidade()
- void diminuiVelocidade()
- void setRotacaoAtivada()
- boolean getLigado()
- int getVelocidade()
- boolean getRotacaoHabilitada()

## Alternativas de implementação
### setLigado() - Fácil
Se é true recebe false, e vice-versa
### aumentaVelocidade() - Fácil
Incrementa em 1 a velocidade
### diminuiVelocidade() - Fácil
Decrementa em 1 a velocidade
### setRotacaoAtivada() - Fácil
Se é true recebe false, e vice-versa
### getLigado(), getVelocidade() e getRotacaoHabilitada() - Fácil
Retorna o valor do atributo

## Stubs

```
public class Ventilador{
  private boolean ligado;
  private int velocidade;
  private boolean rotacaoHabilitada;

  public Ventilador(){
    this.ligado = false;
    this.rotacaoHabilitada = false;
    this.velocidade = 1;
  }

  public void setLigado(){
    return;
  }

  public void aumentaVelocidade(){
    return;
  }

  public void diminuiVelocidade(){
    return;
  }

  public void setRotacaoHabilitada(){
    return;
  }

  public boolean getLigado(){
    return false;
  }

  public int getVelocidade(){
    return 0;
  }

  public boolean getRotacaoHabilitada(){
    return false;
  }
}
```