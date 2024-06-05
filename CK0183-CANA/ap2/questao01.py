import math

def minimiza_multas(tarefas):
  # Ordena tarefas por multa decrescente
  tarefas.sort(key=lambda tarefa: tarefa["multa"], reverse=True)
  agenda = {}
  multa_total = 0

  # Agenda as tarefas por dia
  for dia in range(1, math.ceil(len(tarefas) / 2) + 1):
    agenda[dia] = []

  for tarefa in tarefas:
    PT = tarefa["prazo"]
    MT = tarefa["multa"]
    agendado = False

    # Tenta agendar a tarefa nos dias anteriores ao prazo
    for dia in range(PT, 0, -1):
      if len(agenda[dia]) < 2:
        agenda[dia].append(tarefa)
        agendado = True
        break

    # Se não agendou antes do prazo, tenta agendar depois
    if not agendado:
      for dia in range(math.ceil(len(tarefas) / 2), PT, -1):
        if len(agenda[dia]) < 2:
          agenda[dia].append(tarefa)
          break
      multa_total += MT

  return agenda, multa_total

tarefas = [
  {"prazo": 2, "multa": 10},
  {"prazo": 1, "multa": 5},
  {"prazo": 3, "multa": 7},
  {"prazo": 1, "multa": 8},
  {"prazo": 2, "multa": 2},
  {"prazo": 2, "multa": 4},
  {"prazo": 1, "multa": 9},
  {"prazo": 1, "multa": 3},
  {"prazo": 2, "multa": 6},
  {"prazo": 1, "multa": 1},
]

agenda, multa_total = minimiza_multas(tarefas)

print("Agenda:")
for dia, tarefas_do_dia in agenda.items():
  print(f"Dia {dia}: {tarefas_do_dia}")

print(f"\nMulta total: {multa_total}")
