#include <map>
#include <cstdio>
#include <vector>
#include <utility>
 
using namespace std;
 
#define REP(i,a,b) for(int i=a;i<b;i++)
#define FOR(i,n) REP(i,0,n)
 
typedef long long LL;
 
int main(){
	int n,w,m,a,count=0,start;
	multimap<int,int> map;
	vector<int> vec;
	multimap<int,int>::iterator it;
	bool fwd=true;
 
	scanf("%d %d %d",&n,&m,&w);
 
	FOR(i,n){
		scanf("%d",&a);
		vec.push_back(a);
	}
 
	FOR(i,n){
		map.insert(pair<int,int>(vec[i],count));
		count++;
	}
 
	/*for(it=map.begin();it!=map.end();it++){
		printf("%d -> %d\n",it->first,it->second);
	}*/
 
	pair<int,int> temp;
	pair <multimap<int,int>::iterator, multimap<int,int>::iterator> ret;
 
	FOR(i,m){
		start = map.begin()->second;
 
		// cout<<start<<endl;
		if(start+w-1 < n){
												//Moving in forward direction
			FOR(i,w){
				int val = vec[start+i];
				ret = map.equal_range(val);
				for (it=ret.first; it!=ret.second; ++it){
					if(it->second == start+i)
						break;
				}
 
				temp = *it;
				map.erase(it);
				temp.first += 1;
				map.insert(temp);
			}
		}
		else{
 
			FOR(i,w){
				int val = vec[start-i];
			    ret = map.equal_range(val);
				for (it=--(ret.second); it!=ret.first; --it){
					if(it->second == start-i)
						break;
				}
				temp = *it;
				map.erase(it);
				temp.first += 1;
				map.insert(temp);
			}
		}
	}
 
	// temp = *map.find(1);
	// cout<<temp.first<<" "<<temp.second;
 
	// map.erase(map.begin());
	// map.insert(pair<int,int>(4,1));
 
	/*for(it=map.begin();it!=map.end();it++){
		printf("%d -> %d\n",it->first,it->second);
	}*/
 
	printf("%d",map.begin()->first);
	return 0;
 
}