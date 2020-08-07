#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s1;
    cin>>s1;
    string ans1="",ans2="";
    ll flag=0;
    ll len_s1=s1.size();
    for(ll i=0;i<len_s1;i++)
    {
        if(s1[i]=='.')
            flag=1;
        else if(flag==0)
            ans1.push_back(s1[i]);
        else
        {
            ans2.push_back(s1[i]);
        }
    }
    if(ans1.size()>0)
    {
        
        if(ans1[0]!='-')
        {
            cout<<"$";
            ll len_ans1=ans1.size();
            ll i;
            if(len_ans1<=3)
                cout<<ans1;
            else
            {
                if(len_ans1%3==1)
                {
                    cout<<ans1[0];
                    i=1;
                }
                else if(len_ans1%3==2)
                {
                    cout<<ans1[0]<<ans1[1];
                    i=2;
                }
                else
                {
                    cout<<ans1[0]<<ans1[1]<<ans1[2];
                    i=3;
                }
                for(ll j=i;j<len_ans1-2;j+=3)
                    cout<<","<<ans1[j]<<ans1[j+1]<<ans1[j+2];
            }
            cout<<".";
            ll x=0;
            ll len_ans2=ans2.size();
            for(ll p=0;(p<len_ans2)&&(x<2);p++,x++)
            {
                cout<<ans2[p];
            }
            while(x<2)
            {
                cout<<"0";
                x++;
            }
            cout<<endl;
        }
        else
        {
            cout<<"($";
            ll len_ans1=ans1.size();
            ll i;
            if(len_ans1==1)
                cout<<"0";
            if(len_ans1-1<=3)
            {
                for(ll i=1;i<len_ans1;i++)
                    cout<<ans1[i];
            }
            else
            {
                if((len_ans1-1)%3==1)
                {
                    cout<<ans1[1];
                    i=2;
                }
                else if((len_ans1-1)%3==2)
                {
                    cout<<ans1[1]<<ans1[2];
                    i=3;
                }
                else
                {
                    cout<<ans1[1]<<ans1[2]<<ans1[3];
                    i=4;
                }
                for(ll j=i;j<len_ans1-2;j+=3)
                    cout<<","<<ans1[j]<<ans1[j+1]<<ans1[j+2];
            }
            cout<<".";
            ll x=0;
            ll len_ans2=ans2.size();
            for(ll p=0;(p<len_ans2)&&(x<2);p++,x++)
            {
                cout<<ans2[p];
            }
            while(x<2)
            {
                cout<<"0";
                x++;
            }
            cout<<")"<<endl;
        }
    }
    else
    {
        cout<<"$0.";
        ll x=0;
        ll len_ans2=ans2.size();
        for(ll p=0;(p<len_ans2)&&(x<2);p++,x++)
        {
            cout<<ans2[p];
        }
        while(x<2)
        {
            cout<<"0";
            x++;
        }
        
    }
    
    
}