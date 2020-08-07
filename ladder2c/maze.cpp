#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //ios::sync_with_stdio(0);cin.tie(0);
    ll n,m,k,total=0;
    cin>>n>>m>>k;
    ll maze[n][m];
    for(ll i=0;i<n;i++)
    {
       string temp;
       cin>>temp;
       for(ll j=0;j<m;j++)
       { 
            if(temp[j]=='.')
            {
                maze[i][j]=2;
                total++;
            }
            else
            {
                maze[i][j]=1;
            }
            
       } 
    }
    ll c=0;
    ll si=0,sj=0;
    ll flag=0;
    for(si=0;si<n;si++)
    {

        for(sj=0;sj<m;sj++)
        {
            if(maze[si][sj]==2)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    queue <pair <ll,ll>> q;
    q.push(pair <ll,ll>(si,sj));
    while((!(q.empty()))&&(c<total-k))
    {
        pair <ll,ll> s=q.front();
        q.pop();
        si=s.first;sj=s.second;
        maze[si][sj]=0;
        c++;
        if(si>0)
        {
            if(maze[si-1][sj]==2)
            {
                maze[si-1][sj]=3;
                q.push(pair <ll,ll>(si-1,sj));
            }
        }
        if(si<n-1)
        {
            if(maze[si+1][sj]==2)
            {
                maze[si+1][sj]=3;
                q.push(pair <ll,ll>(si+1,sj));
            }
        }
        if(sj>0)
        {
            if(maze[si][sj-1]==2)
            {
                maze[si][sj-1]=3;
                q.push(pair <ll,ll>(si,sj-1));
            }
        }
        if(sj<m-1)
        {
            if(maze[si][sj+1]==2)
            {
                maze[si][sj+1]=3;
                q.push(pair <ll,ll>(si,sj+1));
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(maze[i][j]==0)
                cout<<".";
            else if(maze[i][j]==1)
            {
                cout<<"#";
            }
            else
            {
                cout<<"X";
            }
            
        }
        cout<<endl;
    }
}