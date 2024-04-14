#include<iostream>
#define inf 99999
#define nil -1
#define max 20
using namespace std;
void floydwarshall(int cost[][max],int d[max][max],int p[max][max],int n)
{
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j] = cost[i][j];
            if(d[i][j]==0 || d[i][j]==inf)
            {
                p[i][j] = nil;
            }
            else
            {
                p[i][j] = i;
            }
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = p[k][j];
                }
            }
        }
    }
}
int main()
{
    int n;
    int i,j;
    n=5;
    int cost[][max] = {
        {0,0,0,0,0,0},
        {0,0,3,8,inf,-4},
        {0,inf,0,inf,1,7},
        {0,2,inf,-5,0,inf},
        {0,inf,inf,inf,6,0}
    };
    int dist[max][max],parent[max][max];
    floydwarshall(cost,dist,parent,n);
    cout<<"\n\nDistance Matrix : ";
    for(i=1;i<=n;i++)
    {
        cout<<endl;
        for(j=1;j<=n;j++)
        {
            if(dist[i][j]==inf)
            {
                cout<<"inf\t\t";
            }
            else
            {
                cout<<dist[i][j]<<"\t\t";
            }
        }
    }
    cout<<endl<<"\nParent Matrix : ";
    for(i=1;i<=n;i++)
    {
        cout<<endl;
        for(j=1;j<=n;j++)
        {
            if(parent[i][j]==nil)
            {
                cout<<"nil\t\t";
            }
            else
            {
                cout<<parent[i][j]<<"\t\t";
            }
        }
    }
    return 0;
}