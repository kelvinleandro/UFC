#include <iostream>
#include <vector>
#include "images.h"

struct cor
{
  unsigned char R;
  unsigned char G;
  unsigned char B;

  cor(unsigned char r, unsigned char g, unsigned char b) : R(r), G(g), B(b) {}
};

struct ponto
{
  float x;
  float y;

  ponto(float x0, float y0) : x(x0), y(y0) {}
};

bool compara_pontos(float xi, float xf, float x)
{
  if (xi > xf)
  {
    if (x < xf)
      return false;
    else
      return true;
  }
  else
  {
    if (x > xf)
      return false;
    else
      return true;
  }
}

std::vector<unsigned char> fazer_linha(std::vector<unsigned char> imagem,
                                       int largura, int altura,
                                       int canais, cor linha,
                                       ponto inicial, ponto final)
{
  inicial.y = -inicial.y;
  final.y = -final.y;
  inicial.x += ((float)largura) / 2;
  final.x += ((float)largura) / 2;
  inicial.y += ((float)altura) / 2;
  final.y += ((float)altura) / 2;

  float a = (final.y - inicial.y) / (final.x - inicial.x);
  float b = inicial.y - a * inicial.x;

  for (int x = inicial.x; compara_pontos(inicial.x, final.x, x); x += inicial.x > final.x ? -1 : 1)
  {
    for (int y = inicial.y; compara_pontos(inicial.y, final.y, y); y += inicial.y > final.y ? -1 : 1)
    {
      int indice = ((y * largura + x) * canais);
      if (y == (int)(a * x + b))
      {
        imagem[indice] = linha.R;
        imagem[indice + 1] = linha.G;
        imagem[indice + 2] = linha.B;
      }
    }
  }

  return imagem;
}

int main()
{

  int largura = 1280;
  int altura = 720;
  int canais = 3;

  std::vector<unsigned char> imagem(largura * altura * canais, 0);
  imagem = fazer_linha(imagem, largura, altura, canais, cor(200, 150, 0), ponto(-200, -200), ponto(100, 100));
  stbi_write_png("imagens/linha.png", largura, altura, canais, imagem.data(), 0);
  return 0;
}
