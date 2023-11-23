% Função que calcula a resposta no domínio do tempo de um sistema
% de 2a. ordem subamortecido
function y = subamortecido(tempo,u,K,zeta,wn)
 wd = wn*sqrt(1-zeta^2); % Frequência Natural Amortecida
 phi = atan(sqrt(1-zeta^2)/zeta ); % Fase
% Número de pontos em que a função será calculada
N = length(tempo);
% Cálculo da resposta esperada no domínio do tempo
%-------------------------------------------------------------------------
y = zeros(N,1);
for k=1:N
 t = tempo(k);
 if ( t > 0 )
 y(k) = u*(K-K/sqrt(1-zeta^2)*exp(-zeta*wn*t)*sin(wd*t+phi));
 else
 y(k) = 0;
 end
end
%-------------------------------------------------------------------------