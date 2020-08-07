#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define pb push_back
#define mod (ll)1e6+7
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
ve <unordered_set <string>> hashtable(mod);
int hashcompute(string s)
{
    int ans=0;
    int x=1;
    frn(i, sz(s)-1, 0)
    {
        ans+=((s[i]-'a')*x);
        x=x*26;
        x%=mod;
        ans%=mod;
    }
    return ans;
}
int main()
{
    fastio
    int n;
    cin>>n;
    string cipher;
    cin>>cipher;
    int m;
    cin>>m;
    unordered_map <string,string> imp;
    ve <int> lim(26,0);
    while(m--)
    {
        string word;
        cin>>word;
        string s;
        fr(i, 0, sz(word)-1)
        {
            if(word[i]<'a')
            {
                s.pb(word[i]-'A'+'a');
            }
            else
            {
                s.pb(word[i]);
            }
        }
        lim[s[0]-'a']=max(lim[s[0]-'a'], sz(word));
        imp[s]=word;
        hashtable[hashcompute(s)].insert(s);
    }
    ve <int> dp(sz(cipher)+1, -1);
    dp[0]=-2;
    fr(i, 1, n)
    {
        int val=0;
        string check="";
        frn(j, i, max(1,i-lim[cipher[i-1]-'a']-5))
        {
            check.pb(cipher[j-1]);
            val*=26;
            val+=(cipher[j-1]-'a');
            val%=mod;
            if(dp[j-1]!=-1)
            {
               if(sz(hashtable[val]))
                {
                    if(hashtable[val].find(check)!=hashtable[val].end())
                    {
                        dp[i]=j;
                        break;
                    }   
                }
            }
        }
    }
    int i=n;
    ve <string> ans;
    while(i>=1)
    {
        int j=dp[i];
        string word;
        frn(k, i-1,j-1)
        {
            word.pb(cipher[k]);
        }
        ans.pb(word);
        i=j-1;
    }
    frn(i, sz(ans)-1, 0)
    {
        cout<<imp[ans[i]]<<" ";
    }
    cout<<endl;
    //*/
}