#include <iostream>
using namespace std;
#include <cstring>

void getNextval(char *p, int *next)   //make the table for next compared position
{
    next[0]=-1;
    int k=-1;
    int j=0;
    int plen=strlen(p);
    while(j<plen-1)
    {
    	if(k==-1 || p[k]==p[j])
	{
	    j++;
	    k++;
	    if(p[j]!=p[k])
	    	next[j]=k;
	    else next[j]=next[k];
	}
	else k=next[k];
    }
}

int kmp(char *s, char *p)
{
	int next[10]={0};
	int slen=strlen(s);
	int plen=strlen(p);
	getNextval(p,next);
	int i=0,j=0;

	while(i<slen && j<plen)
	{
	    if(j==-1 || p[j]==s[i])
	    {
	    	i++;
		j++;
	    }
	    else j=next[j];
	}
	if(j==plen)
	    return i-j;
	else return -1;
}

int main()
{
    char s[20];
    char p[20];
    cin>>s>>p;
    cout<<kmp(s,p)<<endl;
}
