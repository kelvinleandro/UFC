# multiplicacao de polinomios (FFT / Convolucao)
addi s0, zero, 0x100 # ENDERECO_BASE_1 = 0
addi s1, zero, 0x200 # ENDERECO_BASE_2 = 0
addi s2, zero, 0x300 # ENDERECO_BASE_3 = 0

# Inicializando dados do array A (digitos da matricula como coefs do polinomio)
addi t0, zero, 5
sw t0, 0(s0)
addi t0, zero, 4
sw t0, 4(s0)
addi t0, zero, 0
sw t0, 8(s0)
addi t0, zero, 0
sw t0, 12(s0)
addi t0, zero, 0
sw t0, 16(s0)
addi t0, zero, 6
sw t0, 20(s0)

# Inicializando dados do array B (coeficientes do polimonio da questao)
addi t0, zero, 2
sw t0, 0(s1)
addi t0, zero, 1
sw t0, 4(s1)
addi t0, zero, 3
sw t0, 8(s1)
addi t0, zero, 1
sw t0, 12(s1)

mv t1, zero # indice_linha = 0

# inicio da convolucao
convolucao:
    mv t0, zero # soma = 0
    mv t2, zero # j = 0
    
    # calculo dos coeficientes
    loop:
        # resultado[i+j] += A[i]*B[j]
        add t3, s0, t1 # endereco_A = ENDERECO_BASE_A + i
        lw t4, 0(t3) # t4 = A[i]
        add t3, s1, t2 # endereco_B = ENDERECO_BASE_B + j
        lw t5, 0(t3) # t5 = B[j]
        add t3, t1, t2 # i+j
        add t3, s2, t3 # endereco_resultado = ENDERECO_BASE_RESULTADO + (i+j)
        lw t6, 0(t3) # t6 = resultado[i+j]
        mul t5, t5, t4 # t5 * t4
        add t6, t6, t5 # t6 += t5 * t4
        sw t6, 0(t3) # salva t6 (resultado[i+j])
        addi t2, t2, 4 # passa para a proxima coluna
        addi t3, zero, 16 # j_maximo
        bne t2, t3, loop # se j < j_maximo, volta para o "loop"

    addi t1, t1, 4 # passa para a proxima linha
    addi t3, zero, 24 # i_maximo
    bne t1, t3, convolucao # se i < i_maximo, volta para "convolucao"