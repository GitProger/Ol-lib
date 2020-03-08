class segment_tree:
    def __init__(self, a, func):
        self.n = len(a)
        self.func = func
        self.t = [0 for _ in range(2 ** int(1 + ceil(log2(self.n))))]
        self.__build(a, 0, 0, self.n - 1)

    def __build(self, a, v, tl, tr):
        if tl == tr:
            self.t[v] = a[tl]
            return
        tm = (tl + tr) // 2;
        self.__build(a, v * 2 + 1, tl    , tm);
        self.__build(a, v * 2 + 2, tm + 1, tr);
        self.t[v] = self.func(self.t[v * 2 + 1], self.t[v * 2 + 2]);

    def __get(self, l, r, v, tl, tr):
        if l > r:
            return 0
        if l == tl and r == tr:
            return self.t[v]
        tm = (tl + tr) // 2;
        return self.func(
                   self.__get(l    , min(r, tm), v * 2 + 1, tl    , tm),
                   self.__get(max(l, tm + 1), r, v * 2 + 2, tm + 1, tr))
    
    def __assign(self, pos, new_val, v, tl, tr):
        if tl == tr:
            t[v] = new_val
            return
        tm = (tl + tr) // 2
        if pos <= tm:
            self.__assign(pos, new_val, v * 2 + 1, tl, tm)
        else:
            self.__assign(pos, new_val, v * 2 + 2, tm + 1, tr)
        self.t[v] = self.func(self.t[v * 2 + 1], self.t[v * 2 + 2])

    def get(self, l, r):
        return self.__get(l, r, 0, 0, self.n - 1)
    def assign(self, p, new_v):
        return self.__assign(p, new_v, 0, 0, self.n - 1)        
