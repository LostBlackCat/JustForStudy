#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007LL;
LL n,m;

struct matrix{
    static const int MATRIX_N = 11;
    LL a[MATRIX_N][MATRIX_N];
    int row, col;

    matrix():row(MATRIX_N),col(MATRIX_N){memset(a,0,sizeof(a));}
    matrix(int x, int y):row(x),col(y){memset(a,0,sizeof(a));}
    LL* operator [] (int x){return a[x];}
    matrix operator * (matrix x){
        matrix tmp(col, x.row);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++) if(a[i][j])//Ï¡Êè¾ØÕóÓÅ»¯
                for(int k = 0; k < x.col; k++) if (x[j][k]){
                    tmp[i][k] += a[i][j] * x[j][k];
                    //mult(a[i][j], x[j][k], MOD);
                    tmp[i][k] %= MOD;
                }
        return tmp;
    }
    void operator *= (matrix x){*this = *this * x;}
    matrix operator ^ (LL x){
        matrix ret(row, col);
        for (int i = 0; i < col; i++) ret[i][i] = 1;
        matrix tmp = *this;
        for (; x; x >>= 1, tmp *= tmp){if (x&1) ret *= tmp;}
        return ret;
    }
    void print(){
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++) printf("%lld ",a[i][j]);
            puts("");
        }
    }
};

int main() {
    LL n;
    matrix B(3, 1);
    while(scanf("%lld%lld%lld%lld", &B[0][0], &B[1][0], &B[2][0], &n) == 4) {
        matrix A(3, 3);
        A[0][0] = 0; A[0][1] = 1; A[0][2] = 0;
        A[1][0] = 0; A[1][1] = 0; A[1][2] = 1;
        A[2][0] = 0; A[2][1] = 1; A[2][2] = 1;
        A = A ^ n;
        matrix C(3, 1);
        C = A * B;
        printf("%lld\n", (C[0][0] + C[1][0] + C[2][0]) % MOD);
    }
    return 0;
}
