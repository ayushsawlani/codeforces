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
#define fr(i, a, b); for (int i = a; i < b; i++)
#define frn(i, a, b); for (int i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
int main()
{
    //fastio
    ll n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    ll dp[n1+1][n2+1][2];
    memset(dp,0,(n1+1)*(n2+1)*2*sizeof(ll));
    dp[0][0][0]=1;
    dp[0][0][1]=1;
    fr(i,0,n1+1)
    {
        fr(j,0,n2+1)
        {
            if(i>0)
            {
                fr(k,0,k1)
                {   
                    if(i-k>0)
                    {
                        dp[i][j][0]+=dp[i-k-1][j][1];
                    }
                    dp[i][j][0]%=(ll)1e8;
                }
            }
            if(j>0)
            {
                fr(k,0,k2)
                {   
                    if(j-k>0)
                    {
                        dp[i][j][1]+=dp[i][j-k-1][0];
                    }
                    dp[i][j][1]%=(ll)1e8;
                }
            }
        }
    }
  /*  fr(i,0,n1+1)
    {
        fr(j,0,n2+1)
        {
            cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        }
    }
    */
    cout<<(dp[n1][n2][0]+dp[n1][n2][1])%((ll)1e8)<<endl;
}