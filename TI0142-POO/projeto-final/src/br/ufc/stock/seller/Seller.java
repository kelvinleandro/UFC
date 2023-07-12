package br.ufc.stock.seller;

import br.ufc.stock.Item;
import br.ufc.stock.exception.InsufficientAmountStockException;
import br.ufc.stock.exception.NegativeAmountException;
import br.ufc.stock.sale.Sale;
import br.ufc.stock.seller.exception.SellerNegativeAmountException;

import java.io.Serializable;
import java.math.BigDecimal;


public interface Seller {

    Sale sell(int amount) throws SellerNegativeAmountException, NegativeAmountException, InsufficientAmountStockException;
    BigDecimal price(int amount) throws SellerNegativeAmountException;
    Item getItemType();



}
