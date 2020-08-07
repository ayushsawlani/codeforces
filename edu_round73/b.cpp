#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n-1;j+=2)
        {
            if(i%2==0)
            {
                cout<<"WB";
            }
            else
            {
                cout<<"BW";
            }
            
        }
        if((n%2==1)&&(i%2==0))
            cout<<"W";
        else if((n%2==1)&&(i%2==1))
            cout<<"B";
        cout<<endl;
    }   
}