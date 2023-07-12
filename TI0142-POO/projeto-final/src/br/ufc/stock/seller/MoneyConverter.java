package br.ufc.stock.seller;

import java.math.BigDecimal;
import java.text.DecimalFormat;

public class MoneyConverter {
    public static String convertBigDecimal(BigDecimal money){
        BigDecimal formattedValue = money.setScale(2, BigDecimal.ROUND_HALF_UP);
        DecimalFormat decimalFormat = new DecimalFormat("#,##0.00");
        String valorString = decimalFormat.format(formattedValue);
        return valorString;
    }
}
