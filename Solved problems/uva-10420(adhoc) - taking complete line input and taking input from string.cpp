#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define F first
#define S second

typedef long long LL;
typedef pair<int,int> ii;

int main() {
    int n;
    scanf("%d\n",&n);
    
    map<string,int> maps;
    map<string,int>::iterator it;
    string country,name;


    while(n--){
        string line;
        getline(cin,line);
        istringstream iss(line);
        iss>>country;
    /*
        while(getline(cin,line)!=0){
            if(line == "")
                break;
        }
    */
        if(maps.count(country) != 0){
            maps[country] += 1;
        }
        else{
            maps[country] =1;
        }
    }

    for(it=maps.begin();it!=maps.end();it++){
        printf("%s %d\n",(it->F).c_str(),it->S);
    }
    return 0;
}