#include <iostream>
#define cimg_display 0
#include "CImg.h"

using namespace cimg_library;

// Função para gerar e salvar uma imagem
void salvarImagem(const CImg<unsigned char>& imagem, const std::string& nomeArquivo) {
    imagem.save_png(nomeArquivo.c_str());
}



int main() {
    // Tamanho da imagem
    const int width = 800;
    const int height = 600;


    CImg<unsigned char> imagem1(width, height, 1, 3, 0);

    // Preencha a imagem com um degradê
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            imagem1(x, y, 0) = static_cast<unsigned char>(x / static_cast<double>(width) * 255);
            imagem1(x, y, 1) = static_cast<unsigned char>(y / static_cast<double>(height) * 255);
            imagem1(x, y, 2) = 127; // Valor fixo para o canal azul
        }
    }



    CImg<unsigned char> imagem2(width, height, 1, 3, 0);

    // Desenhar um retângulo verde na imagem2
    const unsigned char verde[] = { 0, 255, 0 };
    imagem2.draw_rectangle(100, 100, 300, 300, verde, 1.0f);




    CImg<unsigned char> imagem3(width, height, 1, 3, 0);

    // Desenhar um círculo verde na imagem3
    imagem3.draw_circle(400, 400, 100, verde, 1.0f);




    CImg<unsigned char> imagem4(width, height, 1, 3, 0);

    // Linha verde no centro da primeira imagem
    imagem4.draw_line(0, height / 2, width, height / 2, verde, 1.0f);


    // Linha vermelha no centro da primeira imagem
    const unsigned char vermelho[] = { 255, 0, 0 };
    imagem4.draw_line(width / 2, 0, width / 2, height, vermelho, 1.0f);




    
    // Salvar as cinco imagens em formato PNG
    salvarImagem(imagem1, "imagem1.png");
    salvarImagem(imagem2, "imagem2.png");
    salvarImagem(imagem3, "imagem3.png");
    salvarImagem(imagem4, "imagem4.png");

    return 0;
}
