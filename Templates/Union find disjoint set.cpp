#define ELEMENTS 5

int numSets,parent[ELEMENTS],ranks[ELEMENTS],setSize[ELEMENTS];
void make_sets(int number_of_elements){
    numSets = number_of_elements;
    for(int i = 0; i < number_of_elements; i++){parent[i] = i;ranks[i] = 0;setSize[i] = 1;}
}
int find_set(int element){                              
    if(element != parent[element]) parent[element] = find_set(parent[element]);    
    return parent[element];
}
void set_union(int x, int y){                   
    int rx, ry;rx = find_set(x);ry = find_set(y);
    if(rx == ry) return;numSets--;
    if(ranks[rx] == ranks[ry]) ranks[rx]++,parent[ry] = rx,setSize[rx] += setSize[ry];
    else if(ranks[rx] > ranks[ry]) parent[ry] = rx,setSize[rx] += setSize[ry];
    else parent[rx] = ry,setSize[ry] += setSize[rx];
}
int num_sets(){return numSets;}
int set_size(int i){return setSize[find_set(i)];}
bool is_same_set(int i,int j){
  if(find_set(i) == find_set(j)) return true;
  else return false;
}