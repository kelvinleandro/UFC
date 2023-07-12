package br.ufc.stock.seller.manager;

import br.ufc.stock.Item;
import br.ufc.stock.seller.BaseSeller;
import br.ufc.stock.seller.CommonSeller;
import br.ufc.stock.seller.DiscountSeller;
import br.ufc.stock.seller.Seller;
import br.ufc.stock.seller.manager.exception.ExistentSellerException;

import java.io.Serializable;
import java.util.Optional;
import java.util.Vector;
import java.util.stream.Collectors;
public class SellerManager implements Serializable {
    private final Vector<BaseSeller> sellers;

    public SellerManager() {
        sellers = new Vector<BaseSeller>();
    }

    public void register(BaseSeller seller) throws ExistentSellerException {
        boolean exists = false;

        for (Seller s : this.sellers) {

            if (seller.equals(s)) {
                exists = true;
                break;
            }
        }

        if (exists) {
            throw new ExistentSellerException(seller);
        } else {
            this.sellers.add(seller);
        }
    }

    public Optional<Seller> get(String name) {
        for (Seller s : sellers) {
            if (s.getItemType().getName().equals(name)) {
                return Optional.of(s);
            }
        }
        return Optional.empty();
    }

    public Vector<Item> getProducts(){
        return new Vector<>(
                this.sellers
                        .stream()
                        .map(Seller::getItemType)
                        .collect(Collectors.toList())
        );
    }
    public Vector<BaseSeller> getSellers(){
        return sellers;
    }

    public BaseSeller getByIndex(int index){return sellers.get(index);}
}
