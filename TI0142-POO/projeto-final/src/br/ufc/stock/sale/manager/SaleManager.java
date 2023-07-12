package br.ufc.stock.sale.manager;

import br.ufc.stock.sale.Sale;

import java.io.Serializable;
import java.util.List;
import java.util.Vector;
import java.util.Collections;

public class SaleManager implements Serializable {
    private Vector<Sale> sales;

    public SaleManager() {
        this.sales = new Vector<Sale>();
    }

    public void register(Sale sale) {
        if (!sales.contains(sale))
            sales.add(sale);
    }

    public List<Sale> getSales() {
        return Collections.unmodifiableList(sales);
    }
}
