#include <iostream>
#include <stdexcept> //biblioteca pra usar a exceção throw runtime_error
using namespace std;

template <typename Thing>
class Node
{
public:
    Thing D;
    Node<Thing>* Next;
};

template <typename Thing>
class Stack
{
    Node<Thing>* Top;
    int N;
public:
    Stack();//construtor
    int size();//tamanho
    bool Empty();//vazia
    Thing TOP(); //retorna quem ta no topo
    bool Push(Thing T); //insere na pilha
    void Pop(); //retira da pilha
    void Clear(); //limpa
    void Reverse();
    ~Stack(); //destrutor
};

template <typename Thing>
Stack<Thing>::Stack() //construtor
{
    Top=nullptr;
    N=0;
}

template <typename Thing>
int Stack<Thing>::size()
{
    return N;
}

template <typename Thing>
bool Stack<Thing>::Empty()
{
    return !Top;
}

template <typename Thing>
Thing Stack<Thing>:: TOP()
{
    if(!N){
        throw runtime_error("Pilha vazia."); //throw sendo a exceção
                                            //como se fosse um break
    }
    return Top->D;
}

template <typename Thing>
bool Stack<Thing>::Push(Thing T)
{
    Node<Thing>* P= new Node<Thing>;
    if(!P)
    {
        return false;
    }
    P->D=T;
    P->Next=Top;
    Top=P;
    N++;
    return true;
}

template <typename Thing>
void Stack<Thing>::Pop(){
    if(!Empty()){
        Node<Thing>* P=Top;
        Top=Top->Next;
        delete P;
        N--;
    }
    
}

template <typename Thing>
void Stack<Thing>::Clear(){
    Node<Thing>* P;
    while(Top){
        P=Top;
        Top=Top->Next;
        delete P;
    }
    N=0;
}

template <typename Thing>
void Stack<Thing>::Reverse() {
    Stack<Thing> aux1, aux2;

    // Desempilha os elementos da pilha original e empilha na auxiliar
    while (!this->Empty()) {
        aux1.Push(this->TOP());
        this->Pop();
    }

    // Transfere os elementos da pilha auxiliar de volta para a original
    while (!aux1.Empty()) {
        aux2->Push(aux1.TOP());
        aux1.Pop();
    }
    while (!aux2.Empty()) {
        this->Push(aux2.TOP());
        aux2.Pop();
    }
}

template <typename Thing>
Stack<Thing>::~Stack(){
    Clear();
}


int main() {
    Stack<int> s;
    s.Push(5);
    s.Push(10);
    cout << "Topo da pilha: " << s.TOP() << endl;
    cout << "Tamanho: " << s.size() << endl;
}