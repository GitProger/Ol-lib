#ifndef __LIGHT_STREAM_LIB_INC
#define __LIGHT_STREAM_LIB_INC
#include <stdio.h>
#include <typeinfo>

#define FASTIO_PATTERN(op, type, code) \
        fastio &operator op (type) { \
            code; \
            return *this; \
        }


class fastio {
    private: 
        FILE *out = stdout;
        FILE *in = stdin;
        FILE *err = stderr;
        template <class T> void write(const T &val) {
            this->operator<< (val);
        }
        template <class T> void read(T &val) {
            this->operator>> (val);
        }
        template <class T> void error(const T &val) {
            this->operator<= (val);
        }        
    public:
        fastio() {}
        ~fastio() {}

        /*fastio &operator >> (char *val) {
            scanf("%s", val);
            return *this;        
        }
        fastio &operator << (const char *val) {
            printf("%s", val);
            return *this;        
        }
        fastio &operator <= (const char *val) {
            fprintf(this->err, "%s", val);
            return *this;        
        }
        //*/

        FASTIO_PATTERN(>>, char *val, scanf("%s", val))
        FASTIO_PATTERN(<<, const char *val, printf("%s", val))
        FASTIO_PATTERN(<=, const char *val, fprintf(this->err, "%s", val))

        FASTIO_PATTERN(>>, int &val, scanf("%d", &val))
        FASTIO_PATTERN(<<, int val, printf("%d", val))
        FASTIO_PATTERN(>>, long long &val, scanf("%lld", &val))
        FASTIO_PATTERN(<<, long long val, printf("%lld", val))
        FASTIO_PATTERN(>>, long &val, scanf("%ld", &val))
        FASTIO_PATTERN(<<, long val, printf("%ld", val))
        FASTIO_PATTERN(>>, short &val, scanf("%hd", &val))
        FASTIO_PATTERN(<<, short val, printf("%hd", val))
        FASTIO_PATTERN(>>, char &val, scanf("%c", &val))
        FASTIO_PATTERN(<<, char val, printf("%c", val))
        
        template <class T, class ...AT> void write
                (const T &val, const AT &...args)
        {
            this->operator<< (val);
            this->write(args...);
        }
        
        template <class T, class ...AT> void read
                (T &val, AT &...args)
        {
            this->operator>> (val);
            this->read(args...);
        }

        template <class T, class ...AT> void error
                (const T &val, const AT &...args)
        {
            this->operator<= (val);
            this->error(args...);
        }        
};
fastio console;
/** - usage of another types:
 *  - example:
 *  fastio& operator << (light_stream &out, XTYPE val) {
 *      out << val.MEMBER;
 *      ...
 *      return out;
 *  }
 */
#undef FASTIO_PATTERN
#endif
