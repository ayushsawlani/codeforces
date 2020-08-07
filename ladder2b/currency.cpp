#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int arr1[s.size()],arr2[s.size()];
    int len_s=s.size();
    int flag1=0,flag2=0;
    for(int i=0;i<len_s;i++)
    {
        arr1[i]=(int)s[i]-48;
        arr2[i]=arr1[i];
    }
    for(int i=0;i<len_s-1;i++)
    {
        if((arr1[i]%2==0)&&(arr1[i]<arr1[len_s-1]))
        {
            int temp=arr1[i];
            arr1[i]=arr1[len_s-1];
            arr1[len_s-1]=temp;
            flag1=1;
            break;
        }
    }
    for(int i=len_s-2;i>=0;i--)
    {
        if((arr2[i]%2==0)&&(arr2[i]>arr2[len_s-1]))
        {
            int temp=arr2[i];
            arr2[i]=arr2[len_s-1];
            arr2[len_s-1]=temp;
            flag2=1;
            break;
        }
    }
    if(!(flag1||flag2))
        cout<<-1<<endl;
    else
    {
        if((flag1)&&(flag2))
        {
            int *p=arr1;
            int flag=0;
            for(int i=0;i<len_s;i++)
            {
                if(p[i]>arr2[i])
                    break;
                else if(p[i]<arr2[i])
                {
                    flag=1;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(flag==1)
                p=arr2;
            for(int i=0;i<len_s;i++)
                cout<<p[i];
            cout<<endl;
        }
        else if(flag1)
        {
            for(int i=0;i<len_s;i++)
                cout<<arr1[i];
            cout<<endl;
        }
        else
        {
            for(int i=0;i<len_s;i++)
                cout<<arr2[i];
            cout<<endl;
        }
    }
}