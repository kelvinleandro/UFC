package br.ufc.stock;

import java.io.Serializable;
import java.util.Optional;
import java.util.Vector;
import br.ufc.stock.exception.ItemAlreadyExists;

public class ItemManager implements Serializable {
    private Vector<Item> items;

    public ItemManager(){
        this.items = new Vector<Item>();
    }

    public void register(Item item) throws ItemAlreadyExists{
        boolean alreadyExists = false;
        for(Item current : items){
            if(current.getName().equals(item.getName()))
                alreadyExists = true;
        }

        if(!alreadyExists)
            this.items.add(item);
        else
            throw new ItemAlreadyExists();

    }

    public Optional<Item> getByName(String name){
        Item item = null;
        for(Item current : items){
            if(current.getName().equals(name)) {
                item = current;
                break;
            }
        }
        return Optional.ofNullable(item);
    }

    public Optional<Item> getById(String id){
        Item item = null;
        for(Item current : items){
            if(current.getId().equals(id)) {
                item = current;
                break;
            }
        }
        return Optional.ofNullable(item);
    }

    public Optional<Vector<Item>> getItems() {
        return Optional.of(items);
    }

    public Optional<Item> getByIndex(int index){
        return Optional.ofNullable(items.get(index));
    }
    public void deleteByIndex(int index){
        Optional<Item> item = getByIndex(index);
        if(item.isPresent()){
            items.remove(item.get());
        }
    }
}
