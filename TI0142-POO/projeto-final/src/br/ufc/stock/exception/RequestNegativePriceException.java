package br.ufc.stock.exception;

import java.math.BigDecimal;

public class RequestNegativePriceException extends RuntimeException{
    private BigDecimal price;
    public RequestNegativePriceException(BigDecimal price){
        this.price = price;
    }

    @Override
    public String getMessage() {
        return String.format("Request should not have negative values as total price: %s", price.toString());
    }
}
