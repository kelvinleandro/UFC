%% Atividade 1
load Equipe_10;
y=z1(:,1);
y = (y - min(y)) / (max(y) - min(y));
x=linspace(0,1000,length(y));
figure(1)
plot(x,y,"-b");
title("Temperatura x Tempo");
xlabel("Tempo");
ylabel("Temperatura");
%% Atividade 2
dy=gradient(y, x);
[slope, inflection_point] = max(dy);
inflexy = y(inflection_point);
n = inflexy - (slope * x(inflection_point));
tangent_line = slope * x + n;

atraso = find(dy ~= 0, 1);
x_atraso = x(atraso);
x_max_tau = (y(end) - n) / slope;
constempo = x_max_tau - x_atraso;

disp(['Atraso: ', num2str(atraso)]);
disp(['X[atraso]: ', num2str(x_atraso)]);
disp(['Constante de Tempo: ', num2str(constempo)]);

figure(2);
plot(x,y,'-b', 'DisplayName', 'Curva');
hold on;
plot(x(inflection_point), y(inflection_point), 'ro', 'DisplayName', 'Ponto de inflexão');
plot(x,tangent_line,'-.m', 'DisplayName', 'Reta Tangente');
title("Temperatura x Tempo");
xlabel("Tempo");
ylabel("Temperatura");
legend();
grid on;
hold off;
%% Atividade 2 plot
figure('Position', [100, 100, 1000, 400]);

% Plot the curve
subplot(1, 2, 1);
plot(x, y, '-b', 'LineWidth', 1.5, 'DisplayName', 'Curva');
hold on;

% Plot the tangent line
plot(x, tangent_line, '-.m', 'LineWidth', 1.5, 'DisplayName', 'Reta Tangente');

% Add horizontal line for K
y_k = y(end);
plot([x(1), x(end)], [y_k, y_k], ':r', 'LineWidth', 1.5, 'DisplayName', 'Ganho K');

% Add vertical lines for inflection point and tangent line = K
plot([x_atraso, x_atraso], [y(1), y(end)], '--g', 'LineWidth', 1.5, 'DisplayName', 'Ponto de Inflexão');
plot([x_max_tau, x_max_tau], [y(1), y(end)], '--m', 'LineWidth', 1.5, 'DisplayName', 'reta tangente = K');

title('Temperatura x Tempo');
xlabel('Tempo');
ylabel('Temperatura');
legend();
grid on;
xlim([0, 1000]);

hold off;
%% Atividade 3
syms s t;
G = y(end) * exp(-x(atraso) * s) / (constempo * s + 1);
U = 1 / s;
H = G * U;
h=matlabFunction(ilaplace(H));
h_t = h(x);

mse = mean((transpose(h_t) - y).^2);
fprintf('Mean Squared Error (MSE): %.4f\n', mse);

figure(3);
plot(x, h_t, 'r', 'DisplayName', 'Estimado');
hold on;
plot(x, y, 'b', 'DisplayName', 'Real');
title('Modelo');
legend();
xlabel('Tempo');
ylabel('Temperatura');
grid on;
hold off;
