package br.ufc.poo.banco;

import br.ufc.poo.conta.ContaAbstrata;
import br.ufc.poo.conta.ContaEspecial;
import br.ufc.poo.conta.ContaImposto;
import br.ufc.poo.conta.ContaPoupanca;

import br.ufc.poo.conta.repo.IRepositorioConta;

public class BancoIndependente implements IBanco, IAuditavel {
  private IRepositorioConta repositorio;
  private double taxaPoupanca = 0.01;
  private double taxaImposto = 0.01;
  private double bonusPercentagem = 0.01;

  public BancoIndependente(IRepositorioConta repositorio) {
    this.repositorio = repositorio;
  }

  public double saldoTotal() {
    ContaAbstrata[] lista = this.repositorio.listar();
    double saldo = 0.0;
    for (ContaAbstrata conta : lista) {
      saldo += conta.getSaldo();
    }
    return saldo;
  }

  public int numeroContas() {
    // TODO
    return this.repositorio.tamanho();
  }

  public void cadastrar(ContaAbstrata conta) {
    if (conta != null && !this.repositorio.existe(conta.getNumero())) {
      this.repositorio.inserir(conta);
      if (conta instanceof ContaImposto)
        ((ContaImposto) conta).setTaxa(this.taxaImposto);
    }
  }

  public void fechar(String numero) {
    // TODO
    if (this.repositorio.existe(numero))
      repositorio.remover(numero);
  }

  public void creditar(String numero, double valor) {
    // TODO
    if (this.repositorio.existe(numero))
      repositorio.procurar(numero).creditar(valor);
  }

  public void debitar(String numero, double valor) {
    // TODO
    if (this.repositorio.existe(numero))
      repositorio.procurar(numero).debitar(valor);
  }

  public double saldo(String numero) {
    // TODO
    if (this.repositorio.existe(numero))
      return repositorio.procurar(numero).getSaldo();

    return -1;
  }

  public void transferir(String origem, String destino, double valor) {
    ContaAbstrata contaOrigem = this.repositorio.procurar(origem);
    if (contaOrigem != null) {
      ContaAbstrata contaDestino = this.repositorio.procurar(destino);
      if (contaDestino != null) {
        double saldoAntigo = contaOrigem.getSaldo();
        contaOrigem.debitar(valor);
        if (contaOrigem.getSaldo() <= saldoAntigo - valor)
          contaDestino.creditar(valor);
      } else {
        System.out.println("Conta Destino nº " + destino + " Inexistente!");
      }
    } else {
      System.out.println("Conta Origem nº " + origem + " Inexistente!");
    }
  }

  public void renderJuros(String numero) {
    ContaAbstrata conta = this.repositorio.procurar(numero);
    if (conta != null) {
      if (conta instanceof ContaPoupanca) {
        ((ContaPoupanca) conta).renderJuros(this.taxaPoupanca);
      } else {
        System.out.println("Esta não é uma Conta Poupança!");
      }
    } else {
      System.out.println("Conta Inexistente!");
    }
  }

  public void renderBonus(String numero) {
    ContaAbstrata conta = this.repositorio.procurar(numero);
    if (conta != null) {
      if (conta instanceof ContaEspecial) {
        ((ContaEspecial) conta).renderBonus();
      } else {
        System.out.println("Esta não é uma Conta Especial!");
      }
    } else {
      System.out.println("Conta Inexistente!");
    }
  }

  public void setTaxaPoupanca(double valor) {
    this.taxaPoupanca = valor;
  }

  public double getTaxaPoupanca() {
    return this.taxaPoupanca;
  }

  public void setTaxaImposto(double valor) {
    // TODO
    if (valor >= 0)
      this.taxaImposto = valor;
  }

  public double getTaxaImposto() {
    return this.taxaImposto;
  }

  public void setBonusPercentagemGeral(double valor) {
    this.bonusPercentagem = valor;
    for (ContaAbstrata conta : this.repositorio.listar()) {
      if (conta instanceof ContaEspecial) {
        ((ContaEspecial) conta).setBonusPercentagem(this.bonusPercentagem);
      }
    }
  }

  public double getBonusPercentagemGeral() {
    return this.bonusPercentagem;
  }

  public void setBonusPercentagemConta(String numero, double valor) {
    // TODO
    if (this.repositorio.existe(numero)) {
      ContaAbstrata conta = repositorio.procurar(numero);
      if (conta instanceof ContaEspecial) {
        ((ContaEspecial) conta).setBonusPercentagem(valor);
      }
    }
  }

  public double getBonusPercentagemConta(String numero) {
    // TODO
    if (this.repositorio.existe(numero)) {
      ContaAbstrata conta = repositorio.procurar(numero);
      if (conta instanceof ContaEspecial)
        return ((ContaEspecial) conta).getBonusPercentagem();
    }

    return -1;
  }
}