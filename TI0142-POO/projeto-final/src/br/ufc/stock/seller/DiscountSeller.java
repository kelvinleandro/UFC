package br.ufc.stock.seller;

import br.ufc.stock.Stock;
import br.ufc.stock.seller.exception.SellerNegativeAmountException;
import br.ufc.store.StoreRequester;

import java.io.Serializable;
import java.math.BigDecimal;


public class DiscountSeller extends BaseSeller implements Serializable {

    public DiscountSeller(Stock stock, BigDecimal price, StoreRequester requester) {
        this.stock = stock;
        this.price = price;
        this.requester = requester;
    }

    @Override
    public BigDecimal price(int amount) throws SellerNegativeAmountException {
        if (amount < 0) {
            throw new SellerNegativeAmountException(amount);
        }

        BigDecimal discount = BigDecimal.ZERO;
        if (amount >= 30) {
            discount = new BigDecimal("0.3");
        } else if (amount >= 20) {
            discount = new BigDecimal("0.2");
        } else if (amount >= 10) {
            discount = new BigDecimal("0.1");
        }

        return this.price.multiply(new BigDecimal(amount))
                .multiply(BigDecimal.ONE.add(discount));
    }

    public String toString() {
        return String.format("Seller com desconto do estoque de %s de preço base R$%s",stock.getItemName(),MoneyConverter.convertBigDecimal(super.getPrice()));
    }
}
