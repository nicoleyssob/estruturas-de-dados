#include <iostream>
#include <stdexcept> //biblioteca pra usar a exceção throw runtime_error

using namespace std;

template <typename Thing>
class Node
{
public:
    Thing D;
    Node<Thing>* Next; //ponteiro que guarda o endereço do prox nó
};

template <typename Thing>
class Queue
{
    Node<Thing>* Head;
    Node<Thing>* Tail;
    int N;
public:
    Queue();//construtor
    int Size(); //tamanho
    bool Empty();
    bool Push(Thing T);
    Thing Front();
    Thing Back();
    void Pop();
    void Clear();
    ~Queue();
};

template <typename Thing>
Queue<Thing>::Queue()//construtor
{
    Head=Tail=nullptr;
    N=0;
}

template <typename Thing>
bool Queue<Thing>::Empty()
{
    return !Head;
}

template <typename Thing>
int Queue<Thing>::Size()
{
    return N;
}

template <typename Thing> 
bool Queue<Thing> ::Push(Thing T){
    Node<Thing>*P=new Node<Thing>; 
    if(!P){
        return false;
    }
    P->D=T;
    P->Next=0;
    if(!Head){
        Head =P;
    }else{
        Tail->Next=P;
    }
    Tail=P;
    N++;
    return true;
}

template <typename Thing>
Thing Queue <Thing>::Front(){
    if(!N){
        throw runtime_error("Fila vazia."); 
    }
    return Head->D;
}

template <typename Thing>
Thing Queue <Thing> :: Back(){
    if(!N){
        throw runtime_error("Fila vazia.");
    }
    return Tail->D;
}

template <typename Thing>
void Queue <Thing> :: Pop(){
    if(!Empty()){
        Node<Thing>*P=Head;
        Head=Head->Next;
        delete P;
        if(!Head){
            Tail=Head;
        }
        N--;
    }
}

template <typename Thing>
void Queue <Thing> ::Clear(){
    Node<Thing>*P;
    while(Head){
        P=Head;
        Head=Head->Next;
        delete P;
    }
    Tail=nullptr;
    N=0;
}

template<typename Thing>
Queue <Thing> ::~Queue(){
    Clear();
} 

int main(){
    Queue<int> s;
    s.Push(5);
    s.Push(10);
    s.Push(7);
    s.Pop();
    cout << "Frente da fila: " << s.Front() << endl;
    cout << "Traseira da fila: " << s.Back() << endl;
    cout << "Tamanho: " << s.Size() << endl;
    s.Clear();
    cout << "Tamanho após o clear: " << s.Size() << endl;
    s.Push(5);
    cout << "Frente da fila apos push 5: " << s.Front() << endl;
    cout << "Traseira da fila: " << s.Back() << endl;

    return 0;
}