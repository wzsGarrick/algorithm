//without test
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


class Edge
{
public:	
	int src,dest,weight;
	Edge(int s,int d,int w) {
		src = s;
		dest = d;
		weight = w;
	}
};

bool myComp(Edge*x,Edge*y) {
	return x->weight < y->weight;
}

class Graph 
{
	int V;
	int E;
	int *set;   //use for detecting  whether two vertices are connected or not
	vector<Edge*> MST;
	vector<Edge*> g;

public:

	Graph():V(0),E(0){}
	Graph(int v,int e){
		V=v;
		E=e;
		set = new int [v];
		for(int i=0; i<v; i++)
			set[i]=i;
	}
	
	
	void addEdge(int s,int d,int w) {
		Edge *newEdge = new Edge(s,d,w);
		g.push_back(newEdge);
	}

	int find(int x) {   
		if(set[x]!=x)
			set[x]=find(set[x]);
		return set[x];
	}
	
	
	bool hadUnion(int x,int y) {
		int t1 = find(x);
		int t2 = find(y);
		if(t1 == t2) return true;
		if(t1<t2)
			set[y] = t1;
		else set[x] = t2;
		return false;
	}
	
	void kruskal() {
		sort(g.begin(),g.end(),myComp);
		for(int i=0;i<E;i++) {
			if(hadUnion(g[i]->src,g[i]->dest))
				continue;
			MST.push_back(g[i]);
		}
		printMST();
	}

	void printMST() {
		for(int i=0; i<MST.size(); i++)
			cout<<MST[i]->src<<"--"<<MST[i]->dest<<"    "<<MST[i]->weight<<endl;
	}
};


int main() {
	int v,e;
	cin>>v>>e;
	Graph g(v,e);
	int s,d,w;
	while(e--) {
		cin>>s>>d>>w;
		g.addEdge(s,d,w);
	}
	g.kruskal();
}

