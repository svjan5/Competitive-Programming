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

vector<pair<ii,int> > vec(20);
int arr[8];

int main() {
        int n,m,a,b,c;
        while(scanf("%d %d",&n,&m)!=EOF){
                if(n==0 && m==0) break;
                vector<pair<ii,int> >::iterator it;
                FOR(i,n) arr[i]=i;

                FOR(i,m){
                        scanf("%d %d %d",&a,&b,&c);
                        vec[i].F.F=a;
                        vec[i].F.S=b;
                        vec[i].S=c;
                }
                
                int counts,maincount=0;
                int a_pos,b_pos;
                do{
                        counts = 0;
                        FOR(i,m){
                                a = vec[i].F.F;
                                b = vec[i].F.S;
                                c = vec[i].S;
                                FOR(i,n){
                                        if(arr[i] == a) a_pos = i;
                                        else if(arr[i] == b) b_pos = i;
                                }
                                counts += (c>0) ?(abs(a_pos-b_pos)<=c) :(abs(a_pos-b_pos)>=-c);
                        }
                        // printf("%d\n",counts );
                        if(counts == m)
                                maincount++;
                }while(next_permutation(arr,arr+n));
                printf("%d\n",maincount );
        }

        return 0;
}