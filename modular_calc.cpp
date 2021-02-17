const int MOD = 998244353;
const int N = 200043;
int fact[N];
int add(int x, int y)
{
    return (x%MOD + y%MOD) % MOD;
}
 
int sub(int x, int y)
{
    return add(x, MOD - y);
}
 
int mul(int x, int y)
{
    return (x%MOD * 1ll * y%MOD) % MOD;
}
 
int binpow(int x, int y)
{
    int z = 1;
    while(y > 0)
    {
        if(y % 2 == 1)
            z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}
 
int inv(int x)
{
    return binpow(x, MOD - 2);
}
 
 
 
int C(int n, int k)
{
    if(k > n)
        return 0;
    return mul(fact[n], inv(mul(fact[k], fact[n - k])));
}
void init(int n){
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = mul(i, fact[i - 1]);
}
 
 
 
