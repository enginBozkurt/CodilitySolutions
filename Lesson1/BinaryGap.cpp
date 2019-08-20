// Right shift and bitwise and opeartion equals to 1.   
// Therefore we exploit this to get your gap ‘ends’ and then count the zeroes inbetween.  
// We use set a boolean to true after our first ‘1’ to skip trailing zeroes.  
// As long as n does not consist of 1s only:  


 int solution(int N) {  
 // write your code in C++14 (g++ 6.2.0)  
   
  unsigned int iCurrentNumZeroes = 0;  
  unsigned int iMaxNumZeroes =  0;  
  bool bStartCounting = false;  
    
  while(N) {  
      if(1 == (N & 1)) {  
          iMaxNumZeroes = (iCurrentNumZeroes > iMaxNumZeroes) ? iCurrentNumZeroes: iMaxNumZeroes;  
          iCurrentNumZeroes = 0;  
          bStartCounting = true;  
      }  
      else {  
          if(bStartCounting)  
            iCurrentNumZeroes++; //if digit is zero increment counter  
      }  
        
      N >>= 1; //set next digit to check  
  }  
    
  return  iMaxNumZeroes;  
 }