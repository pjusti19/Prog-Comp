#include <stdio.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    
    if(n <= 0)
        return false;
    
    if(1162261467 % n)
        return false;
    
    return true;
    
}

