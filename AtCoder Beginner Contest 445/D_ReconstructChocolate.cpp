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
ostream &operator<<(ostream &o, pair<T, V> p);

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

template <class T, class V>
ostream &operator<<(ostream &o, pair<T, V> p)
{
    return o << "(" << p.first << ", " << p.second << ")";
}

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

int n, h, w;
struct Choco
{
    int w, h, pos;
};
vector<Choco> choco;

void solve()
{
    cin >> h >> w >> n;
    choco.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> choco[i].h >> choco[i].w;
        choco[i].pos = i + 1;
    }

    vector<pair<int, int>> ans(n);
    vector<Choco> chocoH(choco.begin(), choco.end()), chocoW(choco.begin(), choco.end());
    sort(chocoH.begin(), chocoH.end(), [](const Choco &a, const Choco &b)
         { return a.h > b.h; });
    sort(chocoW.begin(), chocoW.end(), [](const Choco &a, const Choco &b)
         { return a.w > b.w; });

    int hPtr = 0;
    int wPtr = 0;
    int padTop = 1, padLeft = 1;
    for (int i = 0; i < n; ++i)
    {
        int hRemain = h - padTop + 1;
        int wRemain = w - padLeft + 1;
        while (hPtr < n && ans[chocoH[hPtr].pos - 1].first)
            ++hPtr;
        while (wPtr < n && ans[chocoW[wPtr].pos - 1].first)
            ++wPtr;

        debug(i, hPtr, wPtr, padTop, padLeft, hRemain, wRemain);

        if (hPtr < n && chocoH[hPtr].h == hRemain)
        {
            ans[chocoH[hPtr].pos - 1].first = padTop;
            ans[chocoH[hPtr].pos - 1].second = padLeft;
            padLeft += chocoH[hPtr].w;
            ++hPtr;
        }
        else if (wPtr < n && chocoW[wPtr].w == wRemain)
        {
            ans[chocoW[wPtr].pos - 1].first = padTop;
            ans[chocoW[wPtr].pos - 1].second = padLeft;
            padTop += chocoW[wPtr].h;
            ++wPtr;
        }
    }

    for (auto &i : ans)
        cout << i.first << " " << i.second << endl;
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
