int solution(vector<int> &A) {  
	// write your code in C++14 (g++ 6.2.0)  
	  
	int zCount = 0;  // how many going east   
	int passing = 0; // total passing pairs  
	  
	  
	for (auto  &a : A) {  
	if(a == 1) {  
		  
		passing += zCount;  
	}  
	else   
	  zCount++;  
	}  
	  
	if(passing > 1e9 || passing < 0) return -1;  
	  
	else   
	  return passing;  
	  
}  
