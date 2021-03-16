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

void copiaPilha(struct noPilha* pi, struct pilha* p, int cont, int n){
    if(cont == n){
        cont--;
        n--;
    } else {
        pi = pi->prox;
        cont++;
        copiaPilha(pi, p, cont, n);
        p->empilha(pi->dado);
    }
}

int main(void){
    int i, j;
    pilha p1;
    pilha p2;
    pilha p3;
    pilha aux1;
    pilha aux2;
    pilha aux3;

    p1.cria();
    p2.cria();
    p3.cria();
    aux1.cria();
    aux2.cria();
    aux3.cria();

    fila f1;
    f1.cria();

    p1.empilha("1");
    p1.empilha("2");
    p1.empilha("3");
    p1.empilha("4");
    p1.empilha("5");

    p2.empilha("1");
    p2.empilha("2");
    p2.empilha("3");
    p2.empilha("4");
    p2.empilha("5");

    p3.empilha("1");
    p3.empilha("2");
    p3.empilha("3");
    p3.empilha("4");
    p3.empilha("5");

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
    
    cout << "\nPilha p1 invertida: ";
    for(i=0; i<p1.n; i++){
        cout << p1.inicio -> dado << " ";
        p1.desempilha();
    }
    cout <<"\n\n";

    //A troca de ordem de p2 será usando duas pilhas
    cout << "Pilha p2: ";
    for(i=0; i<p2.n; i++){
        aux1.empilha(p2.inicio->dado);
        cout << p2.inicio->dado << " ";
        p2.desempilha();
    }

    for(i=0; i<aux1.n; i++){
        aux2.empilha(aux1.inicio->dado);
        aux1.desempilha();
    }

   
    for(i=0; i<aux2.n; i++){
        p2.empilha(aux2.inicio->dado);
        aux2.desempilha();
    }

    noPilha* p;
    p = p2.inicio;
    cout << "\nPilha p2 invertida: ";
    while(p != 0){
        cout << p->dado << " ";
        p = p->prox;
    }
    cout <<"\n";

    //A troca de ordem de p3 será usando uma pilha
    noPilha* pi;
    int k=p3.n - 1;
    int cont = 0;

    pi = p3.inicio;
    copiaPilha(pi,&aux3, cont, k);
    aux3.empilha(pi->dado);

    cout << "\nPilha p3: ";
    for(i=0; i<p3.n; i++){
        cout << p3.desempilha() << " ";
    }

    p3.n=0;

    for(i=0; i<aux3.n; i++){
        p3.empilha(aux3.inicio->dado);
        aux3.desempilha();
    }

    pi = p3.inicio;
    cout << "\nPilha p3 invertida: ";
    while(pi != 0){
        cout << pi->dado << " ";
        pi = pi->prox;
    }
    cout << "\n\n";
}
