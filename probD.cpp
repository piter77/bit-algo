#include <iostream>
#include <math.h>
using namespace std;



int main()
{
    int n, j;
    bool swap=true;
    cin>>n;
    int tab[n];
    for (int i=0; i<n; i++)
        cin>>tab[i];

    j=1;
    while (swap)
    {
        swap=false;
        for (int i=0; i<(n-j); i++)
        {
            if (tab[i]>tab[i+1])
            {
                swap=true;
                tab[i]=tab[i]+tab[i+1];
                tab[i+1]=tab[i]-tab[i+1];
                tab[i]=tab[i]-tab[i+1];
            }
        }
        j++;
    }

    for (int i=0; i<n; i++)
        cout<<tab[i]<<" ";
}
