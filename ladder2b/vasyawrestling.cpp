#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int sum=0,flag;
    long long int arr1[n],arr1_c=0;
    long long int arr2[n],arr2_c=0;
    for(long long int i=0;i<n;i++)
    {
        long long int temp;
        cin>>temp;
        sum+=temp;
        if(temp>0)
            arr1[arr1_c++]=temp;
        else
            arr2[arr2_c++]=(-1)*temp;
        if((i==n-1)&&(temp>0))
            flag=0;
        if((i==n-1)&&(temp<0))
            flag=1;
    }
    if(sum>0)
        cout<<"first"<<endl;
    else if(sum<0)
        cout<<"second"<<endl;
    else
    {
        long long int min=std::min(arr1_c,arr2_c);
        long long int flag1=0;
        for(long long int i=0;i<min;i++)   
        {
            if(arr1[i]>arr2[i])
            {
                flag1=1;
                break;
            }
            else if(arr1[i]<arr2[i])
            {
                flag1=2;
                break;
            }
        }
        if(flag1==1)
            cout<<"first"<<endl;
        else if(flag1==2)
            cout<<"second"<<endl;
        else
        {
            if(flag==0)
                cout<<"first"<<endl;
            else
            {
                cout<<"second"<<endl;
            }
            
        }
    }
    
}