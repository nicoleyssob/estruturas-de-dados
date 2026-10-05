#include <iostream>

using namespace std;

template <typename Thing>
class Node
{
    public:
    Thing D;
    Node<Thing>* Next;
    Node<Thing>* Prev;
};

template <typename Thing>
class ListDE
{
    Node<Thing>*Head;
    Node<Thing>*Tail;
    Node<Thing>*It;
    int N;
public:
    ListDE();
    int Size();
    void Clear();
    bool Empty();
    bool PushFront(Thing T);
    bool PushBack(Thing T);
    bool PushIt(Thing T);
    void ItBegin();
    bool ItEnd();//fim da lista
    void ItMM(); //it vai pra frente
    void Itmm();// it vai pra trás
    Thing getFront();
    Thing getBack();
    Thing getIt();
    void PopFront();
    void PopBack();
    void PopIt();
    ~ListDE();
};

template <typename Thing>
ListDE<Thing>::ListDE(){
    It=Head=Tail=nullptr;
    N=0;
}

template <typename Thing>
int ListDE<Thing>::Size(){
    return N;
}

template <typename Thing>
void ListDE<Thing>::Clear(){
    Node<Thing>*P;
    while (Head){
        P=Head;
        Head=Head->Next;
        delete P;
    }
    N=0;
    It=Head=Tail=nullptr;
}

template <typename Thing>
bool ListDE<Thing>::Empty(){
    return !Head;
}

template <typename Thing>
bool ListDE<Thing>::PushFront(Thing T){
    Node<Thing> *P=new Node<Thing>;
    if(!P) return false;
    P->D=T;
    if(!Head){
        Head=Tail=P;
        P->Prev=P->Next=nullptr;
    }else{
        P->Next=Head;
        P->Prev=nullptr;
        Head->Prev=P;
        Head=P;
    }
    N++;
    return true;
}

template <typename Thing>
bool ListDE<Thing>::PushBack(Thing T){
    Node<Thing> *P=new Node<Thing>;
    if(!P) return false;
    P->D=T;
    P->Next=nullptr;
    if(!Tail){
        P->Prev=nullptr;
        Tail=Head=P;
    }else{
        P->Prev=Tail;
        Tail->Next=P;
        Tail=P;
    }
    N++;
    return true;
}

template <typename Thing>
bool ListDE<Thing>::PushIt(Thing T){ //insere na frente do it
    if(!It) return false;
    Node<Thing>*P=new Node<Thing>;
    if(!P) return false;
    P->D=T;
    P->Next=It->Next;
    P->Prev=It;
    if(It->Next){
        It->Next->Prev=P;
    }else{
        Tail=P;
    }
    It->Next=P;
    It=P;
    N++;
    return true;
}

template <typename Thing>
void ListDE<Thing>::ItBegin(){
    It=Head;
}

template <typename Thing>
bool ListDE<Thing>::ItEnd(){
    return !(It);
}

template <typename Thing>
void ListDE<Thing>::ItMM(){
    if(It) It=It->Next;
}

template <typename Thing>
void ListDE<Thing>::Itmm(){
   if(It) It=It->Prev;
}

template <typename Thing> 
Thing ListDE<Thing>::getFront(){
    if(!Head){
         cout<<"Lista vazia."<<endl;
        return Thing(); //volta o valor padrao de inicio, seja int, string etc
    } 
    return Head->D;
}

template <typename Thing>
Thing ListDE<Thing>::getIt(){
    if(!(It)){
        cout<<"Iterador no final da lista ou lista vazia."<<endl;
        return Thing();
    }else{
        return It->D;
    }
    
}

template <typename Thing>
Thing ListDE<Thing>::getBack(){
    if(!Head){
         cout<<"Lista vazia."<<endl;
        return Thing(); //volta o valor padrao de inicio, seja int, string etc
    } 
    return Tail->D;
}

template <typename Thing>
void ListDE<Thing>::PopFront(){
    if(Head){ //se o head n for nulo = a lista n tá vazia
        Node<Thing>* P=Head;
        Head=Head->Next;
        if (Head) {
            Head->Prev = nullptr;
        }else{
            Tail=nullptr;
        }
        delete P;
        N--;
    } 
}

template <typename Thing>
void ListDE<Thing>::PopIt() {
    if (!It) return;
    Node<Thing>* P = It;
    if(Head==Tail&&It==Head){//único elemento
        Head=Tail=It=nullptr;
    }
    else if(It==Head){//Nó no início
        Head=Head->Next;
        Head->Prev=nullptr;
        It=Head;
    }
    else if(It==Tail){//Nó no final
        Tail=Tail->Prev;
        Tail->Next=nullptr;
        It=nullptr;//It não pode ir além do final
    }
    else{// Nó no meio
        It->Prev->Next=It->Next;
        It->Next->Prev=It->Prev;
        It=It->Next;
    }
    delete P;
    N--;
}


template <typename Thing>
void ListDE<Thing>::PopBack(){
    if(Tail){
        Node<Thing>* P=Tail;
        Tail=Tail->Prev;
        if(Tail){
            Tail->Next=nullptr;
        }else{
            Head=nullptr;
        }
        delete P;
        N--;
    } 
}

template <typename Thing>
ListDE<Thing>::~ListDE(){
     Node<Thing>* P;
    while(Head){
        P=Head;
        Head=Head->Next;
        delete P;
    }
    N=0;
}