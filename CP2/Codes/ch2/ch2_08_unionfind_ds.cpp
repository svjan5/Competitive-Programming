#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {
        private:
                vi p, rank, setSize;                       
                int numSets;
        public:
                UnionFind(int N) {
                        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
                        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
                int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
 
                bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
 
                void unionSet(int i, int j) {
                        if (!isSameSet(i,j)){
                                numSets--; 
                                int x = findSet(i), y = findSet(j);
                                if (rank[x] > rank[y]) { 
                                        p[y] = x; 
                                        setSize[x] += setSize[y]; 
                                }
 
                                else{ 
                                        p[x] = y; 
                                        setSize[y] += setSize[x];
                                        if (rank[x] == rank[y]) rank[y]++; 
                                } 
                        } 
                }
 
                int numDisjointSets() { return numSets; }
                int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

/*Using both path compression and union by rank heuristics*/

#define ELEMENTS 5

int parent[ELEMENTS];           /*points to representative of its set*/
int ranks[ELEMENTS];            /*Stores the information about ranks of elements*/
int setSize[ELEMENTS];
int numSets;

void make_sets(int number_of_elements){
    int i;
    numSets = number_of_elements;
    for(i = 0; i < number_of_elements; i++){
        parent[i] = i;                          /*All elements are set in themselves*/
        ranks[i] = 0;                           /*Initially all ranks elements' ranks are set to 1*/
        setSize[i] = 1;                         /*Size of each set is 1 */
    }
}

int find_set(int element){                              /*Find set with path compression*/
    if(element != parent[element])                      /*Root of tree has itself as its parent*/
        parent[element] = find_set(parent[element]);    Recursively compressing path
    return parent[element];
}

void set_union(int x, int y){                   /*where x and y are elements of different sets*/
    int rx, ry;                                 /*representatives of x and y sets*/
    rx = find_set(x);
    ry = find_set(y);
    if(rx == ry) return;                        /*Elements are already in same set*/
    numSets--;
    if(ranks[rx] == ranks[ry]){                 /*Algorithm from cormen*/
        ranks[rx]++;
        parent[ry] = rx;
        setSize[rx] += setSize[ry];
    }

    else if(ranks[rx] > ranks[ry]){
        parent[ry] = rx;
        setSize[rx] += setSize[ry];
    }
    
    else{
        parent[rx] = ry;
        setSize[ry] += setSize[rx];
    }
}

int num_sets(){return numSets;}
int set_size(int i){return setSize[find_set(i)];}
bool is_same_set(int i,int j){
  if(find_set(i) == find_set(j)) return true;
  else return false;
}

int main() {
  printf("Assume that there are 5 disjoint sets initially\n");
  UnionFind UF(5); // create 5 disjoint sets
  make_sets(5);

  printf("%d\n", num_sets()); // 5
  set_union(0, 1);
  printf("%d\n", num_sets()); // 4
  set_union(2, 3);
  printf("%d\n", num_sets()); // 3
  set_union(4, 3);
  printf("%d\n", num_sets()); // 2
  printf("is_same_set(0, 3) = %d\n", is_same_set(0, 3)); // will return 0 (false)
  printf("is_same_set(4, 3) = %d\n", is_same_set(4, 3)); // will return 1 (true)
  for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
    printf("find_set(%d) = %d, set_size(%d) = %d\n", i, find_set(i), i, set_size(i));
  set_union(0, 3);
  printf("%d\n", num_sets()); // 1
  for (int i = 0; i < 5; i++) // find_set will return 3 for {0, 1, 2, 3, 4}
    printf("find_set(%d) = %d, set_size(%d) = %d\n", i, find_set(i), i, set_size(i));
  return 0;
}
