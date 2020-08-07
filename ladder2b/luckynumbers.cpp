#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll isgreater(string s1,string s2)
{
    ll len_s1=s1.size();
    ll len_s2=s2.size();
    if(len_s1>len_s2)
        return 1;
    else if(len_s1<len_s2)
        return 0;
    else
    {
        for(ll i=0;i<len_s1;i++)
        {
            if(s1[i]>s2[i])
                return 1;
            else if(s1[i]<s2[i])
                return 0;
        }
        return 1;
    }
}
string string_sort(string s, ll i, ll j)
{
    for(ll p=i;p<=j;p++)
    {
        ll min=p;
        for(ll q=p+1;q<=j;q++)
            if(s[q]<s[min])
                min=q;
        char temp=s[p];
        s[p]=s[min];
        s[min]=temp;
    }
    return s;
}
string next(string s)
{
    string s1="";
    ll len_s1=s.size();
    for(ll i=0;i<len_s1;i++)
        s1.push_back(s[i]);
    ll i,j,flag1=0;
    for(i=len_s1-1;i>=0;i--)
    {
        ll flag=0;
        for(ll p=i+1;p<len_s1;p++)
        {
            if(s1[p]>s1[i])
            {
                flag=1;
                j=p;
            }
            
        }
        if(flag)
        {
            char temp=s1[j];
            s1[j]=s1[i];
            s1[i]=temp;
            s1=string_sort(s1,i+1,len_s1-1);
            return s1;
            break;
        }
    }
    return "already greatest";
}
int main()
{
    string s;
    cin>>s;
    ll len_s=s.size();
    if(len_s%2==1)
    {
        for(ll i=0;i<(len_s+1)/2;i++)
            cout<<"4";
        for(ll i=0;i<(len_s+1)/2;i++)
            cout<<"7";
    }
    else
    {
        string s1="";
        for(ll i=0;i<len_s/2;i++)
            s1.push_back('4');
        for(ll i=0;i<len_s/2;i++)
            s1.push_back('7');
        while(1)
        {
            if(isgreater(s1,s))
                break;
            s1=next(s1);
        }
        if(s1!="already greatest")
            cout<<s1;
        else
        {
            for(ll i=0;i<(len_s+2)/2;i++)
                cout<<"4";
            for(ll i=0;i<(len_s+2)/2;i++)
                cout<<"7";
        }
    }
    cout<<endl;
    
}