package br.ufc.stock.exception;

public class ItemAlreadyExists extends Exception{
    public ItemAlreadyExists(){
        super("O item já existe.");
    }
}
