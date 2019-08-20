#include <iostream>  
#include <stack>  
#include <vector>  
  
using namespace std;  
  
int solution(vector<int> &A) {  
	  
	int consecutive_size = 0;  
	int candidate = 0;  
  
	for(auto &a : A) {  
  
		if(consecutive_size == 0) {  
			candidate = a;  
			consecutive_size++;  
		}  
		else if(candidate == a)  
			consecutive_size++;  
		else  
			consecutive_size--;  
   }  
		int occurence_counter = 0;  
		int occurence_index = -0;  
  
		for(unsigned int i =0; i < A.size(); i++) {  
  
			if(A[i] == candidate) {  
				occurence_counter++;  
				occurence_index = i;  
			}  
  
		}  
  
		return occurence_counter > (int)A.size() / 2.0 ? occurence_index : -1;    
}  
