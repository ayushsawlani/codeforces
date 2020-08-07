#include <bits/stdc++.h>
using namespace std;
#define ll long long
string max1(string s1,string s2)
{
    if(s1.size()>s2.size())
        return s1;
    else if(s2.size()>s1.size())
        return s2;
    else
    {
        for(ll i=0;i<s1.size();i++)
        {
            if(s1[i]>s2[i])
                return s1;
            else if (s1[i]<s2[i])
                return s2;
        }
        return s1;
    }
    

}
int main()
{
    ll x;
    cin>>x;
    ll a[10];
    a[0]=INT64_MAX;
    //cout<<a[0]<<endl;
    for(ll i=1;i<10;i++)
        cin>>a[i];
    string ans="-1";
    for(ll i=1;i<10;i++)
    {
        ll left_paint=x%a[i];
        ll mi=9;
        ll letters_left=x/a[i];
        string temp;
        if(letters_left==0)
            temp="-1";
        while(1)
        {
            if((a[mi]==a[i])||(letters_left==0))
                break;
            for(ll j=0;j<left_paint/(a[mi]-a[i]);j++)
            {
                if(letters_left==0)
                    break;
                temp.push_back((char)(mi+48));
                letters_left--;
            }
            left_paint=left_paint%(a[mi]-a[i]);
            mi--;
        }
        while(letters_left>0)
        {
            temp.push_back((char)(i+48));
            letters_left--;
        }
        ans=max1(ans,temp);
    }
    cout<<ans<<endl;
    
}