#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0,n,s;
    cin>>n>>s;
    int ans_arr[n],arr[n];
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        int flag=0;
        for(int j=0;j<temp;j++)
        {
            int temp2;
            cin>>temp2;
            if(s>temp2)
                flag=1;
        }
        if(flag)
            ans_arr[ans++]=i+1;
    }
    cout<<ans<<endl;
    for(int i=0;i<ans;i++)
        cout<<ans_arr[i]<<" ";
    if(ans==0)
        cout<<endl;
}