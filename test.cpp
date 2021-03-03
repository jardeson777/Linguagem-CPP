#include<iostream>
#include<string>
using namespace std;

class pilha{
    public:
        char* lista;
        long int topo=0;
};

void empilhar(struct pilha* p1){
    char valor;
    cout << "O que vc quer empilhar? ";
    cin >> valor;
    cout << '\n';

    p1 -> lista[p1 -> topo] = valor;
    
    p1 -> topo++;
}

void desempilhar(struct pilha* p1){
    cout << p1 -> lista[p1 -> topo-1] << " Foi desempilhado\n\n";
    p1 -> topo--;
}

void pilhaCompleta (struct pilha* p1){
    int tamanho = p1 -> topo;
    
    for(int i = p1 -> topo-1; i>=0; i--){
        printf("%d%c ---> ", tamanho, 167);
        cout << p1 -> lista[i] << '\n';
        
        tamanho--;
    }
}

int main(void){
    pilha p1;
    int opcao;
    
    while(true){
        cout << "-----------------MENU-----------------\n";
        cout << "1 - Empilhar algum elemento\n";
        cout << "2 - Retirar ultimo elemento\n";
        cout << "3 - Qual elemento esta no topo\n";
        cout << "4 - Mostrar pilha completa\n";
        cout << "5 - Sair\n";
        cout << "\nDigite uma opcao(1 ate 5): ";
        cin >> opcao;
        cout << "--------------------------------------\n\n";
        
        switch(opcao){
            case 1: empilhar(&p1); break;
            
            case 2: 
                if(p1.topo <= 0){
                    cout << "Nao tem nada para desempilhar\n\n";
                    break;
                } else {
                    desempilhar(&p1); 
                    break;
                }
                
            case 3:
                if(p1.topo == 0){
                    cout << "Nao tem nada na pilha\n\n"; 
                    break;
                } else {
                    cout << "Item no topo: " << p1.lista[p1.topo-1] << "\n\n"; 
                    break;
                }
            
            case 4:
                if(p1.topo == 0){ 
                    cout << "Pilha vazia\n\n"; 
                    break;
                } else {
                    cout << "Itens na pilha\n\n";
                    pilhaCompleta(&p1); break;
                }
            
            case 5: exit(0);
            
            default:
                cout << "Opcao invalida, tente novamente\n\n"; 
                break;
        }
    }
}