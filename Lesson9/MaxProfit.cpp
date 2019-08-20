int solution(vector<int> &A) {  
	// write your code in C++14 (g++ 6.2.0)  
	if (A.size() < 2) return 0; // at least 2 days required to gain profit  
	  
	int maxProfit = 0;  // maximum profit  
	int lastMin = A[0]; // last minimum price  
	  
	for (unsigned int i = 1; i < A.size(); i++) // loop over days  
	{  
		maxProfit = max (maxProfit, A[i] - lastMin); // update max profit  
		lastMin = min (lastMin, A[i]); // update last min  
	}  
	  
	return maxProfit;  
}  
