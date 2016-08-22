#include<iostream>  
using namespace std;      
const long N = 100000;     
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};     
int main()      
{       
    for(long i = 2 ; i < N ; i ++)         
    {              
        if(! isNotPrime[i])
		{
			prime[num_prime ++]=i; 
		}                              
        //¹Ø¼ü´¦1          
        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)  
        {                 
            isNotPrime[i * prime[j]] = 1;    
            if( !(i % prime[j] ) )  //¹Ø¼ü´¦2                                 
			{
				break; 
			}               
        }          
    }
    return 0;     
}
bool prime[N];    
memset(prime, true, sizeof(prime));
prime[0] = prime[1] = false;

for(int i=2; i*i<maxn; i++) {
　　if(prime[i])
　　　　for(int j=i*i; j<maxn; j += i) {
  　　　　  prime[j] = false;
　　　　}
}
