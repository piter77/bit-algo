#include <iostream>
#include <math.h>
using namespace std;

void merge (int *tab, int size, int mid){
    int merged[size];
    int left=0;
    int right=mid;
    int i=0;
    while (left<mid and right<size){
        if(tab[left]<=tab[right]){
            merged[i]=tab[left];
            left++;
            i++;
        }
        else{
            merged[i]=tab[right];
            right++;
            i++;
        }
    }
    while (left<mid){
        merged[i]=tab[left];
        left++;
        i++;
    }
    while (right<size){
        merged[i]=tab[right];
        right++;
        i++;
    }
    for (int j=0; j<size; j++){
        tab[j]=merged[j];
    }
}

void mergesort (int * tab, int size){
    if (size==1) return;
    int mid = size/2;
    mergesort (tab, mid);
    mergesort (tab+mid, size-mid);
    merge (tab, size, mid);
}

int main()
{
    int size;
    cin>>size;
    int tab[size];

    for (int i=0; i<size; i++)
        cin>>tab[i];
    mergesort(tab, size);

    for (int i=0; i<size; i++)
        cout<<tab[i]<<" ";

    return 0;
}
