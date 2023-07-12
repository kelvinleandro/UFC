package br.ufc.store;

import br.ufc.gui.exception.ExceptionDialog;
import br.ufc.stock.request.Request;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Collections;
import java.util.List;
import java.util.Vector;

public class StoreRequester implements Serializable {
    private Store store;
    private List<Request> requestQueue;
    public StoreRequester(Store store){
        this.store = store;
        this.requestQueue = new Vector<Request>();
    }

    public void credit(BigDecimal value){
        store.credit(value);
    }

    public void debit(Request request){
        try{
            store.debit(request.getValue());
            request.conclude();
        }
        catch(Exception e){
            new ExceptionDialog(e);
            request.decline();
            this.requestQueue.add(request);
        }

    }

    public void retryAll(){
        for(Request req : this.requestQueue){
            this.debit(req);
        }
    }

    public List<Request> getAllRequests(){
        return Collections.unmodifiableList(this.requestQueue);
    }
}
