#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

class noPilha{
    public:
        string dado;
        noPilha* proximo;
};

class pilha{
    public:
        noPilha* inicio; 
        int cont, i;

        void cria(){
            this -> inicio = 0;
            this -> cont = 0;
        }

        void empilha(string dado){
            auto* no = new noPilha{.dado = dado, .proximo = this -> inicio};
            this -> inicio = no;
            this -> cont++;
        }

        void desempilha(){
            noPilha* pi = this -> inicio -> proximo;
            delete this -> inicio;
            this -> inicio = pi;
            this -> cont--;
        }

        void libera(){
            for(i=0; i<cont; i++){
                noPilha* pi = this -> inicio -> proximo;
                delete this -> inicio;
                this -> inicio = pi;
            }
            cont = 0;
        }

        string topo(){
            return this -> inicio -> dado;
        }
};

int main(void){
    pilha p1;
    pilha p2;

    p1.cria();
    p2.cria();

    p1.empilha("9");
    p1.empilha("7");
    p1.empilha("9");
    p1.desempilha();
    p1.empilha("1");
    p2.empilha("a");
    
    cout << "\n\n" << p1.topo() << "\n\n";
}