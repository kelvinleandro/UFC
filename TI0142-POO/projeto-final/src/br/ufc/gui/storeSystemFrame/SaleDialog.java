package br.ufc.gui.storeSystemFrame;

import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.stock.sale.Sale;
import br.ufc.stock.seller.BaseSeller;
import br.ufc.stock.seller.MoneyConverter;
import br.ufc.stock.seller.Seller;
import br.ufc.stock.seller.manager.SellerManager;
import br.ufc.store.Store;
import br.ufc.user.VendorUser;

import javax.swing.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.util.List;

public class SaleDialog extends JPanel {
    SellerManager sellerManager;
    VendorUser vendorUser;
    JList<String> sellerSelector;
    JLabel priceLabel;
    JTextField amountField = new JTextField();

    public SaleDialog(Store store) {
        this.sellerManager = store.getSellerManager();
        this.vendorUser = store.getActiveUser();

        this.setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

        JLabel amountLabel = new JLabel("Amount:");

        priceLabel = new JLabel();
        priceLabel.setText("Price: R$ 00,00");

        List<BaseSeller> sellerList = sellerManager.getSellers();

        sellerSelector = new JList<>(sellerList.stream()
                                    .map(Seller::toString)
                                    .toArray(String[]::new));

        amountField.getDocument().addDocumentListener(new DocumentListener() {
            @Override
            public void insertUpdate(DocumentEvent e) {
                updatePrice();
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                updatePrice();
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                updatePrice();
            }


        });
        sellerSelector.addListSelectionListener(e -> updatePrice());

        this.add(amountLabel);
        this.add(amountField);
        this.add(new JScrollPane(sellerSelector));
        this.add(priceLabel);

        int option = JOptionPane.showOptionDialog(null, this, "Realizar Venda", JOptionPane.DEFAULT_OPTION,
                JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Vender", "Cancelar"}, null);

        if (option == 0) {
            int amount = Integer.parseInt(amountField.getText());
            int selectedIndex = sellerSelector.getSelectedIndex();
            if (selectedIndex != -1) {
                BaseSeller selectedSeller = sellerManager.getByIndex(selectedIndex);
                try {
                    Sale sale = selectedSeller.sell(amount);
                    vendorUser.registerSale(sale);
                    store.registerSale(sale);
                } catch (Exception e) {
                    new ExceptionDialog(e);
                }
            }
        }
    }
    void updatePrice() {
        int selectedIndex = sellerSelector.getSelectedIndex();
        try {
            int amount = Integer.parseInt(amountField.getText());
            priceLabel.setText(selectedIndex!=-1 ? "Price: "+ MoneyConverter.convertBigDecimal(sellerManager.getByIndex(selectedIndex).price(amount))
                    : "Price: R$ 00,00");
        }catch (NumberFormatException e){
            priceLabel.setText("Price: R$ 00,00");
        }catch (Exception e){
            new ExceptionDialog(e);
        }
    }
}
