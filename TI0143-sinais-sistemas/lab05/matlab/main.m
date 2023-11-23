%% Atividade 1.a
t = -1:0.01:5;
a = 10;
u = heaviside(t);
x = exp(-a*t) .* u;
h = sin(a*t) .* u;

figure(1);
subplot(1, 2, 1);
plot(t, x, 'color', [0, 0.2, 0.4], 'LineWidth', 1.5);
grid on;
xlabel('Tempo (s)');
ylabel('x(t)');
title('Gráfico de x(t)');

subplot(1, 2, 2);
plot(t, h, 'color', [0.5, 0, 0], 'LineWidth', 1.5);
grid on;
xlabel('Tempo (s)');
ylabel('h(t)');
title('Gráfico de h(t)');
sgtitle('Gráficos de x(t) e h(t)');
%% Atividade 1.b
figure(2);
plot(-t, h, 'r', 'LineWidth', 1.5, 'DisplayName', 'h(-t)');
hold on;
plot(t, x, 'g', 'LineWidth', 1.5, 'DisplayName', 'x(t)');
title('Gráfico das funções h(-t) e x(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');
legend();
grid on;
%% Atividade 1.c
conv = conv(h, x, 'same');
figure(3);
plot(t, conv, 'LineWidth', 1.5);
title('Convolução de h(t) e x(t)');
xlabel('Tempo (s)');
ylabel('Amplitude');
grid on;
%% Atividade 2
t = linspace(-2, 6, 1000);
a = -0.5; b = 0.5;

x = double(t >= a & t <= b);
g = max(t, 0);
h = heaviside(t) - heaviside(t - 5);

figure(4);
plot(t, x, 'b', 'LineWidth', 1.5, 'DisplayName', 'x(t): pulso retangular unitário');
hold on;
plot(t, g, 'g', 'LineWidth', 1.5, 'DisplayName', 'g(t): rampa unitária');
plot(t, h, 'r', 'LineWidth', 1.5, 'DisplayName', 'h(t)');
xlabel('t');
ylabel('f(t)');
legend();
grid on;
%% Atividade 2 - Comutatividade
conv_xh = conv(x, h, 'same');
conv_hx = conv(h, x, 'same');

figure(5);
subplot(1, 2, 1);
plot(t, conv_xh, 'color', [0, 0.2, 0.6], 'LineWidth', 1.5);
grid on;
title('Conv(x, h)');
xlabel('Tempo (t)');
ylabel('Amplitude');

subplot(1, 2, 2);
plot(t, conv_hx, 'color', [0, 0.4, 0], 'LineWidth', 1.5);
grid on;
title('Conv(h, x)');
xlabel('Tempo (t)');
ylabel('Amplitude');
sgtitle('Resultados da Convolução');

%% Atividade 2 - Distributividade
conv1 = conv(x, h + g, 'same');
conv2 = conv(x, h, 'same') + conv(x, g, 'same');

figure(6);
subplot(1, 2, 1);
plot(t, conv1, 'color', [0.5, 0, 0.8], 'LineWidth', 1.5);
grid on;
title('Conv(x, h+g)');
xlabel('Tempo (t)');
ylabel('Amplitude');

subplot(1, 2, 2);
plot(t, conv2, 'color', [0.6, 0, 0], 'LineWidth', 1.5);
grid on;
title('Conv(x, h) + Conv(x, g)');
xlabel('Tempo (t)');
ylabel('Amplitude');
sgtitle('Resultados das Convoluções');