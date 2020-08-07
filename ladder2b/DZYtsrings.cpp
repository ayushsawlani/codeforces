#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int arr[26];
    map <char,int> m;
    int max=0;
    for(int i=0;i<26;i++)
    {
        cin>>arr[i];
        //cout<<arr[i]<<" ";
        if(max<arr[i])
            max=arr[i];
    }
    //cout<<max;
    //cout<<endl;
    for(int i=0;i<26;i++)
        m[(char)(i+97)]=arr[i];
    int sum=0;
    int len_s=s.size();
    for(int i=0;i<len_s;i++)
        sum+=(m[s[i]])*(i+1);
    for(int i=len_s+1;i<=len_s+k;i++)
        sum+=i*max;
    cout<<sum<<endl;
}