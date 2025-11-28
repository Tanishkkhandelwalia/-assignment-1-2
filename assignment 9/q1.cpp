include<bits/stdc++.h>
using namespace std;
#define MAX 100
#define INF 999999
class Graph{
public:
	int V,adj[MAX][MAX];
	Graph(int n){
		V=n;
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				adj[i][j]=0;
	}
	void addEdge(int u,int v,int w){
		adj[u][v]=w;
		adj[v][u]=w;
	}
	void bfs(int s){
		int q[MAX],f=0,r=0,vis[MAX]={0};
		q[r++]=s;
		vis[s]=1;
		while(f<r){
			int u=q[f++];
			cout<<u<<" ";
			for(int v=0;v<V;v++)
				if(adj[u][v]&&!vis[v]){
					vis[v]=1;
					q[r++]=v;
				}
		}
		cout<<endl;
	}
	void dfsUtil(int u,int vis[]){
		vis[u]=1;
		cout<<u<<" ";
		for(int v=0;v<V;v++)
			if(adj[u][v]&&!vis[v])
				dfsUtil(v,vis);
	}
	void dfs(int s){
		int vis[MAX]={0};
		dfsUtil(s,vis);
		cout<<endl;
	}
	void kruskal(){
		int par[MAX];
		for(int i=0;i<V;i++)par[i]=i;
		auto fp=[&](int x){
			while(par[x]!=x)x=par[x];
			return x;
		};
		int e=0;
		while(e<V-1){
			int mn=INF,a=-1,b=-1;
			for(int i=0;i<V;i++)
				for(int j=0;j<V;j++)
					if(adj[i][j]&&adj[i][j]<mn){
						int p1=fp(i),p2=fp(j);
						if(p1!=p2){
							mn=adj[i][j];
							a=i;b=j;
						}
					}
			if(a==-1)break;
			cout<<a<<"-"<<b<<endl;
			par[fp(a)]=fp(b);
			e++;
		}
	}
	void prim(int s){
		int key[MAX],par[MAX],used[MAX]={0};
		for(int i=0;i<V;i++)key[i]=INF;
		key[s]=0;
		par[s]=-1;
		for(int k=0;k<V;k++){
			int u=-1,mn=INF;
			for(int i=0;i<V;i++)
				if(!used[i]&&key[i]<mn)mn=key[i],u=i;
			used[u]=1;
			for(int v=0;v<V;v++)
				if(adj[u][v]&&!used[v]&&adj[u][v]<key[v]){
					key[v]=adj[u][v];
					par[v]=u;
				}
		}
		for(int i=0;i<V;i++)
			if(par[i]!=-1)
				cout<<par[i]<<"-"<<i<<endl;
	}
	void dijkstra(int s){
		int d[MAX],u[MAX]={0};
		for(int i=0;i<V;i++)d[i]=INF;
		d[s]=0;
		for(int k=0;k<V;k++){
			int nd=-1,mn=INF;
			for(int i=0;i<V;i++)
				if(!u[i]&&d[i]<mn)mn=d[i],nd=i;
			u[nd]=1;
			for(int v=0;v<V;v++)
				if(adj[nd][v]&&d[nd]+adj[nd][v]<d[v])
					d[v]=d[nd]+adj[nd][v];
		}
		for(int i=0;i<V;i++)
			cout<<i<<" "<<d[i]<<endl;
	}
};
int main(){
	Graph g(5);
	g.addEdge(0,1,2);
	g.addEdge(0,2,3);
	g.addEdge(1,3,4);
	g.addEdge(2,4,5);
	g.addEdge(3,4,1);
	g.bfs(0);
	g.dfs(0);
	g.kruskal();
	g.prim(0);
	g.dijkstra(0);
}
