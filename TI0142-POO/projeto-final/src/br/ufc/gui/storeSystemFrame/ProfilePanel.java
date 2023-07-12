package br.ufc.gui.storeSystemFrame;

import br.ufc.stock.sale.Sale;
import br.ufc.user.VendorUser;

import javax.swing.*;
import java.awt.*;
import java.util.List;

public class ProfilePanel extends JPanel{

    protected final List<Sale> sales;
    protected JList<String> salesList;
    protected DefaultListModel<String> listModel;
    VendorUser vendorUser;
    JScrollPane scrollPane;


    public ProfilePanel(VendorUser vendorUser){
        this.vendorUser = vendorUser;
        this.setLayout(new BorderLayout());

        sales = null;
        listModel = new DefaultListModel<>();
        salesList = new JList<>(listModel);


        scrollPane = new JScrollPane(salesList);
        add(scrollPane, BorderLayout.CENTER);
    }
    public void loadSales()
    {
        listModel.clear();
        List<Sale> salesVector = vendorUser.getSales();
        for (Sale current : salesVector) {
            listModel.addElement(current.toString());
        }
    }

}
