package br.ufc.gui.storeSystemFrame;

import br.ufc.stock.sale.Sale;
import br.ufc.stock.seller.MoneyConverter;

import javax.swing.*;
import java.awt.*;
import java.math.BigDecimal;
import java.util.Optional;

public class MainPanel extends JPanel{
    JLabel totalRevenueLabel = new JLabel();
    JLabel lastSaleDateLabel = new JLabel();
    public MainPanel(){
        this.setLayout(new BorderLayout());

        JLabel titleLabel = new JLabel("Menu Principal");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 20));
        titleLabel.setHorizontalAlignment(SwingConstants.CENTER);
        this.add(titleLabel, BorderLayout.NORTH);

        JPanel infoPanel = new JPanel(new GridLayout(2, 2, 10, 10));
        infoPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        infoPanel.add(totalRevenueLabel);

        infoPanel.add(lastSaleDateLabel);

        this.add(infoPanel, BorderLayout.CENTER);
    }
    public void updateTotalRevenueLabel(BigDecimal revenue){
        totalRevenueLabel.setText("Saldo: R$"+ MoneyConverter.convertBigDecimal(revenue));
    }
    public void updateLastSaleLabel(Optional<Sale> optionalSale){
        if(optionalSale.isPresent()){
            lastSaleDateLabel.setText("Ultima venda: "+optionalSale.get());
        }
        else{
            lastSaleDateLabel.setText("Ultima venda:");
        }

    }
}
