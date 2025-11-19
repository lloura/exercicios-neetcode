#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListaEncadeada {
private:
    ListNode* head;

public:
    ListaEncadeada() : head(nullptr) {}

    ~ListaEncadeada() {
        liberarLista();  // libera toda a memória quando a lista sai do escopo
    }

    void adicionar(int val){
        if (!head){
            head = new ListNode(val);
            return;
        }

        ListNode* node = head;
        while(node->next != nullptr)
            node = node->next;

        node->next = new ListNode(val);
    }

    void imprimirLista(){
        ListNode* node = head;

        while(node != nullptr){
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }

    void alterar(int val, int newVal) {
        ListNode* node = head;

        while(node != nullptr && node->val != val)
            node = node->next;

        if (node != nullptr)
            node->val = newVal;
    }

    void remover(int val){
        if (head == nullptr)
            return;

        if (head->val == val){
            ListNode* aux = head;
            head = head->next;
            delete aux;
            return;
        }

        ListNode* node = head;
        while(node != nullptr && node->next != nullptr && node->next->val != val)
            node = node->next;

        if (node != nullptr && node->next != nullptr) {
            ListNode* aux = node->next;
            node->next = node->next->next;
            delete aux;
        }
    }

    bool existe(int val){
        ListNode* node = head;

        while(node != nullptr){
            if (node->val == val)
                return true;
            node = node->next;
        }

        return false;
    }

    void inverterLista(){
        ListNode* ante = nullptr;
        ListNode* node = head;
        ListNode* prox = nullptr;

        while(node != nullptr){
            prox = node->next;
            node->next = ante;
            ante = node;
            node = prox;
        }
        head = ante;
    }

    int tamanho() {
        int count = 0;
        ListNode* node = head;
        while (node != nullptr) {
            count++;
            node = node->next;
        }
        return count;
    }

    void inserirNaPosicao(int val, int pos){
        if (pos < 1 || pos > tamanho() + 1)
            return;

        // Inserção no início
        if (pos == 1) {
            ListNode* novo = new ListNode(val);
            novo->next = head;
            head = novo;
            return;
        }

        ListNode* node = head;
        int p = 1;

        while (p < pos - 1 && node != nullptr) {
            p++;
            node = node->next;
        }

        if (node != nullptr) {
            ListNode* novo = new ListNode(val);
            novo->next = node->next;
            node->next = novo;
        }
    }

    void removerNaPosicao(int pos){
        if (pos < 1 || pos > tamanho() || head == nullptr)
            return;

        // Remover no início
        if (pos == 1){
            ListNode* aux = head;
            head = head->next;
            delete aux;
            return;
        }

        ListNode* node = head;
        int p = 1;
        while (p < pos - 1 && node->next != nullptr) {
            p++;
            node = node->next;
        }

        if (node != nullptr && node->next != nullptr) {
            ListNode* aux = node->next;
            node->next = node->next->next;
            delete aux;
        }
    }

    int getPrimeiro(){
        if (head == nullptr) throw runtime_error("Lista vazia");
        return head->val;
    }

    int getUltimo(){
        if (head == nullptr) throw runtime_error("Lista vazia");

        ListNode* node = head;
        while (node->next != nullptr)
            node = node->next;
        return node->val;
    }

    bool isEmpty(){
        return head == nullptr;
    }

private:
    void liberarLista(){
        ListNode* node = head;
        while(node != nullptr){
            ListNode* aux = node;
            node = node->next;
            delete aux;
        }
        head = nullptr;
    }

};

int main() {
    ListaEncadeada lista;

    lista.adicionar(1);
    lista.adicionar(2);
    lista.adicionar(3);
    lista.adicionar(4);

    cout << "lista inicial: ";
    lista.imprimirLista();

    cout << "tamanho inicial da lista: ";
    cout << lista.tamanho() << endl;
    
    lista.remover(3);
    cout << "lista após remover o 3: ";
    lista.imprimirLista();

    lista.alterar(4, 6);
    cout << "lista após alterar o 4 por 6: ";
    lista.imprimirLista();

    cout << "verificando se o 2 existe na lista: ";
    cout << (lista.existe(2) ? ("sim") : ("não")) << endl;

    cout << "verificando se o 8 existe na lista: ";
    cout << (lista.existe(8) ? ("sim") : ("não") ) << endl;

    lista.adicionar(8);
    cout << "lista após adicionar o 8: ";
    lista.imprimirLista();

    lista.adicionar(5);
    cout << "lista após adicionar o 5: ";
    lista.imprimirLista();

    cout << "tamanho atual da lista: ";
    cout << lista.tamanho() << endl;

    cout << "invertendo a lista: ";
    lista.inverterLista();
    lista.imprimirLista();

    cout << "inserindo o número 0 na 3° posição da lista: ";
    lista.inserirNaPosicao(0, 3);
    lista.imprimirLista();

    cout << "removendo elemento da 4° posição da lista: ";
    lista.removerNaPosicao(4);
    lista.imprimirLista();

    cout << "primeiro elemento: " << lista.getPrimeiro() << endl;
    cout << "último elemento: " << lista.getUltimo() << endl;
    cout << "lista está vazia? " << (lista.isEmpty() ? "sim" : "não") << endl;

    return 0;
}
