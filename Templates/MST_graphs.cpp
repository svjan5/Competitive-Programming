#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define mp make_pair
#define pb push_back
 
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<pair<int,ii > > EdgeList;
vi dfs_num;

class UnionFind {                                              // OOP style
	private:
	  vi p, rank, setSize;                       // remember: vi is vector<int>
	  int numSets;
	  
	public:
	  UnionFind(int N) {
	    setSize.assign(N, 1); 
	    numSets = N; 
	    rank.assign(N, 0);
	    p.assign(N, 0); 
	    for (int i = 0; i < N; i++) 					//Set is initialized as well
	    	p[i] = i; 
	  }
	    
	  int findSet(int i) { 
	  	return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
	  }

	  bool isSameSet(int i, int j) { 
	  	return findSet(i) == findSet(j); 
	  }

	  void unionSet(int i, int j) { 
	    if (!isSameSet(i, j)) { 
	    	numSets--; 
	    	int x = findSet(i), y = findSet(j);

	    	if (rank[x] > rank[y]){ 				// rank is used to keep the tree short
	    		p[y] = x; 
	    		setSize[x] += setSize[y]; 
	    	}

		    else {
		    	p[x] = y; 
		    	setSize[y] += setSize[x];
		        if (rank[x] == rank[y]) 
		        	rank[y]++; 
	    	} 
		} 
	  }


	  int numDisjointSets() { 
	  	return numSets; 
	  }
	  
	  int sizeOfSet(int i) { 
	  	return setSize[findSet(i)]; 
	  }

};

int main() {
	int t,V,E,price;
	scanf("%d",&t);
 
	while(t--){
		scanf("%d %d %d",&price,&V,&E);
		
		FOR(i,E){
			int u,v,w;
			scanf("%d %d %d",&u,&v,&w);
			EdgeList.push_back(make_pair(w,(ii(u,v))));
		}

		sort(EdgeList.begin(),EdgeList.end());
		int total_length=0;

		UnionFind UF(V);
		FOR(i,E){
			pair<int,pair<int,int> > front = EdgeList[i];
			if(!UF.isSameSet(front.second.first,front.second.second)){
				total_length += front.first;
				UF.unionSet(front.second.first,front.second.second);
			}
		}
		/*cout<<E<<endl;
		FOR(i,E){
			printf("%d %d %d\n",EdgeList[i].first,EdgeList[i].second.first,EdgeList[i].second.first);
		}*/
		
		printf("%d\n",price * total_length);
	}
	return 0;
}