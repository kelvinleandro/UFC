/**
 * The StockManager class manages a collection of stocks.
 * It allows registering and retrieving stocks based on different criteria.
 */
package br.ufc.stock.manager;

import br.ufc.stock.Item;
import br.ufc.stock.Stock;
import br.ufc.stock.exception.NegativeAmountException;
import br.ufc.stock.exception.StockAlreadyExistsException;

import java.io.Serializable;
import java.util.List;
import java.util.Optional;
import java.util.Vector;

public class StockManager implements Serializable {
    private Vector<Stock> stocksVector;

    public StockManager() {
        stocksVector = new Vector<>();
    }

    public void registerByStock(Stock stock) throws StockAlreadyExistsException {
        if(stocksVector.contains(stock)){
            throw new StockAlreadyExistsException(stock);
        }
        stocksVector.add(stock);
    }
    public void registerByItem(Stock stock) throws StockAlreadyExistsException {
        Optional<Stock> existingStock = get(stock.getItemType());

        if (existingStock.isPresent()) {
            throw new StockAlreadyExistsException(existingStock.get());
        }

        stocksVector.add(stock);
    }
    public Optional<Stock> get(Item item){
        for (Stock stock : stocksVector) {
            if (stock.containsItem(item)) {
                return Optional.of(stock);
            }
        }
        return Optional.empty();
    }
    public Vector<Stock> getStocks() {
        return stocksVector;
    }
    public Optional<Stock> getByIndex(int index){
        return Optional.ofNullable(stocksVector.get(index));
    }
}

