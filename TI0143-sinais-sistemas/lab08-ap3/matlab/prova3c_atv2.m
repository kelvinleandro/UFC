close all
clear all
clc

% $$$$$$$$$$$$$$$$$$$$$$$$$$ Modelo de 2a. ordem $$$$$$$$$$$$$$$$$$$$$$$$$$

% y(k) = a1y(k-1) + a0y(k-2) + b1u(k-1) + b0u(k-2)

% y(k) = 1.238 y(k-1) - 0.3016 y(k) + 0.03175 x(k-2) – 0.03175 x(k)

% y(k) - 1.238 y(k-1) + 0.3016 y(k) = 0.03175 x(k-2) – 0.03175 x(k)

% Y(z) - 1.238 Y(z) z^-1 + 0.3016 Y(z) = 0.03175 X(z) z^-2 - 0.03175 X(z)

% Y(z) [1.3016 - 1.238 z^-1] = X(z) [-0.03175 + 0.03175 z^-2] 

% G(z) = [-0.03175 + 0.03175 z^-2]
%        -------------------------
%          [1.3016 - 1.238 z^-1]

numerator = [-0.03175, 0, 0.03175];
denominator = [1.3016, -1.238, 0];

Ts = 0.01;
Ts1 = 0.1;
Ts2 = 1.0;

% Criando a função de transferência no domínio Z
Gz = tf(numerator, denominator, Ts, 'Variable','z^-1');

% Substituindo z por (2+Ts1*s)/(2-Ts1*s) em Gz para obter G1_s
G1_s = tf(tustin_num(numerator, Ts1), tustin_den(denominator, Ts1)); % Convertendo a função de transferência discreta para contínua

% Substituindo z por (2+Ts2*s)/(2-Ts2*s) em Gz para obter G2_s
G2_s = tf(tustin_num(numerator, Ts2), tustin_den(denominator, Ts2)); % Convertendo a função de transferência discreta para contínua

Gz
G1_s
G2_s

figure (1)
step(Gz) % Resposta ao degrau de tempo discreto para o modelo de 2a. ordem.
title("Respostas ao degrau unitário em G(z)")

figure (2)
step(G1_s) % Resposta ao degrau de tempo discreto para o modelo de 2a. ordem.
title("Respostas ao degrau unitário em G_1 (s) com T = 0.1s")

figure (3)
step(G2_s) % Resposta ao degrau de tempo contínuo para o modelo de 2a. ordem.
title("Respostas ao degrau unitário em G_2 (s) com T = 1.0s")

function numerator_s = tustin_num(numerator, Ts)
    numerator_s = [Ts^2 * (numerator(1) + numerator(3)), 4 * Ts * (numerator(1) - numerator(3)), 4 * (numerator(1) + numerator(3))];
end

function denominator_s = tustin_den(denominator, Ts)
    denominator_s = [Ts^2 * (denominator(1) - denominator(2)), 4 * Ts * denominator(1), 4 * (denominator(1) + denominator(2))];
end