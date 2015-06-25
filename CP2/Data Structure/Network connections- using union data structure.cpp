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

#define ELEMENTS 10000

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int parent[ELEMENTS];           /*points to representative of its set*/
int ranks[ELEMENTS];            /*Stores the information about ranks of elements*/

void make_sets(int number_of_elements){
    int i;
    for(i = 0; i < number_of_elements; i++){
        parent[i] = i;                          /*All elements are set in themselves*/
        ranks[i] = 0;                           /*Initially all ranks elements' ranks are set to 1*/
    }
}

int find_set(int element){
    if(element != parent[element])                      /*Root of tree has itself as its parent*/
        parent[element] = find_set(parent[element]);    /*Recursively compressing path*/
    return parent[element];
}

void set_union(int x, int y){                   /*where x and y are elements of different sets*/
    int rx, ry;                                 /*representatives of x and y sets*/
    rx = find_set(x);
    ry = find_set(y);
    if(rx == ry) return;                        /*Elements are already in same set*/
        
    if(ranks[rx] == ranks[ry]){
        ranks[rx]++;
        parent[ry] = rx;
    }

    else if(ranks[rx] > ranks[ry])
        parent[ry] = rx;
    
    else
        parent[rx] = ry;
}

int main() {
        int t,n,c1,c2;
        char ch;
        string line;
        scanf("%d\n\n",&t);

        while(t--){
                scanf("%d\n",&n);
                make_sets(n);
                int succ=0,unsucc=0;    

                while(getline(cin,line)!=0){
                        if(line == "")
                                break;

                        istringstream iss(line);
                        iss>>ch>>c1>>c2;
                        // printf("%c %d %d\n",ch,c1,c2);
                        if(ch == 'c')
                                set_union(c1-1,c2-1);
                        else{
                                if(find_set(c1-1) == find_set(c2-1))
                                        succ++;
                                else
                                        unsucc++;
                        }
                }
                printf("%d,%d\n",succ,unsucc);
                if(t!=0) printf("\n");
        }
        return 0;
}