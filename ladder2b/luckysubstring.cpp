#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int four=0,seven=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='4')
            four++;
        else if(s[i]=='7')
            seven++;
    }
    if((four)||(seven))
    {
        if(seven>four)
            cout<<"7"<<endl;
        else
        {
            cout<<"4"<<endl;
        }
        
    }
    else
        cout<<"-1"<<endl;
}