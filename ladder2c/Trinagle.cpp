#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll a,b;
    cin>>a>>b;
    for(ll i=1;i<b;i++)
    {
        ll j=sqrt(b*b-i*i);
        if(((long double)j==sqrt(b*b-i*i))&&((j*a)%b==0)&&((i*a)%b==0))
        {
            if((i!=((-1)*j*a)/b)&&((j!=(i*a)/b)))
            {
                cout<<"YES"<<endl;
                cout<<0<<" "<<0<<endl<<i<<" "<<j<<endl<<((-1)*j*a)/b<<" "<<(i*a)/b<<endl;
                return 0;
            }
            else if((j!=((-1)*i*a)/b)&&((i!=(j*a)/b)))
            {
                cout<<"YES"<<endl;
                cout<<0<<" "<<0<<endl<<j<<" "<<i<<endl<<((-1)*i*a)/b<<" "<<(j*a)/b<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}