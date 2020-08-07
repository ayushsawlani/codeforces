#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n/4;i++)
        cout<<"abcd";
    if(n%4==1)
        cout<<"a"<<endl;
    else if(n%4==2)
        cout<<"ab"<<endl;
    else if(n%4==3)
        cout<<"abc"<<endl;
}