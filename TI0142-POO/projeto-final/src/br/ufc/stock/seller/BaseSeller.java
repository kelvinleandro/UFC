package br.ufc.stock.seller;

import br.ufc.stock.Item;
import br.ufc.stock.exception.InsufficientAmountStockException;
import br.ufc.stock.exception.NegativeAmountException;
import br.ufc.stock.request.Request;
import br.ufc.stock.Stock;
import br.ufc.stock.sale.Sale;
import br.ufc.stock.seller.exception.CreditRequestException;
import br.ufc.stock.seller.exception.SellerNegativeAmountException;
import br.ufc.store.StoreRequester;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDate;

public abstract class BaseSeller implements Seller, Serializable {
    protected Stock stock;
    protected BigDecimal price;
    protected StoreRequester requester;

    public Sale sell(int amount) throws SellerNegativeAmountException, NegativeAmountException, InsufficientAmountStockException {
        if (amount < 0) {
            throw new SellerNegativeAmountException(amount);
        }

        BigDecimal totalPrice = this.price(amount);
        stock.decreaseAmount(amount);
        this.requester.credit(totalPrice);


        return new Sale(
                this.getItemType(),
                amount,
                totalPrice,
                LocalDate.now()
        );
    }

    public abstract BigDecimal price(int amount) throws SellerNegativeAmountException;

    @Override
    public Item getItemType() {
        return this.stock.getItemType();
    }

    @Override
    public boolean equals(Object o) {
        boolean sameInstansce = this.getClass().equals(o.getClass());
        return ((Seller) o).getItemType().equals(this.getItemType()) && sameInstansce;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }

    public abstract String toString();
}
