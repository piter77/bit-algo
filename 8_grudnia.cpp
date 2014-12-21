#include <iostream>
#include <cstddef>
using namespace std;

struct node{
    int value;
    node * next;
};

node * insert (int value, node * head) // wstawianie wartości do posortowanego zbioru
{
    node * prev;
    note * quest;
    prev=NULL;
    qest=head;
    while(qest->value<=value && qest!=NULL){
        prev=qest;
        qest=qest->next;
    }

    node * nowy = new node;
    nowy->value=value;

    if (qest==NULL and prev==NULL){ //zbiór pusty
         nowy->next=NULL;
         //head=nowy; // w wersji z przekazaniem przez referencję &
         return nowy;
    }
    if (prev!=NULL){
        nowy->next=qest;
        prev->next=nowy;
        return head;
    }
    if (qest!=NULL and prev==NULL){
        nowy->next=qest;
        //head=nowy; // w wersji z przekazaniem przez referencję &
        return nowy;
    }

}

node * remove_wzorcowo (int value, node * head) // usuwa wskazany element
{
    if (head==NULL)
        return head;
    if (head-> value == value){
        node * pointer = head->next;
        delete head;
        return pointer;
    }
    node * to_delete = head->next;
    node * previous = head;
    while (to_delete->next!= NULL && to_delete->value!=value){
        previous=to_delete;
        to_delete=to_delete->next;
    }

    if(to_delete->value==value){
        previous->next= to_delete -> next;
        delete to_delete;
    }
    return head;

}

node * find_remove (int query, node * head)
{

     while (head!=NULL){ //nie ma takiego elementu
        if (head->next->value == query){
            return head;
        }
        else head=head->next;
    }
    return NULL;
}

node * remove_moje (int value, node * head)
{
    node * prev=find_remove (value, head);
    if (prev != NULL){
        prev->next=prev->next->next;
        delete prev->next;
    }
    return head;
}

node * push_front (int value, node * head) // dopisuje coœ od przodu do ³añcucha
{
    node * nowy = new node;
    nowy->next=head;
    nowy->value=value;
    return nowy;
}


node * find (int query, node * head)      // szuka wartoœci query w ³añcuchu
{
     while (head!=NULL){ //nie ma takiego elementu
        if (head->value == query){
            return head;
        }
        else head=head->next;
    }
    return NULL;
}

node * find_recusrive (int query, node * head){ // szuka rekursywnie wartoœci query w ³añcuchu
    if (head == NULL)
        return NULL;
    else
        if (head->value == query)
            return head;
        else
            find (query, head->next);
}

int main()
{



    return 0;
}
