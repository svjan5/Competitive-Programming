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

int main() {
    int t,R,C,M,N;
    scanf("%d",&t);
    int count=0;
 
    while(t--){
        count++;
        int maxCount=-1;
        char c;
        map<char,int> freq;
        vector<char> vec;

        scanf("%d %d %d %d\n",&R,&C,&M,&N);
        
        FOR(i,R){
            FOR(j,C){
                scanf("%c",&c);
                
                if(freq.count(c)!=0){            /*Means element is already in the map*/
                    freq[c] += 1;
                    if(freq[c]>maxCount){
                        vec.clear();
                        vec.pb(c);
                        maxCount = freq[c];
                    }
                    else if(freq[c] == maxCount){
                        vec.pb(c);
                    }
                }

                else{
                    freq[c] = 1;
                    if(freq[c]>maxCount){
                        vec.clear();
                        vec.pb(c);
                        maxCount = freq[c];
                    }

                    else if(freq[c] == maxCount){
                        vec.pb(c);
                    }

                }
            }
            
            scanf("%c",&c);
            
        }
            // cout<<maxCount<<endl;
            int maxFreq = maxCount*vec.size();

            int res = M*(maxFreq) + N*(R*C-maxFreq);
            printf("Case %d: %d\n",count,res);
    }
    return 0;
}