package br.ufc.poo.conta.repo;

import br.ufc.poo.conta.ContaAbstrata;
import br.ufc.poo.conta.repo.excecao.*;

import java.util.Vector;

public class VectorConta implements IRepositorioConta {
  private Vector<ContaAbstrata> contas;

  public VectorConta() {
    this.contas = new Vector<ContaAbstrata>();
  }

  public void inserir(ContaAbstrata conta) throws CEException {
    if (this.existe(conta.getNumero())) {
      throw new CEException(conta.getNumero());
    }

    if(conta != null){
      this.contas.add(conta);
    }
  }

  public void remover(String numero) throws CIException {
    if (!this.existe(numero)) {
      throw new CIException(numero);
    }

    this.contas.remove(this.procurar(numero));
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
    return this.contas.toArray(new ContaAbstrata[contas.size()]);
  }

  public int tamanho() {
    return this.contas.size();
  }
}