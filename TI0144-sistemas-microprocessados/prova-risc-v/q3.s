# Números Felizes entre 1 e 50
# 1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49

addi a2,zero,0x100 # BASE_ADDRESS = 0x100
addi a3,zero,0 # INDEX = 0x0
addi a4,zero,1 # ATUAL_NUMERO = 1
addi a5,zero,10 # BASE = 10
addi a6,zero,51 # MAX = 51

numeros_felizes:
	beq a4,a6,fim # se ATUAL_NUMERO == 51, fim
	mv t0,a4 # t0 = a4
    ciclo:
        mv t1,zero # t1 = soma = 0
        soma_digitos:
            rem t2,t0,a5 # t2 = resto da divisão por 10
            mul t3, t2, t2 # t3 = resto * 2
            div t0, t0, a5 # t0 = t0 // 10
            add t1,t1,t3 # t1 = t1 + t3
            bne t0, zero, soma_digitos # se t0 != 0, vai para "soma_digitos"
        addi t2,zero,1 
        beq t1,t2,verdadeiro # se soma_digitos == 1, vai para "verdadeiro"
        addi t2,zero,4
        beq t1,t2,falso # se soma_digitos == 4, vai para "falso"
        mv t0, t1
        j ciclo # volta pro "ciclo"

verdadeiro:
	add t0,a2,a3 # ENDERECO = BASE_ADDRESS + INDEX
    sw a4, 0(t0) # salva ATUAL_NUMERO em BASE_ADDRESS[INDEX]
    addi a3,a3,4 # pula o index em 4
    j adicionar_numero # vai para "adicionar_numero"

falso:
	j adicionar_numero # vai para "adicionar_numero"

adicionar_numero:
	addi a4,a4,1 # ATUAL_NUMERO++
    j numeros_felizes # vai para "numeros_felizes"

fim: