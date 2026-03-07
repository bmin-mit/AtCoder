#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), (void)cin.tie()
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

template <class T, class V>
ostream &operator<<(ostream &o, pair<T, V> p)
{
    return o << "(" << p.first << ", " << p.second << ")";
}

#define P(T, O, C)                          \
    template <class U>                      \
    ostream &operator<<(ostream &o, T<U> v) \
    {                                       \
        o << O;                             \
        int f = 0;                          \
        for (auto &i : v)                   \
            o << (f++ ? ", " : "") << i;    \
        return o << C;                      \
    }

#define Q(T, O, C)                             \
    template <class K, class V>                \
    ostream &operator<<(ostream &o, T<K, V> v) \
    {                                          \
        o << O;                                \
        int f = 0;                             \
        for (auto &i : v)                      \
            o << (f++ ? ", " : "") << i;       \
        return o << C;                         \
    }

P(vector, '[', ']')
P(set, '{', '}')
Q(map, '{', '}')

template <class T, size_t N>
ostream &operator<<(ostream &o, array<T, N> v)
{
    o << "[";
    int f = 0;
    for (auto &i : v)
        o << (f++ ? ", " : "") << i;
    return o << "]";
}

void dbg(const char *s) { cerr << endl; }

template <class T, class... A>
void dbg(const char *s, T v, A... a)
{
    const char *c = s;
    int b = 0;
    while (*c && (*c != ',' || b))
        b += bool(strchr("({[", *c)), b -= bool(strchr(")}]", *c)), c++;
    cerr.write(s, c - s) << " = " << v << (sizeof...(a) ? " |" : "");
    if (sizeof...(a))
        dbg(c + 1, a...);
    else
        cerr << endl;
}

#ifdef LOCAL
#define debug(...) dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

#define M 10007

int powMod(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    int half = powMod(a, b / 2) % M;

    if (b % 2 == 0)
        return (half * half) % M;
    else
        return (((half * half) % M) * a) % M;
}

int inv(int a)
{
    return powMod(a, M - 2);
}

int divideMod(int a, int b)
{
    int inverse = inv(b);
    return (a % M * inverse) % M;
}

int repeatDigit(int c, int l)
{
    int term = powMod(10, l);
    term = (term - 1 + M) % M;
    term = (term * c) % M;

    return divideMod(term, 9);
}

void solve()
{
    int k, m;
    cin >> k >> m;

    int num = 0;
    while (k--)
    {
        int c, l;
        cin >> c >> l;

        int pad = powMod(10, l);
        num = (num * pad) % M;

        int rep = repeatDigit(c, l);
        num = (num + rep) % M;
    }

    cout << divideMod(num, m) << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
