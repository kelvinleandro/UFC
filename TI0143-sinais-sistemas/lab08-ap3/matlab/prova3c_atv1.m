close all
clear all
clc

load GrupoRobo_10.mat; % baixar os dados do grupo A

l = length(z1); % comprimento do vetor z1
y = z1(:, 1); % valores medidos de y
u = z1(:, 2); % entrada de sinal

figure (1)
plot(y, 'r');
title("Valores medidos");


%$$$$$$$$$$$$$$$$$$$$$$$ Início Modelo de 1a. ordem $$$$$$$$$$$$$$$$$$$$$$$

X1 = [y(1:end-1), u(1:end-1)];% Modelo Discreto

theta1 = pinv(X1'*X1)*X1'*y(2:end); % Obtenção dos parâmetros a1,b1

y1_est = sim_1st(u, theta1); % Simulando resposta pro modelo de 1a. ordem

erro1 = y - y1_est; % Erro de estimação

Jest1 = norm(erro1)^2 / l;  % MSE

fprintf('Os parâmetos estimados foram:\n'), theta1
fprintf('------------------------------------------------------------------\n');
fprintf('A equação à diferenças é:\ny(k) = %.4f y(k-1) + %.4f u(k-1)\n\n', theta1(1), theta1(2));
fprintf('------------------------------------------------------------------\n');
fprintf('A aproximação J é: \n%d\n\n', Jest1);
fprintf('------------------------------------------------------------------\n');
fprintf('A função em Z é:\nY(z) = %.4f Y(z) z^-1 + %.4f U(z) z^-1 \n\n',theta1(1), theta1(2));
fprintf('------------------------------------------------------------------\n');
fprintf('A função de transferência em z, G(z) é:\n\n');
fprintf('Y(z)/U(z) = (%.4f z^-1 )/(1 - %.4f z^-1 )\n\n',theta1(2),abs(theta1(1)));

%$$$$$$$$$$$$$$$$$$$$$$$$ Final Modelo de 1. Ordem $$$$$$$$$$$$$$$$$$$$$$$$


%$$$$$$$$$$$$$$$$$$$$$$$ Início Modelo de 2a. ordem $$$$$$$$$$$$$$$$$$$$$$$

X = [y(2:end-1), y(1:end-2), u(2:end-1), u(1:end-2)]; % Modelo Discreto

theta2 = pinv(X'*X)*X'*y(3:end); % Obtenção dos parâmetros a1, a0, b1, b0

y2_est = sim_2nd(u, theta2); % Simulando resposta pro modelo de 2a. ordem

erro2 = y - y2_est; % erro de estimação

Jest2 = norm(erro2)^2 / l;  % MSE

Gz2 = tf_z_2nd(theta2); % Função de transferência no domínio Z pra 2a. ordem

Gs2 = d2c(Gz2); % Função de transferência no domínio S pra 2a. ordem

fprintf('Os parâmetos estimados foram:'), theta2
fprintf('------------------------------------------------------------------\n');
fprintf('A equação a diferenças é:\ny(k) = %.4f y(k-1) + %.4f y(k-2) + %.4f u(k-1) + %.4f u(k-2)\n\n', theta2(1), theta2(2), theta2(3), theta2(4));
fprintf('------------------------------------------------------------------\n');
fprintf('A aproximação Jest é: \n%d\n\n', Jest2);
fprintf('------------------------------------------------------------------\n');
fprintf('A função em Z é:\nY(z) = %.4f Y(z) z^-1 + %.4f Y(z) z^-2 +%.4f U(z) z^-1 + %.4f U(z) z^-2\n\n', theta2(1), theta2(2), theta2(3),theta2(4));
fprintf('------------------------------------------------------------------\n');
fprintf('A função de transferência em z, G(z) é:\n\n')
fprintf('Y(z)/U(z) = (%.4f z^-1 + %.4f z^-2)/(1 - %.4f z^-1 + %.4f z^-2)', theta2(3), theta2(4), theta2(1), abs(theta2(2)));

figure (2)
step(90*Gz2, 180) % Resposta ao degrau de tempo discreto para o modelo de 2a. ordem.
title("Resposta ao degrau em tempo discreto pra 2^a ordem")

figure (3)
step(90*Gs2, 180) % Resposta ao degrau de tempo contínuo para o modelo de 2a. ordem.
title("Resposta ao degrau em tempo contínuo pra 2^a ordem")

%$$$$$$$$$$$$$$$$$$$$$$$$ Final Modelo de 2. Ordem $$$$$$$$$$$$$$$$$$$$$$$$


figure (4)
plot(y,'r')
hold on
plot(y1_est,'g');
hold on
plot(y2_est,'b');
hold on
title("y(k) medidos e estimados")
legend({'y_m_e_d_i_d_o','y_e_s_t_1_a_._o_r_d_e_m','y_e_s_t_2_a_._o_r_d_e_m'},'Location','southeast')


%$$$$$$$$$$$$$$$$$$$$$$$$$$$ Funções Utilizadas $$$$$$$$$$$$$$$$$$$$$$$$$$$

function y_est1 = sim_1st(u, theta)
    % Inicialização do vetor de saída estimado
    y_est1 = zeros(size(u));
    
    % Condição inicial
    y_est1(1) = 0; % Supondo condição inicial zero
    
    % Simulação do modelo de primeira ordem
    for k = 2:length(u)
        y_est1(k) = theta(1) * y_est1(k-1) + theta(2) * u(k-1);
    end
end


function y_est2 = sim_2nd(u, theta)
    % Inicialização do vetor de saída estimado
    y_est2 = zeros(size(u));
    
    % Condições iniciais
    y_est2(1) = 0; % Supondo condição inicial y(k=0) = 0
    y_est2(2) = 0; % Supondo condição inicial y(k=1) = 0
    
    % Simulação do modelo de segunda ordem
    for k = 3:length(u)
        y_est2(k) = theta(1) * y_est2(k-1) + theta(2) * y_est2(k-2) + theta(3) * u(k-1) + theta(4) * u(k-2);
    end
end

function Gz2 = tf_z_2nd(theta)
    Gz2 = tf([0, theta(4), theta(3)], [1, -theta(1), -theta(2)], 1, 'Variable','z^-1');
end
