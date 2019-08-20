#include<iostream>  
#include<vector>  
#include<numeric>  
  
using namespace std;  
  
int solution(vector<int> &A) {  
	// write your code in C++14 (g++ 6.2.0)  
	  
	vector<int> suffixSum(A.size() + 1);  
	  
	int count = 0;  
	 
	  
	for (int i(A.size()-1); i >= 0; --i) {  
	  
			  
		suffixSum[i] = A[i] + suffixSum[i + 1];  
			  
		if (A[i] == 0) count += suffixSum[i];  
		if (count > 1000000000) return -1;  
			  
		}  
	return count;  
}  
