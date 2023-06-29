import br.ufc.poo.conta.ContaAbstrata;
import br.ufc.poo.conta.Conta;
import br.ufc.poo.conta.ContaPoupanca;
import br.ufc.poo.conta.ContaEspecial;
import br.ufc.poo.conta.ContaImposto;
import br.ufc.poo.conta.excecao.*;

import br.ufc.poo.conta.repo.excecao.*;
import br.ufc.poo.conta.repo.VectorConta;

import br.ufc.poo.banco.excecao.*;
import br.ufc.poo.banco.BancoIndependente;

public class Main {
  public static void main(String[] args) {
    // testaPasso1();
    // testaPasso2();
    // testaPasso3();
    // testaPasso4();
    // testaPasso5();
    // testaPasso6();
    // testaPasso7();
    testaPasso8();
  }

  public static void testaPasso1() {
    Conta conta = new Conta("123");
    try {
      conta.creditar(50);
      conta.debitar(70);
    } catch (SIException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso2() {
    // TODO
    Conta conta = new Conta("123");
    try {
      conta.creditar(50);
      conta.debitar(-30);
      // } catch (VNException e) {
      // e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso3() {
    // TODO
    ContaPoupanca conta = new ContaPoupanca("123");
    try {
      conta.creditar(50);
      conta.renderJuros(-0.03);
    } catch (TNPException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso4() {
    // TODO
    ContaEspecial conta = new ContaEspecial("123");
    try {
      conta.creditar(50);
      conta.setBonusPercentagem(-0.03);
    } catch (PNBException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso5() {
    // TODO
    ContaImposto conta = new ContaImposto("123");
    try {
      conta.creditar(50);
      conta.setTaxa(-0.03);
    } catch (TNIException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso6() {
    // TODO
    VectorConta contas = new VectorConta();
    Conta conta = new Conta("123");
    try {
      contas.inserir(conta);
      contas.remover("456");
    } catch (CIException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso7() {
    // TODO
    VectorConta contas = new VectorConta();
    Conta conta1 = new Conta("123");
    Conta conta2 = new Conta("123");
    try {
      contas.inserir(conta1);
      contas.inserir(conta2);
    } catch (CEException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static void testaPasso8() {
    // TODO
    VectorConta contas = new VectorConta();
    Conta conta1 = new Conta("123");
    Conta conta2 = new Conta("456");

    try {
      BancoIndependente banco = new BancoIndependente(contas);
      banco.cadastrar(conta1);
      banco.cadastrar(conta2);
      banco.creditar("123", 10);
      banco.transferir("123", "456", -5);
    } catch (TIException e) {
      e.printStackTrace();
    } catch (Exception e) {
      e.printStackTrace();
    }
  }
}