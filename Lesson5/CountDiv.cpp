#include <iostream>   
#include <cmath>   
using namespace std;  
  
  
int solution(int A, int B, int K) {  
	  
	// write your code in C++14 (g++ 6.2.0)  
	double nStart = ceil(A / (double) K);  
	double nEnd = floor(B / (double) K);  
		  
	return (int) (nEnd - nStart + 1);  
}  
