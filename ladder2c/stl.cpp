#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
int main();
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n;
    cin>>n;
    string in;
    getline(cin,in);
    getline(cin,in);
    vector <string> input;
    string temp="";
    for(ll i=0;i<in.size();i++)
    {
        if(in[i]==' ')
        {
            input.push_back(temp);
            temp="";
        }
        else
        {
            temp.push_back(in[i]);   
        }
    }
    input.push_back(temp);
    ll Size=input.size();
    ll brace_count[Size];
    memset(brace_count,0,Size*sizeof(ll));
    ll comma[Size];
    memset(comma,0,Size*sizeof(ll));
    vector <ll> type_count;
    for(ll i=0;i<Size;i++)
    {
        if(input[i]=="pair")
        {
            type_count.push_back(0);
        }
        else
        {
            if(type_count.size())
            {
                if(type_count[type_count.size()-1]==0)
                {    
                    type_count[type_count.size()-1]++;
                    comma[i]=1;
                }
                else
                {
                    while(type_count.size())
                    {
                        if(type_count[type_count.size()-1]!=1)
                            break;
                        brace_count[i]++;
                        type_count.pop_back();
                    }
                    if(type_count.size())
                    {
                        comma[i]=1;
                        type_count[type_count.size()-1]++;
                    }
                    else
                    {
                        if(i!=Size-1)
                        {
                            cout<<"Error occurred"<<endl;
                            return 0;
                        }
                    }
                    
                }
            }
            else if(input.size()==1);
            else
            {
                cout<<"Error occurred"<<endl;
                return 0;
            }
        }
    }
    if(type_count.size())
    {
        cout<<"Error occurred"<<endl;
        return 0;
    }
    for(ll i=0;i<Size;i++)
    {
        cout<<input[i];
        while(brace_count[i]--)
            cout<<">";
        if(comma[i])
            cout<<",";
        if(input[i]=="pair")
            cout<<"<";
    }
    cout<<endl;
}