clear;      % Limpa todas as variáveis do Workspace
clc;        % Limpa a Janela de Comandos
close all;  % Fecha todas as figuras abertas

P = input("Valor de P: ");
A = input("Valor de A: ");

graus = 0:90;
radiano = deg2rad(graus);

sigma_avg = (P / A) * sin(radiano);
tau_avg = (P / (2 * A)) * sin(2 * radiano);

figure;

subplot(1, 2, 1);
plot(graus, sigma_avg);
xlabel("Ângulo (graus)");
ylabel("sigma_avg");
title("Tensão normal média");
xticks(0:15:90);
grid on;

subplot(1, 2, 2);
plot(graus, tau_avg);
xlabel("Ângulo (graus)");
ylabel("tau_avg");
title("Tensão de cisalhamento média");
xticks(0:15:90);
grid on;
