addi s1, zero, 0 # i = 0
addi t1, zero, 0 # t1 = 0
addi t2, zero, 200 # t2 = 0
for:
    bge s1, t2, done  # if i >= 200 then done
    slli t0,s1, 2 # t0 = i * 4
    add t0, t0, s0 # address of scores[i]
    lw t1, 0(t0) # t1 = scores[i]
    addi t1, t1, 10 # t1 = scores[i] + 10
    sw t1, 0(t0) # scores[i] = t1
    addi s1, s1, 1 # i = i + 1
    beq zero, zero, for # repeat
done: