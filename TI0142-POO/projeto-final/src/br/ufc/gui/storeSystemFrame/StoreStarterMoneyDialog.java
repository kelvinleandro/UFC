package br.ufc.gui.storeSystemFrame;

import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.store.Store;

import javax.swing.*;
import java.math.BigDecimal;

public class StoreStarterMoneyDialog {
    public static Store showStoreStarterMoneyDialog() {
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        JLabel moneyLabel = new JLabel("Saldo inical:");
        JTextField moneyField = new JTextField();

        panel.add(moneyLabel);
        panel.add(moneyField);

        int option = JOptionPane.showOptionDialog(null, panel, "Saldo inicial", JOptionPane.DEFAULT_OPTION,
                JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Iniciar"}, null);

        if (option == 0) {
            try{
                BigDecimal money = new BigDecimal(moneyField.getText());
                return new Store(money);
            }
            catch(Exception e){
                new ExceptionDialog(e);
            }


        }
        return new Store(new BigDecimal(0));
    }
}
