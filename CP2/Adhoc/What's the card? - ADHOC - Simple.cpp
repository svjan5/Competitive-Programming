#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define pb push_back
#define mp make_pair

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;

string deck[52];

int main() {
    int t;
    scanf("%d",&t);
    int count=0;

    while(t--){
        count++;

        FOR(i,52) cin>>deck[i];

        int X,Y=0,num=25;
        // cout<<deck[25]<<endl;
        FOR(i,3){
            switch(deck[num][0]){
                case 'A':
                case 'K':
                case 'Q':
                case 'J':
                case 'T':
                    Y += 10;
                    break;

                default:
                    X = deck[num][0]-'0';
                    Y = Y+X;
                    num = num-(10-X);
                    // cout<<Y<<endl;
            }
            num--;
        }

        
        FOR(i,26){
            num++;
            deck[num] = deck[26+i];
        }
        printf("Case %d: %s\n",count,deck[Y-1].c_str());

        /*FOR(i,52){
            printf("%s ",deck[i].c_str());
        }*/
    }
    return 0;
}