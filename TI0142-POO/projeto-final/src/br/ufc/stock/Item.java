package br.ufc.stock;

import java.io.Serializable;

public class Item implements Serializable {
    private String name;
    private String descriptor;
    private String id;
    private static int itemNo = 1;

    public Item(String name, String descriptor) {
        this.name = name;
        this.descriptor = descriptor;
        this.id = Integer.toString(Item.itemNo);
        Item.itemNo += 1;
    }

    public boolean equals(Object o){
        return this==o;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDescriptor(String descriptor) {
        this.descriptor = descriptor;
    }

    public String getDescriptor() {
        return descriptor;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }


    @Override
    public String toString() {
        return name + " - " + descriptor;
    }
}
