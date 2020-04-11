#include <bits/stdc++.h>
using namespace std;
/////////////////
    //#define __FILE_IO_TASK
    #ifdef __FILE_IO_TASK
    ifstream in_str_io("in");
    ofstream out_str_io("out");
    #define cout out_str_io
    #define cin in_str_io
    #endif
    #define int ll
typedef long long ll;
typedef long double ld;
typedef long long var;
typedef pair<int,int>prii;
typedef pair<ll,ll>prll;
typedef vector<int>veci;
typedef vector<ll>vecl;
typedef vector<veci> graph;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef bitset<64> bits;
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define psh push_back
#define pp pop_back
#define all(a) a.begin(),a.end()
#define binser binary_search
#define qsort sort
#define msort stable_sort
#define hsort heap_sort
#define vec vector
#define forn(i,n) for(int i=0;i<(n);i++)
#define mod(a) ((a)%(MOD))
#define $ '\n'
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define coutop(type, code) \
    ostream &operator << (ostream &out, const type &__##type) { \
        {code}\
        return out;\
    } 
#define cinop(type, code) \
    istream &operator >> (istream &in, type &__##type) { \
        {code}\
        return in;\
    }

template <class T> T gcd(T a, T b) {
     while (a && b)
         if (a > b)
             a %= b;
         else 
             b %= a;
     return a + b;
}

template <class T> void sortf(vector<T> &v) {
    stable_sort(v.begin(), v.end());
}

template <class T> void sortb(vector<T> &v) {
    stable_sort(v.rbegin(), v.rend());
}

template <class T> T max3(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T> T min3(T a, T b, T c) {
    return min(a, min(b, c));
}

template <typename T> istream &operator>> (istream &in, vector<T> &v) {
     for (T &t : v)
         in >> t;
     return in;
}

ostream &operator<< (ostream &out, const vector<char> &v) {
    for (const char &t : v)
        out << t;
    out << endl;
    return out;
}

template <typename T> ostream &operator<< (ostream &out, const vector<T> &v) {
    for (const T &t : v)
        out << t << ' ';
    return out;
}

static void init_iostream_speed() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
}

template <typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template <class T> void swap(T *a, T *b) {
    T c = *a;
    *a = *b;
    *b = c;
}

template <typename T> class vector2 : public vector<T> {
    public:
        int min_ind() {
            return min_element(this->begin(), this->end()) - this->begin();
        }

        int max_ind() {
            return max_element(this->begin(), this->end()) - this->begin();
        }
    
        T min() {
            return *min_element(this->begin(), this->end());
        }
    
        T max() {
            return *max_element(this->begin(), this->end());
        }
    
        void sortf() {
            ::sortf(*this);
        }
    
        void sortb() {
            ::sortb(*this);
        }

        vector2() : vector<T>()
            {}
        vector2(vector<T> __v) : vector<T>(__v)
            {}
        vector2(initializer_list<T> __i_l) : vector<T>(__i_l)
            {}
        vector2(size_t __n, size_t __val = 0) : vector<T>(__n, __val)
            {}
};

template <class T> T sum(const vector<T> &vc) {
    T ans = 0;
    for (const T &v : vc)
        ans += v;
    return ans;
}

int nextInt() {
    int t;
    cin >> t;
    return t;
}

ll nextLong() {
    ll t;
    cin >> t;
    return t;
}

constexpr ll MOD = 1000000007;

bool operator << (const string &a, const string &b) { // compare strings as integers  "34" << "100" <=> 34 <= 100
    if (a == b)
        return true;
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int intlen(ll x) {
    int res = 1;
    while (x /= 10)
        res++;
    return res;
}

string operator * (const string &s, int x) {
    string a;
    while (x--)
        a += s;
    return a;
}

ll factorial(int x) {
    ll a = 1;
    for (int i = 1; i <= x; i++)
        a *= i;
    return a;
}

template <class T> T reverse(T obj) {
    reverse(all(obj));
    return obj;
}

template <class T> struct reader : public T {
    template <class ...Con> reader(Con &&...par) : T(par...) {
          cin >> *this;
    }
};

template <> class reader<int> {
    int x;
    public:
        reader() {
            cin >> x;
        }
        operator int() {
            return x;
        }
};

class TaskAnswer
    {};

void answer () {
    cout << $;
    throw TaskAnswer();
}
template <class C, class ...Ts> void answer(C &&cur, Ts &&...args) {
    cout << cur;
    answer(args...);
}

class Answerer {
    private:
        ostream &out;
        void operator() () {
             out << $;
             throw TaskAnswer();
        }
    public:
        Answerer(ostream &os) : out(os)
            {}
        template <class C, class ...Ts> void operator() (C &&cur, Ts &&...args) {
            out << cur;
            this->operator()(args...);
        }
};

struct Fenwick { // + -> min, to prefix min
    int *t, n;
    ~Fenwick() { delete[] t; }
    Fenwick(const vector<int> &a) : n(a.size()) {
        t = new int[n];
        for (int i = 0; i < n; i++)
            set(i, a[i]);
    }
    void set(int i, int val) {
        for (; i < n; i |= (i + 1))
            t[i] = t[i] + val;
    }    
    int get(int r) const {
        int s = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            s = s + t[r];
        return s;
    }
    int operator [] (int p) const { return get(p); }
    int operator () (int l, int r) const
        { return get(r) - get(l - 1); }
};


veci prefix_function(string s) {
    int n = s.size();
    veci p(n);
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

veci z_func(const string &s) {
    int n = (int)s.size();
    veci z(n);
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

int knut(string s, string t) {
    auto p = prefix_function(s + '$' + t);
    int n = s.size(), m = t.size();
    for (int i = n + 1; i <= n + m; i++)
        if (p[i] == n)
            return i - n - n;
    return -1;
}

class yesno {
    private:
        string yes, no;
    public:
        yesno(string y, string n) : yes(y), no(n)
            {}
        string operator () (bool ok) const {
             return ok ? this->yes : this->no;
        }
};

template <class ResType, class InputType> vector<ResType>
Map(ResType (*func)(InputType), const vector<InputType> &was) {
    vector<ResType> res;
    res.reserve(was.size());
    for (const auto &e : was)
        res.push_back(func(e));
    return res;
}

template <class Seq> class poly_hash {
    private:
        const int M = MOD;
        int seed, n;
        vector<int> pows, hsh;
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

Answerer fanswer(cout);
mt19937 rnd(228);

inline void __main_task();
signed main() {
/**/    init_iostream_speed();
//**/    for (;;) { try { __main_task(); } catch (TaskAnswer) {} cout << endl; } /// DEBUG
//**/    int t; cin >> t; while (t--)                                            /// MULTITEST
        try {
            __main_task();
        } catch (TaskAnswer) {
        }
        cout.flush();
        return 0;
}

inline void __main_task() {
    reader<int> a, b;
    answer(a + b);
}
