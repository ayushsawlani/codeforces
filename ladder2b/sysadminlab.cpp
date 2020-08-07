#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s;
    cin>>s;
    ll len_s=s.size();
    vector <ll> v;
    ll i=0;
    ll x=0;
    while(i<len_s)
    {
        if(s[i]=='@')
        {
            v.push_back(x);
            x=0;
        }
        else
        {
            x++;
        }
        i++;        

    }
    v.push_back(x);
    ll len_v=v.size();
    ll flag=0;
    for(i=1;i<len_v-1;i++)
        if(v[i]<2)
            flag=1;
    if((v[0]<1)||(v[len_v-1]<1))
        flag=1;
    if(len_v==1)
        flag=1;
    if(flag)
        cout<<"No solution"<<endl;
    else
    {
    ll flag=0;
        i=0;
        while(i<len_s)
        {
            if(i<len_s-1)
            {
                if((s[i+1]=='@')&&(flag==1))
                    cout<<',';
                else if(s[i+1]=='@')
                    flag=1;
            }

            cout<<s[i];
                        i++;
        }
        cout<<endl;
    }
    
}