struct Culc {

    vector<long long> factorial;
    long long p;

    //階乗
    Culc(long long N, long long p_) {
        long long ans = 1;
        p=p_;
        factorial.push_back(ans);
        for (long long i = 1; i <= N; i++) {
            ans = ans * i % p;
            factorial.push_back(ans);
        }
    }

    long long extgcd(long long a, long long b, long long &x, long long &y) {
        long long g = a;
        if (b) {
            g = extgcd(b, a % b, y, x);
            y -= x * (a / b);
        } else {
            x = 1;
            y = 0;
        }
        return g;
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }

    long long inverse(long long a, long long p) {
        long long x, y;
        extgcd(a, p, x, y);
        return ((x % p) + p) % p;
    }

//nCk mod p
//
    long long combination(long long n, long long k, long long p) {
        //set_factを呼んでから
        return factorial[n] * (inverse(factorial[k] * factorial[n - k] % p, p)) % p;
    }

};