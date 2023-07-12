package br.ufc.stock.request;

import br.ufc.stock.exception.RequestNegativePriceException;

import java.io.Serializable;
import java.math.BigDecimal;

public class Request implements Serializable {

    private BigDecimal value;
    private Concludable concludable;
    private RequestStatus status;

    public BigDecimal getValue(){
        return this.value;
    }

    public Request(Concludable concludable, BigDecimal value){
        this.concludable = concludable;
        this.status = RequestStatus.PROCESSING;
        if(value.compareTo(BigDecimal.ZERO) < 0){
            throw new RequestNegativePriceException(value);
        }
        this.value = value;
    }

    public void conclude() {
        this.status = RequestStatus.CONCLUDED;
        this.concludable.conclude();
    }

    public void decline() {
        this.status = RequestStatus.DECLINED;
    }

    public boolean isConcluded(){
        return this.status.equals(RequestStatus.CONCLUDED);
    }
    public boolean isDeclined(){
        return this.status.equals(RequestStatus.DECLINED);
    }



    @Override
    public String toString() {
        return "Request{" +
                "value=" + value +
                ", status=" + status +
                '}';
    }
}
