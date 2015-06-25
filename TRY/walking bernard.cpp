#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define MEM(a,b) memet(a,(b),ssizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef long long LL;
typedef pair<int,int> ii;

char path[501];
int home[100][100];
int city[201][201];
bool visit[201][201];

int n,m;
int xpos=0,ypos=0;
char face='E';
int total=0;

void checkadd(int x,int y){
    if(!(x<0 || x>=2*n+1 || y<0 || y>=2*m+1)){
        total += city[x][y];

        if(visit[x][y]==false){
            visit[x][y]=true;
            city[x][y] = city[x][y]/2;
        }
    }
}

void moveForward(){
    int x=xpos;
    int y=ypos;

    switch(face){
        case 'E':
            y++;
            checkadd(x+1,y);
            checkadd(x-1,y);
            ypos += 2;
            break;
        case 'W':
            y--;
            checkadd(x+1,y);
            checkadd(x-1,y);
            ypos += -2;
            break;
        case 'N':
            x--;
            checkadd(x,y+1);
            checkadd(x,y-1);
            xpos += -2;
            break;
        case 'S':
            x++;
            checkadd(x,y+1);
            checkadd(x,y-1);
            xpos += 2;
            break;
    }
}

void rotateRight(){
    switch(face){
        case 'E':
            face = 'S';
            break;
        case 'W':
            face = 'N';
            break;
        case 'N':
            face = 'E';
            break;
        case 'S':
            face = 'W';
            break;
    }
}

void rotateLeft(){
    switch(face){
        case 'E':
            face = 'N';
            break;
        case 'W':
            face = 'S';
            break;
        case 'N':
            face = 'W';
            break;
        case 'S':
            face = 'E';
            break;
    }
}

int main(){
    scanf("%d %d\n",&n,&m);

    FOR(i,n) FOR(j,m) scanf("%1d",&home[i][j]);
    scanf("%s",path);

    memset(city,0,sizeof(city));
    memset(visit,false,sizeof(visit));

    for(int i=1;i<2*n+1;i+=2){
        for(int j=1;j<2*m+1;j+=2){
            city[i][j] = home[(int)(i/2)][(int)(j/2)];
        }
    }
    
    for(int i=0;i<(int)strlen(path);i++){
        char step = path[i];
        // printf("%c :",step);
        // printf("%d %d => %c  == %d",xpos,ypos,face,total);
        switch(step){
            case 'M':
                moveForward();
                break;
            case 'R':
                rotateRight();
                break;
            case 'L':
                rotateLeft();
                break;
            default:
                printf("\nERROR!!");
        }

        // printf("     ********************************    %d %d => %c  == %d\n",xpos,ypos,face,total);
        /*FOR(i,2*n+1){
            FOR(j,2*m+1)
                printf("%d",city[i][j]);
            cout<<endl;
        }*/

    }

    printf("%d",total);

    /*FOR(i,n){
        FOR(j,m){
            printf("%d",home[i][j]);
        }
        cout<<endl;
    }

    FOR(i,2*n+1){
        FOR(j,2*m+1)
            printf("%d",city[i][j]);
        cout<<endl;
    }*/
    return 0;
}