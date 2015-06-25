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
    char c;
    
    list<char> text;
    list<char>::iterator it,it1;

    
    while(c!=EOF){
        c = getchar_unlocked();

        text.clear();
        it=text.begin();

        while(c!='\n' && c!=EOF){
            if(c=='[')
                it = text.begin();
            
            else if(c==']')
                it = text.end();

            else{
                text.insert(it,c);    
            }
            c=getchar_unlocked();

        }
            
            for(it1=text.begin();it1!=text.end();it1++)
                printf("%c",*it1);
            cout<<endl;   
    }

    

    return 0;
}