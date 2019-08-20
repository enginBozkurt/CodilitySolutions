vector<int> solution(int N, vector<int> &A) {  
	// write your code in C++14 (g++ 6.2.0)  
	vector <int> counters (N, 0); // vector of counters  
	  
	int currentMax = 0;  // current maximum counter  
	int lastUsedMax = 0; // last used maximum counter  
	  
	for (auto &a : A) // loop over A  
		if (a <= N)   // "increase"  
		{  
			counters[a-1] = max (counters[a-1], lastUsedMax) + 1;   
			currentMax = max (counters[a-1], currentMax);          
		}  
		else lastUsedMax = currentMax; // "max counter"  
  
	// check if "max counter" was applied for each element  
	if (lastUsedMax > 0)   
		for (auto &c : counters)   
			if (c < lastUsedMax)   
				c = lastUsedMax;  
	return counters;  
}  
