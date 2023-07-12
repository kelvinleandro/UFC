package br.ufc.gui.exception;

import javax.swing.*;

public class ExceptionDialog {

    public ExceptionDialog(Exception exception) {
        showExceptionDialog(exception);
    }

    private void showExceptionDialog(Exception exception) {
        String message = exception.getMessage();
        JOptionPane.showMessageDialog(null, message, "Erro", JOptionPane.ERROR_MESSAGE);
    }

    // Exemplo de uso
    public static void main(String[] args) {
        try {
            throw new NullPointerException("Erro: Referência nula.");
        } catch (Exception e) {
            new ExceptionDialog(e);
        }
    }
}