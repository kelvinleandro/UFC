package br.ufc.user.exception;

public class VendorUserNotFound extends Exception{
    public VendorUserNotFound(){
        super("Usuário não encontrado.");
    }
}
