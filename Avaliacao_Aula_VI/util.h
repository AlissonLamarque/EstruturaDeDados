typedef struct no {
    int dado;
    struct no *prox;
} Lista;

typedef struct na{
    Lista *lista;
    struct na *prox;
} ListaGenerica;


int contar(Lista *lista){
    Lista *p;
    int qtd = 0;
    for (p = lista; p; p = p->prox) {
        qtd++;
    }
    return qtd;
}

bool contem(Lista *lista, int valor){
    Lista *p;
    
    for (p = lista; p; p = p->prox) {
        if (p->dado == valor) return true;
    }
    return false;
}

Lista *inserir(int valor, Lista *lista) {
    //alocar memoria
    Lista *novo;
    novo = (Lista*)malloc(sizeof(Lista));

    //depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    //engatar novo na sua posicao
    Lista *p, *pR;
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
        if (valor == p->dado) {
            free(novo);
            return lista;
        }
        if (valor < p->dado) {
            //achei a posicao
            break;
        }
    }
    //inserir na primeira posicao
    if (p == lista) {
        novo->prox = p;
        return novo;
    }
    //inserir na ultima posicao
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //inserir em alguma posicao do meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

void exibir(Lista *lista) {
    Lista *p;
    for (p = lista; p; p = p->prox) {
        cout << p->dado << ", ";
    }
}

void exibirListaGenerica(ListaGenerica *lista) {
    ListaGenerica *pGenerica;
    Lista *p;
    int qtd = 0;
    for (pGenerica = lista; pGenerica; pGenerica = pGenerica->prox ) {
        cout << "Exibindo lista " << qtd+1 << ":" << endl; 
        for (p = pGenerica->lista; p; p = p->prox) {
            cout << p->dado << ", ";
        }
        cout << endl;
        qtd++;
    }
}

void exibirValoresIguais(ListaGenerica *lista, int tamanhoListaGenerica){ // ESTA COMPARANDO TUDO DUAS VEZES
    ListaGenerica *pGenerica;
    Lista *p;
    Lista *p2;
    ListaGenerica *pGAux;
    Lista *listaR = NULL;
    ListaGenerica *teste = lista;
    int contador;

    cout << "Exibindo valores que aparecem em todas as listas:" << endl;
    //Rodando lista genérica
    for (pGenerica = lista; pGenerica; pGenerica = pGenerica->prox) {
        //Rodando lista interna
        for (p = teste->lista; p; p = p->prox) {
            contador = 1;
            /*
            //for (p = pGenerica->lista; p; p = p->prox) {
            O problema está na declaração do FOR porque está comparando lista1 - lista2, lista2 - lista3, lista3 - lista4
            */
            pGAux = pGenerica->prox;
            while (pGAux){
                for (p2 = pGAux->lista; p2; p2 = p2->prox){
                    cout << "Comparando " << p->dado << " com " <<  p2->dado << endl;
                    if (p->dado == p2->dado){                                         /* Está inserindo após comparar apenas com a próxima lista */
                        contador++;
                        cout << "+1 ponto para -> " << p->dado << " - " << p2->dado << endl;
                    }
                }
                pGAux = pGAux->prox; //Manda para proxima lista da generica
            }

            if (contador == tamanhoListaGenerica) {
                listaR = inserir(p->dado, listaR);
                cout << p->dado << " inserido - " << contador<< " - "<< tamanhoListaGenerica << endl;
            }
        }
    }
    exibir(listaR);
}

ListaGenerica *empilharLista(Lista *lista, ListaGenerica *listaGenerica){
    // Alocando espaço de lista genérica
    ListaGenerica *novo;
    novo = (ListaGenerica*)malloc(sizeof(ListaGenerica));

    // Inserindo lista interna na lista genérica
    novo->lista = lista;
    novo->prox = listaGenerica;

    // Retornando lista genérica atualizada
    return novo;
}

ListaGenerica *popularListaGenerica(ListaGenerica *listaGenerica, int qtdListas, int qtdElementos) {
    int valor;
    srand(time(NULL));

    // Laço para gerar a quantidade de listas definidas na lista genérica
    for (int i = 0; i < qtdListas; i++){
        Lista *lista = NULL;
        
        // Laço para gerar a quantidade de elementos definidos dentro das listas internas
        do {
            // Evitando duplicidade e inserindo elemento na lista interna
            valor = rand() % 10;
            if (!contem(lista, valor)) lista = inserir(valor, lista);

            // Garantindo que todas as listas terão a mesma quantidade de elementos
            if (contar(lista) == qtdElementos) {
                listaGenerica = empilharLista(lista, listaGenerica);
                break;
            }
        } while (contar(lista) < qtdElementos);
    }
    return listaGenerica;
}