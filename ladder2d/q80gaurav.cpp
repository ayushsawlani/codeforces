#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
#define inarr(arr,n); for(int i=0;i<n;i++) cin >> arr[i];
#define outarr(arr,n); for(int i=0;i<n;i++) cout<<arr[i]<<' ';
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ve vector
#define fi first
#define se second
#define pa pair
#define fastio  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ld long double
#define fr(i, a, b); for (ll i = a; i < b; i++)
#define frn(i, a, b); for (ll i = a; i > b; i--)
#define mk make_pair
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 1e18;
double p[5005]={0},prob[5005][5005]={0},ans = 0,cur = 0,tmp = 0,q=0;
int t[5005]={0},N,T;
int main(void)
{
    cin>>N>>T;
    fr(i,0,N)
    {
        cin>>p[i]>>t[i];
        p[i] *= 0.01;
    }
    prob[0][0] = 1; //base case
    fr(i,1,N+1)
    {
        cur=0,tmp=0,q=pow(1-p[i-1],t[i-1]-1);
        fr(k,0,T+1)
        {
            cur=cur*(1-p[i-1])+prob[i-1][k];
            if(k>=t[i-1]-1)
            {
                cur -= prob[i-1][k-t[i-1]+1] * q;
                if(k>=t[i-1])
                {
                    prob[i][k] += prob[i-1][k-t[i-1]] * q;
                }
            }
            if(k >= T-t[i-1] && k < T)
            {
                tmp = prob[i-1][k+1] + (1-p[i-1]) * tmp;
            }
            prob[i][k+1] = cur * p[i-1];
        }
        ans += tmp * (i-1);
    }
    fr(k,0,T+1)
    {
        ans += N * prob[N][k];
    }
    printf("%.15lf\n", ans);
}