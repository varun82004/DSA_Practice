#include<iostream>
using namespace std;
void rabin_karp(string text, string pattern)
{
    int n,m;
    n = text.length();
    m = pattern.length();
    int h=1,d=256,q=101,p=0,t=0;
    for(int i=0;i<m-1;i++)
    {
        h=(h*d)%q;
    }
    for(int i=0;i<m;i++)
    {
        p = (d*p+pattern[i])%q;
        t = (d*t+text[i])%q;
    }
    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            bool pivot=true;
            for(int j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                {
                    pivot=false;
                    break;
                }
            }
            if(pivot)
            {
                cout<<i<<endl;
            }
        }
        if(i<n-m)
        {
            t = (d*(t-h*text[i])+text[i+m])%q;
            if(t<0)
            {
                t=t+q;
            }
        }
    }
}
int main()
{
	string text="Life is not good when it is cyclic, it is good only when it is non-cyclic";
	string pattern="ood";
	rabin_karp(text,pattern);
	return 0;
}