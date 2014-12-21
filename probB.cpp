#include<iostream>
using namespace std;

long long NWD (long long a, long long b)
{
    while (b!=0)
    {
        long long c;
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

long long NWW (long long a, long long b)
{
    return a*b/(NWD(a, b));
}

int main ()
{
    long long z, i;
    cin>>z;
    long long t[2*z];
    i=0;
    while(i<2*z)
    {
        cin>>t[i]>>t[i+1];
        i+=2;
    }
    i=0;
    while(i<2*z)
    {
        cout<<NWD(t[i], t[i+1])<<" "<<NWW(t[i], t[i+1])<<endl;
        i+=2;
    }
}
