# Prática 2
## Parte 1 - A Interação básica Request/Response HTTP
### Passo 7
1. Seu navegador está rodando a versão 1.0 ou 1.1 do HTTP? Qual versão do HTTP está executando no servidor?

R: Está rodando a versão 1.1 em ambos

2. Quais idiomas (se há algum) o seu navegador indica que deseja receber a página web solicitada do servidor?

R: Accept-language pt-br

3. Qual o seu endereço IP? Qual o endereço IP do servidor gaia.cs.umass.edu?

R: meu IP: 10.0.0.35 ; ip servidor: 128.119.245.12

4. Qual o código de status retornado do servidor para o seu navegador?

R: 200 OK

5. Quando o arquivo HTML que você solicitou foi modificado pela última vez pelo servidor?

R: wed, 20 mar 2024 05:59:02 GMT

6. Quantos bytes de conteúdo são retornados para o seu navegador?

R: 128 bytes

7. Inspecionando o payload (carga útil) da mensagem de resposta http: você vê algum cabeçalho de algum outro protocolo? Se sim, nomeie algum.

R: Sim. Tem o TCP e o IP.

## Parte 2 - A interação CONDICIONAL Request/Response HTTP
### Passo 13

1. Inspecione os conteúdos da primeira requisição HTTP GET enviada do seu navegador para o servidor. Você vê a linha “IF-MODIFIED-SINCE:” na requisição HTTP?

R: Não há a linha IF-MODIFIED-SINCE

2. Inspecione o conteúdo da resposta do servidor . O servidor retornou explicitamente o conteúdo do arquivo? Como você pode afirmar isso?

R: Sim, ele retorna o codigo html

3. Agora inspecione o conteúdo da segunda requisição HTTP GET da página HTTP-wireshark-file2.html enviada do seu cliente para o servidor. Você vê a linha “IF-MODIFIED-SINCE:” na requisição HTTP? Se sim, que informação segue o cabeçalho “IF-MODIFIED-SINCE:”?

R: Há a linha IF-MODIFIED-SINCE na requisição. WED, 20 MAR 2024 05:59:02 GMT

4. Qual código e frase de status HTTP são retornados do servidor em resposta à segunda requisição HTTP? O servidor retornou explicitamente o conteúdo desse arquivo? Explique.

R: 304 not modified. Não retorna o codigo html, pois o arquivo esta salvo no cache

### Passo 19
1. Qual é a resposta do servidor (código e frase de estado) para a mensagem HTTP GET inicial do seu navegador?

R: 401 Unauthorized

2. Quando o seu navegador envia a mensagem HTTP GET pela segunda vez, qual novo campo é incluído na mensagem GET?

R: Pela segunda vez, o campo Authorization em HTTP foi adicionado com o conteudo "Basic d2lyZXNoYXJrLXN0dWRlbnRzOm5ldHdvcms="
