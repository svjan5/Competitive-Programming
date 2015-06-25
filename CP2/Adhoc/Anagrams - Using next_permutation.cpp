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

string str;

bool compare (char a, char b)
{
    bool isLowerA = true, isLowerB = true;
    if (a >= 'A' && a <= 'Z') 
        isLowerA = false;
    if (b >= 'A' && b <= 'Z') 
        isLowerB = false;
 
    //Both are upper or lower case
    if (isLowerA && isLowerB) 
        return a < b;
    if (!isLowerA && !isLowerB) 
        return a < b;
    
    //a it's a lowercase
    if (isLowerA){
        a -= ('a'-'A');
        return a < b;
    }

    else{
        b -= ('a'-'A');
        return a <= b;
    }
}

int main(){
    int cases;scanf("%d",&cases);
    while(cases--){
        string s;
        cin>>s;
        sort(s.begin(),s.end(),compare);
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end(),compare));
    }
    return 0;   
}