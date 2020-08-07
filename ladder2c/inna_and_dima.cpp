#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define Size (int)1e6
ll finalclan=-1;
ll clan[(int)1e6];
ll pi[(int)1e6];
ll dist[(int)1e6];
ll compsize[Size];
ll c[Size];
ll cutil[Size];
ll leftover[Size];
ll *final =new ll();
void diameter(vector <vector<ll>> &G,ll seed, ll traversed,string *in,ll util)
{
    traversed++;
    c[seed]=1;
    if((*final)/4<(traversed)/4)
    {
        (*final)=(traversed);
        finalclan=clan[seed];
    }
    else if((*final)/4==(traversed)/4)
    {
        if(in[finalclan/util][finalclan%util]!='D')
        {
            (*final)=(traversed);
            finalclan=clan[seed];
        }
    }
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it]==0)
        {
            diameter(G,(*it),traversed, in, util);
        }
        else
        {
            if((*final)/4<(traversed+leftover[*it])/4)
            {
                (*final)=(traversed+leftover[*it]);
                finalclan=clan[seed];
            }
            else if((*final)/4==(traversed+leftover[*it])/4)
            {
                if(in[finalclan/util][finalclan%util]!='D')
                {
                    (*final)=(traversed+leftover[*it]);
                    finalclan=clan[seed];
                }
            }
        }
    }
}
ll csize(vector <vector <ll>> &G, ll seed)
{
    c[seed]=1;
    ll ans=1;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(c[*it]==0)
            ans=max(ans,1+csize(G,(*it)));
        else
        {
            ans=max(ans,1+leftover[*it]);
        }
    }
    leftover[seed]=ans;
    return ans;
}
bool cycle_detection(vector <vector <ll>> &G, ll seed, ll clantype, map <char,char> &next, string *in,ll util)
{
    clan[seed]=clantype;
    cutil[seed]=1;
    for(auto it=G[seed].begin();it!=G[seed].end();it++)
    {
        if(clan[(*it)]==-1)
        {
            if(cycle_detection(G,(*it),clantype,next,in,util))
            {
               return true;
            }
        }
        else if(cutil[*it]==1)
        {
            return true;  
        }
    }
    cutil[seed]=0;
    return false;
}
int main()
{
    (*final)=-5;
    map <char,char> next;
    next['D']='I';
    next['I']='M';
    next['M']='A';
    next['A']='D';
    ll n,m;
    cin>>n>>m;
    string in[n];
    for(ll i=0;i<n;i++)
    {
        cin>>in[i];
    }
    vector <vector <ll>> G,invG;
    for(ll i=0;i<n*m;i++)
    {
        G.push_back(vector <ll>());
        invG.push_back(vector <ll>());
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(i>0)
            {
                if(in[i-1][j]==next[in[i][j]])
                {
                    G[i*m+j].push_back((i-1)*m+j);
                    invG[(i-1)*m+j].push_back(i*m+j);
                }
            }
            if(j>0)
            {
                if(in[i][j-1]==next[in[i][j]])
                {
                    G[i*m+j].push_back(i*m+j-1);
                    invG[(i)*m+j-1].push_back(i*m+j);
                }
            }
            if(j<m-1)
            {
                if(in[i][j+1]==next[in[i][j]])
                {
                    G[i*m+j].push_back(i*m+j+1);
                    invG[(i)*m+j+1].push_back(i*m+j);
                }
            }
            if(i<n-1)
            {
                if(in[i+1][j]==next[in[i][j]])
                {
                    G[i*m+j].push_back((i+1)*m+j);
                    invG[(i+1)*m+j].push_back(i*m+j);
                }
            }
 
        }
    }
    //cycle detection
    memset(clan,-1,Size*sizeof(ll));
    memset(cutil,0,Size*sizeof(ll));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if((clan[i*m+j]==-1))
            {
                ll x=1;
                if(cycle_detection(G,i*m+j,i*m+j,next,in,m))
                {
                    cout<<"Poor Inna!"<<endl;
                    return 0;
                }
            }
        }
    }
    memset(c,0,Size*sizeof(ll));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(c[i*m+j]==0)
            {
                compsize[i*m+j]=csize(G,i*m+j);
            }
        }
    }
    for(ll i=0;i<n*m;i++)
    {
        compsize[i]=compsize[clan[i]];
    }
    memset(c,0,Size*sizeof(ll));
    for(ll i=0;i<n*m;i++)
    {
        if(c[i]==0)
            diameter(G,i,0,in,m);
    }
    if(in[finalclan/m][finalclan%m]!='D')
    {
        if((*final)%4==0)
            (*final)--;
    }
    if((*final)/4>0)
        cout<<(*final)/4<<endl;
    else
    {
        cout<<"Poor Dima!"<<endl;
    }
    
}