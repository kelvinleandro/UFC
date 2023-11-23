% Função que mede a qualidade do modelo de 2a ordem subamortecido
function J = MSE(p)
% Parâmetros do modelo matemático
% p = [K,zeta,wn]
%--------------------------------------
 K=p(1); % Ganho DC
 zeta=p(2); % Fator de Amortecimento
 wn=p(3); % Frequência Natural
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
%T=0.01; % Intervalo de amostrgem
tempo=linspace(0,0.01,length(ym))';%transposto
%-----------------------------------------------
% Resposta Esperada
%----------------------------------------------------------
 ym_esp = subamortecido(tempo,u,K,zeta,wn);
 %---------------------------------------------------------
 % Cálculo Erro Quadrático Médio (MSE)
 erro = ym - ym_esp ;
 J = mean(erro.^2);
end