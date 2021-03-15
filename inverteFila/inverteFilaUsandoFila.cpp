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
        int cont, n;
        noFila* inicio;
        noFila* fim;

        void cria(){
            cont = 0;
            n = 0;
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
            n++;
        }

        void desenfileira(){
            auto dado = inicio -> dado;
            noFila* p = this -> inicio -> prox;
            delete inicio;
            this -> inicio = p;
            cont --;
        }
};

void desenfileiraEnfileirando(struct fila* f1, struct fila* aux){
    if(f1->cont == 1){
        return;
    } else {
        aux->enfileira(f1->inicio->dado);
        f1->desenfileira();
        desenfileiraEnfileirando(f1, aux);
    }
}

void inverteFilaComFila(struct fila* f, struct fila* aux1, struct fila* aux2, int qtdLoop){
    int i;
    if(qtdLoop == f->n){
        return;
    }
    else if(qtdLoop == 0){
        desenfileiraEnfileirando(f, aux1);
        qtdLoop++;
        inverteFilaComFila(f, aux1, aux2, qtdLoop);
    } 
    
    else if (qtdLoop % 2 != 0){
        desenfileiraEnfileirando(aux1, aux2);
        f->enfileira(aux1->inicio->dado);
        f->n--;
        aux1->desenfileira();
        qtdLoop++;
        inverteFilaComFila(f, aux1, aux2, qtdLoop);
    } 
    
    else if (qtdLoop % 2 == 0 & qtdLoop != 0){
        desenfileiraEnfileirando(aux2, aux1);
        f->enfileira(aux2->inicio->dado);
        f->n--;
        aux2->desenfileira();
        qtdLoop++;
        inverteFilaComFila(f, aux1, aux2, qtdLoop);
    }
}

void printFila(struct fila* f){
    noFila* fi;
    fi = f->inicio;
    while(fi != 0){
        cout << fi->dado << " ";
        fi = fi->prox;
    }
}

int main(void){
    fila f1;
    fila aux1;
    fila aux2;

    int qtdLoop = 0;
    f1.cria();
    aux1.cria();
    aux2.cria();

    f1.enfileira("1");
    f1.enfileira("2");
    f1.enfileira("3");
    f1.enfileira("4");

    cout << "Fila f1: ";
    printFila(&f1);

    inverteFilaComFila(&f1, &aux1, &aux2, qtdLoop);

    cout << "\nFila f1 invertida: ";
    printFila(&f1);
    cout << "\n\n";
}