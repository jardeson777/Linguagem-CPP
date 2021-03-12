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

        void desempilha(){
            string dado = this -> inicio -> dado;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont--;
        }
};


class noFila{
    public:
        string dado;
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

        void enfileira(string dado){
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


int main(void){
    int i;
    pilha p1;
    pilha p2;
    pilha p3;
    p1.cria();
    p2.cria();
    p3.cria();
    fila f1;
    f1.cria();

    p1.empilha("1");
    p1.empilha("2");
    p1.empilha("3");
    p1.empilha("4");
    p1.empilha("5");

    p2.empilha("6");
    p2.empilha("7");
    p2.empilha("8");
    p2.empilha("9");
    p2.empilha("10");

    p3.empilha("11");
    p3.empilha("12");
    p3.empilha("13");
    p3.empilha("14");
    p3.empilha("15");

    //A troca de ordem de p1 será usando uma fila

    cout << "Pilha p1: ";
    for(i=0; i<p1.n; i++){
        f1.enfileira(p1.inicio->dado);
        cout << p1.inicio -> dado << " ";
        p1.desempilha();
    }

    for(i=0; i<p1.n; i++){
        p1.empilha(f1.inicio->dado);
        f1.desenfileira();
        p1.n--;
    }
    
    cout << "\n\nPilha p1 invertida: ";
    for(i=0; i<p1.n; i++){
        cout << p1.inicio -> dado << " ";
        p1.desempilha();
    }
    cout <<"\n\n";
}