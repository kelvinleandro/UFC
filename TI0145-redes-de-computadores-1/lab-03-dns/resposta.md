# Prática 03 - Introdução ao DNS - nslookup

## PARTE 01

**1. Execute nslookup para obter o endereço IP do servidor web do Massachusetts Institute of Technology: http://www.mit.edu. Qual é o endereço IP de http://www.mit.edu?**

R: 104.104.149.67

**2. Qual é o endereço IP do servidor DNS que forneceu a resposta ao seu comando nslookup na pergunta 1 acima?**

R: 127.0.0.53

**3. A resposta ao seu comando nslookup na pergunta 1 acima veio de um servidor autoritativo ou não autoritativo?**

R: não autoritativo

**4. Use o comando nslookup para determinar o nome do servidor de nomes autoritativo para o domínio http://www.mit.edu. Qual é esse nome? (Se houver mais de um servidor autoritativo, qual é o nome do primeiro servidor autoritativo retornado pelo nslookup)? Se você tivesse que encontrar o endereço IP desse servidor de nomes autoritário, como você faria isso?**

R: dscb.akamaiegdge.net, usaria nslookup com -type=NS

## PARTE 02

**1. Localize a primeira mensagem de consulta DNS resolvendo o nome gaia.cs.umass.edu. Qual é o número do pacote no rastreamento da mensagem de consulta DNS? Esta mensagem de consulta é enviada por UDP ou TCP?**

R: nº pacote 47, UDP

**2. Agora localize a resposta DNS correspondente à consulta DNS inicial. Qual é o número do pacote no rastreamento da mensagem de resposta do DNS? Esta mensagem de resposta é recebida via UDP ou TCP?**

R: nº pacote 48, UDP

**3. Qual é a porta de destino para a mensagem de consulta DNS? Qual é a porta de origem da mensagem de resposta DNS?**

R: Porta de destino para a mensagem de consulta DNS: **53**. Porta de origem da mensagem de resposta DNS: **53**

**4. Para qual endereço IP a mensagem de consulta DNS é enviada?**

R: src: 10:0.0.235, dst: 200.19.190.6

**5. Examine a mensagem de consulta DNS. Quantas “perguntas” esta mensagem DNS contém? Quantas respostas “respostas” contém?**

R: perguntas: 1. Respostas: 0

**6. Examine a mensagem de resposta DNS para a mensagem de consulta inicial. Quantas “perguntas” esta mensagem DNS contém? Quantas respostas “respostas” contém?**

R: perguntas: 1. Respostas: 1

**7. A página da web para o arquivo base http://gaia.cs.umass.edu/kurose_ross/ faz referência ao objeto de imagem http://gaia.cs.umass.edu/kurose_ross/header_graphic_book_8E_2.jpg , que, como a página base, está em gaia.cs.umass.edu. Qual é o número do pacote no rastreamento para a solicitação HTTP GET inicial para o arquivo base http://gaia.cs.umass.edu/kurose_ross/? Qual é o número do pacote no rastreamento da consulta DNS feita para resolver gaia.cs.umass.edu para que essa solicitação HTTP inicial possa ser enviada para o endereço IP gaia.cs.umass.edu? Qual é o número do pacote no rastreamento da resposta DNS recebida? Qual é o número do pacote no rastreamento da solicitação HTTP GET para o objeto de imagem http://gaia.cs.umass.edu/kurose_ross/header_graphic_book_8E2.jpg? Qual é o número do pacote na consulta DNS feita para resolver gaia.cs.umass.edu para que essa segunda solicitação HTTP possa ser enviada para o endereço IP gaia.cs.umass.edu? Discuta como o cache de DNS afeta a resposta a esta última pergunta.**

R: nº pacote 54 (get http), nº pacote 47 (consulta dns), nº pacote 48 (resposta dns). 
Se ja estiver em cache não precisa consultar dns

## PARTE 03

**1. Qual é a porta de destino para a mensagem de consulta DNS? Qual é a porta de origem da mensagem de resposta DNS?**

R: ambas portas 53 

**2. Para qual endereço IP a mensagem de consulta DNS é enviada? Este é o endereço IP do seu servidor DNS local padrão?**

R: dst: 200.19.190.6. Não é o ip do servidor dns local padrão

**3. Examine a mensagem de consulta DNS. Que “Tipo” de consulta DNS é? A mensagem de consulta contém alguma “resposta”?**

R: type A. Não possui resposta

**4. Examine a mensagem de resposta DNS para a mensagem de consulta. Quantas “perguntas” esta mensagem de resposta DNS contém? Quantas “respostas”?**

R: 1 pergunta, 1 resposta


## PARTE 04

**1. Para qual endereço IP a mensagem de consulta DNS é enviada? Este é o endereço IP do seu servidor DNS local padrão?**

R: dst: 200.19.190.6. Não é o ip do servidor dns local padrão

**2. Examine a mensagem de consulta DNS. Quantas perguntas tem a consulta? A mensagem de consulta contém alguma “resposta”?**

R: 1 pergunta, a consulta contém uma response

**3. Examine a mensagem de resposta DNS. Quantas respostas tem a resposta? Quais informações estão contidas nas respostas? Quantos registros de recursos adicionais são retornados? Quais informações adicionais estão incluídas nesses registros de recursos adicionais?**

R: possui 3 respostas. Possui atributos como name, name server , type (que é NS, authorative name server), class para cada resposta. São retornados 3 registros de recursos adicionais. Para cada registro possui atributos como name, type (que é A, host address), class, address em cada registro adicional.