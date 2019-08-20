#include <vector>  
  
using namespace std;  
  
int gcd(int a, int b)  
{  
	  
	int k = a % b;  
	  
	if (k == 0)  
	  return b;  
		
   else   
	 return gcd(b, k);  
}  
  
  
bool recursiveCheck(int gcdValue, int divisor) {  
	  
	int newGCD = gcd(gcdValue, divisor);  
	  
	if (newGCD == 1)  
	  return false;  
		
	if (divisor / newGCD == 1)  
	  return true;  
	  
	return recursiveCheck(newGCD, divisor / newGCD);  
}  
  
bool processDivisor(int divisor, int gcdValue)  
{  
   if (divisor < gcdValue)  
   {  
	  if (gcdValue % divisor == 0)  
		 return true;  
   }  
   return recursiveCheck(gcdValue, divisor);  
}  
  
  
bool checkPair(int a, int b) {  
	  
	if (a == b)  
	  return true;  
		
	int gcdValue = gcd(a, b);  
	  
	  
	if (gcdValue == 1)  
	  return false;  
	  
	 return processDivisor( a / gcdValue, gcdValue ) && processDivisor ( b / gcdValue, gcdValue );  
	  
}  
  
int solution(vector<int> &A, vector<int> &B) {  
	  
	const int N = static_cast<int>(A.size());  
	  
	int count = 0;  
	  
	for (int i = 0; i < N; i++)  
	{  
	   if (checkPair(A[i], B[i]))  
		  count++;  
	}  
	  
	return count;  
}  
