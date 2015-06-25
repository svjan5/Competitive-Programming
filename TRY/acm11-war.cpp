#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
 
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define mp make_pair
 
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
char land[500][500];
int R,C;
 
int dr[] = {0,1,-1,0};
int dc[] = {1,0,0,-1};
 
void blockSurrounding(int a,int b){
    int x,y;
    FOR(i,4){
        x = a + dr[i];
        y = b + dc[i];
 
        if(x<0 || y<0 || x>R-1 || y>C-1)
            continue;
 
        if(land[x][y]=='.')
            land[x][y]='&';
        else
            continue;
    }
 
}
 
int main() {
    int t;
    char c;
    scanf("%d",&t);
 
    while(t--){
        map<char,vii > main;
        scanf("%d %d\n",&R,&C);
        FOR(i,R){
            FOR(j,C){
                scanf("%c",&c);
                land[i][j]=c;
                if(c!='.' && c!='#'){
                    if(!main.count(c)){
                        vii v;
                        v.pb(mp(i,j));
                        main[c] = v;
                    }
                    else{
                        main[c].pb(mp(i,j));
                    }
                }
            }
            scanf("%c",&c);
        }
 
        map<char,vii>::iterator it;
        int x,y,x1,y1;
        int count;
        while(true){
            count=0;

            for(it=main.begin();it!=main.end();it++){
                c = it->first;
                vii v = it->second;
                vii vtemp;

                cout<<c<<endl;
                FOR(i,(int)v.size()){
                    x1 = v[i].first;
                    y1 = v[i].second;
 
                    FOR(j,4){
                        x = x1 + dr[j];
                        y = y1 + dc[j];
                        if(x<0 || y<0 || x>R-1 || y>C-1)
                            continue;
                        if(land[x][y]==c || land[x][y]=='#' || land[x][y]=='&' || land[x][y]=='*')
                            continue;
                        if(land[x][y]=='.'){
                            land[x][y]=c;
                            vtemp.pb(mp(x,y));
                        }
                        else{
                            land[x][y]='*';
                            blockSurrounding(x,y);
                        }
                    }
                }

                it->second = vtemp;

                if(main[c].size()==0)
                    count++;
                // FOR(i,(int)vtemp.size())
                //     printf("(%d,%d) ",vtemp[i].first,vtemp[i].second );

                // FOR(i,(int)main[c].size())
                //     printf("(%d,%d) ",main[c][i].first,main[c][i].second );


                FOR(i,R){
                    FOR(j,C){
                        printf("%c",land[i][j]);
                    }
                    cout<<endl;
                }
                cout<<endl;
            }
            if(count==(int)main.size())
                break;
        }
 
        FOR(i,R){
            FOR(j,C){
                // if(land[i][j]=='&')
                //     land[i][j]='.';
                printf("%c",land[i][j]);
            }
            cout<<endl;
        }
 
 
        /*map<char,vii>::iterator it;
        for(it=main.begin();it!=main.end();it++){
            c = it->first;
            vii v = it->second;
            printf("%c :",c);
            FOR(j,v.size())
                printf("(%d,%d) ",v[j].first,v[j].second);
            cout<<endl;
        }*/ 
 
    }
    return 0;
}