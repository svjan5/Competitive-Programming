#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
#define REP1(i,a,b) for(int i=a;i<=b;i++)
#define FOR1(i,n) REP1(i,1,n)

#define MOD 1000

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef long long LL;
typedef pair<int,int> ii;

int reg[10],ip;
string ram[1000];
bool halt;

int str2int (string str, int base=10){
    char *end;
    long  l;
    const char *s = str.c_str();
    l = strtol(s, &end, base);
    return l;
}

void execute(string cmd){
        int d,n,s,a;

        switch(cmd[0]){
                case '1':
                        halt = true;
                        break;
                case '2':                       /*Sets register d to n*/
                        d = cmd[1]-'0';
                        n = cmd[2]-'0';
                        reg[d] = n;
                        break;
                case '3':                       /*Add n to register d*/
                        d = cmd[1]-'0';
                        n = cmd[2]-'0';
                        reg[d] = (reg[d] + n)%MOD;
                        break;
                case '4':                       /*Multiply register d by n*/
                        d = cmd[1]-'0';
                        n = cmd[2]-'0';
                        reg[d] = (reg[d] * n)%MOD;
                        break;
                case '5':                       /*set register d to value of register s*/
                        d = cmd[1]-'0';
                        s = cmd[2]-'0';
                        reg[d] = reg[s];
                        break;
                case '6':                       /*Add register s to register d*/
                        d = cmd[1]-'0';
                        s = cmd[2]-'0';
                        reg[d] = (reg[d] + reg[s])%MOD;
                        break;
                case '7':                       /*multiply register d to the value of register s*/
                        d = cmd[1]-'0';
                        s = cmd[2]-'0';
                        reg[d] = (reg[d] * reg[s])%MOD;
                        break;
                case '8':                       /*set register d to the value in RAM whose address is in register a*/
                        d = cmd[1]-'0';
                        a = cmd[2]-'0';
                        reg[d] = str2int(ram[reg[a]]);
                        break;
                case '9':                       /*set the value in RAM whose address is in register a to the value of register s*/
                        s = cmd[1]-'0';
                        a = cmd[2]-'0';
                        char buffer[4];
                        sprintf(buffer,"%3d",reg[s]);
                        ram[reg[a]] = string(buffer);
                        // printf("STORING THIS %s to RAM address %d\n",ram[reg[a]].c_str(),reg[a] );
                        break;
                case '0':                       /*goto the location in register d unless register s contains 0*/
                        d = cmd[1]-'0';
                        s = cmd[2]-'0';
                        if(reg[s]!=0) ip = reg[d];
                        break;
        }
}

int main() {
        int t;
        string cmd;
        scanf("%d\n",&t);
        string line;

        while(t--){
                MEM(reg,0);
                FOR(i,1000) ram[i]="000";
                int index=0;
                ip=0;
                halt = false;

                
                while(getline(cin,line)>0){
                        if(line.size() == 0) break;
                        stringstream ss(line);
                        ss>>cmd;
                        ram[index] = cmd;
                        index++;
                        // printf("%d=> %s\n",t,cmd.c_str());
                }
                // FOR(i,10) printf("%d=> %s \n",t,ram[i].c_str());
                
                int count=0;

                while(!halt){

                        cmd = ram[ip++];
                        // cout<<cmd<<endl;
                        count ++;
                        execute(cmd);
                        /*printf("Executed command %d :%s   ip=>%d\n",count,cmd.c_str(),ip+1-1);
                        printf("Register :");FOR(i,10) printf("%d ",reg[i]);
                        printf("\nRAM :");FOR(i,20) printf("%s ",ram[i].c_str());
                        printf("\n\n");
                        if(count==16)
                                break;*/
                }
                if(t==0)
                        printf("%d\n",count);
                else
                        printf("%d\n\n",count );
        }
        return 0;
}



