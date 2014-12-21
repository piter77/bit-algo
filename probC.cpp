#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int z, n;
    cin>>z;
    bool *tab = new bool [z];
    int j=0;
    while(j<z){
        cin>>n;
        if (n==2)
            tab[j]=true;
        else if (n<2 or n%2==0)
            tab[j]=false;
        else{
            tab[j]=true;
            for (int i=3; i*i<=n; i+=2){
                if (n%i==0)
                    tab[j]=false;
            }
        }
        j++;
    }
    for(int j=0; j<z; j++){
        if (tab[j])
            cout<<"TAK"<<endl;
        else
            cout<<"NIE"<<endl;
    }
    delete[] tab;
}
