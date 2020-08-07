#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M1 1000000
#define M2 1000
int c[M1+1];
int b[M1+1];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    int n;
    cin>>n;
    for(int i=0;i<=M1;i++)
    {
        c[i]=0;
        b[i]=-1;
    }
    //n=200000;
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        //temp=i+1;
        c[temp]=1;
    }
    for(int i=1;i<=M1;i++)
    {
        if(c[i])
            b[i]=i;
        else
        {
            b[i]=b[i-1];       
        }
    }
    for(int i=M2+1;i<=M1;i++)
    {
        if(c[i])
        {
            for(int j=2*i-1;j<=M1;j=j+i)
            {
                if(b[j]>i)
                {
                    ans=max(ans,b[j]%i);
                }
            }
            ans=max(ans,b[M1]%i);
        }
    }
    for(int i=1;i<=M1;i++)
    {
        if(c[i]==1)
        {
            int x=M2;
            for(int j=1;j<=min(x,i);j++)
            {
                if(c[j])
                    ans=max(ans,i%j);
            }
        }
    }
    cout<<ans<<endl;

}
