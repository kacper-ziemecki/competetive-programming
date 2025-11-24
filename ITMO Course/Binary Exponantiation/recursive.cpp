long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b >> 1);
    if (b&1)
        return res * res * a;
    else
        return res * res;
}