#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void countCoprime(int n)
{
    int count = 0;
    
    for (int i = 2; i <= sqrt(n); i++) {
 
        if (n % i == 0) {
 
            
            if (gcd(i, n) == 1) {
                count++;
            }
        }
    }
 
    cout << count;
}
 
int main()
{
    int N;
    cin >> N;
    countCoprime(N);
 
    return 0;
}
