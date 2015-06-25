#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)
#define INF 1000000007

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef long long LL;
typedef pair<int,int> ii;

int grid[500][500];
int mem[505][505][1000];
int R,C;

/*int minHealth(int x,int y,int health){
    int value=0;
    health = health+grid[x][y];
    if(x>R-1 || y>C-1)
        return INF;

    if(x==R-1 && y==C-1)
        return grid[x][y];

    if(health<=0){
        if(x==0 && y==0);
        else{
           value= (-health)+1;
           health=1;
        }
    }

    // printf("%d %d %d value=%d\n",x,y,health,value );
    return value + min( minHealth(x+1,y,health),
                        minHealth(x,y+1,health));
}*/

inline int getint(){
    int num=0;
    char c=getchar_unlocked();
    while(!(c>='0' && c<='9'))
        c=getchar_unlocked();
 
    while(c>='0' && c<='9'){
        num=(num<<3)+(num<<1)+(c-'0');
        c=getchar_unlocked();
    }
    return num;
}

int minHealth(int x,int y,int health){
    int value=0;

    health = health+grid[x][y];

    if(mem[x][y][health] != -1)
        return mem[x][y][health];

    if(x>R-1 || y>C-1)
        mem[x][y][health] = INF;

    else if(x==R-1 && y==C-1)
        return grid[x][y];

    else if(health<=0 && !(x==0 && y==0)){
        value= (-health)+1;
        health=1;
    }

    if(mem[x][y][health] == -1) mem[x][y][health] =  value + min( minHealth(x+1,y,health),minHealth(x,y+1,health));

    // printf("%d %d %d value=%d\n",x,y,health,mem[x][y][health] );
    return mem[x][y][health];

}
 



int main() {
    int t;
    scanf("%d",&t);
 
    while(t--){
        scanf("%d %d\n",&R,&C);
        FOR(i,R) FOR(j,C) scanf("%d",&grid[i][j]);

        int res = minHealth(0,0,0);
        memset(mem,-1,sizeof(mem));

        if(res==0)
            printf("1\n");
        else
            printf("%d\n",res);


        /*FOR(i,R){
            FOR(j,C)
            printf("%d ",grid[i][j]);
            cout<<endl;
        }*/


    }
    return 0;
}