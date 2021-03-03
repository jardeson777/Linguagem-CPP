#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class noPilhaEnc{
    public:
        string dado;
        noPilhaEnc* prox;
};

class pilhaEnc{
    public:
        noPilhaEnc* inicio;
        int n;

        void cria(){
            this -> n = 0;
            this -> inicio = 0;
        }

        void libera(){
            if(n>0){
                while (n > 0){
                    desempilha();
                }
            } else {
                cout << "Nao tem nada para desempilhar";
            }
        }

        void top(){
            if(this -> n > 0){
                cout << "--------------------------------------\n";
                cout <<  this -> inicio -> dado;
            } else {
                cout << "--------------------------------------";
                cout << "Nao existe nenhum valor no topo\n";
            }
        }
        
        void empilha(string dado){
            auto* no = new noPilhaEnc{.dado = dado, .prox = inicio};
            this -> inicio = no;
            this -> n++;
            cout << "\n--------------------------------------\n";
            cout << "Valor " << dado << " empilhado";
        }

        void desempilha(){
            if(n == 0){
                cout << "\n--------------------------------------";
                cout << "\nNao tem nenhum valor para desempilhar";
            } else {
                noPilhaEnc* p = this -> inicio -> prox;
                auto aux = this -> inicio -> dado;
                delete this -> inicio;
                
                this -> inicio =  p;
                n--;
                cout << "\n--------------------------------------\n";
                cout << "O valor " << aux << " foi dempilhado";
            }
        }
};

int main(void){
    string resposta;
    int opcao;
    pilhaEnc p1;
    p1.cria();

    while(true){
        
        cout << "\n-----------------MENU-----------------";
        cout << "\n1 - Empilhar";
        cout << "\n2 - Desempilhar";
        cout << "\n3 - Mostrar Topo";
        cout << "\n4 - Desempilhar tudo";
        cout << "\n5 - Sair\n\n";
        cout << "Qual opcao voce escolhe: ";
        cin >> opcao;

        switch (opcao)
        {
            case 1:
                cout << "\n--------------------------------------\n";
                cout << "Qual valor voce deseja empilhar? ";
                cin >> resposta;
                p1.empilha(resposta);

                break;
            
            case 2:
                p1.desempilha();
                break;
            
            case 3:
                p1.top();
                break;

            case 4:
                p1.libera();
                break; 

            case 5:
                exit(0);
                break;

            default:
                break;
        }
    }
}