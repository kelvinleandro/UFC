package br.ufc.stock.seller.exception;

public class SellerNegativeAmountException extends Exception{
    private int amount;
    public SellerNegativeAmountException(int amount){
        this.amount = amount;
    }

    @Override
    public String getMessage() {
        return String.format("Negative value for amount: %d", amount);
    }
}
