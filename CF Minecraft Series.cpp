#include <bits/stdc++.h>

using i64 = long long;

constexpr int K = 1E6 + 2;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k, t;
    std::cin >> n >> m >> k >> t;
    
    const int N = n * m;
    std::vector<std::vector<int>> ap(N), an(N);
    
    std::bitset<K> fp, fn;
    for (int i = 1; i <= t; i++) {
        fp[i] = fn[i] = 1;
    }
    
    std::vector<int> cp(t + 1), cn(t + 1);
    cp[0] = cn[0] = 1;
    
    for (int i = 0; i < k; i++) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--;
        if (z && z > -t && z < t) {
            if (z > 0) {
                ap[x * m + y].push_back(z);
            } else {
                an[x * m + y].push_back(-z);
            }
        }
    }
    
    auto add = [&](int x, int y) {
        for (auto i : ap[x * m + y]) {
            if (!cp[i]++) {
                fp[i] = 0;
            }
        }
        for (auto i : an[x * m + y]) {
            if (!cn[i]++) {
                fn[i] = 0;
            }
        }
    };
    
    auto del = [&](int x, int y) {
        for (auto i : ap[x * m + y]) {
            if (!--cp[i]) {
                fp[i] = 1;
            }
        }
        for (auto i : an[x * m + y]) {
            if (!--cn[i]) {
                fn[i] = 1;
            }
        }
    };
    
    auto check = [&]() {
        return fp._Find_first() + fn._Find_first() >= t + 1;
    };
    
    std::vector len(n, std::vector<int>(m));
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        int x0 = i, x1 = i, y0 = 0, y1 = 0;
        int l = 0;
        fp = 1;
        fp = fn = ~fp;
        std::fill(cp.begin() + 1, cp.end(), 0);
        std::fill(cn.begin() + 1, cn.end(), 0);
        for (int j = 0; j < m; j++) {
            if (l && (i == 0 || l >= len[i - 1][j])) {
                l--;
            }
            l = std::min({l, n - i, m - j});
            while (y1 < j + l) {
                for (int i = x0; i < x1; i++) {
                    add(i, y1);
                }
                y1++;
            }
            while (y0 < j) {
                for (int i = x0; i < x1; i++) {
                    del(i, y0);
                }
                y0++;
            }
            while (x1 > i + l) {
                x1--;
                for (int i = y0; i < y1; i++) {
                    del(x1, i);
                }
            }
            while (!l || !check()) {
                l++;
                if (i + l > n || j + l > m) {
                    break;
                }
                while (y1 < j + l) {
                    for (int i = x0; i < x1; i++) {
                        add(i, y1);
                    }
                    y1++;
                }
                while (x1 < i + l) {
                    for (int i = y0; i < y1; i++) {
                        add(x1, i);
                    }
                    x1++;
                }
            }
            ans += std::min(n - i, m - j) - l + 1;
            len[i][j] = l;
        }
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
