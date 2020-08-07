#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll * z_array(string s)
{
    ll* ans=(ll*)(malloc(s.size()*sizeof(ll)));
    ans[0]=-1;
    ll l=0,r=0;
    for(ll i=1;i<s.size();i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while((r<s.size())&&(s[r]==s[r-i]))
            {
                r++;
            }
            r--;
            ans[i]=r-l+1;
        }
        else
        {
            ll k=i-l;
            if(ans[k]+i<=r)
            {
                ans[i]=ans[k];
            }
            else
            {
                l=i;
                while((r<s.size())&&(s[r]==s[r-i]))
                {
                    r++;
                }
                r--;
                ans[i]=r-l+1;
            }
            
        }
    }
    return ans;
}
int main()
{
    ll arr[1000001]={0};
    string s;
    cin>>s;
    ll *z=z_array(s);
    ll ans=-1;
    ll len_s=s.size();
    ll greatest =0;
    for(ll i=1;i<s.size();i++)
    {
        if(i+z[i]!=s.size())
            greatest=max(greatest,z[i]);
    }
    for(ll i=1;i<s.size();i++)
    {
        if((i+z[i]==s.size())&&(greatest>=z[i]))
        {
            ans=max(ans,z[i]);
        }
        else
        {
            if(greatest<z[i])
                greatest=z[i];
        }
    }
    if(ans==-1)
    {
        cout<<"Just a legend"<<endl;
    }
    else
    {
        for(ll i=0;i<ans;i++)
            cout<<s[i];
        cout<<endl;
    }



    

}