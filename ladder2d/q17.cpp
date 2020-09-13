#include<iostream>
#include<bits/stdc++.h>
using namespace std;
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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    string s;
    cin>>s;
    ll a_even=0,a_odd=0,b_even=0,b_odd=0;
    fr(i,0,sz(s))
    {
        if(s[i]=='a')
        {
            if(i%2)
            {
                a_odd++;
            }
            else
            {
                a_even++;
            }
        }
        else
        {
             if(i%2)
            {
                b_odd++;
            }
            else
            {
                b_even++;
            }
        }
    }
    ll ans_even=a_odd*a_even+b_odd*b_even;
    ll ans_odd=(a_odd)*(a_odd+1)+(a_even)*(a_even+1)+(b_odd)*(b_odd+1)+(b_even)*(b_even+1);
    ans_odd/=2;
    cout<<ans_even<<" "<<ans_odd<<endl;
}