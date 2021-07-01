#include<bits/stdc++.h>
//#include<vector>
#include <iostream>

using namespace std;
int gen(){
  static  int i =0;
   return ++i;
}
int main(){

	std::vector<int> A(20);

	std::cout << "Demonstration of fill STL library -------------------->" << std::endl;
 	fill(A.begin(), A.end() , 89);
  	for(auto i = A.begin() ;i != A.end() ; i++) 
	   std::cout << *i << "  ";
	  
	std::cout << std::endl << "Erarse function ---------------------------------->" << std::endl;
	
	A.erase(A.begin(), A.end());
	
  	for(auto i = A.begin() ;i != A.end() ; i++) 
	   std::cout << *i << "  ";

	std::vector<int> Ab(23,1);
        fill(A.begin(), A.end() , 99);
  	for(auto i = Ab.begin() ;i != Ab.end() ; i++) 
	   std::cout << *i << "  ";
	std::cout << std::endl << "Generater function ---------------------------------->" << std::endl;
	std::vector<int> aa(40);
	generate(aa.begin(), aa.end(), gen);

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";
	std::cout << std::endl << "iota function --------------------------------------------->" << std::endl;
        iota(aa.begin(), aa.end(), 100);

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";
	cout << endl << "replace function ------------------------------------------------------->" << endl;
        replace(aa.begin(), aa.end(), 123 , 9999);

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";
     	
	cout << endl << "STRUCTURE CHANGE ------------------------------------------------>\n remove function ------------------------------------------------------->" << endl;
	remove(aa.begin(), aa.end(), 9999);

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";
        cout << endl << " Erase fuction and remove function both will use to remove the particular value and eliminate the space of it ------------------------------------->\n";
        aa.erase(remove(aa.begin(), aa.end(), 100) , end(aa));

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";
	cout << "\nCopy Backward function ---------------------------------------------------------------------------------------------> \n";
        copy_backward(aa.begin() , aa.begin() + 8 , aa.begin() + 10);

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";
	
	cout << "\nMove Backward function ---------------------------------------------------------------------------------------------> \n";
         
        move_backward(aa.begin() , aa.begin() + 8 , aa.begin() + 10);

  	for(auto i = aa.begin() ;i != aa.end() ; i++) 
	   std::cout << *i << "  ";

	cout << "\nUnique function ---------------------------------------------------------------------------------------------> \n";
       	aa.push_back(139);
       	aa.push_back(139);
       	aa.push_back(139);
       	aa.push_back(139);
       	aa.push_back(139);
	aa[1] = 101;
//	vector<int>::iterator ip
	auto ip = unique(aa.begin(),aa.end()); //It will only Remove adjacent elements 
        aa.resize(distance(aa.begin(),ip));
  	for( ip = aa.begin() ;ip != aa.end() ; ++ip) 
	   cout << *ip << "  ";

	cout << "\nUnique function ---------------------------------------------------------------------------------------------> \n";
        
	return 0;
}
