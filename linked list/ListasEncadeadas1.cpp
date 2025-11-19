#include <iostream>

using namespace std;

// Estrutura comum de nodos para uma lista encadeada singular (singly-linked list) (só aponta para o próximo)
struct ListNode {
    int val;
    ListNode* next; // armazena o endereço de memória do próximo nodo
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void imprimirNodes(ListNode* head) { // recebe o ínicio da lista
    ListNode* node = head; // este node servirá como forma de percorrer a lista sem alterar a estrutura original
    while (node != nullptr){ // enquanto o node atual não for nullptr
        cout << node->val << " "; // imprime o valor do node atual
        node = node->next; // avança para o próximo
    }
    cout << endl;
}

void adicionarNode(ListNode* head, int val) {
    ListNode* node = head;

    while (node != nullptr){ // enquanto o node atual não for nullptr
        node = node->next; // avança para o próximo node
        if (node->next == nullptr){ // caso o node atual for o último (estiver apontando para nullptr)
            ListNode* newnode = new ListNode(val); // cria um novo *ponteiro* de node, onde seu node correspondente é criado com o valor passado
            node->next = newnode; // substitui o next do node atual, o último da lista, pelo endereço do node recém criado
            break;
        }
    } 
}

void deletarNode(ListNode*& head, int val) {
    if (head == nullptr)
        return;
    
    if (head->val == val){
        head = head->next;
        return;
    }

    ListNode* node = head;

    while(node->next != nullptr && node->next->val != val) // parar um node antes do node que tiver o valor a ser deletado
        node = node->next;
    
    if (node->next != nullptr) {
        ListNode* aux = node->next;
        node->next = node->next->next; // substituir o next do node atual pelo endereço do node que vem depois do que contem o valor, pulando-o
        delete aux;
    }
}

void editarNode(ListNode* head, int val, int newVal) {
    ListNode* node = head;

    while(node != nullptr && node->val != val) // enquanto o node atual não tiver o valor a ser substituido
        node = node->next; // percorre a lista

    if (node != nullptr)
        node->val = newVal; // substitui o valor do node atual pelo seu novo valor
}

bool verificarNodeExiste(ListNode* head, int val) {
    ListNode* node = head;

    while(node != nullptr){
        if (node->val == val)
            return true;
        node = node->next;
    }
    return false;
}

int main() {
    ListNode node4(3);
    ListNode node3(2, &node4);
    ListNode node2(1, &node3);
    ListNode node1(0, &node2);
    
    ListNode* head = &node1;

    imprimirNodes(head);
    
    adicionarNode(head, 4);
    imprimirNodes(head);

    deletarNode(head, 0);
    imprimirNodes(head);

    editarNode(head, 4, 5);
    imprimirNodes(head);

    cout << verificarNodeExiste(head, 2) << endl;
    


    return 0;
}