int solution(int K, vector<int> &A) {  
	// write your code in C++14 (g++ 6.2.0)  
	int count = 0;  
	int length = 0;  
	  
	for (auto &rope : A) {  
		length += rope;  // Tied with the previous one.  
		// Find a qualified rope. Prepare to find the  
		// next one.  
		if(length >= K) {  
			count++;  
			length = 0;  
		}  
	}  
	  
	return count;  
	  
} 
