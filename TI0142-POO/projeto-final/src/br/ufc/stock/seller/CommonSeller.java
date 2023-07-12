package br.ufc.stock.seller;

import br.ufc.stock.Stock;
import br.ufc.stock.seller.exception.SellerNegativeAmountException;
import br.ufc.store.StoreRequester;

import java.io.Serializable;
import java.math.BigDecimal;

public class CommonSeller extends BaseSeller implements Serializable {

    public CommonSeller(Stock stock, BigDecimal price, StoreRequester requester) {
        this.stock = stock;
        this.price = price;
        this.requester = requester;
    }

    @Override
    public BigDecimal price(int amount) throws SellerNegativeAmountException {
        if (amount < 0) {
            throw new SellerNegativeAmountException(amount);
        }
        return this.price.multiply(
                new BigDecimal(amount)
        );
    }

    @Override
    public String toString() {
        return String.format("Seller do estoque de %s de preço base R$ %s",stock.getItemName(),MoneyConverter.convertBigDecimal(super.getPrice()));
    }
}
