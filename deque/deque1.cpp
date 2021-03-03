#include <iostream>
#include <stdio.h>
using namespace std;

class noDeque{
    public:
        string dado;
        noDeque* inicio;
        noDeque* fim;
};

class deque{
    public:
        noDeque* fim;
        noDeque* frente;
        int contFrente, contFim;

        void cria(){
            this -> fim = 0;
            this -> frente = 0;
            this -> contFrente = 0;
            this -> contFim = 0;
        }

        void insereInicio(string dado){
            auto* no = new noDeque{.dado = dado, .inicio = frente};
            this -> frente = no;
            contFrente++;

            cout << "\n----------------------------------------\n";
            cout << "O dado " << this -> frente -> dado << " foi adicionado";
        }

        void insereFim(string dado){
            auto* no = new noDeque{.dado = dado, .fim = fim};
            this -> fim = no;
            contFim++;

            cout << "\n----------------------------------------\n";
            cout << "O dado " << this -> fim -> dado << " foi adicionado";
        }

        void removeInicio(){
            if(contFrente == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem nenhum dado na frente";
            } else {
                noDeque* prox = this -> frente -> inicio;
                auto dado = this -> frente -> dado;

                delete this -> frente;
                contFrente--;

                this -> frente = prox;
                cout << "\n----------------------------------------\n";
                cout << "O dado " << dado << " foi removido";
            }
        }

        void removeFim(){
            if(contFim == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem nenhum dado no fim";
            } else {
                noDeque* prox = this -> fim -> fim;
                auto dado = this -> fim -> dado;

                delete this -> fim;
                contFim--;

                this -> fim = prox;
                cout << "\n----------------------------------------\n";
                cout << "O dado " << dado << " foi removido";
            }
        }

        void buscaInicio(){
            if(this -> contFrente == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem nenhum dado na frente";
            } else {
                cout << "\n----------------------------------------\n";
                cout << "O dado que esta no inicio eh " << this -> frente -> dado;
            }
        }

        void buscaFim(){
            if(this -> contFim){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem nenhum dado na frente";
            } else {
                cout << "\n----------------------------------------\n";
                cout << "O dado que esta no fim eh " << this -> fim -> dado;
            }
        }
};


int main(void){
    int opcao;
    string resposta;
    deque d1;

    while(true){
        cout << "\n----------------------------------------\n";
        cout << "------------------MENU------------------\n";
        cout << "1 - Inserir na frente";
        cout << "\n2 - Inserir atras";
        cout << "\n3 - Remover na frente";
        cout << "\n4 - Remover atras";
        cout << "\n5 - Mostrar frente";
        cout << "\n6 - Mostrar atras";
        cout << "\n7 - Retirar todos da frente";
        cout << "\n8 - Retirar todos de tras";
        cout << "\n9 - Sair\n";
        cout << "Qual opcao voce escolhe: ";
        cin >> opcao;


        switch (opcao){
            case 1:
                cout << "O que voce deseja inserir na frente? ";
                cin >> resposta;

                d1.insereInicio(resposta);
                break;
            
            case 2:
                cout << "O que voce deseja inserir atras? ";
                cin >> resposta;

                d1.insereFim(resposta);
                break;

            case 3:
                d1.removeInicio();
                break;

            case 4:
                d1.removeFim();
                break;
            
            case 5:
                d1.buscaInicio();
                break;

            case 6:
                d1.buscaFim();
                break;

            case 7:
                while(d1.contFrente > 0){
                    d1.removeInicio();
                }
                break;

            case 8:
                while(d1.contFim > 0){
                    d1.removeFim();
                }
                break;
            
            case 9:
                exit(0);
                break;

            default:
                break;
            }
    }

    
}