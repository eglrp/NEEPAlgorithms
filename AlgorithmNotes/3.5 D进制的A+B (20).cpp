#include <cstdio>
const int maxn = 31;

int main() {
    int A, B, D;
    int digit = 0; //数位
    int res[maxn]; //结果数组
    scanf("%d%d%d", &A, &B, &D);
    int C = A + B;
    if (D > 1 && D <= 10) {
        do {
            res[digit++] = C % D;
            C /= D;
        } while (C);
    }
    for (int i = digit - 1; i >= 0; i--)
        printf("%d", res[i]);
    return 0;
}
