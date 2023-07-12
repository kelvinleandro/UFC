package br.ufc.store.Exception;

import br.ufc.stock.seller.MoneyConverter;

import java.math.BigDecimal;

public class NotEnoughCash extends Exception{
    public NotEnoughCash(BigDecimal value){
        super("Faltam R$ "+ MoneyConverter.convertBigDecimal(value) +" para realizar essa transação");
    }
}
