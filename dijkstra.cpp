/*
 *Dijksta
 *Adjacent list version
 *without perfect test
 *
 *author: garrick
 *date: 2014.12.21
 *
 */

#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

class AdjNode {
public:
	int dest;
	int weight;

	AdjNode(int d,int w) {
		dest = d;
		weight = w;
	}
};

class Graph {
	int v;
	int *dist;
	bool *visited;
	int *parent;               //use for constructing the path
	vector<list<AdjNode*> > graph  ;

public:

	Graph(int V) {
		v=V;
		graph.resize(v+1);
		dist = new int [v+1];              //initial
		memset(dist,0x3f,sizeof(int)*(v+1));
		visited = new bool [v+1];
		memset(visited,0,sizeof(bool)*(v+1));
		parent = new int [v+1];
		memset(parent,-1,sizeof(int)*(v+1));
	}
	
	void addEdge(int s,int d,int w) {
		AdjNode* newNode = new AdjNode(d,w);
		graph[s].push_back(newNode);
	}

	void dijkstra(int s) {
		dist[s] = 0;
		int min , idx;
		for(int i=1; i<=v; i++) 	{
			min = 0x3f3f3f3f;
			for(int j=1; j<=v; j++)           //find the min vertice
				if(!visited[j] && min > dist[j])
				{
					min = dist[j];
					idx = j;
				}

			visited[idx] = true;

			list<AdjNode*>::iterator it;
			for(it=graph[idx].begin(); it!=graph[idx].end(); it++)
				if(!visited[(*it)->dest] && dist[(*it)->dest] > dist[idx] + (*it)->weight) {
					dist[(*it)->dest] = dist[idx] + (*it)->weight;
					parent[(*it)->dest] = idx;
				}
		}
		printpath(s);
	}

	void printpath(int s) {         //need to reverse
		stack<int> stk;
		for(int i=1; i<=v; i++) {
			if(i==s) continue;
			int k=i;
			while(true) {
				stk.push(k);
				if(k==s) break;
				else k = parent[k];
			}

			while(!stk.empty()) {
				if(stk.top() == i) 
					cout<<i<<"   "<<dist[i]<<endl;
				else cout<<stk.top()<<"->";
				stk.pop();
			}
		}
	}
};


int main()
{
	int s,d,w,v,e;
	cin>>v>>e;
	Graph g(v);
	while(e--) {
		cin>>s>>d>>w;
		g.addEdge(s,d,w);
	}
	int src;
	cin>>src;
	g.dijkstra(src);
}

