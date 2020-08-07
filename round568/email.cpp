#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        ll len_s1=s1.size();
        ll len_s2=s2.size();
        pair<char,ll> arr1[len_s1],arr2[len_s2];
        ll arr1_c=0,arr2_c=0;
        ll current=0,c=1;
        for(ll j=1;j<len_s1;j++)
        {
            if(s1[j]!=s1[current])
            {
                arr1[arr1_c].first=s1[current];
                arr1[arr1_c].second=c;
                arr1_c++;
                c=1;
                current=j;
            }
            else
            {
                c++;
            }
        }
        arr1[arr1_c].first=s1[current];
        arr1[arr1_c].second=c;
        arr1_c++;
        current =0,c=1;
        for(ll j=1;j<len_s2;j++)
        {
            if(s2[j]!=s2[current])
            {
                arr2[arr2_c].first=s2[current];
                arr2[arr2_c].second=c;
                arr2_c++;
                c=1;
                current=j;
            }
            else
            {
                c++;
            }
        }
        arr2[arr2_c].first=s2[current];
        arr2[arr2_c].second=c;
        arr2_c++;
       
        ll flag=0;
        if(arr1_c!=arr2_c)
            flag=1;
        else
        {
            for(ll j=0;j<arr1_c;j++)
            {
                if(arr1[j].first!=arr2[j].first)
                {
                    flag=1;
                    break;
                }
                if(arr1[j].second>arr2[j].second)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
        
        
    }
}