#define BUF 100

class segment_tree {
    private:
        int *t;
        int n;
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
        int sum(int v = 1, int tl = 0, int tr = n - 1, int l, int r) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return t[v];
            int tm = (tl + tr) / 2;
           return sum(v * 2, tl, tm, l, min(r, tm))
                + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        }
        void assign(int v = 1, int tl = 0, int tr = n - 1, int pos, int new_val) {
            if (tl == tr) {
                t[v] = new_val;
                return;
            }
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                assign(v * 2, tl, tm, pos, new_val);
            else
                assign(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
};
