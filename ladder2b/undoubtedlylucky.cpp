#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll total(ll n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 9;
    else if(n==2)
        return 99;
    else
    {
        return total(n-1)+9*(pow(2,n-1)-1)+36*(pow(2,n)-2)+9;
    }
}
string next(string num,char a,char b)
{
    ll len_num=num.size();
    for(ll i=len_num-1;i>=0;i--)
    {
        if(num[i]==a)
        {
            num[i]=b;
            break;
        }
        else
        {
            num[i]=a;
        }
        
    }
    return num;
}

string itos(ll i)
{
    string s="";
    if(i==0)
        s.push_back('0');
    while(i>0)
    {
        s.push_back((char)((i%10)+48));
        i=i/10;
    }
    ll len_s=s.size();
    for(ll i=0;i<(len_s+1)/2;i++)
    {
        ll temp=s[i];
        s[i]=s[len_s-i-1];
        s[len_s-i-1]=temp;
    }
    return s;
}
ll nc2(ll n)
{
    if(n>=2)
        return ((n)*(n-1))/2;
    else
    {
        return 0;
    }
    
}
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
ll isgreater__(string s1,string s2)
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
        return 0;
    }
}
int main()
{
    ll n;
    cin>>n;
    if(n<=100)
    {
        cout<<n<<endl;
    }
    else
    {
        string num=itos(n);
        ll ans=0,len_num=num.size();
        ans+=(total(len_num-1));
      //          cout<<ans<<endl;
        ll a=(ll)(num[0]-48);
        ans+=((nc2(a-1))*(pow(2,len_num)-2)+(a-1)*(9-a+1)*(pow(2,len_num-1)-1)+(a-1)*(pow(2,len_num-1)-1)+a-1);
    //            cout<<ans<<endl;
        char x=num[0];
        ll j=1;
        while(j<len_num)
        {
            if(num[j]!=x)
                break;
            j++;
        }
        if(j==len_num)
        {
            ans+=(a)*(pow(2,len_num-1)-1)+1;
        }
        else
        {
            if(num[j]>num[0])
            {
                ans+=((a)*(pow(2,len_num-1)-1)+1);
  //              cout<<ans<<endl;
                ans+=(9-num[0]+48)*(pow(2,len_num-j-1)-1);
                ans+=(num[j]-num[0]-1)*(pow(2,len_num-j-1));
//                cout<<ans<<endl;
                ll i=0;
                string temp="";
                while(i<j)
                {
                    temp.push_back(num[i]);
                    i++;
                }
                temp.push_back(num[j]);
                i++;
                while(i<len_num)
                {
                    temp.push_back(num[0]);
                    i++;
                }
                while(isgreater(num,temp))
                {
                    temp=next(temp,num[0],num[j]);
                    ans++;
                }
            }
            else
            {
                ans+=((a)*(pow(2,len_num-1)-1)+1);
  //              cout<<ans<<endl;
                ans+=(num[j]-num[0]+1)*(pow(2,len_num-j-1));
                ans-=(num[0]-48-1)*(pow(2,len_num-j-1)-1);
//                cout<<ans<<endl;
                ll i=0;
                string temp="";
                while(i<j)
                {
                    temp.push_back(num[i]);
                    i++;
                }
                temp.push_back(num[0]);
                i++;
                while(i<len_num)
                {
                    temp.push_back(num[0]);
                    i++;
                }
                
                while(isgreater__(temp,num))
                {
                    temp=next(temp,num[0],num[j]);
                    ans--;
                }
            }
        }
        cout<<ans<<endl;
    }
}