#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans=-1;
    for(int i=(a+1)/2;i<=a;i++)
        if(i%b==0)
        {
            ans=i;
            break;
        }
    cout<<ans;

}