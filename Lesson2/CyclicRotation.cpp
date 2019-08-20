vector<int> solution(vector<int> &A, int K) {  
	// write your code in C++14 (g++ 6.2.0)  
	  
	if (A.size() == 0) return A;  
   
	if (K == 0) return A;  
	  
   
	vector<int> result(A.size());  
	  
	for (unsigned int i = 0; i < result.size(); i++) {  
		  
		result[(i + K) % A.size()] = A[i];  
	}  
	  
	return result;  
}  
