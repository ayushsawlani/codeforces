#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
string next(string s)
{
    ll flag=0;
    ll m1=0;
    for(ll i=s.size()-1;i>=0;i--)
    {
        for(ll j=i-1;j>=0;j--)
        {
            if(s[i]>s[j])
            {
                //cout<<i<<" "<<j<<endl;
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                sort(s.begin()+j+1,s.end());
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        return s;
    else
    {
        return "";
    }
    
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll found=0;
    if(p==1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(p==2)
    {
        if(n>2)
            cout<<"NO"<<endl;
        else
        {
            if(n==2)
            {
                if(s[1]=='a')
                    cout<<"NO"<<endl;
                else
                {
                    cout<<"ba"<<endl;
                }
            }
            else
            {
                if(s[0]=='b')
                    cout<<"NO"<<endl;
                else
                {
                    cout<<"b"<<endl;
                }
            }
            
        }
        return 0;
    }

    ll q=-1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=p-1+'a'-s[i];j++)
        {
            if(i>0)
            {
                if(s[i]+j!=s[i-1])
                {
                    if(i>1)
                    {
                        if(s[i]+j!=s[i-2])
                        {
                            found=1;
                            s[i]+=j;
                            q=i;
                            break;
                        }
                    }
                    else
                    {
                        q=i;
                        found=1;
                        s[i]+=j;
                        break;
                    }
                }
            }
            else
            {
                s[i]+=j;
                found=1;
                break;
            }
            
        }
        if(found)
            break;
    }
    if(found)
    {
        for(ll i=q+1;i<n;i++)
        {
            for(ll j=0;j<p;j++)
            {
                if(i>0)
                {
                    if('a'+j!=s[i-1])
                    {
                       if(i>1)
                        {
                            if('a'+j!=s[i-2])
                            {
                                s[i]='a'+j;
                                break;
                            }
                        }
                       else
                        {
                           s[i]=j+'a';
                           break;
                        }
                    }
                }
            }
        }
        cout<<s<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}