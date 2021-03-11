#include <iostream>
#include <stdio.h>
using namespace std;

class noFila{
    public:
        string dado;
        noFila* prox;
};

class pilhaComFila{
    public:
        noFila* inicio;
        noFila* fim;
        int cont, n;

        void cria(){
            this -> inicio = 0;
            this -> fim = 0;
            this -> cont = 0;
            this -> n = 0;
        }

        void enfileira(string dado){
            noFila* no = new noFila{.dado = dado, .prox = 0};
            if(cont == 0){
                inicio = fim = no;
            } else {
                fim->prox = no;
                fim = no;
            }

            cont++;
            n++;
        }

        string desenfileira(){
            
            if(cont > 0){
                auto dado = this -> inicio -> dado;
                noFila* prox1 = this -> inicio -> prox;
                delete this -> inicio;
                this -> inicio = prox1;

                cont--;

                return dado;
            }
        }

        void topo(){
            if(cont>0){
                cout << "\n--------------------------------------\nDado no topo: ";
                cout << this -> fim -> dado;
            } else {
                cout << "\n--------------------------------------\n";
                cout << "Nao tem nenhum dado empilhado";
            }
        }

        void libera(){
            int i;
            if(this -> cont > 0){
                for(i=0; i<this->cont;i++){
                    desenfileira();
                }
                cout << "\n--------------------------------------\n";
                cout << "Todos dados foram removidos";
            } else {
                cout << "\n--------------------------------------\n";
                cout << "Nao existe dado";
            }
        }
};


int main(void){
    string resposta;
    int opcao, chaveSeletora = 1, i;
    pilhaComFila p1;
    pilhaComFila p2;

    p1.cria();
    p2.cria();

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

                if(chaveSeletora == 1){
                    p1.enfileira(resposta);
                } else {
                    p2.enfileira(resposta);
                }
                break;
            
            case 2:
                if(chaveSeletora == 1){
                    if(p1.cont > 0){
                        for(i=0; i<p1.n-1; i++){
                            p2.enfileira(p1.inicio->dado);
                            p1.desenfileira();
                        }
                        auto dado = p1.desenfileira();
                        p1.n = 0;
                        chaveSeletora = 2;

                        cout << "\n--------------------------------------\n";
                        cout << "O dado " << dado << " foi desempilhado";
                    } else {
                        cout << "Nao tem dado para desempilhar";
                    }

                } else {
                    if(p2.cont > 0){
                        for(i=0; i<p2.n-1; i++){
                            p1.enfileira(p2.inicio->dado);
                            p2.desenfileira();
                        }
                        auto dado = p2.desenfileira();
                        chaveSeletora = 1;
                        p2.n = 0;
                        cout << "\n--------------------------------------\n";
                        cout << "O dado " << dado << " foi desempilhado"; 
                    } else {
                        cout << "Nao tem dado para desempilhar";
                    }
                }
                break;
            
            case 3:
                if(chaveSeletora == 1){
                    p1.topo();
                } else {
                    p2.topo();
                }
                break;

            case 4:
                if(chaveSeletora == 1){
                    p1.libera();
                } else {
                    p2.libera();
                }
                break; 

            case 5:
                exit(0);
                break;

            default:
                cout << "Opcao invalida, tente novamente!";
                break;
        }
    }
}