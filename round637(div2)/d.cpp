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
#define fr(i, a, b) for (int i = a; i < b; i++)
#define frn(i, a, b) for (int i = a; i > b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
ve <string> refe(10);
 
ll func(string s, ll k)
{
    frn(i, 9, -1)
    {
        ll count=0;
        ll flag=0;
        fr(j, 0, 7)
        {
            if((refe[i][j]=='1')&&(s[j]=='0'))
                count++;
            else if((refe[i][j]=='0')&&(s[j]=='1'))
            {
                flag=1;
                break;
            }
        }
        if(flag)
            continue;
        if(count==k)
            return i;
    }
    return -1;
}
string conv(ll x)
{
    string ans;
    fr(i, 0, 7)
    {
        if(x%2)
            ans.push_back('1');
        else
        {
            ans.push_back('0');
        }
        x=x/2;
    }
    fr(i, 0, 7/2)
    {
        char _temp;
        swap(ans[i], ans[7-i-1], _temp);
    }
    return ans;
}
ll stobin(string s)
{
    ll x=1;
    ll ans=0;
    frn(i, 6,-1)
    {
        ans+=(x*(s[i]-'0'));
        x=x*2;
    }
    return ans;
}
void dfs(ve <ve <ll>> &dp, ve <ve <ll>> &valid,ve<string> &inp,ve <ve <ll>> &ano, pair <ll,ll> seed)
{
    valid[seed.fi][seed.se]=1;
    if(seed.fi>0)
    {
        fr(i, max(seed.se-7,(ll)0),seed.se+1)
        {
            if((dp[seed.fi-1][i]!=-1)&&(ano[stobin(inp[seed.fi])][seed.se-i]!=-1))
            {
                if(valid[seed.fi-1][i]==0)
                {
                    dfs(dp, valid,inp,ano, pair<ll,ll>(seed.fi-1,i));
                }
            }
            
        }
    }
}
int main()
{
    fastio
    ll n, k;
    cin>>n>>k;
    refe[0]="1110111";
    refe[1]="0010010";
    refe[2]="1011101";
    refe[3]="1011011";
    refe[4]="0111010";
    refe[5]="1101011";
    refe[6]="1101111";
    refe[7]="1010010";
    refe[8]="1111111";
    refe[9]="1111011";
    ve <string> inp(n)
    inarr(i, inp, n);
    ve <ve <ll>> ano((ll)pow(2,7), ve <ll>(k+5));
    fr(i, 0, pow(2,7))
        fr(j, 0, k+4)
            ano[i][j]=func(conv(i),j);
 
    ve <ve <ll>> dp( n+5, ve<ll>(k+5,-1));   
    fr(i, 0, n)
    {
        ll val=stobin(inp[i]);
        fr(j, 0, k+1)
        {
            if(i==0)
                dp[i][j]=ano[val][j];
            else
            {
                fr(l, j-7, j+1)
                {
                    if(l<0)
                        l=0;
                    ll digit=ano[val][j-l];
                    if((digit!=-1)&&(dp[i-1][l]!=-1))
                        dp[i][j]=max(dp[i][j],digit);
                }   
            }
        }
    }
    if(dp[n-1][k]==-1)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    ve <ve <ll>> valid(n+5, ve <ll> (k+5,0));
    
    dfs(dp, valid,inp,ano, pair <ll,ll> (n-1,k));
    ll start=0;
    ve <ll> ans;
    fr(i, 0, n)
    {
        ll m1=-1;
        ll s1=-1;
        ll val=stobin(inp[i]);
        fr(j, start, min(start+8,k+1))
        {
            if(valid[i][j])
            {
                if(ano[val][j-start]>m1)
                {
                    s1=j;
                    m1=ano[val][j-start];
                }
            }
        }
        ans.pb(m1);
        start=s1;
    } 
    fr(i, 0, n)
        cout<<ans[i];
    cout<<endl;
    //*/
}