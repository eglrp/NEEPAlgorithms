/**
* 问题：给定三个正整数a、b、m (a<10^9, b<10^18, 1<m<10^9)，求a^b % m
* 思路：快速幂（二分幂）
*       如果b是奇数，那么有a^b = a * a^(b-1)
*       如果b是偶数，那么有a^b = a^(b/2) * a^(b/2)
**/


/**
* 快速幂的递归写法
**/
typedef long long LL;
LL binaryPow(LL a, LL b, LL m) {
    if (b == 0)
        return 1; //如果b为0，那么a^0=1
    if (b % 2 == 1)
        return a * binaryPow(a, b - 1, m); //b为奇数，转换为b-1
    else {
        //b为偶数，转换为b/2
        LL mul = binaryPow(a, b / 2, m);
        return mul * mul % m;
    }
}

/**
* 快速幂的迭代写法
**/
typedef long long LL;
LL binaryPow(LL a, LL b, LL m) {
    LL ans = 1;
    while (b > 0) {
        //如果b的二进制末尾为1（也可以写成if(b % 2)）
        if (b & 1)
            ans = ans * a % m; //令ans累积上a
        a = a * a % m; //令a平方
        b >>= 1; //将b的二进制右移1位，即b = b >> 1或b = b / 2
    }
    return ans;
}
