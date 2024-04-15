#include<iostream>
using namespace std;
void greedy_act_sel(int s[],int f[],int n)
{
    int *arr = new int [n];
    arr[0]=1;
    int k=0;
    for(int m=1;m<n;m++)
    {
        if(s[m]>=f[k])
        {
            arr[m]=1;
            k=m;
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            cout<<"Activity "<<i<<"\n";
        }
    }
}
int main()
{
    int s[5]={0,5,18,25,40};
    int f[5]={4,19,22,28,42};
    greedy_act_sel(s,f,5);
}