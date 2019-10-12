//STL-maps
#include<bits/stdc++.h>
using namespace std;
int main(){
	//declaring the container map
	map<int, int>m;//stores the data in the form of (KEY-VALUE) pair
	
	//inserting the elements in a map
	m.insert(pair<int,int>(1,40));
	m.insert(pair<int,int>(2,50));
	m.insert(pair<int,int>(3,60));
	m.insert(pair<int,int>(4,70));
	m.insert(pair<int,int>(5,80));
	
	//iterating a map
	map<int,int>::iterator itr; 
    for (itr=m.begin();itr!=m.end();++itr) { 
        cout<<itr->first<<" - "<<itr->second<<endl; 
    }
	//OUTPUT:1 - 40
    //       2 - 50
	//       3 - 60
	//       4 - 70
	//       5 - 80   
}
