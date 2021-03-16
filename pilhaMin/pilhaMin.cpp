#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

template <typename tipo>
class noPilha{
    public:
        tipo dado;
        noPilha* prox;
};

template <typename tipo>
class pilha{
    public:
        noPilha<tipo>* inicio;
        int cont, i;
        void cria(){
            inicio = 0;
            cont = 0;
        }
        void libera(){
            for(i=0; i<cont; i++){
                noPilha<tipo>* p = this -> inicio -> prox;
                delete this -> inicio;
                this -> inicio = p;
                cont--;
            }
        }
        void empilha(tipo dado){
            auto* pi = new noPilha<tipo>{.dado = dado, .prox = inicio};
            inicio = pi;
            cont++;
        }
        void desempilha(){
            noPilha<tipo>* pi = this -> inicio -> prox;
            auto dado = this -> inicio->dado;
            delete this -> inicio;
            this -> inicio = pi;
            cont --;
        }
        int topo(){
            return this -> inicio ->dado;
        }
    
};

template <typename tipo>
tipo pilhaMin(struct pilha<tipo>* p){
    noPilha<tipo>* pi = p->inicio;
    tipo minimo = pi->dado;

    while(pi != 0){
        if(pi -> dado < minimo){
            minimo = pi->dado;
        }
        pi = pi->prox;
    }
    return minimo;
}

int main(void){
    pilha<int> p1;
    p1.cria();

    p1.empilha(5);
    p1.empilha(2);
    p1.empilha(3);

    cout << "\nO menor valor dessa pilha eh: " << pilhaMin(&p1) << "\n\n";
    
}