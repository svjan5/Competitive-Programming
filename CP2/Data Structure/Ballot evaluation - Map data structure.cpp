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

bool check(string op,int value,int total){
        value = value*10;

        if(op == "<")
                return total < value;

        else if(op == ">")
                return total > value;

        else if(op == "<=")
                return total <= value;

        else if(op == ">=")
                return total >= value;

        else
                return total == value;
}

int main() {

        int p,g;
        map<string,int> party;
        string str;
        int num,dec;

        scanf("%d%d",&p,&g);

        FOR(i,p){
                cin>>str;
                scanf("%d.%d\n",&num,&dec);
                num = num*10+dec;
                party[str]=num;
        }

        /*map<string,double>::iterator it;
        for(it=party.begin();it!=party.end();it++){
        printf("%s => %lf\n",it->F.c_str(),it->S );
        }*/

        string line,word;
        string op;
        int value,total;

        FOR(i,g){
                getline(cin,line);
                total = 0;
                istringstream iss(line);

                while(iss>>word != 0){
                    if(word == "+")
                        continue;

                        else if(party.count(word) !=0 )
                                total += party[word];

                        else {
                                op = word;
                                break;
                        }
                }

                iss>>value;
                // printf("value is %lf\n",value );

                if(check(op,value,total))
                        printf("Guess #%d was correct.\n",i+1);
                else
                        printf("Guess #%d was incorrect.\n",i+1);
        }

        return 0;
}