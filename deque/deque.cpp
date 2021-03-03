#include <iostream>
#include <stdio.h>
using namespace std;

class noDequeFrente{
    public:
        string dado;
        noDequeFrente* inicio;
};

class noDequeTraseira{
    public:
        string dado;
        noDequeTraseira* fim;
};

class deque{
    public:
        noDequeTraseira* fim;
        noDequeFrente* frente;
        int contFrente, contFim;

        void cria(){
            this -> fim = 0;
            this -> frente = 0;
            this -> contFrente = 0;
            this -> contFim = 0;
        }

        void insereInicio(string dado){
            auto* no = new noDequeFrente{.dado = dado, .inicio = frente};
            this -> frente = no;
            contFrente++;
        }

        void insereFim(string dado){
            auto* no = new noDequeTraseira{.dado = dado, .fim = fim};
            this -> fim = no;
            contFim++;
        }

        void removeInicio(){
            if(contFrente = 0){
                cout << "Nao tem nenhum dado na frente";
            } 
        }
};


int main(void){

}