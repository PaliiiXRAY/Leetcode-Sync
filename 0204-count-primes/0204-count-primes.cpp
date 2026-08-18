class Solution {
public:
//sieve's algo, basically we assume every number upto n is prime, by creating a vector array of n size with true values and then we implement sieve 
//1st outer loop and inner loop bounderies you need to understand, it's preety cool too
    int countPrimes(int n) {
     if (n <= 2) return 0;
   
     vector <int> isPrime(n , 1);
    int count = 1;
     for (long long i = 3; i*i < n; i+=2){
        if(isPrime[i]){
            for (long long j = i*i; j<n; j+=2*i){
                isPrime[j] = 0;
            }
        }
     }
     
     for (int i = 3;i<n; i+=2){
        if(isPrime[i]) count++;
     }
     return count;
    }
};