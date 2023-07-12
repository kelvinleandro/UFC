package br.ufc.stock.seller.exception;

import br.ufc.stock.request.Request;

public class CreditRequestException extends RuntimeException {
    private Request req;
    public CreditRequestException(Request req) {
        this.req = req;
    }

    @Override
    public String getMessage() {
        return String.format("Credit requests shouldn't be denied. Request: %s", this.req.toString());
    }
}
