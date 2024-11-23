#include <iostream>

struct Node
{
    int element1;
    int element2;
    Node* next;

    Node(int element1, int element2){
        this->element1 = element1;
        this->element2 = element2;
        next = nullptr;
    }
};

struct List
{
    Node* head;

    List(){
        this->head = nullptr;
    }

    void Inserir(Node* newNode){
        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    Node* ObterProximo(Node* node){
        if (head == nullptr) return nullptr;

        Node* curr = head;

        while (curr != nullptr)
        {
            if (curr == node)
            {
                return curr->next;
            } 
                
            curr = curr->next;
        }
        return nullptr;
    }

    bool Existe(Node* node){
        return findNode(node) != nullptr;
    }

    std::pair<int, int> ObterValor(Node* node){
        Node* foundNode = findNode(node);
        if (foundNode)
        {
            return {foundNode->element1, foundNode->element2};
        }
        return {-1,-1};
    }

    bool AlterarNo(Node* node, int newElement1, int newElement2) {
        Node* foundNode = findNode(node);
        if (foundNode) {
            foundNode->element1 = newElement1;
            foundNode->element2 = newElement2;
            return true;
        }
        return false;
    }

    int Tamanho(){
        if (head == nullptr) return 0;

        Node* curr = head;
        int counter = 0;

        while (curr != nullptr)
        {
            counter++;
            curr = curr->next;
        }
        
        return counter;

    }

    void Excluir(Node* node){
        if (head == node) {
            Node* exclude = head;
            head = head->next;
            delete exclude;
            return;
        }

        Node* curr = head;

        while (curr != nullptr)
        {
            if (curr->next == node)
            {
                Node* exclude = node;
                curr->next = curr->next->next;
                delete exclude;
                return;
            }
            curr = curr->next;
        }
    }

    void mostrarALL(){
        if (head == nullptr){ 
            std::cout << "Empty"; 
            return;
        }

        Node* curr = head;

        while (curr != nullptr)
        {
            std::cout << "["<<curr->element1<<"]" << " " << "["<<curr->element2<<"]" << std::endl;
            curr = curr->next; 
        }
        
    }

    ~List(){
        Node* curr = head;
        while( curr != nullptr ) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
    }

    Node* findNode(Node* node){
        Node* temp = head;
        while (temp != nullptr)
        {
            if (temp == node)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

int main(){

    List lista;

    Node* no1 = new Node(1, 2);
    Node* no2 = new Node(2, 2);
    Node* no3 = new Node(3, 3);
    Node* no4 = new Node(2, 4);

    lista.Inserir(no1);
    lista.Inserir(no2);
    lista.Inserir(no3);

    lista.mostrarALL();

    std::cout << "Tamanho da lista: " << lista.Tamanho() << std::endl;
    std::cout << "No4 existe?: " << lista.Existe(no4) << std::endl;
    
    auto [e1, e2] = lista.ObterValor(no1);
    std::cout << "Valor do primeiro no: " << e1 << ", " << e2 << std::endl;
    lista.AlterarNo(no1, 5, 10);
    auto [b1, b2] = lista.ObterValor(no1);
    std::cout << "Valor do primeiro no alterado: " << b1 << ", " << b2 << std::endl;

    std::cout << "Lista apos excluir no2:" << std::endl;
    lista.mostrarALL();

    return 0;
};