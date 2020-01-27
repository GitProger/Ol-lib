#ifndef BUF
#define BUF 2048
#endif

class segment_tree {
    private:
        int *t, n;
    
        void build(const veci &a, int v = 1, int tl = 0, int tr = n - 1) {
            if (tl == tr) {
                t[v] = a[tl];
                return;
            }
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    
    public:
        segment_tree(const vector<int> &a) {
            this->n = a.size();
            this->t = new int[this->n + BUF];
            build(a);
        }
    
        int sum(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return t[v];
            int tm = (tl + tr) / 2;
            return sum(l, min(r, tm), v * 2, tl, tm)  +  sum(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
        }
    
        void assign(int pos, int new_val, int v = 1, int tl = 0, int tr = n - 1) {
            if (tl == tr) {
                t[v] = new_val;
                return;
            }
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                assign(pos, new_val, v * 2, tl, tm);
            else
                assign(pos, new_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
};
