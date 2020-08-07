#include <bits/stdc++.h>
using namespace std;
int is_sorted(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
        if(arr[i+1]<arr[i])
            return 0;
    return 1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int rev_arr[n];
    int rev_i=0;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(n==1)
    {
        cout<<"yes"<<endl<<"1 1"<<endl;
    }
    else
    {
        for(int i=0;i<n-1;i++)
            if(arr[i+1]<=arr[i])
                rev_arr[rev_i++]=i;
        if(rev_i==0)
        {
            cout<<"yes"<<endl<<"1 1"<<endl;
        }
        else
        {
            int flag=0;
            for(int i=0;i<rev_i-1;i++)
            {
                if(rev_arr[i+1]-rev_arr[i]!=1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                cout<<"no"<<endl;
            }
            else
            {
                for(int i=rev_arr[0];i<=(rev_arr[0]+rev_arr[rev_i-1]+1)/2;i++)
                    {
                        int temp=arr[i];
                        arr[i]=arr[rev_arr[0]+rev_arr[rev_i-1]+1-i];
                        arr[rev_arr[0]+rev_arr[rev_i-1]+1-i]=temp;
                    }
                if(is_sorted(arr,n))
                {
                    cout<<"yes"<<endl<<rev_arr[0]+1<<" "<<rev_arr[rev_i-1]+2<<endl;
                }
                else
                {
                    cout<<"no"<<endl;
                }
            }
        }
        
    }
    
}