#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s,t;
    cin>>n>>s>>t;
    s=s-1;
    t=t-1;
    int p[n];
    int c_arr[100000];
    for(int i=0;i<100000;i++)
        c_arr[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
        p[i]=p[i]-1;
    }
    int j=s;
    int c=0;
    int flag=0;
    while(j!=t)
    {
        if(c_arr[j]==0)
        {
            c_arr[j]=1;
            j=p[j];
        }
        else
        {
            flag=1;
            break;
        }
        c++;
    }
    if(flag==0)
        cout<<c<<endl;
    else
    {
        cout<<-1<<endl;
    }
}