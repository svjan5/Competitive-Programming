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

    
struct cont{
    int id;
    int pent;
    int ac;
    int pCount[10];
};


typedef long long LL;
typedef pair<int,int> ii;
vector<cont> vec;
set<int> reg;



int findIt(int id){
    FOR(i,(int)vec.size()){
        if(vec[i].id == id)
            return i;
    }
    return -1;
}

bool compare(cont c1,cont c2){
    if(c1.ac != c2.ac)
        return c1.ac>c2.ac;
    
    else if(c1.pent != c2.pent)
        return c1.pent < c2.pent;

    else
        return c1.id < c2.id;

}

int main() {
    int t;
    scanf("%d\n",&t);
    string str;
    int con,prob,time;
    char L;

    while(t--){
        vec.clear();
        reg.clear();

        while(getline(cin,str)){

            if(str.length()==0)
                break;

            istringstream iss(str);
            iss>>con>>prob>>time>>L;

            // printf("%d %d %d %c\n",con,prob,time,L );

            if(reg.find(con)!=reg.end()){
                int index = findIt(con);

                if(L == 'C'){
                    vec[index].ac += 1;
                    vec[index].pent = vec[index].pCount[prob]*20 + time;
                }
                else if(L == 'I'){
                    vec[index].pCount[prob] += 1;
                }
            }

            else{
                cont ncon;
                ncon.id=con;

                if(L=='C'){
                    ncon.ac = 1;
                    ncon.pent = time; 
                    ncon.pCount[prob] = 0;        
                }

                else if(L=='I'){
                    ncon.ac = 0;
                    ncon.pent=0;
                    ncon.pCount[prob] = 1;
                }
                
                else{
                    ncon.ac=0;
                    ncon.pent=0;
                    ncon.pCount[prob] = 0;
                }

                vec.push_back(ncon);
                reg.insert(con);
            }

        // cout<<endl;
        }

        sort(vec.begin(),vec.end(),compare);
        FOR(i,(int)vec.size())
            printf("%d %d %d\n",vec[i].id,vec[i].ac,vec[i].pent);
        // cout<<endl;
    }
    return 0;
}