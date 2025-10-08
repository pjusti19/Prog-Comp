#include <stdio.h>
#include <stdlib.h>

// Baseado no Crivo de Eratóstenes (descobri o que era quando fiz o código: https://pt.wikipedia.org/wiki/Crivo_de_Eratóstenes)
int countPrimes(int n) {
    
    if (n <= 2) 
        return 0;
    
    // calloc marcando todos como primos (0) 
    int* sieve = (int*) calloc(n, sizeof(int));
    if (!sieve) 
        return 0;

    // removendo não primos (1)
    sieve[0] = 1;
    sieve[1] = 1;

    for(int i = 2; i < sqrt(n); i++){
        // identificando os primos restantes
        if(sieve[i] == 0)
        {
            // removendo os múltiplos do n.  primo
            for(int j = i*i; j<n ; j+=i)
                sieve[j] = 1;
        }
    }
    
    int primes_count = 0;
    for(int i = 0; i < n; i++){
        if(sieve[i] == 0)
            primes_count++;
    }
    

    free(sieve);
    return primes_count;
}