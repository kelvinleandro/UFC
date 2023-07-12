package br.ufc.gui.login;

import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.user.VendorManager;
import br.ufc.user.VendorUser;

import javax.swing.*;

public class RegisterDialog {

    public static void showRegisterDialog(VendorManager vendorManager) {
        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        JLabel usernameLabel = new JLabel("Usuário:");
        JTextField usernameField = new JTextField();
        JLabel passwordLabel = new JLabel("Senha:");
        JPasswordField passwordField = new JPasswordField();

        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);

        int option = JOptionPane.showOptionDialog(null, panel, "Registro", JOptionPane.DEFAULT_OPTION,
                JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Registrar", "Cancelar"}, null);

        if (option == 0) {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());

            try{
                VendorUser user = new VendorUser(username,password);
                vendorManager.register(user);
                JOptionPane.showMessageDialog(null, "Registro concluído com sucesso!");
            }
            catch (Exception e){
                new ExceptionDialog(e);
            }
        }
    }
}