#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_W = 14;

int N;
char board[MAX_W][MAX_W+1];
int pos[MAX_W];
int bit1, bit2, bit3;

void init(){
        for(int i=0; i<N; i++){
                scanf("%[^\n]%*c", board[i]);
        }
}

int dfs(int depth){
        if(depth == N){
                return 1;
        }

        int ret = 0;

        int cannot = bit1 | bit2 | bit3;
        int t1 = bit1, t2 = bit2, t3 = bit3;

        for(int i=0; i<N; i++){
                if(board[depth][i] == '.' && !((cannot>>i)&1) ){
                        
                        bit1 = t1 | (1<<i);
                        bit2 = (t2<<1) | (1<<(i+1));
                        bit3 = (t3>>1) | (i>0 ? 1<<(i-1) : 0);

                        pos[depth] = i;
                        ret += dfs(depth+1);

                }
        }

        bit1 = t1; bit2 = t2; bit3 = t3;

        return ret;
}

int solve(){
        bit1 = bit2 = bit3 = 0;
        return dfs(0);
}

int main(){
        int c = 0;
        while(scanf("%d ", &N), N){
                init();
                printf("Case %d: %d\n", ++c, solve());
        }
        return 0;
}