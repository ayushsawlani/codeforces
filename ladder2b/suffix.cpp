#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define M 1000000

void rkpa(string s1, int len_s1,string s2,int len_s2,int *i1,int *i2)
{
    for(int i=(*i1);i<len_s1;i++)
    {
        if(s1[i]==s2[(*i2)])
        {
            (*i1)=i+1;
            (*i2)=(*i2)+1;
            rkpa(s1, len_s1, s2, len_s2, i1, i2);
            break;
        }
    }   
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int arr1[26];
    int arr2[26];
    int *i1=(int *)malloc(sizeof(int));
    int *i2=(int *)malloc(sizeof(int));
    (*i1)=0;
    (*i2)=0;
    for(int i=0;i<26;i++)
    {
        arr1[i]=0;
        arr2[i]=0;
    }
    int flag1=0;
    int flag2=0;
    int len_s1=s1.size(),len_s2=s2.size();
    for(int i=0;i<len_s1;i++)
        arr1[(int)s1[i]-97]++;
    for(int i=0;i<len_s2;i++)
        arr2[(int)s2[i]-97]++;
    if (len_s1<len_s2)
        cout<<"need tree"<<endl;
    else
    {
        for(int i=0;i<26;i++)
        {
            if(arr1[i]>arr2[i])
                flag1=1;
            if(arr1[i]<arr2[i])
                flag2=1;
        }
        if(!(flag1||flag2))
            cout<<"array"<<endl;
        else if(flag2)
            cout<<"need tree"<<endl;
        else
        {
            rkpa(s1,len_s1,s2,len_s2,i1,i2);
            if((*i2)==len_s2)
                cout<<"automaton"<<endl;
            else
            {
                cout<<"both"<<endl;
            }
            
        }
    }
}