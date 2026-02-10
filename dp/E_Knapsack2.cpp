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
#define INF 105
#define MAXN 105
#else
#define debug(...) 42
#define INF 1e12
#define MAXN 100005
#endif

struct Item
{
    int value;
    int weight;
};

void solve()
{
    int n, maxW;
    cin >> n >> maxW;

    vector<vector<long long>> dp(n + 1, vector<long long>(MAXN, INF));
    vector<Item> items(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> items[i].weight >> items[i].value;
        dp[1][items[i].value] = items[i].weight;
    }

    dp[0][0] = 0;

    debug(dp);

    for (int i = 1; i <= n; ++i)
    {
        auto item = items[i];
        for (int v = 0; v < dp[i].size(); ++v)
        {
            dp[i][v] = dp[i - 1][v];
            if (item.value <= v)
                debug(i, v, item.value, dp[i - 1][v - item.value] + item.weight);
            if (item.value <= v && dp[i - 1][v - item.value] + item.weight <= maxW)
            {
                debug(item.value, v);
                dp[i][v] = min(dp[i - 1][v], dp[i - 1][v - item.value] + item.weight);
            }
        }

        vector<long long> row(dp[i].begin(), dp[i].begin() + 91);
        debug(row);
    }

    for (int i = dp[n].size() - 1; i >= 0; --i)
        if (dp[n][i] != INF)
        {
            cout << i;
            return;
        }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
