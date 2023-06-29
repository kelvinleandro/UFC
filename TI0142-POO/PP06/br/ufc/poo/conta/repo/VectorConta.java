package br.ufc.poo.conta.repo;

import br.ufc.poo.conta.ContaAbstrata;

import java.util.Vector;

public class VectorConta implements IRepositorioConta {
  private Vector<ContaAbstrata> contas;

  public VectorConta() {
    this.contas = new Vector<ContaAbstrata>();
  }

  public void inserir(ContaAbstrata conta) {
    if (conta != null && !this.existe(conta.getNumero())) {
      contas.add(conta);
    }
  }

  public void remover(String numero) {
    if (numero != null && this.existe(numero)) {
      contas.remove(this.procurar(numero));
    }
  }

  public ContaAbstrata procurar(String numero) {
    for (ContaAbstrata conta : this.contas) {
      if (conta.getNumero().equals(numero)) {
        return conta;
      }
    }
    return null;
  }

  public boolean existe(String numero) {
    return this.procurar(numero) != null;
  }

  public ContaAbstrata[] listar() {
    // TODO
    return this.contas.toArray(new ContaAbstrata[contas.size()]);
  }

  public int tamanho() {
    return this.contas.size();
  }
}