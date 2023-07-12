package br.ufc.stock.request;

import br.ufc.stock.Stock;
import br.ufc.stock.exception.NegativeAmountException;

import java.io.Serializable;

public class ConcludeRestock implements Concludable, Serializable {
    private Stock stock;
    private int amount;
    public ConcludeRestock(Stock stock, int amount) throws NegativeAmountException {
        this.stock = stock;
        if(amount < 0){
            throw new NegativeAmountException(amount);
        }
        this.amount = amount;
    }
    @Override
    public void conclude() {
        try{
            this.stock.increaseAmount(amount);
        }catch(NegativeAmountException nae){
            System.out.println(nae.getMessage());
            System.out.println(nae.getStackTrace());
            System.out.println("This should not happen in any case. Problem in the logic of the program at ConcludeRestock class.");
        }
    }
}
