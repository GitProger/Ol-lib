#ifndef __ALGO_STRING_HPP_INC
#define __ALGO_STRING_HPP_INC

class Bor {
    private:
        struct vertex {
            std::map<char, vertex *> next;
            bool end;
        };
        vertex *root;
    public:
        Bor() {
            this->root = new vertex();
        }
        void add(const std::string &a) {
            vertex *cur = this->root;
            for (char c : a) {
                if (!cur->next[c])
                    cur->next[c] = new vertex();
                cur = cur->next[c];
            }
            cur->end = true;
        }
        bool find(const std::string &a) const {
            vertex *cur = this->root;
            for (char c : a) {
                if (!cur->next[c])
                    return false;
                cur = cur->next[c];
            }
           return cur->end;
        }
};

std::vector<int> prefix_function(const std::string &s) {
    int n = s.size();
    std::vector<int> p(n);
    for (int i = 1, j; i < n; i++) {
        j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

std::vector<int> z_func(const std::string &s) {
    int n = s.size();
    std::vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) 
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r= i + z[i] - 1;
        }
    }
    return z;
}

int knut(const std::string &s, const std::string t) {
    auto p = prefix_function(s + '$' + t);
    int n = s.size(), m = t.size();
    for (int i = n + 1; i <= n + m; i++)
        if (p[i] == n)
            return i - n - n;
    return -1;
}

template <class Seq> class poly_hash {
    private:
        const int M = 1000000007;
        int seed, n;
        std::vector<int> pows, hsh;
    public:
        poly_hash(const Seq &s) : seed(228), n((int)s.size()) {
            pows.push_back(1);
            for (int i = 1; i <= n; i++)
                pows.push_back((pows.back() * seed + M) % M);
            hsh = vector<int>(n + 1);
            for (int i = 0; i < n; i++)
                hsh[i + 1] = ((hsh[i] * seed + s[i]) % M + M) % M;       
        }
        int sub_hash(int l, int r) const {
            return ((hsh[r] - hsh[l] * pows[r - l]) % M + M) % M;
        }
};

#endif /*__ALGO_STRING_HPP_INC MODULE */
