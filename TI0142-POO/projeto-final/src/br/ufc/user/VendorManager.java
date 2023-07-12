package br.ufc.user;

import java.io.Serializable;
import java.util.Optional;
import java.util.Vector;
import br.ufc.user.exception.VendorUsernameAlreadyExists;
import br.ufc.user.exception.VendorPasswordTypedInvalid;
import br.ufc.user.exception.VendorUserNotFound;

public class VendorManager implements Serializable {
    Vector<VendorUser> vendors;

    public VendorManager(){
        this.vendors = new Vector<VendorUser>();
    }

    public void register(VendorUser user) throws VendorUsernameAlreadyExists{
        for(VendorUser current : vendors){
            if(current.getUsername().equals(user.getUsername()))
                throw new VendorUsernameAlreadyExists(user.getUsername());
        }
        this.vendors.add(user);

    }

    public Optional<VendorUser> getVendorByUsername(String username){
        VendorUser user = null;
        for(VendorUser current : vendors){
            if(current.getUsername().equals(username)) {
                user = current;
            }
        }
        return Optional.ofNullable(user);
    }

    public Optional<VendorUser> login(String username, String password)throws VendorPasswordTypedInvalid,VendorUserNotFound{
        Optional<VendorUser> user = getVendorByUsername(username);

        if(user.isEmpty()) {
            throw new VendorUserNotFound();
        }
        else if(user.get().getPasswordHash() != password.hashCode()){
            throw new VendorPasswordTypedInvalid();
        }
        else{
            return user;
        }
    }
}
