package br.ufc.store.Exception;

public class NegativeValueException extends Exception{
    public NegativeValueException(){
        super("Valor negativo.");
    }
}
