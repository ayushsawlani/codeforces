#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    int a[n][2];
    int flag[n];
    for(int i=0;i<n;i++)
    {
        flag[i]=0;
        cin>>a[i][0];
        cin>>a[i][1];
    }
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i][0];
    pair <int,int> b[n];
    for(int i=0;i<n;i++)
    {
        b[i].first=a[i][0]+a[i][1];
        b[i].second=i;
    }
    sort(b,b+n);
    int i=n-1;
    while(1)
    {
        if((sum>=-500)&&(sum<=500))
            break;
        if(i<0)
            break;
        sum-=b[i].first;
        flag[b[i].second]=1;
        if(sum<-500)
        {
            sum+=b[i].first;
            flag[b[i].second]=0;
        }
        i--;
    }
    if(!((sum>=-500)&&(sum<=500)))
        cout<<-1<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(flag[i])
                cout<<"G";
            else
            {
                cout<<"A";
            }
        }
        cout<<endl;
    }
}