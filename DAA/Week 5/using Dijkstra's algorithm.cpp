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
#define F first
#define S second

#define INF 1000000
#define V 200
#define MP make_pair
#define pb push_back

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vii> AdjList(V+1);

void replaceAll(string& str, const string& from, const string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

int main() {
    int v,w,node;
    string line;

    FOR1(i,200){
        getline(cin,line);
        replaceAll(line,","," ");
        istringstream iss(line);
        iss>>node;

        while(iss>>v>>w){
            AdjList[node].pb(ii(v,w));
        }
    }

    int s=1;
    vi dist(V+1, INF); dist[s] = 0;
    priority_queue< ii > pq; pq.push(ii(0, s));

    while (!pq.empty()) {                                             
        ii front = pq.top(); pq.pop();  
        int d = front.first, u = front.second;

        if (d > dist[u]) continue;   

        for (int j = 0; j < (int)AdjList[u].size(); j++){
            ii v = AdjList[u][j];                       
            if (dist[u] + v.second < dist[v.first]) {
                dist[v.first] = dist[u] + v.second;                 
                pq.push(ii(dist[v.first], v.first));
            } 
        }
    }

    FOR1(i,V)
        printf("SSSP(%d, %d) = %d\n", s, i, dist[i]);
    return 0;
}