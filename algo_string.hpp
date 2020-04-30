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
        void add(const string &a) {
            vertex *cur = this->root;
            for (char c : a) {
                if (!cur->next[c])
                    cur->next[c] = new vertex();
                cur = cur->next[c];
            }
            cur->end = true;
        }
        bool find(const string &a) const {
            vertex *cur = this->root;
            for (char c : a) {
                if (!cur->next[c])
                    return false;
                cur = cur->next[c];
            }
           return cur->end;
        }
};


#endif /*__ALGO_STRING_HPP_INC MODULE */
