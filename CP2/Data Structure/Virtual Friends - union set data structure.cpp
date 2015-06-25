#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)

#define INF 1000000000
#define MOD 1000000007

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define ELEMENTS 100000

int numSets,parent[ELEMENTS],ranks[ELEMENTS],setSize[ELEMENTS];
void make_sets(int number_of_elements){
    numSets = number_of_elements;
    for(int i = 0; i < number_of_elements; i++){parent[i] = i;ranks[i] = 0;setSize[i] = 1;}
}
int find_set(int element){                              
    if(element != parent[element]) parent[element] = find_set(parent[element]);    
    return parent[element];
}
void set_union(int x, int y){                   
    int rx, ry;rx = find_set(x);ry = find_set(y);
    if(rx == ry) return;numSets--;
    if(ranks[rx] == ranks[ry]) ranks[rx]++,parent[ry] = rx,setSize[rx] += setSize[ry];
    else if(ranks[rx] > ranks[ry]) parent[ry] = rx,setSize[rx] += setSize[ry];
    else parent[rx] = ry,setSize[ry] += setSize[rx];
}
int num_sets(){return numSets;}
int set_size(int i){return setSize[find_set(i)];}
bool is_same_set(int i,int j){
  if(find_set(i) == find_set(j)) return true;
  else return false;
}

int main() {
        int t,n;
        string f1,f2;
        scanf("%d",&t);
        while(t--){
                map<string,int> nameMap;
                map<string,int>::iterator it;
                int index = 0;
                scanf("%d\n",&n);
                make_sets(100000);

                FOR(i,n){
                        cin>>f1>>f2;
                        if(nameMap.count(f1) == 0) nameMap[f1] = index++;
                        if(nameMap.count(f2) == 0) nameMap[f2] = index++;
                        set_union(nameMap[f1],nameMap[f2]);
                        printf("%d\n",set_size(nameMap[f2]));
                        // printf("%s %s\n",f1.c_str(),f2.c_str());
                }

                /*for(it=nameMap.begin();it!=nameMap.end();it++){
                        printf("%s -> %d\n",it->F.c_str(),it->S );                        
                }*/

        }
        return 0;
}