#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double helper(double a, double b, double x, double y, double v) {
    return sqrt((a-x)*(a-x) + (b-y)*(b-y)) / v;
}

int main() {
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int x, y, v;
    cin >> x >> y >> v;
    double result = helper(a, b, x, y, v);
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> v;
        result = min(result, helper(a, b, x, y, v));
    }
    printf("%.10f\n", result);
    return 0;
}
