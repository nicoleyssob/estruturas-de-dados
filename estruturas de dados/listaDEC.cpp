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
class ListDEC
{
    Node<Thing>*Head;
    Node<Thing>*It;
    int N;
public:
    ListDEC();
    int Size();
    void Clear();
    bool Empty();
    bool PushFront(Thing T);
    bool PushIt(Thing T);
    void ItBegin();
    bool ItEnd();//fim da lista
    void ItMM(); //it vai pra frente
    void Itmm();// it vai pra trás
    Thing getFront();
    Thing getIt();
    void PopFront();
    void PopIt();
    ~ListDEC();
};

template <typename Thing>
ListDEC<Thing>::ListDEC(){
    It=Head=nullptr;
    N=0;
}

template <typename Thing>
int ListDEC<Thing>::Size(){
    return N;
}

template <typename Thing>
void ListDEC<Thing>::Clear() {
    while(N>0){
        Node<Thing>* P=Head;
        if(N==1){
            Head=It=nullptr;
        }else{
            Head=Head->Next;
            P->Prev->Next=P->Next;
            P->Next->Prev=P->Prev;
            if(It==P) It=Head;
        }
        delete P;
        N--;
    }
}


template <typename Thing>
bool ListDEC<Thing>::Empty(){
    return !Head;
}

template <typename Thing>
bool ListDEC<Thing>::PushFront(Thing T){
    Node<Thing> *P=new Node<Thing>;
    if(!P) return false;
    P->D=T;
    if(!Head){
        Head=P;
        P->Prev=P->Next=P;
    }else{
        P->Next=Head;
        P->Prev=Head->Prev;
        Head->Prev->Next=P;
        Head->Prev=P;
        Head=P;
    }
    N++;
    return true;
}

template <typename Thing>
bool ListDEC<Thing>::PushIt(Thing T){ //insere na frente do it
    if(!It) return false;
    Node<Thing>*P=new Node<Thing>;
    if(!P) return false;
    P->D=T;
    P->Next=It->Next;
    P->Prev=It;
    It->Next->Prev=P;
    It->Next=P;
    if(It==Head) Head=P;
    It=P;
    N++;
    return true;
}

template <typename Thing>
void ListDEC<Thing>::ItBegin(){
    It=Head;
}

template <typename Thing>
bool ListDEC<Thing>::ItEnd(){
    return !(It==Head->Prev);
}

template <typename Thing>
void ListDEC<Thing>::ItMM(){
    if(It) It=It->Next;
}

template <typename Thing>
void ListDEC<Thing>::Itmm(){
   if(It) It=It->Prev;
}

template <typename Thing> 
Thing ListDEC<Thing>::getFront(){
    if(!Head){
         cout<<"Lista vazia."<<endl;
        return Thing(); //volta o valor padrao de inicio, seja int, string etc
    } 
    return Head->D;
}

template <typename Thing>
Thing ListDEC<Thing>::getIt(){
    if(!It){
         cout<<"Lista vazia."<<endl;
        return Thing(); //volta o valor padrao de inicio, seja int, string etc
    } 
    return It->D;
}

template <typename Thing>
void ListDEC<Thing>::PopFront(){
    if(Head){ //se o head n for nulo = a lista n tá vazia
        Node<Thing>* P=Head;
        if (N==1) {
            Head=It=nullptr;
        }else{
            Head=Head->Next;
            P->Next->Prev=P->Prev;
            P->Prev->Next=P->Next;
        }
        if(It==P) It=Head;
        delete P;
        N--;
    } 
}

template <typename Thing>
void ListDEC<Thing>::PopIt() {
    if (!It) return;
    Node<Thing>* P = It;
    
    if(N==1){
        Head=It=nullptr;
    }else{
        It->Prev->Next=It->Next;
        It->Next->Prev=It->Prev;
        It=It->Next;
    }
    if(P==Head) Head=Head->Next;
    delete P;
    N--;
}

template <typename Thing>
ListDEC<Thing>::~ListDEC(){
    while(N>0){
        Node<Thing>* P=Head;
        if(N==1){
            Head=It=nullptr;
        }else{
            Head=Head->Next;
            P->Prev->Next=P->Next;
            P->Next->Prev=P->Prev;
            if(It==P) It=Head;
        }
        delete P;
        N--;
    }
}