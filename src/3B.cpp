#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, v;
    scanf("%d%d", &n, &v);
    vector<pair<int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int t, p;
        scanf("%d%d", &t, &p);
        if (t == 1)
            a.emplace_back(p, i+1);
        else
            b.emplace_back(p, i+1);
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    sort(b.begin(), b.end(), greater<pair<int, int>>());
    int i = 0, j = 0;
    while (v > 0 && i+j < n) {
        if (v == 1) {
            if (i < a.size()) {
                v -= 1;
                i += 1;
            }
            if (v == 0 && i > 1 && j < b.size() && a[i-1].first + a[i-2].first < b[j].first) {
                i -= 2;
                j += 1;
            }
            if (v == 1 && i > 0 && j < b.size() && a[i-1].first < b[j].first) {
                v -= 1;
                i -= 1;
                j += 1;
            }
            break;
        }
        else {
            if (i < a.size() && j < b.size()) {
                if (a[i].first * 2 > b[j].first) {
                    v -= 1;
                    i += 1;
                }
                else {
                    v -= 2;
                    j += 1;
                }
            }
            else if (i < a.size()) {
                v -= 1;
                i += 1;
            }
            else {
                v -= 2;
                j += 1;
            }
        }
    }
    int capacity = 0;
    for (int t = 0; t < i; t++)
        capacity += a[t].first;
    for (int t = 0; t < j; t++)
        capacity += b[t].first;
    printf("%d\n", capacity);
    bool first = true;
    for (int t = 0; t < i; t++) {
        if (first) {
            printf("%d", a[t].second);
            first = false;
        }
        else
            printf(" %d", a[t].second);
    }
    for (int t = 0; t < j; t++) {
        if (first) {
            printf("%d", b[t].second);
            first = false;
        }
        else
            printf(" %d", b[t].second);
    }
    puts("");
    return 0;
}
