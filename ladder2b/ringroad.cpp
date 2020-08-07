#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long int ans=0;
    int a=1,b;
    for(int i=0;i<m;i++)
    {
        cin>>b;
        ans+=(b-a+n)%n;
        a=b;
    }
    cout<<ans<<endl;
}