//STL-array
#include<bits/stdc++.h> 
using namespace std;   
int main() {   
  // construction uses aggregate initialization 
  // double-braces required 
  array<int,5>ar1{{3,4,5,1,2}}; 
  array<int,5>ar2={1,2,3,4,5}; 
  array<string,2>ar3={{string("a"),"b"}}; 
  
  //printing the size of the array 
  cout<<ar1.size()<<endl; 
  cout<<ar2.size()<<endl; 
  cout<<ar3.size()<<endl;
   
  //sorting & printing the array 
  sort(ar1.begin(),ar1.end());  
  for (auto i:ar1) 
  cout<<i<<' ';
     
  return 0; 
}
