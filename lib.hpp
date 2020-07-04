#include <bits/stdc++.h>
using namespace std;
/*
  ifstream in_str_io("in");
  ofstream out_str_io("out");
  #define cout out_str_io
  #define cin in_str_io
  #endif //*/
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
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define mod(a) ((a)%(MOD))
#define $ '\n'
#define last(con) if(con)break
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define coutop(type, code) \
    ostream &operator << (ostream &out, const type &_) { \
        {code}\
        return out;\
    } 
#define cinop(type, code) \
    istream &operator >> (istream &in, type &_) { \
        {code}\
        return in;\
    }
template<class T>T gcd(T a,T b){while(a&&b)if(a>b)a%=b;else b%=a;return a+b;}
template<class T>void sortf(vector<T>&v){stable_sort(v.begin(),v.end());}
template<class T>void sortb(vector<T>&v){stable_sort(v.rbegin(),v.rend());}
template<class T>T max3(T a,T b,T c){return max(a,max(b,c));}template<class T>T
min3(T a,T b,T c){return min(a,min(b,c));}template<typename T>istream&operator>>
(istream&in,vector<T>&v){for(T&t:v)in>>t;return in;}ostream&operator<<(ostream&
out,const vector<char>&v){for(const char&t:v)out<<t;out<<endl;return out;}
template<typename T>ostream&operator<<(ostream&out,const vector<T>&v){for(const
T&t:v)out<<t<<' ';return out;}static void init_iostream_speed(){cin.tie(nullptr)
;cout.tie(nullptr);ios::sync_with_stdio(false);}template<typename T>T lcm(T a,T
b){return a*b/gcd(a,b);}template<class T>void swap(T*a,T*b){T c=*a;*a=*b;*b=c;}
template<typename T>class vector2:public vector<T>{public:int min_ind(){return
min_element(this->begin(),this->end())-this->begin();}int max_ind(){return
max_element(this->begin(),this->end())-this->begin();}T min(){return*min_element
(this->begin(),this->end());}T max(){return*max_element(this->begin(),this->end(
));}void sortf(){::sortf(*this);}void sortb(){::sortb(*this);}vector2():vector<T
>(){}vector2(vector<T>__v):vector<T>(__v){}vector2(initializer_list<T>__i_l):
vector<T>(__i_l){}vector2(size_t __n,size_t __val=0):vector<T>(__n,__val){}};
template<class T>T sum(const vector<T>&vc){T ans=0;for(const T&v:vc)ans+=v;
return ans;}int nextInt(){int t;cin>>t;return t;}ll nextLong(){ll t;cin>>t;
return t;}constexpr ll MOD=1000000007;bool operator<<(const string&a,const
string&b){if(a==b)return true;if(a.size()!=b.size())return a.size()<b.size();
return a<b;}int intlen(ll x){int res=1;while(x/=10)res++;return res;}string 
operator*(const string&s,int x){string a;while(x--)a+=s;return a;}ll factorial(
int x){ll a=1;for(int i=1;i<=x;i++)a*=i;return a;}template<class T>T reverse(T o
){reverse(all(o));return o;}

template<class T>struct reader:public T{template<class...Con>reader(Con&&...par)
:T(par...){cin>>*this;}};template<>class reader<int>{int x;public:reader(){cin>>
x;}operator int(){return x;}};

class TaskAnswer{};void answer(){cout<<$;throw TaskAnswer();}template<class C,
class...Ts>void answer(C&&cur,Ts&&...args){cout<<cur;answer(args...);}class
Answerer{private:ostream&out;void operator()(){out<<$;throw TaskAnswer();}
public:Answerer(ostream&os):out(os){}template<class C,class...Ts>void operator()
(C&&cur,Ts&&...args){out<<cur;this->operator()(args...);}};

veci pre_func(const string&s){int n=s.size();veci p(n);for(int i=1;i<n;i++){int
j=p[i-1];while(j>0&&s[j]!=s[i])j=p[j-1];if(s[i]==s[j])j++;p[i]=j;}return p;}int
knut(const string&s,const string&t){auto p = pre_func(s + '$' + t);int n=s.size(
),m=t.size();for(int i=n+1;i<=n+m;i++)if(p[i]==n)return i-n-n;return-1;}

#define FASTIO_PATTERN(op,type,code)fastio&operator op(type){code;return*this;}
class fastio{private:FILE*out=stdout;FILE*in=stdin;FILE *err = stderr;template<
class T>void write(const T&val){this->operator<<(val);}template<class T>void
read(T&val){this->operator>>(val);}template<class T>void error(const T&val){this
->operator<=(val);}public:fastio(){}~fastio(){}FASTIO_PATTERN(>>,char*val,scanf(
"%s",val))FASTIO_PATTERN(<<,const char*val,printf("%s",val))FASTIO_PATTERN(<=,
const char*val,fprintf(this->err,"%s",val))/*FASTIO_PATTERN(>>, int &val, scanf(
"%d", &val))FASTIO_PATTERN(<<, int val, printf("%d", val))*/FASTIO_PATTERN(>>,
long long&val,scanf("%lld",&val))FASTIO_PATTERN(<<,long long val,printf("%lld",
val))FASTIO_PATTERN(>>,long&val,scanf("%ld",&val))FASTIO_PATTERN(<<,long val,
printf("%ld",val))FASTIO_PATTERN(>>,short&val,scanf("%hd",&val))FASTIO_PATTERN(
<<,short val,printf("%hd",val))FASTIO_PATTERN(>>,char&val,scanf("%c",&val))
FASTIO_PATTERN(<<,char val,printf("%c",val))template<class T,class...AT>void
write(const T&val,const AT&...args){this->operator<<(val);this->write(args...);}
template<class T,class...AT>void read(T&val,AT&...args){this->operator>>(val);
this->read(args...);}template<class T,class...AT>void error(const T&val,const AT
&...args){this->operator<=(val);this->error(args...);}};
#undef FASTIO_PATTERN
template<class T>fastio&operator<<(fastio&out,const vector<T>&a){for(const T&x:a
)out<<x<<' ';return out;}template<class T>fastio&operator>>(fastio&in,vector<T>&
a){for(int&x:a)in>>x;return in;}fastio console;

class yesno{private:string yes,no;public:yesno(string y,string n):yes(y),no(n){}
string operator()(bool ok)const{return ok?this->yes:this->no;}};
template<class T>ostream&operator<<(ostream&out,const pair<T,T>&v){out<<v.fir<<
' '<<v.sec;return out;}template<class T>istream&operator>>(istream&in,pair<T,T>
&v){in>>v.fir>>v.sec;return in;}


Answerer fanswer(cout);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline void solve();
signed main() {
/**/    init_iostream_speed();
//**/    for(;;){try{solve();}catch(TaskAnswer){}cout<<endl;}
//**/    int t;cin>>t;while(t--)
        try{solve();}catch(TaskAnswer){}catch(...){cout<<"0\n";}
        cout.flush();
        return 0;
}

inline void solve() {

}
