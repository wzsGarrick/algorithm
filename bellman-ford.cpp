/*
 *Bellman-Ford
 *single source shortest path with negative weight
 *This version is without cycle detect
 *without perfect test
 *
 *author : garrick_w
 *date:2014.12.20
 */

#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;


class Edge
{
public:
	int src,dest,weight;

	Edge(int s, int d, int w) {    
		src = s;
		dest = d;
		weight = w;
	}
}; 


class Graph 
{
	int v;   					 //the number of vertices
	int e;   					 // the number of edges
	int *parent; 				 //use for construct shortest path
	int *dist;      			 // the distance from the single source
	vector<Edge*> edge;    		 //store the graph
public:
	
	Graph(){
		v=e=0;
		parent = NULL;
		dist = NULL;
	}

	Graph(int V, int E) {
		v=V;
		e=E;
		parent = new int [v];
		dist = new int [v];
		memset(dist,0x3f,sizeof(int)*v);     //initial
	}

	void addEdge(int s, int d, int w) {
		Edge* newEdge = new Edge(s,d,w);
		edge.push_back(newEdge);
	}
	
	void bellmanFord(int s) {
		dist[s] = 0;

		for(int k=0; k<v-1; k++)   //run v-1 times,because there are edges  with no more than v-1 between two vertice 
		{
			for(int i=0; i<e; i++) {    
				int src = edge[i]->src;
				int dest = edge[i]->dest;
				int weight = edge[i]->weight;
				if(dist[dest] > weight + dist[src])
				{
					dist[dest] = weight+dist[src];
					parent[dest] = src;
				}
			}
		}

		printpath(s);
	}

	void printpath(int s) {
		stack<int> stk;
		for(int i=0; i<v; i++) {
			if(i==s) continue;
			int k=i;
			while(true) {
				stk.push(k);
				if(k==s) break;
				else k = parent[k];
			}
			while(!stk.empty()) {           //reverse
				if(stk.size() == 1) cout<<stk.top()<<" "<<dist[i]<<endl;
				else cout<<stk.top()<<"->";
				stk.pop();
			}
		}
	}
};

//test 
int main()
{
	int s,d,w,v,e;
	cin>>v>>e;
	Graph g(v,e);
	while(e--) {
		cin>>s>>d>>w;
		g.addEdge(s-1,d-1,w);
	}
	int src;
	cin>>src;
	g.bellmanFord(src-1);
}
