#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld double
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
//uncomment for accurate decimal precision.
ve <ve <ld>> dp1(202, ve <ld>(202, 0.0));
ve <ve <ld>> dp2(202, ve <ld>(202, 0.0));
int main()
{
    //fastio
    cout << fixed << setprecision(12);
    ll n, l, k;
    cin>>n>>l>>k;
    ve <ld> in(n);
    ve <ll> cap(n);
    inarr(i, in, n);
    inarr(i, cap, n);
    ld prod=1;
    fr(i, 0, n-1)
    {
        in[i]=in[i]/100;
    }
    while(1)
    {
        ll f=1;
        fr(i, 0, n-2)
        {
            if(cap[i]<cap[i+1])
            {
                f=0;
                ll _t;
                ld __t;
                swap(cap[i], cap[i+1], _t);
                swap(in[i], in[i+1], __t);
            }
        }
        if(f)
            break;
    }
    dp2[0][k]=1;
    fr(i, 1, n)
    {
        fr(j, 0, n)
        {
            fr(m, 0, 201)
            {
                dp1[j][m]=dp2[j][m]*(1-in[i-1]);
            }
            if(j>0)
            {
                fr(m, 0, 201)
                {
                    if((m+cap[i-1]>=0)&&(m+cap[i-1]<201))
                    {
                        dp1[j][m+cap[i-1]]+=dp2[j-1][m]*in[i-1];
                    }
                    else if(m+cap[i-1]>=201)
                    {
                        dp1[j][201]+=dp2[j-1][m]*in[i-1];
                    }
                }
            }
        }
        dp2=dp1;
        for(auto it: dp1)
        {
            setvector(it, 0.0, 202);
        }
    }
    ld ans=0;
    fr(i, 0, 201)
    {
        fr(j, l, n)
        {
            ans+=dp2[j][i];
        }
    }
    cout<<ans<<endl;
}