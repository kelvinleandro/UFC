package br.ufc.gui.login;

import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.user.VendorManager;
import br.ufc.user.VendorUser;

import javax.swing.*;
import java.util.Optional;

public class LoginDialog {

    public static void showLoginDialog(JFrame tela, VendorManager vendorManager) {
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

        int option = JOptionPane.showOptionDialog(null, panel, "login", JOptionPane.DEFAULT_OPTION,
                JOptionPane.PLAIN_MESSAGE, null, new Object[]{"Login", "Cancelar"}, null);

        if (option == 0) {
            String username = usernameField.getText();
            String password = new String(passwordField.getPassword());

            try {
                Optional<VendorUser> user = vendorManager.login(username,password);
                ((TelaLoginCadastro) tela).sucessLogin(user);

            } catch (Exception e) {
                new ExceptionDialog(e);
            }
        }

    }
}