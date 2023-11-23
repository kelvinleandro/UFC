clear all;
z = 1+sqrt(-1); % um número complexo, note que sqrt (-1)= 1.00001 
real(z) % a parte real de z
imag(z) % a parte imaginária de z
z = 1+sqrt(-100); % um número complexo, note que sqrt (-1) = 1.00001 
real(z) % a parte real de z
imag(z) % a parte imaginária de z

figure(1)
clf
plot(z, 'ro') % o simbolo para "plotar" um circulo vermelho
xlabel('componente real');
ylabel('componente imaginária');
title('Gerar um número complexo no plano');
% adicionando ao gráfico
z2 = 1 + 10i;
hold on % preservando pontos originais quando pontos adicionais são "plotados" 
plot(z2, 'ks') % o símbolo usado é o quadrado preto
% somar números complexos é como somar vetores
plot(z+z2, 'pb') % símbolo é um pentágono azul
axis([0 5 0 25])

%% Ilustrando como as curvas são geradas
figure(2)
clf
t = linspace(0, 2*pi);
plot(t, cos(t), 'r');
hold on
plot(t, sin(t), '-b');
xlabel('t');
title('Funções Trigonométricas')

%% Questao 1
figure(3)
clf
t = linspace(0, 10); % atribuindo um vetor 1X100 a t
z = -1;
plot(t, exp(z*t), 'r-') % linha vermelha
title('"Plots" envolvendo a função exponencial')
hold on
z = 1E-1;
plot(t, exp(z*t), 'k--') % linha preta tracejada
z = 5.0i;
plot(t, exp(z*t), 'b-.') % linha ponto-traço azul 
z = -1+5.0i;
plot(t, exp(z*t), 'k:') % linha pontilhada verde 
xlabel('t');

%Tentar também: 
figure(4)
clf
plot(t, real(exp(z*t)), 'b-') % linha ponto-traço azul 
hold on
plot(t, imag(exp(z*t)), 'g-') % linha ponto-traço azu 
xlabel('t');
title('"Plots" Parte real e Parte imaginária da função exponencial' ) 
legend('real', 'imag')

%% Questao 2
figure(5)
clf
t = linspace(0,10); % atribuindo um vetor 1X100 a t 
z = 1i;
plot(exp(z*t), 'r-') % linha vermelha
title('"plots" envolvendo a função exponencial' ) 
hold on
axis image % definindo a proporção para 1 
z = -0.1+1i;
plot(exp(z*t), 'g--') % linha verde
z = 0.1+1i;
plot(exp(z*t), 'b-.') % linha azul 
xlabel('componente real'); 
ylabel('componente imaginária');

%% Questao 3
figure(6)
clf
t = linspace(0, 8*pi); % definir t
z = 0.05 + 1i; % definir
plot(exp(z*t))
xlabel('componente real'); 
ylabel('componente imaginária');