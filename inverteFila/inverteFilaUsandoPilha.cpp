#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


class noPilha{
    public:
        string dado;
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

        void empilha(string dado){
            auto* no = new noPilha{.dado = dado, .prox = this -> inicio};
            this -> inicio = no;
            cont++;
            n++;
        }

        string desempilha(){
            string dado = this -> inicio -> dado;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont--;

            return dado;
        }
};


class noFila{
    public:
        string dado;
        noFila* prox;
};

class fila{
    public:
        int cont, n;
        noFila* inicio;
        noFila* fim;

        void cria(){
            cont = 0;
            n = 0;
            inicio = 0;
            fim = 0;
        }

        void enfileira(string dado){
            auto* no = new noFila{.dado = dado, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                fim -> prox = no;
                fim = no;
            }
            cont++;
            n++;
        }

        void desenfileira(){
            auto dado = inicio -> dado;
            noFila* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont --;
        }
};

void filaParaPilha(struct fila* f, struct pilha* p){
    if(f->cont == 0){
        return;
    } else {
        p->empilha(f->inicio->dado);
        f->desenfileira();
        filaParaPilha(f,p);
    }
}

void pilhaParaFila(struct pilha* p, struct fila* f){
    if(p->cont == 0){
        return;
    } else {
        f->enfileira(p->inicio->dado);
        p->desempilha();
        pilhaParaFila(p, f);
    }
}

void printFila(struct fila* f){
    noFila* fi;
    fi = f->inicio;
    while(fi != 0){
        cout << fi->dado << " ";
        fi = fi->prox;
    }
}

int main(void){
    fila f1;
    fila aux1;
    fila aux2;

    pilha p1;

    f1.cria();
    aux1.cria();
    aux2.cria();

    p1.cria();  

    f1.enfileira("1");
    f1.enfileira("2");
    f1.enfileira("3");
    f1.enfileira("4");
    f1.enfileira("5");
    
    //Invertendo uma fila usando uma pilha
    cout << "Fila f1: ";
    printFila(&f1);

    filaParaPilha(&f1, &p1);
    pilhaParaFila(&p1, &f1);

    cout << "\nFila f1 invertida: ";
    printFila(&f1);
    
    cout << "\n\n";
}