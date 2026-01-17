#include <iostream>
#include "images.h"
#include <vector>

int kernel[3][3] = {
    {1, 2, 1},
    {2, 4, 2},
    {1, 2, 1}};

int main()
{
  int largura, altura, canais;
  unsigned char *imagem = stbi_load("imagens/piccolo.jpg", &largura, &altura, &canais, 0);
  if (!imagem)
  {
    std::cout << "oh, não achei essa imagem não viu!" << std::endl;
    return -1;
  }
  std::cout << largura << "-" << altura << "-" << canais << std::endl;
  std::vector<unsigned char> imagem_borrada(largura * altura * canais, 0);
  for (int y = 0; y < altura; y++)
  {
    for (int x = 0; x < largura; x++)
    {
      unsigned int indice = (y * largura + x) * canais;
      unsigned char *r, *g, *b;
      r = &imagem[indice];
      g = &imagem[indice + 1];
      b = &imagem[indice + 2];

      int somar = 0;
      int somag = 0;
      int somab = 0;
      for (int ky = -1; ky <= 1; ky++)
      {
        for (int kx = -1; kx <= 1; kx++)
        {
          if (y + ky < altura && x + kx < largura && y + ky > 0 && x + kx > 0)
          {
            unsigned int indice_offset = (((y + ky) * largura) + (x + kx)) * canais;
            int peso = kernel[ky + 1][kx + 1];
            somar += imagem[indice_offset] * peso;
            somag += imagem[indice_offset + 1] * peso;
            somab += imagem[indice_offset + 2] * peso;
          }
        }
      }
      int valorr = abs(somar / 16);
      int valorg = abs(somag / 16);
      int valorb = abs(somab / 16);
      valorr = (valorr > 255) ? 255 : valorr;
      valorg = (valorg > 255) ? 255 : valorg;
      valorb = (valorb > 255) ? 255 : valorb;
      imagem_borrada[indice] = valorr;
      imagem_borrada[indice + 1] = valorg;
      imagem_borrada[indice + 2] = valorb;
    }
  }
  stbi_write_png("imagens/picolo_miope.png", largura, altura, canais, imagem_borrada.data(), 0);
  return 0;
}