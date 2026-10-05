#include <iostream>

using namespace std;

template <typename Thing>
class Node
{
    public:
    Thing D;
    Node<Thing>* Next;
};

template <typename Thing>
class List
{
    Node<Thing>* Head;
    Node<Thing>** It; //ponteiro pra ponteiro
    int N;
public:
    List();
    int Size();
    void Clear();
    bool Empty();
    bool PushFront(Thing T);
    bool PushIt(Thing T);
    void ItBegin();
    bool ItEnd();// fim da lista
    void ItMM();
    Thing getFront();
    Thing getIt();
    void PopFront();
    void PopIt();
    ~List();
};

template <typename Thing>  //inventei *********************
List<Thing>::List(){
    Head=nullptr;
    It=nullptr;
    N=0;
}

template <typename Thing>
int List<Thing>::Size(){
    return N;
}

template <typename Thing>
void List<Thing>::Clear(){
    Node<Thing>* P;
    while(Head){
        P=Head;
        Head=Head->Next;
        delete P;
    }
    N=0;
}

template <typename Thing>
bool List<Thing>::Empty(){
    return !Head;
}

template <typename Thing>
bool List<Thing>::PushFront(Thing T){
    Node<Thing> *P=new Node<Thing>;
    if(!P) return false;
    P->D=T;
    P->Next=Head;
    Head=P;
    N++;
    return true;
}

template <typename Thing>
bool List<Thing>::PushIt(Thing T){
    Node<Thing> *P=new Node<Thing>; //cria P
    if(!P) return false; //falso se P n for criado
    P->D=T; // o D de P recebe o dado a ser inserido
    P->Next=*It;//aponta pra onde o It está apontando fazendo
        // com que o novo nó seja inserido antes do próximo nó
    *It=P; //it agora aponta pro ponteiro P
    N++;
    return true;
}

template <typename Thing>
void List<Thing>::ItBegin(){
    It=&Head;
}

template <typename Thing>
bool List<Thing>::ItEnd(){
    return !(*It);
}

template <typename Thing>
void List<Thing>::ItMM(){
    It=&((*It)->Next);//aponta p/ o endereço do proximo ponteiro por isso o "&"
}

template <typename Thing> //inventei ***********************************
Thing List<Thing>::getFront(){
    if(!Head){
        return Thing(); //volta o valor padrao de inicio, seja int, string etc
    } 
    return Head->D;
}
    

template <typename Thing>
Thing List<Thing>::getIt(){
    if(!(*It)){
        cout<<"Iterador no final da lista ou lista vazia."<<endl;
        return Thing();
    }else{
        return (*It)->D;
    }
    
}

template <typename Thing>
void List<Thing>::PopFront(){
    if(Head){ //se o head n for nulo = a lista n tá vazia
        Node<Thing>* P=Head;
        Head=Head->Next;
        delete P;
        N--;
    } 
}

template <typename Thing>
void List<Thing>::PopIt(){
    if (*It) //se nao for nulo, entra no if
    {
        Node<Thing>* P=*It; //P aponta pra onde It está apontando
        *It=P->Next; //o It agr aponta pro proximo nó 
        delete P; 
        N--;
    }
}

template <typename Thing> //inventei*******************
List<Thing>::~List(){
     Node<Thing>* P;
    while(Head){
        P=Head;
        Head=Head->Next;
        delete P;
    }
    N=0;
}

int main() {
    List<int> lista;

    // Testa PushFront
    lista.PushFront(10);
    lista.PushFront(20);
    lista.PushFront(30); // Lista: 30 -> 20 -> 10

    cout << "Elementos apos PushFront: ";
    lista.ItBegin();
    while (!lista.ItEnd()) {
        cout << lista.getIt() << " ";
        lista.ItMM();
    }
    cout << endl;

    // Testa PushIt (inserir depois do início)
    lista.ItBegin(); // volta o iterador pro começo
    lista.ItMM();    // avança uma posição (agora entre 30 e 20)
    lista.PushIt(25); // Insere 25 entre 30 e 20

    cout << "Elementos apos PushIt (25 entre 30 e 20): ";
    lista.ItBegin();
    while (!lista.ItEnd()) {
        cout << lista.getIt() << " ";
        lista.ItMM();
    }
    cout << endl;

    // Testa PopIt (remove o 25 que acabamos de inserir)
    lista.ItBegin();
    lista.ItMM(); // posição do 25
    lista.PopIt(); // remove 25

    cout << "Elementos apos PopIt (remover 25): ";
    lista.ItBegin();
    while (!lista.ItEnd()) {
        cout << lista.getIt() << " ";
        lista.ItMM();
    }
    cout << endl;

    // Testa PopFront
    lista.PopFront(); // Remove 30

    cout << "Elementos apos PopFront (remover 30): ";
    lista.ItBegin();
    while (!lista.ItEnd()) {
        cout << lista.getIt() << " ";
        lista.ItMM();
    }
    cout << endl;

    // Testa getFront
    cout << "Elemento no topo (getFront): " << lista.getFront() << endl;

    // Testa Size e Empty
    cout << "Tamanho da lista: " << lista.Size() << endl;
    cout << "Lista esta vazia? " << (lista.Empty() ? "Sim" : "Nao") << endl;

    // Testa Clear
    lista.Clear();
    cout << "Lista limpa. Esta vazia? " << (lista.Empty() ? "Sim" : "Nao") << endl;

    return 0;
}

