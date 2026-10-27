#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

#define IF(cond, t, f) (cond ? t : f)
#define OFILE(finp, fout) freopen(finp, "r", stdin), freopen(fout, "w", stdout)
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define MULTI \
    int t;    \
    cin >> t; \
    while (t--)

int n, q;
vector<int> arr, pref1{0}, pref2{0};

int range(int v)
{
    int res = 0;
    int low = 0, high = v;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (mid * (mid + 1) / 2 <= v)
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}

int query(int l, int r)
{
    int l2 = range(l - 1);
    int r2 = range(r);

    int lMiss = l - 1 - (l2 * (l2 + 1) / 2);
    int rMiss = r - (r2 * (r2 + 1) / 2);

    int midSum = pref2[r2] - pref2[l2 + 1];
    int lSum = pref1[l2 + 1] - pref1[lMiss];
    int rSum = pref1[rMiss];

    return lSum + midSum + rSum;
}

void solve()
{
    cin >> n >> q;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n; i++)
    {
        pref1.push_back(arr[i] + pref1.back());
        pref2.push_back(pref1.back() + pref2.back());
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}

signed main()
{
    FAST_IO;

    // MULTI
    solve();

    return 0;
}
