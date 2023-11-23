%% gerando e plotando o sinal
t = -1:0.001:1;
y = cos(2*pi*t) + sin(0.5*pi*t) + 2;

% Frequencia angular (ciclos/seg) e em Hertz
w_cos = 2*pi;
f_cos = w_cos / (2*pi);  % 1 Hertz
w_sin = 0.5*pi;
f_sin = w_sin / (2*pi);  % 0.25 Hertz

figure(1)
plot(t, y)
xlabel('t')
ylabel('y(t)')
grid on
%% contradominio e periodo
contradominio = [min(y), max(y)];
disp(['contradominio = ', num2str(contradominio)])

T = 2*pi / w_sin;
disp(['Periodo = ', num2str(T)])
%% discretizacao para y[n]
Ts = 0.01;
Fs = 1 / Ts;
n = -100:100;
y = @(n) cos(2*pi*n*Ts) + sin(0.5*pi*n*Ts) + 2;
y_n = y(n);

f_cos_disc = f_cos / Ts;
w_cos_disc = 2*pi*(f_cos/Fs);
f_sin_disc = f_sin / Ts;
w_sin_disc = 2*pi*(f_sin/Fs);

disp(['Frequência do cosseno: ', num2str(f_cos_disc), ' ciclos/amostra']);
disp(['Frequência angular do cosseno: ', num2str(w_cos_disc), ' rads/amostra']);
disp(['Frequência do seno: ', num2str(f_sin_disc), ' ciclos/amostra']);
disp(['Frequência angular do seno: ', num2str(w_sin_disc), ' rads/amostra']);
disp(['Contradominio = [', num2str(min(y_n)), ',', num2str(max(y_n)), ']']);

figure(2);
stem(n, y_n, 'BaseValue', 0);
xlabel('n');
ylabel('y(n)');
grid on;
%% componente par do sinal
% Define even_component function
even_component = @(f, x) (f(x) + f(-x)) / 2;

% Calculate even component
par = even_component(y, n);

% Plot the even component
figure(3);
stem(n, par, 'BaseValue', 0);
xlabel('n');
ylabel('y[n]');
grid on;
%% componentes pares e impares do sinal
% Define signal_components function
signal_components = @(f, x) [(f(x) + f(-x)) / 2 ; (f(x) - f(-x)) / 2];

% Calculate even and odd components
components = signal_components(y, n);
par = components(1,:);
impar = components(2,:);

% Plot the signal and its components
figure(4);
plot(n, par + impar, 'DisplayName', 'y[n]');
hold on;
plot(n, par, 'DisplayName', 'componente par');
plot(n, impar, 'DisplayName', 'componente impar');
xlabel('n');
ylabel('y[n]');
legend();
grid on;