package br.ufc.user.exception;

import br.ufc.user.VendorUser;

public class VendorPasswordTypedInvalid extends Exception{
    public VendorPasswordTypedInvalid(){
        super("Senha digitada inválida.");
    }
}
