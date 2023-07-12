/**
 * pedrofalcao10
 * The NegativeBuyPriceException class represents an exception that is thrown
 * when a negative buy price is provided where it is not permitted.
 */
package br.ufc.stock.exception;

import java.math.BigDecimal;

public class NegativeBuyPriceException extends Exception {
    private BigDecimal buyPrice;
    public NegativeBuyPriceException(BigDecimal buyPrice) {
        super("Negative buy price: " + buyPrice + " isn't permitted.");
        this.buyPrice = buyPrice;
    }
    public BigDecimal getBuyPrice() {
        return buyPrice;
    }
}

