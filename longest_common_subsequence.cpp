#include<iostream>
using namespace std;
void print_lcs(char arr[], char **dir,int i,int j);
void lcs(char x[], char y[], int m, int n)
{
    int **num;
    char **dir;
    num = new int *[m+1];
    dir = new char *[m+1];
    for(int i=0;i<=m;i++)
    {
        num[i] = new int[n+1];
        dir[i] = new char[n+1];
    }
    for(int i=0;i<=n;i++)
    {
        num[0][i]=0;
    }
    for(int j=0;j<=m;j++)
    {
        num[j][0]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                num[i][j] = num[i-1][j-1]+1;
                dir[i][j] = 'D';
            }
            else if(num[i-1][j]>=num[i][j-1])
            {
                num[i][j] = num[i-1][j];
                dir[i][j] = 'U';
            }
            else
            {
                num[i][j] = num[i][j-1];
                dir[i][j] = 'L';
            }
        }
    }
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<num[i][j]<<"\t";
        }
        cout<<"\n";
    }
    print_lcs(x,dir,m,n);
    return;
}
void print_lcs(char arr[], char **dir,int i,int j)
{
    if(i==0||j==0)
    {
        return;
    }
    else if(dir[i][j]=='D')
    {
        print_lcs(arr,dir,i-1,j-1);
        cout<<arr[i-1];
    }
    else if(dir[i][j]=='U')
    {
        print_lcs(arr,dir,i-1,j);
    }
    else
    {
        print_lcs(arr,dir,i,j-1);
    }

}
int main()
{
    char X[5] = {'A','B','C','A','B'};
    char Y[5] = {'A','C','A','B','A'};
    lcs(X,Y,5,5);
}