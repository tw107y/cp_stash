#include <iostream>
using namespace std;

// Sieve of Erathosthenes for a nloglogn computation of prime numbers up to n. Obtained from geeksforgeeks.
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize all entries it as true.
    // A value in prime[i] will finally be false if i is not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime.
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or equal to the square of it numbers which are multiple of p and are less than p^2 are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers.
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}


// Clean version
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}


// With prime factorisation (This is trash because memory blows up for large inputs (1e7))
bool marked[N+1];
vector<int> primefactorization[N+1];
void sieve() {
    for (int i = 2; i <= N; i++) {
        if (!marked[i]) {
            primefactorization[i].push_back(i);
            for (int j = 2*i; j <= N; j += i) {
            marked[j] = true;
            int tmp = j;
            while (tmp % i == 0) {
                primefactorization[j].push_back(i);
                tmp /= i;
            }
            }
        }
    }
}


// low memory usage with logn divisor/factorisation retrieval 
const int N = 1e7; // change the limits dummy
int spf[N + 1]; // smallest prime factor 
 
void sieve() {
    for (int i = 0; i <= N; i++)
        spf[i] = i;
    for (int i = 2; i <= N; i += 2)
        spf[i] = 2;
    for (long long i = 3; i <= N; i++) {
        if (spf[i] == i) {
        for (long long j = i * i; j <= N; j += i)
            spf[j] = i;
        }
    }
}
 
vector<long long> getDivisors(int n) {
    std::vector<long long> res{1};
    while (n > 1) {
        const int prime_factor = spf[n], d = res.size();
        int tmp = 1;
        for (; n % prime_factor == 0; n /= prime_factor) {
            tmp *= prime_factor;
            for (int i = 0; i < d; ++i) {
                res.emplace_back(res[i] * tmp);
            }
        }
    }
    return res;
}

vector<long long> getFactors(int n) { // Could be wrong cuz I just made it without testing xd
    std::vector<long long> res{1};
    while (n > 1) {
        const int prime_factor = spf[n];
        for (; n % prime_factor == 0; n /= prime_factor) {
            res.emplace_back(prime_factor);
        }
    }
    return res;
}
