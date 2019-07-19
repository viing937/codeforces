#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long long MOD = 998244353;

long long mul(long long a, long long b)
{
    return (a * b) % MOD;
}

long long add(long long a, long long b)
{
    return (a + b) % MOD;
}

long long calculate(long long num, long long k, long long v)
{
    long long acc = 0;
    long long base = 1;
    for (int _ = 0; num && _ < k; _++)
    {
        acc = add(acc, mul(mul((num % 10), base), v));
        base = mul(base, 10);
        acc = add(acc, mul(mul((num % 10), base), v));
        base = mul(base, 10);
        num /= 10;
    }
    while (num)
    {
        acc = add(acc, mul(mul((num % 10), base), v));
        acc = add(acc, mul(mul((num % 10), base), v));
        base = mul(base, 10);
        num /= 10;
    }
    return acc;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, long long> length_cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        length_cnt[to_string(a[i]).length()] += 1;
    }

    long long rls = 0;
    for (long long num : a)
        for (auto [k, v] : length_cnt)
            rls = add(rls, calculate(num, k, v));

    cout << rls << endl;
    return 0;
}