#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    string arr[m];
    for(int i=0;i<m;i++)
        arr[i]="";
    for(int i=0;i<m;i++)
    {
        long long int temp;
        cin>>temp;
        while(temp>0)
        {
            if(temp%2==1)
                arr[i].append("1");
            else
            {
                arr[i].append("0");
            }
            temp=temp/2;
        }
    }
    long long int feder;
    cin>>feder;
    string f="";
    while(feder>0)
    {
        if(feder%2==1)
            f.append("1");
        else
        {
            f.append("0");
        }
        feder=feder/2;
    }
    for(int i=0;i<m;i++)
    {
        int p=0;
        int max=std::max(arr[i].size(),f.size());
        for(int j=f.size();j<max;j++)
            f.append("0");
        for(int j=arr[i].size();j<max;j++)
            arr[i].append("0");
        for(int j=0;j<max;j++)
        {
            if(arr[i][j]!=f[j])
                p++;
        }
        if(p<=k)
            ans++;
    }
    cout<<ans<<endl;
}