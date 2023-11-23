% -------------------------------------- Rotina Principal -------------------------------------------------
% Encontrar o mínimo de uma função escalar de várias variáveis,
% começando por uma estimativa inicial
clear;
clc;
home
% Estimativa inicial (Valores devem ser atribuídos por Grupo)
%-------------------------------------------
K = 1.0047; % Ganho DC
zeta = 0.5247; % Fator de Amortecimento - Adimensional
wn = 1237.8505; % Frequência Natural - rad/s
p0=[K zeta wn]; % Parâmetros
%-------------------------------------------
% Cálculo dos parâmetros ótimos via Função fminsearch.
% Essa função do MATLAB começa no ponto p0 e retorna um
% valor p que é um minimizador local da função descrita em MSE.
%------------------------------------------
p = fminsearch ('MSE',p0);


K=p(1); % Ganho DC
zeta=p(2); % Fator de Amortecimento
wn=p(3); % Frequência Natural

fprintf('Zeta: %.4f\n', zeta);
fprintf('Frequência Natural: %.4f\n', wn);
fprintf('K: %.4f\n', K);

%--------------------------------------
% Dados - Valores Medidos de Entrada e Saída
% load GrupoRobo_A
%--------------------------------------
load GrupoRobo_10.mat
data=z1;
u=data(1,2); % Amplitude do degrau de entrada
ym = data(:,1); % Saída Medida
%--------------------------------------
% tempo é vetor de instantes de tempo - segundos
%-----------------------------------------------
T=0.01; % Intervalo de amostrgem
tempo=linspace(0,0.01,length(ym))';%transposto
%-----------------------------------------------
% Resposta Esperada
%----------------------------------------------------------
%ym_esp = subamortecido(tempo,u,K,zeta,wn);
ym_esp = subamortecido(tempo,u,1.0022,0.5000,1207.5308);

plot(tempo,ym);
hold on;
plot(tempo,ym_esp)
title('Função e Aproximação de 1ª Ordem');
xlabel('Tempo');
ylabel('Função');
legend('Função Original',"Aproximação de 2ª ordem");
grid on;

%------------------------------------------

%Calculo do erro
squared_error = (ym - ym_esp).^2;
mean_squared_error = mean(squared_error);
rmse = sqrt(mean_squared_error);

fprintf('MSE: %.4f\n', mean_squared_error);
fprintf('RMSE: %.4f\n', rmse);