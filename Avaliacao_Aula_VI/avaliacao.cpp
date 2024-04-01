#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "util.h"

int main() {
    int tamanhoListaGenerica, tamanholistaInterna;
    ListaGenerica* listaGenerica = NULL;

    // Recebendo tamanho da lista genérica e das listas internas
    cout << "Quantas listas deseja gerar?" << endl;
    cin >> tamanhoListaGenerica;
    fflush(stdin);
    cout << "Quantos elementos deseja gerar em cada lista?" << endl;
    cin >> tamanholistaInterna;
   
    // Populando lista genérica
    listaGenerica = popularListaGenerica(listaGenerica, tamanhoListaGenerica, tamanholistaInterna);

    // Exibir conteúdo das listas
    exibirListaGenerica(listaGenerica);

    // Mostrar números que aparecem em todas as listas
    exibirValoresIguais(listaGenerica, tamanhoListaGenerica);

    // Mostrar números que aparecem em somente uma lista
    //exibirValoresUnicos(listaGenerica);

    return 1;
}