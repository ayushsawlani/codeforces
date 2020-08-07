#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans=0;
    int arr[26]; 
    for(int i=0;i<26;i++)
        arr[i]=0;
    int len_s=s.size();
    for(int i=0;i<len_s;i++)
    {
        arr[(int)(s[i])-97]++;
    }
    for(int i=0;i<26;i++)
    {
        if(arr[i]%2==1)
            ans++;
    }
    if(ans==0)
        cout<<"First"<<endl;
    else if(ans%2==1)
        cout<<"First"<<endl;
    else
    {
        cout<<"Second"<<endl;
    }
    
}