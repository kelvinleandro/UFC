/**
 * pedrofalcao10
 * The Stock class represents a stock of items in a store.
 * It keeps track of the item type, amount, buy price, and requester.
 * It also provides methods for managing the stock, such as decreasing/increasing the amount and restocking.
 */
package br.ufc.stock;

import br.ufc.stock.exception.InsufficientAmountStockException;
import br.ufc.stock.exception.NegativeAmountException;
import br.ufc.stock.exception.NegativeBuyPriceException;
import br.ufc.stock.request.ConcludeRestock;
import br.ufc.stock.request.Request;
import br.ufc.store.StoreRequester;

import java.io.Serializable;
import java.math.BigDecimal;
import java.text.DecimalFormat;

public class Stock implements Serializable {
    private Item itemType;
    private int amount;
    private BigDecimal buyPrice;
    private StoreRequester requester;
    private int minimalAmount; // The red zone to restock the items
    private int defaultAmount; // The default amount of items in the stock

    public Stock(Item itemType, int amount, BigDecimal buyPrice, StoreRequester requester)
            throws NegativeAmountException, NegativeBuyPriceException {
        if (amount < 0) {
            throw new NegativeAmountException(amount);
        }

        if (buyPrice.compareTo(BigDecimal.ZERO) < 0) {
            throw new NegativeBuyPriceException(buyPrice);
        }

        this.itemType = itemType;
        this.buyPrice = buyPrice;
        this.requester = requester;
        this.restock(amount);
    }

    public void decreaseAmount(int amount) throws NegativeAmountException, InsufficientAmountStockException {
        if (amount < 0) {
            throw new NegativeAmountException(amount);
        }

        if (amount > this.amount) {
            throw new InsufficientAmountStockException(this.amount);
        }

        if (this.amount - amount > minimalAmount) {
            this.amount -= amount;
        } else {
            this.amount -= amount;
            restock(defaultAmount - this.amount);
        }
    }

    public void increaseAmount(int amount) throws NegativeAmountException {
        if (amount < 0) {
            throw new NegativeAmountException(amount);
        }
        this.amount += amount;
    }
    public void restock(int amount) throws NegativeAmountException {
        if (amount < 0) {
            throw new NegativeAmountException(amount);
        }
        Request req  = new Request(
                new ConcludeRestock(this, amount),
                this.priceToBuy(amount)
        );
        this.requester.debit(req);
    }

    public BigDecimal priceToBuy(int amount) throws NegativeAmountException{
        if(amount < 0){
            throw new NegativeAmountException(amount);
        }
        return this.buyPrice.multiply(BigDecimal.valueOf(amount));
    }

    public Item getItemType() { return itemType; }
    public String getItemName(){return itemType.getName();}

    public boolean containsItem(Item item) { return itemType.getName().equals(item.getName()); }


    public int getAmount() { return amount; }

    public boolean equals(Object o){
        return ((Stock)o)
                .getItemType()
                .getName()
                .equals(
                        this.getItemType()
                                .getName()
                );
    }

    public BigDecimal getBuyPrice() {
        return buyPrice;
    }

    @Override
    public String toString() {
        BigDecimal formattedValue = buyPrice.setScale(2, BigDecimal.ROUND_HALF_UP);
        DecimalFormat decimalFormat = new DecimalFormat("#,##0.00");
        String valorString = decimalFormat.format(formattedValue);

        return "Estoque de " + itemType.toString()
                + ", com quantidade atual de "
                + this.amount + ", e preco de restoque R$ "
                + valorString;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public void setBuyPrice(BigDecimal buyPrice) {
        this.buyPrice = buyPrice;
    }
}
