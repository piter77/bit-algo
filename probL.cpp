#include <iostream>
#include <math.h>
using namespace std;

int x=0;

void merge (int *tab, int size, int mid){
    int *merged = new int [size];
    int left=0;
    int right=mid;
    int i=0;
    while (left<mid and right<size){
        if(tab[left]<tab[right]){
            merged[i]=tab[left];
            left++;
            i++;
        }
        else if (tab[left]>tab[right]){
            merged[i]=tab[right];
            right++;
            i++;
        }
        else{
            left++;
            x++;
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
    delete[] merged;
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
    int n;
    int m;
    cin>>m>>n;
    int size=m+n;
    int *tab = new int [size];

    for (int i=0; i<size; i++)
        cin>>tab[i];

    mergesort(tab, size);

    for (int i=0; i<size-x; i++)
        cout<<tab[i]<<" ";

    delete[] tab;
    return 0;
}
