package br.ufc.gui.CRUD;

import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.stock.Stock;
import br.ufc.stock.manager.StockManager;
import br.ufc.stock.seller.BaseSeller;
import br.ufc.stock.seller.CommonSeller;
import br.ufc.stock.seller.DiscountSeller;
import br.ufc.stock.seller.Seller;
import br.ufc.stock.seller.manager.SellerManager;
import br.ufc.store.StoreRequester;

import javax.swing.*;
import java.awt.*;
import java.math.BigDecimal;
import java.util.List;

public class CRUDSeller extends CRUDAbstract<Seller>{

    private StockManager stockManager;
    private SellerManager sellerManager;
    private StoreRequester storeRequester;

    public CRUDSeller(StockManager stockManager,SellerManager sellerManager, StoreRequester storeRequester){
        super();
        add(new JLabel("CRUD Seller"), BorderLayout.NORTH);
        this.stockManager = stockManager;
        this.sellerManager = sellerManager;
        this.storeRequester = storeRequester;
        loadElements();

    }
    public void addElement(){
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        JLabel priceLabel = new JLabel("Preço:");
        JTextField priceField = new JTextField();

        String[] options = {"Normal", "Desconto"};
        JComboBox<String> selectBox = new JComboBox<>(options);

        List<Stock> stockList = stockManager.getStocks(); // Obtém a lista de estoques do StockManager

        JList<String> stockSelector = new JList<>(stockList.stream()
                .map(Stock::getItemName)
                .toArray(String[]::new));

        panel.add(priceLabel);
        panel.add(priceField);
        panel.add(selectBox);
        panel.add(new JScrollPane(stockSelector));

        int option = JOptionPane.showOptionDialog(null, panel, "Criar Seller", JOptionPane.DEFAULT_OPTION,
                JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Adicionar", "Cancelar"}, null);

        if (option == 0) {
            BigDecimal price = new BigDecimal(priceField.getText());
            boolean isDiscount = selectBox.getSelectedItem().equals("Desconto");
            int selectedIndex = stockSelector.getSelectedIndex();
            if (selectedIndex != -1) {
                Stock selectedStock = stockList.get(selectedIndex);
                try {
                    BaseSeller seller;
                    if (!isDiscount) {
                        seller = new CommonSeller(selectedStock, price, storeRequester);
                    } else {
                        seller = new DiscountSeller(selectedStock, price, storeRequester);
                    }
                    sellerManager.register(seller);
                    listModel.addElement(seller.toString());
                } catch (Exception e) {
                    new ExceptionDialog(e);
                }
            }
        }
    }
    public void editElement(){
        // Obtém o índice do produto selecionado na lista
        int selectedIndex = elementList.getSelectedIndex();

        if (selectedIndex != -1) {
            BaseSeller sellerSearched = sellerManager.getByIndex(selectedIndex);
            String newPrice = JOptionPane.showInputDialog("Digite o novo preço do item:", sellerSearched.getPrice());

            if (newPrice != null) {

                sellerSearched.setPrice(new BigDecimal(newPrice));

                listModel.set(selectedIndex, sellerSearched.toString());
            }
        }

    }

    protected void loadElements() {
        List<BaseSeller> elems = this.sellerManager.getSellers();
        for (Seller current : elems) {
            listModel.addElement(current.toString());
        }
    }

}
