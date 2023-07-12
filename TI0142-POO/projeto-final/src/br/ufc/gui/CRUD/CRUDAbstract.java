package br.ufc.gui.CRUD;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Vector;

public abstract class CRUDAbstract<T> extends JPanel {
    protected final Vector<T> elements;
    protected JList<String> elementList;
    protected DefaultListModel<String> listModel;

    protected JPanel buttonPanel;

    JScrollPane scrollPane;

    public CRUDAbstract() {
        elements = new Vector<>();
        listModel = new DefaultListModel<>();

        setLayout(new BorderLayout());

        elementList = new JList<>(listModel);
        scrollPane = new JScrollPane(elementList);
        add(scrollPane, BorderLayout.CENTER);

        JButton addButton = new JButton("Adicionar");
        JButton editButton = new JButton("Editar");

        buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        buttonPanel.add(addButton);
        buttonPanel.add(editButton);
        add(buttonPanel, BorderLayout.SOUTH);

        // Ação do botão Adicionar
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addElement();
            }
        });

        // Ação do botão Editar
        editButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                editElement();
            }
        });

    }

    public abstract void addElement();
    public abstract void editElement();
    protected abstract void loadElements();
}