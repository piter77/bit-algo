#include <iostream>
#include <math.h>
using namespace std;

void binsearch (int *tab, int maxi)
{
    int mid=maxi;
    int mini=0;
    int szukana;
    cin>>szukana;
    while (mini<=maxi){
        mid=(mini+maxi)/2;
        if (tab[mid]<szukana)
            mini=mid+1;
        else
            maxi=mid-1;
    }
    if (tab[mini]==szukana)
        cout<<mini+1<<" ";
    else
        cout<<"-1 ";
}

int main()
{
    int n, k;
    cin>>n;
    cin>>k;
    int *tab = new int [n];

    for (int i=0; i<n; i++)
        cin>>tab[i];

    for (int i=0; i<k; i++)
        binsearch (tab, n-1);
    return 0;
}
