# fibonacci
.data
        n: .word 10 # n-esimo termo de fibonacci

.text
main:
        la  s0, n              # carrega o endereço da variavel "n"
        lw  s0, 0(s0)          # carrega o valor armazenado no endereço
        li  s1, 1              # carrega "1" em s1
        blt  s0, s1, end       # vai para "end" se n < 1 (caso inicial de fib.)
        sub s1, s0, s1         # Calcula "n-1" e armazena em s1
        li  t0, 0              # registrador armazena o termo Fibonacci anterior (fib[i-2]).
        li  s0, 1              # registrador armazena o termo Fibonacci atual (fib[i-1]).
        
loop: 
        mv  t1, s0             # move o valor de s0 para te
        add  s0, s0, t0        # calcula o proximo termo da sequencai
        mv  t0, t1             # move o termo atual para o termo anterior
        addi  s1, s1, -1       # decrementa o contador
        bgt  s1, zero, loop    # volta para "loop" se o contador é > 0

end: