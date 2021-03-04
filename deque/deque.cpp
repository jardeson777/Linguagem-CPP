#include <iostream>
#include <stdio.h>
using namespace std;

class noDeque{
    public:
        string dado;
        noDeque* prox;
        noDeque* ant;
};

class deque{
    public:
        noDeque* inicio;
        noDeque* fim;
        noDeque* valor;
        int cont;   

        void cria(){
            this -> inicio = 0;
            this -> fim = 0;
            this -> cont = 0;
        }

        void insereInicio(string dado){
            auto* novo = new noDeque{.dado = dado, .prox = 0, .ant = 0};
            
            if(inicio == 0){ //então só tem um elemento, com isso a inicio e o fim vai ser o mesmo dado
                this -> inicio = novo;
                this -> fim = novo;
            } else { //Se já tiver elemento criado, então eu crio um no vazio de nome valor que vai ser o msm valor do inicio.
                noDeque* valor;
                valor = this -> inicio;
                novo -> prox = valor; //Como funciona como uma pilha, o prox dado é o "valor" 
                valor -> ant = novo; //O valor que está antes do "valor" é o novo
                this -> inicio = novo; //Atualiza o dado do inicio
            }
            cout << "\n----------------------------------------\n";
            cout << "O dado " << novo -> dado << " foi adicionado";
            cont++;
        }

        void insereFim(string dado){
            auto* novo = new noDeque{.dado = dado, .prox = 0, .ant = 0};
            if(inicio == 0){ //Se não tiver ngm então o inicio e fim vai ser o msm dado
                this -> inicio = novo;
                this -> fim = novo;
            } else {
                noDeque* valor;
                valor = this -> fim;
                valor -> prox = novo;
                novo -> ant = valor;
                this -> fim = novo;
            }
            cout << "\n----------------------------------------\n";
            cout << "O dado " << novo -> dado << " foi adicionado";
            cont++;
        }

        void removeInicio(){
            if(cont == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem dado para remover";
            } else {
                noDeque* prox = this -> inicio -> prox;
                auto dado = this -> inicio -> dado;

                delete this -> inicio;
                this -> inicio = prox;
                cont--;
                cout << "\n----------------------------------------\n";
                cout << "O dado " << dado << " foi removido";
            }
        }

        void removeFim(){
            if(cont == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem dado para remover";
            } else {
                noDeque* prox = this -> fim -> prox;
                auto dado = this -> fim -> dado;

                delete this -> fim;
                this -> fim = prox;
                cont--;
                cout << "\n----------------------------------------\n";
                cout << "O dado " << dado << " foi removido";
            }
        }

        void buscaInicio(){
            if(this -> cont == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem nenhum dado";
            } else {
                cout << "\n----------------------------------------\n";
                cout << "O dado que esta no inicio eh " << this -> inicio -> dado;
            }
        }

        void buscaFim(){
            if(this -> cont == 0){
                cout << "\n----------------------------------------\n";
                cout << "Nao tem nenhum dado";
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

    d1.cria();
    while(true){
        cout << "\n----------------------------------------\n";
        cout << "------------------MENU------------------\n";
        cout << "1 - Inserir na frente";
        cout << "\n2 - Inserir atras";
        cout << "\n3 - Remover na frente";
        cout << "\n4 - Remover atras";
        cout << "\n5 - Mostrar frente";
        cout << "\n6 - Mostrar atras";
        cout << "\n7 - Retirar todos os dados";
        cout << "\n8 - Sair\n";
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
                if(d1.cont > 0){
                    while(d1.cont > 0){
                        d1.removeFim();
                    }
                    cout << "\n----------------------------------------\n";
                    cout << "Todos os dados foram removidos";
                } else {
                    cout << "\n----------------------------------------\n";
                    cout << "Nao tem nenhum dado para ser removido";
                }
                break;

            case 8:
                exit(0);
                break;

            default:
                cout << "\n----------------------------------------\n";
                cout << "Opcao invalida, tente novamente";
                break;
            }
    }

}