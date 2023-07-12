package br.ufc.gui.storeSystemFrame;

import br.ufc.gui.CRUD.CRUDItem;
import br.ufc.gui.CRUD.CRUDSeller;
import br.ufc.gui.CRUD.CRUDStock;
import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.serializing.SaveStore;
import br.ufc.store.Store;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class StoreSystemFrame extends JFrame {

    private JPanel mainPanel;
    private JPanel profilePanel;
    private JPanel itemPanel;
    private JPanel stockPanel;
    private JPanel sellerPanel;

    private List<String> sales;

    private Store store;

    public StoreSystemFrame(Store store) {

        this.store = store;
        setTitle("Sistema de estoque");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setLocationRelativeTo(null);

        sales = new ArrayList<>();

        createMenuBar();

        mainPanel = new MainPanel();
        profilePanel = new ProfilePanel(store.getActiveUser());
        itemPanel = new CRUDItem(store.getItemMananger());
        stockPanel = new CRUDStock(
                store.getStockManager(),
                store.getItemMananger(),
                store.getStoreRequester()
        );
        sellerPanel = new CRUDSeller(
                store.getStockManager(),
                store.getSellerManager(),
                store.getStoreRequester()
        );

        showMainPanel();

        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                SaveStore.saveData(store);
            }
        });
    }

    private void createMenuBar() {
        JMenuBar menuBar = new JMenuBar();

        JMenuItem itemMenu = new JMenuItem("Item");
        itemMenu.addActionListener(e -> showItemPanel());
        menuBar.add(itemMenu);

        JMenuItem stockMenu = new JMenuItem("Stock");
        stockMenu.addActionListener(e -> showStockPanel());
        menuBar.add(stockMenu);

        JMenuItem sellerMenu = new JMenuItem("Seller");
        sellerMenu.addActionListener(e -> showSellerPanel());
        menuBar.add(sellerMenu);

        JMenuItem salesMenu = new JMenuItem("Sales");
        salesMenu.addActionListener(e -> {
            new SaleDialog(store);
            ((MainPanel)mainPanel).updateTotalRevenueLabel(store.getCash());
        });
        menuBar.add(salesMenu);

        JMenuItem profileMenu = new JMenuItem("Profile");
        profileMenu.addActionListener(e -> showProfilePanel());
        menuBar.add(profileMenu);

        JMenuItem menuMenu = new JMenuItem("Menu");
        menuMenu.addActionListener(e -> showMainPanel());
        menuBar.add(menuMenu);

        setJMenuBar(menuBar);
        try{
            BufferedImage originalImage = ImageIO.read(new File("images/image.png"));
            setIconImage(originalImage);
        }
        catch(Exception e){
            new ExceptionDialog(e);
        }
    }

    public void showMainPanel() {
        ((MainPanel)mainPanel).updateLastSaleLabel(store.getLastTransaction());
        ((MainPanel)mainPanel).updateTotalRevenueLabel(store.getCash());
        setContentPane(mainPanel);
        validate();
        repaint();
    }

    private void showItemPanel() {
        setContentPane(itemPanel);
        validate();
        repaint();
    }

    private void showStockPanel() {
        ((CRUDStock)stockPanel).loadElements();
       setContentPane(stockPanel);
       validate();
       repaint();
    }
    private void showSellerPanel() {
        setContentPane(sellerPanel);
        validate();
        repaint();
    }
    private void showProfilePanel() {
        ((ProfilePanel)profilePanel).loadSales();
        setContentPane(profilePanel);
        validate();
        repaint();
    }

    public Store getStore(){
        return store;
    }
}
