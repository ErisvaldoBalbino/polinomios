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
        if (head == nullptr) return false;

        Node* curr = head;

        while (curr != nullptr)
        {
            if (curr == node)
            {
                return true;
            } 
                
            curr = curr->next;
        }
        return false;
    }

    void ObterValor(Node* node){
        if (head == nullptr) std::cout << "Empty";

        Node* curr = head;

        while (curr != nullptr)
        {
            if (curr == node)
            {
                std::cout << curr->element1 << " " << curr->element2 << std::endl;
            } 
                
            curr = curr->next;
        }
    }

    void AlterarNo(Node* node, int newElement1, int newElement2){
        if (head == nullptr) std::cout << "Empty";

        Node* curr = head;

        while (curr != nullptr)
        {
            if (curr == node)
            {
                curr->element1 = newElement1;
                curr->element2 = newElement2;
                return;
            } 
                
            curr = curr->next;
        }
    }

    int Tamanho(){
        if (head == nullptr) std::cout << "Empty";

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
        if (head == nullptr) std::cout << "Empty";

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

    lista.ObterValor(no1);

    std::cout << lista.Tamanho() << std::endl;
    std::cout << lista.Existe(no4) << std::endl;

    lista.AlterarNo(no1, 5, 10);
    lista.ObterValor(no1);

    lista.Excluir(no2);
    
    lista.mostrarALL();

    return 0;
};