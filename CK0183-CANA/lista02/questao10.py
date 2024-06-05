# Seja 1, ... , n um conjunto de tarefas. Cada tarefa consome um dia de trabalho;
# durante um dia de trabalho somente uma das tarefas pode ser executada. Os dias de trabalho são numerados de 1 a n. 
# A cada tarefa T está associado um prazo PT: a tarefa deveria ser executada em algum dia do intervalo 1, ..., PT. 
# A cada tarefa T está associada uma multa não-negativa MT. Se uma dada tarefa T é executada depois do prazo PT, 
# sou obrigado a pagar a multa MT (mas a multa não depende do número de dias de atraso). 
# Problema: Programar as tarefas (ou seja, estabelecer uma bijeção entre as tarefas e os dias de trabalho) 
# de modo a minimizar a multa total. Escreva um algoritmo guloso para resolver o problema.

def minimiza_multa(tarefas, n):
    # Ordenar tarefas por MT decrescente e PT crescente
    tarefas.sort(key=lambda x: (-x['MT'], x['PT']))

    # Vetor de dias inicialmente vazio
    dias = [None] * (n + 1)

    # Total de multa acumulada
    total_multa = 0

    # Atribuir cada tarefa ao melhor dia disponível
    for tarefa in tarefas:
        PT = tarefa['PT']
        MT = tarefa['MT']

        # Tentar agendar a tarefa no dia mais próximo ao prazo possível
        agendado = False
        for dia in range(PT, 0, -1):
            if dias[dia] is None:
                dias[dia] = tarefa
                agendado = True
                break

        # Se não foi agendado antes do prazo, agenda depois e acumula multa
        if not agendado:
            for dia in range(n, PT, -1):
                if dias[dia] is None:
                    dias[dia] = tarefa
                    total_multa += MT
                    break

    return total_multa

# Exemplo de uso
tarefas = [
    {'T': 1, 'PT': 4, 'MT': 70},
    {'T': 2, 'PT': 2, 'MT': 60},
    {'T': 3, 'PT': 4, 'MT': 50},
    {'T': 4, 'PT': 3, 'MT': 40},
    {'T': 5, 'PT': 1, 'MT': 30}
]
n = 5
print(minimiza_multa(tarefas, n))  # Saída esperada: 30
