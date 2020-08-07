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
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long int
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define frn(i, a, b) for (int i = a; i >= b; i--)
#define mk make_pair
#define endl "\n"
#define setvector(vname,value,size); for(int i=0;i<size;i++)vname[i]=value;
const ll inf = 9e18;
//cout << fixed << setprecision(9) << ans <<endl; for accurate decimal precision.
ve <ll> lpsarray(string pat)
{
    ll M=sz(pat);
    ve <ll> lps(sz(pat), 0);
    int len = 0;   
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    return lps;
}
#define si 1e2+4
void trace_back(string &s, ve <ll> &tr, ve <ve <ve <ve <ll>>>> &pi)
{
    if(pi[tr[0]][tr[1]][tr[2]][0]!=-1)
    {
        trace_back(s,pi[tr[0]][tr[1]][tr[2]], pi);    
    }
    cout<<s[tr[0]];
}
int main()
{
    string s1, s2, virus;
    cin>>s1>>s2>>virus;
    ve <ll> util=lpsarray(virus);
    ve <ve <ve <ll>>> dp(si, ve <ve <ll>>(si, ve <ll>(si, 0)));
    ve<ve <ve <ve <ll>>>> pi(si, ve<ve <ve <ll>>>(si, ve<ve <ll>>(si, ve <ll> (3, -1))));
    ve <ve <ll>> atka(si, ve <ll> (26));
    fr(i, 0, sz(virus)-1)
    {
        fr(j, 0, 25)
        {
            if(j+'A'==virus[i])
            {
                atka[i][j]=i+1;
            }
            else
            {
                if(i>0)
                    atka[i][j]=atka[util[i-1]][j];
                else
                {
                    atka[i][j]=0;
                }
            }
        }
    }
    fr(i, 1, sz(s1))
    {
        fr(j, 1, sz(s2))
        {
            fr(k, 0, sz(virus)-1)
            {
                if(s1[i-1]==s2[j-1])
                {
                    if(dp[i][j][atka[k][s1[i-1]-'A']]<dp[i-1][j-1][k]+1)
                    {  
                        dp[i][j][atka[k][s1[i-1]-'A']]=dp[i-1][j-1][k]+1;
                        pi[i][j][atka[k][s1[i-1]-'A']]={i-1, j-1, k};
                    }
                }
                if(dp[i][j][k]<dp[i-1][j][k])
                {
                    dp[i][j][k]=dp[i-1][j][k];
                    pi[i][j][k]=pi[i-1][j][k];
                }                
                if(dp[i][j][k]<dp[i][j-1][k])
                {
                    dp[i][j][k]=dp[i][j-1][k];
                    pi[i][j][k]=pi[i][j-1][k];
                }
            }
        }
    }
    ve <ll> ans(3, -1);
    ll ans1=0;
    fr(i, 0, sz(virus)-1)
    {
        if(dp[sz(s1)][sz(s2)][i]>ans1)
        {
            ans1=dp[sz(s1)][sz(s2)][i];
            ans=pi[sz(s1)][sz(s2)][i];
        }
    }
    if(ans1==0)
    {
        cout<<0<<endl;
        return 0;
    }
    trace_back(s1, ans, pi);
    //*/
}