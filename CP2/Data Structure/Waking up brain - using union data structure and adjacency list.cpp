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


#define ELEMENTS 26

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

bool awake[26];

int main() {

        int n,m;
        string line;
        char a,b;
        int count=0;

        while(scanf("%d\n%d\n",&n,&m) != EOF){
                map<char,vector<char> > AdjList;
                map<char,vector<char> >::iterator it;
                make_sets(ELEMENTS);
                MEM(awake,false);

                getline(cin,line);
                for(int i=0;i<line.length()-1;i++){
                        set_union(line.at(i)-'A',line.at(i+1)-'A');
                        awake[line.at(i)-'A'] = true;
                        awake[line.at(i+1)-'A'] = true;
                }
                // rep = find_set(line.at(0)-'A');

                FOR(i,m){
                        getline(cin,line);
                        a = line.at(0);
                        b = line.at(1);
                        AdjList[a].pb(b);
                        AdjList[b].pb(a);
                }

                bool anyChange=true;
                int awakeAround,years=0;
                bool awakeTemp[26];

                while(anyChange){
                        /*for(it=AdjList.begin();it!=AdjList.end();it++){
                                printf("%c -> ",it->F );
                                if(awake[it->F - 'A'])
                                        printf("Yes\t");
                                else
                                        printf("NO \t");
                        }
                        printf("\n");
                        */

                        FOR(i,26) awakeTemp[i] = awake[i];
                        anyChange=false;

                        for(it=AdjList.begin();it!=AdjList.end();it++){
                                awakeAround=0;
                                if(!awake[(it->F)-'A']){
                                        FOR(i,(int)it->S.size()){
                                                if(awake[it->S[i]-'A'])
                                                        awakeAround++;
                                        }
                                        if(awakeAround>=3){
                                                anyChange=true;
                                                awakeTemp[it->F-'A']=true;
                                        }
                                }
                        }
                        FOR(i,26) awake[i] = awakeTemp[i];
                        years++;
                }
                
                // bool allDone=true;
                /*for(it=AdjList.begin();it!=AdjList.end();it++){
                        if(!awake[it->F - 'A']){
                                allDone=false;
                                break;
                        }
                }*/
                int awakeCount=0;
                FOR(i,26) if(awake[i]) awakeCount++;

                /*if(count==0){
                        if(awakeCount == n)
                                printf("WAKE UP IN, %d, YEARS",years-1);
                        else
                                printf("THIS BRAIN NEVER WAKES UP");
                }
                else{
                        if(awakeCount == n)
                                printf("\nWAKE UP IN, %d, YEARS",years-1);
                        else
                                printf("\nTHIS BRAIN NEVER WAKES UP"); 
                }
                count++;*/
                if(awakeCount == n)
                                printf("WAKE UP IN, %d, YEARS\n",years-1);
                        else
                                printf("THIS BRAIN NEVER WAKES UP\n");
                /*for(it=AdjList.begin();it!=AdjList.end();it++){
                        printf("%c => ",it->F);
                        FOR(i,(int)it->S.size()){
                                printf("%c ",it->S[i]);
                        }
                        printf("\n");
                }*/
                // getline(cin,line);
        }

        return 0;
}