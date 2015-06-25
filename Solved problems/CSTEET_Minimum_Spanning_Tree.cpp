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
 
vi pset;
vector<pair<int,ii > > EdgeList;
 
void initSet(int N) { pset.assign(N, 0);
for (int i = 1; i <= N; i++) pset[i] = i; }
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
 
int main() {
    int t,V,E,price,total_length;
    scanf("%d",&t);
 
    while(t--){
        scanf("%d %d %d",&price,&V,&E);
        EdgeList.clear();
        pset.clear();

        FOR(i,E){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            EdgeList.pb(mp(w,(mp(u,v))));
        }
 
        sort(EdgeList.begin(),EdgeList.end());
        total_length=0;
        initSet(V);

        FOR(i,E){
            pair<int,pair<int,int> > front = EdgeList[i];
            if(!isSameSet(front.second.first,front.second.second)){
                total_length += front.first;
                unionSet(front.second.first,front.second.second);
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