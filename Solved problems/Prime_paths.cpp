#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define LIMIT 10000

typedef long long LL;
typedef pair<int,int> ii;

bool pssbl;
bool isprime[10000];

void sieve(int largest){
    FOR(i,largest+1) isprime[i]=true;                   /*Initializing all numbers as prime*/
    isprime[0] = isprime[1] = false;

    for (int i = 2; i <= largest; i++) {
        if (isprime[i]) {
            for (int j = 2*i; j <= largest; j += i) {
                isprime[j] = false;
            }
        }
    }}
int power(int x, unsigned int y){
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;}
string numToStr (int Number ){
    ostringstream ss;
    ss << Number;
    return ss.str();}
int strToNum (const string &Text){
    istringstream ss(Text);
    int result;
    return ss >> result ? result : 0;}

int bfs_scan(int start,int end){
    int front,temp;
    queue<int> q;
    map<int,int> dist;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        front = q.front();q.pop();

        if(front == end) break;

        string num = numToStr(front);

        REP1(i,1,9){
            num[0] = '0'+i;
            temp = strToNum(num);
            if( dist.find(temp)==dist.end() && isprime[temp]){
                dist[temp] = dist[front]+1;
                q.push(temp);
            }
        }

        REP1(i,1,3){
            num = numToStr(front);
            FOR(j,10){
                num[i] = '0'+j;
                temp = strToNum(num);
                if( dist.find(temp)==dist.end() && isprime[temp]){
                    dist[temp] = dist[front]+1;
                    q.push(temp);
                }
            }
        }
    }

    if(!dist.count(end)) {
        pssbl = false;
        return 0;
    }

    return dist[end];
}

int main() {
	int t,start,end;
	scanf("%d",&t);
    sieve(10000);

	while(t--){
        pssbl=true;
        scanf("%d %d",&start,&end);
        int count = bfs_scan(start,end);
        if(pssbl)
            printf("%d\n",count);
        else
            printf("Impossible\n");
	}
	return 0;
}