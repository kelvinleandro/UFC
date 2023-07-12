package br.ufc.user.exception;

import br.ufc.user.VendorUser;

public class VendorUsernameAlreadyExists extends Exception{
    public VendorUsernameAlreadyExists(String username){
        super("O nome de usuário " + username + " já está sendo utilizado");
    }
}
