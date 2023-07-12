package br.ufc.store;

import br.ufc.stock.ItemManager;
import br.ufc.stock.manager.StockManager;
import br.ufc.stock.sale.Sale;
import br.ufc.stock.seller.manager.SellerManager;
import br.ufc.store.Exception.NegativeValueException;
import br.ufc.store.Exception.NotEnoughCash;
import br.ufc.user.VendorManager;
import br.ufc.user.VendorUser;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Optional;
import java.util.Vector;

public class Store implements Serializable {
    private Vector<Sale> sales;
    private BigDecimal cash;
    private ItemManager itemManager;
    private StockManager stockManager;
    private SellerManager sellerManager;
    private VendorManager vendorManager;
    private VendorUser activeUser;
    private StoreRequester storeRequester;



    public Store(BigDecimal money){
        sales = new Vector<Sale>();
        cash = money;
        vendorManager = new VendorManager();
        itemManager = new ItemManager();
        stockManager = new StockManager();
        storeRequester = new StoreRequester(this);
        sellerManager = new SellerManager();
    }
    public void setVendor(VendorUser user){
        activeUser = user;
    }
    public VendorManager getVendorManager(){
        return vendorManager;
    }
    public ItemManager getItemMananger(){
        return itemManager;
    }
    public void debit(BigDecimal value) throws NegativeValueException,NotEnoughCash{
        if(value.compareTo(BigDecimal.valueOf(0)) == -1){
            throw new NegativeValueException();
        }
        else if(cash.compareTo(value)>=0){
            cash = cash.subtract(value);
        }
        else{
            throw new NotEnoughCash(value.subtract(cash));
        }

    }

    public void credit(BigDecimal value) {
        cash = cash.add(value);
    }


    public VendorUser getActiveUser() {
        return activeUser;
    }

    public BigDecimal getCash() {
        return cash;
    }

    public void registerSale(Sale sale){sales.add(sale);}
    public Optional<Sale> getLastTransaction() {
        if(sales.isEmpty())
            return Optional.ofNullable(null);
        return Optional.ofNullable(sales.lastElement());
    }

    public StockManager getStockManager() {
        return stockManager;
    }

    public StoreRequester getStoreRequester() {
        return storeRequester;
    }

    public SellerManager getSellerManager(){return sellerManager;}
}