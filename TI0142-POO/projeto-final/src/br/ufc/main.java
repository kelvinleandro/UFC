package br.ufc;

import br.ufc.gui.login.TelaLoginCadastro;

import br.ufc.serializing.ReadStore;
import br.ufc.serializing.SaveStore;
import br.ufc.store.Store;


public class main {
    public static void main(String[] args) {
        Store store = ReadStore.desserialize();

        TelaLoginCadastro telaLoginCadastro = new TelaLoginCadastro(store);
        telaLoginCadastro.setVisible(true);

        SaveStore.serialize(store);
    }
}


