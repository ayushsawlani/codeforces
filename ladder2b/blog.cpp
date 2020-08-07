#include <bits/stdc++.h>
using namespace std;
int *itoa(long long int x)
{
    int c=0;
    int *p=(int *)(malloc(20*sizeof(int)));
    for(int i=0;i<20;i++)
        p[i]=0;
    while(x>0)
    {
        p[c++]=x%10;
        x=x/10;
    }
    return p;
}
int *add(int *a, int *b)
{
    int *sum=(int *)(malloc(20*sizeof(int)));
    for(int i=0;i<20;i++)
        sum[i]=0;
    int c=0;
    for(int i=0;i<20;i++)
    {
        sum[i]=(c+a[i]+b[i])%10;
        c=(a[i]+b[i])/10;
    }
    return sum;
}
int *mm(int *a, int *b)
{
    int *sum=(int *)(malloc(20*sizeof(int)));
    for(int i=0;i<20;i++)
        sum[i]=0;
    for(int i=0;i<20;i++)
    {
        int *c=(int *)(malloc(20*sizeof(int)));
        int carry=0;
        for(int j=0;j<20;j++)
            c[j]=0;
        for(int j=0;j<20;j++)
        {
            c[j+i]=(a[i]*b[i]+carry)%10;
            carry=(a[i]*b[i]+carry)/10;
        }
        int *temp=sum;
        sum=add(sum,c);
    }
    return sum;
}
int isgreater(int *a, int *b)
{
    int flag1=0;
    for(int i=19;i>=0;i--)
    {
        if(a[i]>b[i])
        {
            flag1=1;
            break;
        }
        else if(a[i]<b[i])
            break;
    }
    if(flag1)
        return 1;
    else 
        return 0;
}
int main()
{
    long long int h,w;
    cin>>h>>w;
    int x,y;
    for(x=1;x<w;x=2*x);
    for(y=1;y<h;y=2*y);
    cout<<x<<" "<<y<<endl;
    if(h==w)
        cout<<h<<" "<<x<<endl;
    if(isgreater(mm(itoa(h),itoa(y)),mm(itoa(w),itoa(x))))
        cout<<h<<" "<<y<<endl;
    else
    {
        cout<<w<<" "<<x<<endl;
    }
    
}