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
ll ans_to_problem;
struct TrieNode
{
    vector <struct TrieNode*> children;
    char value;
    bool isend;
};
struct TrieNode *CreateNode(char val)
{
    ans_to_problem++;
    struct TrieNode *ans=(new struct TrieNode());
    ans->value=val;
    fr(i,0,26)
    {
        ans->children.pb(NULL);
    }
    ans->isend=true;
    return ans;
}
bool TrieStringSearch(struct TrieNode *root,string s)
{
    struct TrieNode* temp=root;
    fr(i,0,sz(s))
    {
        if(temp->children[s[i]-'a']!=NULL)
        {
            temp=temp->children[s[i]-'a'];
        }
        else
        {
            return false;
        }
    }
    return true;
}
void TrieAddString(struct TrieNode *root, string s)
{
    if(TrieStringSearch(root,s))
        return;
    ll i=0;
    struct TrieNode *temp=root;
    while(i<sz(s))
    {
        if(temp->children[s[i]-'a']!=NULL)
        {
            temp=temp->children[s[i]-'a'];
            i++;
        }
        else
        {
            break;
        }
    }
    if(i==sz(s))
        temp->isend=true;
    while(i<sz(s))
    {
        struct TrieNode* toadd=CreateNode(s[i]);
        if(i!=sz(s)-1)
            toadd->isend=false;
        temp->children[s[i]-'a']=toadd;
        temp=toadd;
        i++;
    }
}
int main()
{
    //fastio
    string s,_bin;
    ll k;
    cin>>s>>_bin>>k;
    ve <ll> bin(26);
    struct TrieNode *root=CreateNode(' ');
    fr(i,0,26)
    {
        bin[i]=_bin[i]-'0';
    }
    
    fr(i,0,sz(s))
    {
        string toadd="";
        ll bad=0;
        fr(j,i,sz(s))
        {
            if(bin[s[j]-'a']==0)
                bad++;
            if(bad>k)
            {
                break;
            }
            toadd.pb(s[j]);
        }
        TrieAddString(root,toadd);
    }
    cout<<ans_to_problem-1<<endl;
    /**/
}