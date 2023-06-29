package br.ufc.poo.banco;

import br.ufc.poo.conta.ContaAbstrata;
import br.ufc.poo.conta.excecao.*;
import br.ufc.poo.conta.repo.excecao.*;
import br.ufc.poo.banco.excecao.TIException;

public interface IBanco {

  public void cadastrar(ContaAbstrata conta) throws PNBException, TNIException, CEException, CIException;

  public void fechar(String numero) throws CIException;

  public void creditar(String numero, double valor) throws VNException;

  public void debitar(String numero, double valor) throws SIException, VNException;

  public void transferir(String origem, String destino, double valor) throws TIException;

  public double saldo(String numero);

  public void renderJuros(String numero) throws VNException, TNPException;

  public void renderBonus(String numero) throws VNException;

  public void setTaxaPoupanca(double valor) throws TNPException;

  public double getTaxaPoupanca();

  public void setTaxaImposto(double valor) throws TNIException;

  public double getTaxaImposto();

  public void setBonusPercentagemGeral(double valor) throws PNBException;

  public double getBonusPercentagemGeral();

  public void setBonusPercentagemConta(String numero, double valor) throws PNBException;

  public double getBonusPercentagemConta(String numero);
}