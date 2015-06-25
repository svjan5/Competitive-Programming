#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define INF 1000000000

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

const int VER = 200;

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vector<vi> AdjList(VER+1),temp;

int main() {
	string line;
	int u,v,w;

	while(getline(cin,line)){
		istringstream iss(line);
        iss>>u;
        while(iss>>v){
        	AdjList[u].pb(v);
        }
	}

	
	int N=200,n;

	int minCount=INF;;

	while(N--){
		temp = AdjList;
		bool avl[VER+1];MEM(avl,true);
		int avlCount=VER;
		vector<int>::iterator it;

		while(avlCount>2){


			while(true){
				u = rand() % VER + 1;				/*Chose a random vertex*/
				if(avl[u])
					break;
			}

			n = rand() % temp[u].size();
			v = temp[u][n];							/*Selected edge between u and v*/

/*Removes occurence of v in Adjacency list of u*/
			while( (it=find(temp[u].begin(),temp[u].end(),v))!=temp[u].end() ){		
				temp[u].erase(it);
			}

/*Updates the Adjacency list*/
			FOR(i,(int)temp[v].size()){
				w = temp[v][i];
				if(w == u)
					continue;
				else{
					while( (it=find(temp[w].begin(),temp[w].end(),v))!=temp[w].end() )
						*it = u;
					temp[u].pb(w);
				}
			}

			avlCount--;
			avl[v]=false;
		}

		FOR1(i,VER){
			if(avl[i]){
				if(minCount > temp[i].size())
					minCount = temp[i].size();
				break;
			}
		}

	}
	printf("%d\n",minCount );
	/*FOR1(i,VER){
		printf("%d => ",i);
		FOR(j,(int)AdjList[i].size()){
			printf("%d ",AdjList[i][j]);
		}
		cout<<endl;
	}*/

    return 0;
}