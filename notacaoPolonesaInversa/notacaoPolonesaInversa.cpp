#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class noPilha{
    public:
        char dado;
        noPilha* prox;
};

class pilha{
    public:
        int cont, n;
        noPilha* inicio;

        void cria(){
            cont = 0;
            inicio = 0;
            n = 0;
        }

        void empilha(char dado){
            auto* no = new noPilha{.dado = dado, .prox = this -> inicio};
            this -> inicio = no;
            cont++;
            n++;
        }

        string desempilha(){
            char dado = this -> inicio -> dado;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont--;

            return dado;
        }
};


class noFila{
    public:
        char dado;
        noFila* prox;
};

class fila{
    public:
        int cont;
        noFila* inicio;
        noFila* fim;

        void cria(){
            cont = 0;
            inicio = 0;
            fim = 0;
        }

        void enfileira(char dado){
            auto* no = new noFila{.dado = dado, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                fim -> prox = no;
                fim = no;
            }
            cont++;
        }

        void desenfileira(){
            auto dado = inicio -> dado;
            noFila* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont --;
        }
};

void separaExpressao(string dado, struct pilha* p, struct fila* f){
    int i;
    for(i=0; i<dado.length(); i++){
        if(dado[i] == '+' | dado[i] == '-' | dado[i] == '*' | dado[i] == '/'){
            p->empilha(dado[i]);
        } else {
            f->enfileira(dado[i]);
        }
    }
}

void notacaoPolonesaInv(struct pilha* p, struct fila* f){
    int i;
    int tam = f->cont;
    noPilha* pi = p->inicio;
    for(i=0; i<tam; i++){
        
    }
}

int main(void){
    string dado;
    fila dados;
    pilha operadores;

    cout << "Digite a expressao: ";
    cin >> dado;
}