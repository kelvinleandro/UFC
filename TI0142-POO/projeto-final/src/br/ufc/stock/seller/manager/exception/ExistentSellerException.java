package br.ufc.stock.seller.manager.exception;

import br.ufc.stock.seller.Seller;

public class ExistentSellerException extends Exception{
    Seller seller;
    public ExistentSellerException(Seller seller){
        this.seller = seller;
    }

    @Override
    public String getMessage() {
        return String.format("Existent seller on seller manager: %s", seller.toString());
    }
}
