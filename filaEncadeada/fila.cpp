#include <iostream>
#include <string>
#include <stdio.h>
    using namespace std;


class noFila{
    public:
        string dado;
        noFila* prox;
};

class fila{
    public:
        noFila* inicio;
        noFila* fim;
        int cont;
        
        void cria(){
            inicio = 0;
            fim = 0;
            cont = 0;
        }

        // void libera(){
        //     while(cont>0){
        //         desenfileira();
        //     }
        // }

        void enfileira(string dado){
            auto* no = new noFila{.dado = dado, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                // fim -> prox = no;
                fim = no;
            }
            cout << inicio -> dado << " ";
            cout << fim -> dado << " ";
            cont++;
        }

        // void desenfileira(){

        // }
};

int main(void){
    fila f1;
    string n;
    f1.cria();
    f1.enfileira("1");
    cout << "\n";
    f1.enfileira("2");
    cout << "\n";
    f1.enfileira("3");
    cout << "\n";
    f1.enfileira("4");
}