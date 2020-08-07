#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ceil (ll)ceil
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
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(i, vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//uncomment for accurate decimal precision.
//cout << fixed << setprecision(9);
int main()
{
    //fastio
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ve <ll> ptr(n);
        ve <bool> ans(n, true);
        fr(i, 0, n-1)
        {
            ptr[i]=i;
        }
        ll j=n;
        string s1;
        while(j--)
        {
            char m1='z';
            fr(i, 0, n-1)
            {
                if(ans[i])
                m1=min(m1, s[ptr[i]]);
            }
            s1.pb(m1);
            fr(i, 0, n-1)
            {
                if(ans[i])
                {
                    if(s[ptr[i]]!=m1)
                    {
                        ans[i]=false;
                    }
                    else
                    {
                        if((ptr[i]>=i)&&(ptr[i]<n-1))
                        {
                            ptr[i]++;
                        }
                        else
                        {
                            if((n-i)%2==0)
                            {
                                if(ptr[i]==n-1)
                                {
                                    ptr[i]=0;
                                }
                                else
                                {
                                    ptr[i]++;
                                }
                            }
                            else
                            {
                                if(ptr[i]==n-1)
                                {
                                    ptr[i]=i-1;
                                }
                                else
                                {
                                    ptr[i]--;
                                }
                                
                            }
                            
                        }
                    }
                }
            }
            //outarr(i, ptr, n);
            //cout<<endl;
        }
        ll pr=-1;
        frn(i, n-1, 0)
        {
            if(ans[i])
            {
                pr=i+1;       
            }
        }
        cout<<s1<<endl; 
        cout<<pr<<endl;
    }
}