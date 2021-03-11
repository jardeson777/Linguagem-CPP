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
        string frente;

        void cria(){
            cont = 0;
            inicio = 0;
            n = 0;
        }

        void libera(){

        }

        void empilha(string dado){
            auto* no = new noPilha{.dado = dado, .prox = this -> inicio};
            this -> inicio = no;
            if(cont == 0){
                frente = dado;
            }

            cont++;
            n++;
        }

        string desempilha(){
            string dado = this -> inicio -> dado;
            noPilha* p = this -> inicio -> prox;
            delete inicio;
            inicio = p;
            cont--;

            return dado;
        }
};


int main(void){
    int opcao, i;
    int chaveSeletora = 1;
    string resposta;
    pilha p1;
    pilha p2;

    p1.cria();
    p2.cria();

    while (true){
        cout << "\n-----------------MENU-----------------";
        cout << "\n1 - Enfileirar";
        cout << "\n2 - Desenfileirar";
        cout << "\n3 - Frente";
        cout << "\n4 - Liberar";
        cout << "\n5 - Sair\n\n";
        cout << "Qual opcao vc escolhe: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                cout << "\n--------------------------------------\n";
                cout << "Qual valor voce deseja enfileirar? ";
                cin >> resposta;

                if(chaveSeletora == 1){
                    p1.empilha(resposta);
                } else {
                    for(i=0; i<p2.n; i++){
                        p1.empilha(p2.inicio->dado);
                        p2.desempilha();
                    }
                    p1.empilha(resposta);
                    chaveSeletora = 1;
                }
            break;

            case 2:
                if(chaveSeletora == 1){
                    if(p1.cont>0){
                        for(i=0; i<p1.n-1; i++){
                            p2.empilha(p1.inicio->dado);
                            p1.desempilha();
                        }
                        chaveSeletora = 2;

                        string dado = p1.desempilha();
                        p1.n = 0;

                        cout << "\n--------------------------------------\n";
                        cout << "O dado " << dado << " foi desenfilerado";
                    } else {
                        cout << "\n--------------------------------------\n";
                        cout << "Nao tem nenhum dado na fila";
                    }
                } else {
                    if(p2.cont > 0){
                        string dado = p2.desempilha();
                        p2.n = 0;

                        cout << "\n--------------------------------------\n";
                        cout << "O dado " << dado << " foi desenfilerado";
                    } else {
                        cout << "\n--------------------------------------\n";
                        cout << "Nao tem nenhum dado na fila";
                    }
                }
            break;

            case 3:
                if(chaveSeletora == 1 && p1.cont > 0){
                    cout << "\n--------------------------------------\n";
                    cout << "Frente: " << p1.frente;
                } 
                else if((p1.cont == 0 && p2.cont == 0)){
                    cout << "\n--------------------------------------\n";    
                    cout << "Nao possui nenhum dado na fila";
                } else {
                    cout << "\n--------------------------------------\n";
                    cout << "Frente: " << p2.inicio->dado;
                }
            break;

            case 4:
                if(chaveSeletora == 1){
                    for(i=0; i<p1.n; i++){
                        p1.desempilha();
                    }
                    p1.n = 0;
                    cout << "\n--------------------------------------\n";
                    cout << "Todos os dados foram liberados";
                } else {
                    for(i=0; i<p2.n; i++){
                        p2.desempilha();
                    }
                    p2.n = 0;
                    cout << "\n--------------------------------------\n";
                    cout << "Todos os dados foram liberados";
                }
            break;

            case 5:
                exit(0);
            break;
        }
    }
}