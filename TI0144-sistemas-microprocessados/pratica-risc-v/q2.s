factorial:
    addi s0, zero, 5 # fat = 5
    addi s1, zero, 1 # r =1
while:
    beq s0, zero, exit # while (fat >= 0)
    add s2, zero, s0 # i_temp = i
    add s3, zero, zero # r_temp = 0
mult:
    beq s2, zero, end_mult # finaliza multiplicacao
    add s3, s3, s1 # r_temp += r
    addi s2, s2, -1 # i_temp -= 1
    beq zero, zero, mult # goto mult
end_mult:
    addi s1, s3, 0 # r = fat_temp
    addi s0, s0, -1 # fat -= 1
    beq zero, zero, while # goto while
exit: