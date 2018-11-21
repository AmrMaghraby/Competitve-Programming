/*
Editorial link :https://apps.topcoder.com/wiki/display/tc/SRM+569
*/
final int MOD = 1000000009;

long[][] C;    

// The number of times prime factor p appears in the factorization of N!k
long primeAppears(int N, int K, int p)
{
    long res = 0;
    // For each factor x:
    for (int x = 1 ; x <= N; x++) {
        int c = 0;
        int y = x;
        while ( y%p == 0) {
            y /= p;
            c++;
        }
        if (c > 0) {
            //how many times does this factor appear?
            res += (c * C[K + N - x - 1][N - x]  ) % MOD;
        }
    }
    return res % MOD;
}


int countDivisors(int N, int K)
{
    // Precalculate binomial coefficients using Pascal's triangle
    C = new long[K + N + 1][N + K + 1];
    for (int i=0; i<=K + N; i++) {
        C[i][0] = 1;
        for (int j=1; j<=i; j++) {
            C[i][j] = ( C[i-1][j-1] + C[i-1][j] ) % MOD;
        }
    }
    //for each prime between 1 and N: How many times does it appear in N!K?
    boolean[] composite = new boolean[N+1];
    long res = 1;
    // For each prime number i between 1 and N: (Use Erathostenes' Sieve)
    for (int i=2; i<=N; i++) {
        if (! composite[i]) {
            for (int j=i+i; j<=N; j+=i) {
                composite[j] = true;
            }
            res  = (res * (primeAppears(N,K, i ) + 1) ) % MOD;
        }
    }
    return (int)( res % MOD );

}
