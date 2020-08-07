#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(i,arr,n); for(ll i=0;i<n;i++) cin >> arr[i];
#define outarr(i,arr,n); for(ll i=0;i<n;i++) cout<<arr[i]<<' ';
#define swap(a,b,t) {t=a;a=b;b=t;}
#define ve vector
#define sz(a) (int)((a).size())
#define fi first
#define se second
#define pa pair
#define fastio  {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
int main()
{
    fastio
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    if(abs(c-d)>=2)
    {
        cout<<-1<<endl;
        return 0;
    }
    string s="";
    if(c==d)
    {
        if(a>=c+1)
        {
            a--;
            s="4";
            fr(i, 0, c-1)
            {
            s.pb('7');
            s.pb('4');
                a--;
                b--;
            }
       }
        else if(b>=c+1)
        {
            b--;
            s="7";
            fr(i, 0, c-1)
            {
            s.pb('4');
            s.pb('7');
                a--;
                b--;
            }
       }
       else
       {
           cout<<-1<<endl;
           return 0;
       }
       
       
    }
    else if(c>d)
    {
        fr(i, 0, c-1)   
        {
            s.pb('4');
            s.pb('7');
            a--;
            b--;
        }
    }
    else
    {
        fr(i, 0, d-1)
        {
            s.pb('7');
            s.pb('4');
            a--;
            b--;
        }
    }
            if((a<0)||(b<0))
            {
                cout<<-1<<endl;
                return 0;
            }
 
    ll i;
    if(sz(s)==1)
    {
        if((s[0]=='4')&&(b))
        {
            cout<<-1<<endl;
            return 0;
        }
        if((s[0]=='7')&&(a))
         {
            cout<<-1<<endl;
            return 0;
         }
    }
    for(i=0;i<sz(s);i++)
    {
        if(s[i]=='4')
        {
            break;
        }
        cout<<s[i];
    }
    while(a--)
        cout<<"4";
    ll j=sz(s)-1;
    for(;j>=0;j--)
    {
        if(s[j]=='7')
            break;
    }
    for(;i<j;i++)
    {
        cout<<s[i];
    }
    while(b--)
    {
        cout<<"7";        
    }
    for(;i<sz(s);i++)
        cout<<s[i];
}