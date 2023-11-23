%% Exercicio 1
fs = 44100;
t = 0 : 1/fs : 2;
f = 1000;
A = 0.2;
w = 15 * pi/180;
y = A * sin(2*pi * f * t + w);
plot(t, y)
xlabel('Tempo (s)')
ylabel('Amplitude')
sound(y, fs, 16);

%% Exercicio 2
% Cancelamento de Fase
fs = 44100; % frequêcia de amostragem (Hz)
t = 0 : 1/fs : 5; % coordenada - tempo (segundos)
f1 = 440; % frequêcia (Hz)
f2 = 441;
A1 = .3;
A2 = .3;
w1 = 0; % Fase em graus
w2 = 90; % Fase em graus
y1 = A1 * sin(2 * pi * f1 * t + w1 * pi/180);
y2 = A2 * sin(2 * pi * f2 * t + w2 * pi/180);
y = (y1+y2)/2;
plot(t,y);
sound(y, fs, 16);

%% Exercicio 3
%Efeito de Batidas
fs = 44100;
t = 0 : 1/fs : 5;
f1 = 300;
f2 = 330;
A = .5;
w = 0 * pi/180; % graus
y1 = A * sin(2 * pi * f1 * t + w);
y2 = A * sin(2 * pi * f2 * t + w);
y=[y1;y2];
sound(y, fs, 16);

%% Exercicio 4
fs = 44100; % Frequência de amostragem(Hz)
t = 0 : 1/fs : 5; % % coordenada - tempo (segundos)
f1 = 440; % frequência (Hz)
f2 = 2 * f1;
f3 = 3 * f1;
f4 = 4 * f1;
A1 = .3; A2 = A1/2; A3 = A1/3; A4 = A1/4;
w = 0; % Fase
y1 = A1 * sin( 2 * pi * f1 * t + w );
y2 = A2 * sin( 2 * pi * f2 * t + w );
y3 = A3 * sin( 2 * pi * f3 * t + w );
y4 = A4 * sin( 2 * pi * f4 * t + w );
y = (y1+y2+y3+y4)/4;
sound( y, fs, 16 ); % reprodução da onda senoidal

%% Exercicio 5
n=-5:7;
x=4*cos(0.1*pi*n+pi/3)+3*sin(0.3*pi*n+pi);
stem (n,x)

