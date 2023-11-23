%% reproducao e plotagem do sinal da musica
music = '01_MULHERES.wav';
[y,fs]= audioread(music);
x=y(:,1);
figure(1);
plot(x);
fprintf('fs = %.0f\n', fs);
player = audioplayer(y, fs);
play(player);
%% reproducao do audio invertido
reverso = flipud(y);
player = audioplayer(reverso, fs);
play(player);
%% reproducao do audio acelerado
rapido = round(fs * 1.75);
player = audioplayer(y, rapido);
play(player);
%% reproducao do audio devagar
devagar = round(fs * 0.75);
player = audioplayer(y, devagar);
play(player);
%% deslocamento e compressao de sinal qualquer
transforma_sinal = @(x, n, a, b) x(a*n + b);

n = linspace(0, 10, 100);
y1 = cos(n);
y2 = transforma_sinal(@cos, n, 1, -pi/2);

figure;
plot(n, y1, 'DisplayName', 'y(n)');
hold on;
plot(n, y2, 'DisplayName', 'y(a*n + b)');
xlabel('n');
ylabel('y(n)');
grid on;
legend();