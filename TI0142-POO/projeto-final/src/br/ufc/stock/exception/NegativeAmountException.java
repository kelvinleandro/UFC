/**
 * pedrofalcao10
 * The NegativeAmountException class represents an exception that is thrown
 * when a negative amount is provided where it is not permitted.
 */
package br.ufc.stock.exception;

public class NegativeAmountException extends Exception {
    private int amount;
    public NegativeAmountException(int amount) {
        super("Negative amount: " + amount + " isn't permitted.");
        this.amount = amount;
    }
}
