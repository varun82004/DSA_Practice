#include<iostream>
#include<limits.h>
#define max 20
using namespace std;
struct node{
    int data;
    node* next;
};
class SList{
    node *head;
    int size;
    public:
        SList()
        {
            head=NULL;
            size=0;
        }
        void insert(int dat)
        {
            node *newnode = new node;
            newnode->data = dat;
            newnode->next = NULL;
            size+=1;
            if(head==NULL)
            {
                head = newnode;
                return;
            }
            node *itr = head;
            while(itr->next!=NULL)
            {
                itr = itr->next;
            }
            itr->next = newnode;
            return;
        }
        bool elementAt(int p ,int &x)
        {
            node *t = head;
            int c=1;
            while(t!=NULL)
            {
                if(c==p)
                {
                    x = t->data;
                    return true;
                }
                t=t->next;
                c++;
            }
            return false;
        }
        int getSize()
        {
            return size;
        }
};
struct vertex{
    SList adjacent;
    int parent;
    int distance;
    int value;
};
class Graph{
    vertex *v;
    int size;
    void relax(int u, int vv, int w[][max])
    {
        if(v[vv].distance>v[u].distance+w[u][vv])
        {
            v[vv].distance=v[u].distance+w[u][vv];
            v[vv].parent=u;
        }
    }
    public:
        Graph(int n)
        {
            size=n;
            v = new vertex[n];
            for(int i=0;i<n;i++)
            {
                v[i].value=i;
                v[i].parent=-1;
                v[i].distance=INT_MAX;
            }
        }
        void showgraph()
        {
            int mincost=0;
            cout<<"Vetex | "<<"Parent | "<<"Distance |";
            for(int i=0;i<size;i++)
            {
                cout<<"\n";
                if(v[i].parent==-1)
                {
                    cout<<v[i].value<<" | "<<"Source | "<<v[i].distance<<" | "<<endl;
                }
                else
                {
                    cout<<v[i].value<<" | "<<v[i].parent<<" | "<<v[i].distance<<" | "<<endl;
                }
            }
        }
        bool BellmanFord(int w[][max], int s)
        {
            v[s].distance =0;
            int u,vv,p,i;
            for(i=0;i<size-1;i++)
            {
                for(u=0;u<size;u++)
                {
                    for(int p=1;p<=v[u].adjacent.getSize();p++)
                    {
                        if(v[u].adjacent.elementAt(p,vv))
                        {
                            if(w[u][vv]!=0)
                            {
                                relax(u,vv,w);
                            }
                        }
                    }
                }
            }
            for(u=0;u<size;u++)
            {
                for(p=1;p<=v[u].adjacent.getSize();p++)
                {
                    if(v[u].adjacent.elementAt(p,vv))
                    {
                        if(v[vv].distance>v[u].distance+w[u][vv])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        void addEdge(int from,int to)
        {
            v[from].adjacent.insert(to);
        }
};
int main()
{
    int n=6;
    int b[][max] = {
        {0,6,4,5,0,0},
        {0,0,0,0,-1,-8},
        {0,-2,0,0,3,0},
        {0,0,-2,0,0,-1},
        {0,0,0,0,0,3},
        {0,0,0,0,0,0}
    };
    Graph g(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]!=0)
            {
                g.addEdge(i,j);
            }
        }
    }
    int s=0;
    bool res;
    res = g.BellmanFord(b,s);
    if(res)
    {
        cout<<"\n\nSingle Source Shortest Path (Bellman-Ford-Algorithm) Result \n";
        g.showgraph();
    }
    else
    {
        cout<<"No single source shortest path";
    }
}