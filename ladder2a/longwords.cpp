#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        int len_s=s.size();
        if(len_s>10)
            cout<<s[0]<<len_s-2<<s[len_s-1]<<endl;
        else
        {
            cout<<s<<endl;
        }
        
    }
}