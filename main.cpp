#include <iostream>

using namespace std;

struct Node{
    string url;
    Node* anterior;
};

struct Pilha {
    Node *topo; /* posi��o elemento topo */
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
    cout << "Agora voc� est� na p�gina " << p->topo->url << endl;
};

void desempilhar ( struct Pilha *p ){
    if(p->topo == nullptr){
        cout << "N�o cont�m itens na pilha.";
    }else{
        Node* aux = p->topo;
        p->topo = aux->anterior;
        cout << "Agora voc� est� na p�gina " << p->topo->url << endl;
        free(aux);
    }
};
int main()
{
    bool exec = true;
    Pilha p;
    criarPilha(&p);

    while(exec){
        cout << "Voc� deseja: \n0: Sair do programa; \n1: Entrar em uma p�gina;\n2: Voltar." << endl;
        int opcao;
        cin >> opcao;
        if(opcao == 0){
            exec = false;
        }else if(opcao == 1){
            cout << "Insira a url da p�gina" << endl;
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
