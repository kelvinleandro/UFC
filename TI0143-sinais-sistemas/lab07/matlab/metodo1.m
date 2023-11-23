%% Lendo os dados e plotando o sinal
load GrupoRobo_10.mat;
y = z1(:,1);
u = z1(1,2);
x = 0:0.01:(length(y)-1)*0.01;
figure(1);
plot(x,y);
%% Pelo método 1
[max_value, max_index] = max(y); % valor de pico
diff = y-y(end);
stateindex = min(find(diff>0)); % tempo de subida
sobressinal_percentagem = abs(y(max_index)-y(stateindex))/y(stateindex);
sobressinal = -1*log(sobressinal_percentagem)/sqrt(pi^2+(log(sobressinal_percentagem))^2);
fprintf('Sobressinal (zeta): %.4f\n', sobressinal);

%Calculando a frequência natural
tpico = x(max_index);
frequencia_natural = pi/(tpico*sqrt(1-sobressinal^2));
fprintf('Frequencia natural (wn): %.4f\n', frequencia_natural);

%Encontrar o K
K=y(end) / u;
fprintf('K: %.4f\n', K/u);

%Função transferência
syms s t
G = (K*frequencia_natural^2)/(s^2+2*frequencia_natural*sobressinal*s+frequencia_natural^2);
X = u/s;
Y = G*X;
f = ilaplace(Y, s, t);
f_aprox = subs(f, t, x);  % Evaluate the function for time values
%% Plotagem do método 1
figure(2);
plot(x,y);
hold on;
plot(x,f_aprox)
title('Função e Aproximação de 1ª Ordem');
xlabel('Tempo');
ylabel('Função');
legend('Função Original',"Aproximação de 2ª ordem", "Location","southeast");
grid on;
hold off;

%Calculo do erro
mse = mean((f_aprox' - y).^2);
rmse = sqrt(mse);

fprintf('MSE: %.4f\n', mse);
fprintf('RMSE: %.4f\n', rmse);