#include <iostream>

using namespace std;

struct Node{
    string url;
    Node* anterior;
};

struct Pilha {
    Node *topo; /* posição elemento topo */
};

void criarPilha(Pilha* p){
    p->topo = nullptr;
}

void empilhar(struct Pilha *p, Node* n){

    if(p->topo == nullptr){
        p->topo = n;
    }else{
        Node* aux = p->topo;
        p->topo = n;
        p->topo->anterior = aux;
    }
    cout << "Agora você está na página " << p->topo->url << endl;
};

void desempilhar ( struct Pilha *p ){
    if(p->topo == nullptr){
        cout << "Não contém itens na pilha.";
    }else{
        Node* aux = p->topo;
        p->topo = aux->anterior;
        cout << "Agora você está na página " << p->topo->url << endl;
        free(aux);
    }
};
int main()
{
    bool exec = true;
    Pilha p;
    criarPilha(&p);

    while(exec){
        cout << "Você deseja: \n0: Sair do programa; \n1: Entrar em uma página;\n2: Voltar." << endl;
        int opcao;
        cin >> opcao;
        if(opcao == 0){
            exec = false;
        }else if(opcao == 1){
            cout << "Insira a url da página" << endl;
            string url;
            cin >> url;
            Node* pagina = new Node;
            pagina -> url = url;
            empilhar(&p, pagina);

        }else{
            desempilhar(&p);
        }
    }
    return 0;
}
