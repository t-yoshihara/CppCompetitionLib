struct Culc {

    vector<int> factorial;
    int p;

    //階乗
    Culc(int N, int p_) {
        int ans = 1;
        p=p_;
        factorial.push_back(ans);
        for (int i = 1; i <= N; i++) {
            ans = ans * i % p;
            factorial.push_back(ans);
        }
    }

    int extgcd(int a, int b, int &x, int &y) {
        int g = a;
        if (b) {
            g = extgcd(b, a % b, y, x);
            y -= x * (a / b);
        } else {
            x = 1;
            y = 0;
        }
        return g;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    int inverse(int a, int p) {
        int x, y;
        extgcd(a, p, x, y);
        return ((x % p) + p) % p;
    }

//nCk mod p
//
    int combination(int n, int k, int p) {
        //set_factを呼んでから
        return factorial[n] * (inverse(factorial[k] * factorial[n - k] % p, p)) % p;
    }

};