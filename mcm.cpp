#include<iostream>
#include<limits.h>
using namespace std;
int **mcm(int p[],int n)
{
    int **m = new int *[n+1];
    int **s = new int *[n+1];
    for(int i=0;i<n+1;i++)
    {
        m[i]=new int [n+1];
        s[i] = new int [n+1];
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }
    for(int l=2;l<n+1;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            m[i][i+l-1]=INT_MAX;
            for(int k=i;k<i+l-1;k++)
            {
                if(m[i][k]+m[k+1][i+l-1]+(p[i-1]*p[k]*p[i+l-1])<m[i][i+l-1])
                {
                    m[i][i+l-1] = m[i][k] + m[k+1][i+l-1] + p[i-1]*p[k]*p[i+l-1];
                    s[i][i+l-1]=k;
                }
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return s;
}
void print(int **s, int i, int j)
{
    if(i==j)
    {
        cout<<i<<endl;
    }
    else
    {
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int p[]={5,4,6,2,7};
	int** s;
	s=mcm(p,4);
	for(int i=1;i<5;i++){
		for(int j=1;j<5;j++)
			cout<<s[i][j]<<" ";
		cout<<endl;
	}
    return 0;
}