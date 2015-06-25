`
VECTOR C++ STL

int main(){

/*Constructors*/
	vector<int> first;                                 	/*empty vector of ints*/
	vector<int> second (4,100);                        	/*four ints with value 100*/
	vector<int> third (second.begin(),second.end());   	/*iterating through second*/
	vector<int> fourth (third);                        	/*a copy of third */
	int myints[] = {16,2,77,29};				/*the iterator constructor can also be used to construct from arrays:*/
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::vector<int> myvector;
	for (int i=0; i<100; i++) myvector.push_back(i);

/*Size, capacity, max_size*/
	cout << "size: " << myvector.size() << "\n";		/*Size 100*/
	cout << "capacity: " << myvector.capacity() << "\n";	/*Capacity 128*/
	cout << "max_size: " << myvector.max_size() << "\n";	/*Max_size 1073741823*/
	myvector.reserve(100);					/*Changes capacity to 100*/

/*Resize*/
	myvector.resize(5);					/*Changes size of vector*/
	myvector.resize(8,100);					/*Allocates new 3 as 100*/
	myvector.resize(12);					/*Allocates new 4 as 0*/
	/*myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0*/

/*Empty*/ 
	if(myvector.empty()) printf("myvector is Empty\n");

/*Front and back:  front-> 1 2 3 4 5 6 7 8 9 10 <-back*/
	cout<< myvector.front();
	cout<< myvector.back();

/*Assign*/
	first.assign (7,100);             			/*7 ints with a value of 100*/
	second.assign (first.begin(),first.end()-1); 		/*the 5 central values of first*/
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   			/*assigning from array.*/

/*push and pop*/
	myvector.push_back(1);					/* {1 2 3} -> {1 2 3 1}*/
	myvector.pop_back();					/* {1 2 3} -> {1 2}*/

/*Insert*/
	it = myvector.begin();
 	it = myvector.insert ( it , 200 );
 	myvector.insert (it+2,anothervector.begin(),anothervector.end());
 	myvector.insert (myvector.begin(), myarray, myarray+3);

 /*Erase*/
 	myvector.erase (myvector.begin()+5);			/*erase the 6th element*/
 	myvector.erase (myvector.begin(),myvector.begin()+3)	/*erase first 3 elements*/

 /*Clear*/
 	myvector.clear();					/*Empties whole vector*/

 /*Swap*/
 	foo.swap(bar);						/*Exchanges the content of swap with foo*/

}