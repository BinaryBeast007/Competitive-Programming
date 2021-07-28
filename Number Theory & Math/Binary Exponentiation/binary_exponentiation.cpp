// Binary Exponentiation
// Time Complexity - O(Log(pow))
// Explanation: if base is odd multiply result with base
// square the base and half the power eventually
// if base is 0 return the result
// Calculate : (base ^ pow) 
/*
    2^13 = 2*2^12
    2^13 = 2*4^6
*/

long long binExp(long long base, long long pow) {
    long long result = 1;
    while(pow > 0) {
        if(pow %2 == 1) {
            result *= base;
        }
        base *= base;
        pow /= 2;
    }
    return result;
}
// Binary Exponentiation Modulo M
// Time Complexity - O(Log(pow))
// Calculate : (base ^ pow) % M
long long binExp(long long base, long long pow, long long M) {
    long long result = 1;
    while(pow > 0) {
        if(pow %2 == 1) {
            result = (result * base) % M;
        }
        base = (base * base) % M;
        pow /= 2;
    }
    return result;
}
