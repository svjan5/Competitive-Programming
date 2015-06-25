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

typedef long long LL;
typedef pair<int,int> ii;
typedef vector<int> vi;

int main() {
    int t;
    scanf("%d\n",&t);

    while(t--){
        map<string,int> mp;
        map<string,int>::iterator it;
        string line;
        int count=0;

        while(getline(cin,line)){
            if(line.length() == 0)
                break;

            if(mp.count(line)!=0)
                mp[line]++;
            else
                mp[line]=1;

            count++;
            /*printf("%s\n",line.c_str());*/
        }

        double per;
        for(it=mp.begin();it!=mp.end();it++){
            per = ((it->S)/(count*1.0))*100.0;
            printf("%s %.4lf\n",it->F.c_str(),per );
            // printf("%s -> %d\n", it->F.c_str(),it->S);
        }

        cout<<endl;

    }

    return 0;
}