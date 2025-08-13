// 动态规划-切割钢管问题

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

static int* sol;

// 带备忘录的自顶向下方法
int memoized_cut_rod_aux(int *prices, int length, int* r) {
    if (r[length] > 0) {
        return r[length];
    }
    int opt_price;
    int opt_length;
    if (length == 0) {
        opt_price = 0;
    } else {
        opt_price = INT32_MIN;
        for (int i = 1; i <= length; i++) {
            if (opt_price < prices[i-1] + memoized_cut_rod_aux(prices, length-i, r)) {
                opt_price = prices[i-1] + memoized_cut_rod_aux(prices, length-i, r);
                opt_length = i;
            }
        }
    }
    sol[length] = opt_length;
    r[length] = opt_price;
    return opt_price;
}

int memorized_cut_rod(int *prices, int length) {
    int r[length+1];
    memset(r, 0, sizeof(r));
    for (int i = 1; i <= length; i++) {
        r[i] = INT32_MIN;
    }
    return memoized_cut_rod_aux(prices, length, r);
}

int bottom_up_cut_rod(int *prices, int length) {
    int r[length + 1];
    memset(r, 0, sizeof(r));

    for (int j = 1; j <= length; j++) {
        int opt_price = INT32_MIN;
        for (int i = 1; i <= j; i++) {
            if (opt_price < prices[i-1] + r[j-i]) {
                opt_price = prices[i-1] + r[j-i];
                sol[j] = i;
            }
        }
        r[j] = opt_price;
    }
    return r[length];
}



int main(int argc, char **argv) {
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    
    int length = 10;

    // 自顶向下
    sol = (int*) malloc((length+1) * sizeof(int));
    memset(sol, 0, length * sizeof(int));
    int up_bottom_opt_price;
    up_bottom_opt_price = memorized_cut_rod(prices, length);
    printf("Up to bottom optimal price is %d\n", up_bottom_opt_price);
    printf("Up to bottom solution: [");
    while (length > 0) {
        printf("%d ", sol[length]);
        length = length - sol[length];
    }
    printf("]\n");

    // 自底向上
    memset(sol, 0, length * sizeof(int));
    length = 10;
    int bottom_up_opt_price;
    bottom_up_opt_price = bottom_up_cut_rod(prices, length);
    printf("bottom to up optimal price is %d\n", bottom_up_opt_price);
    // print bottom to up solution
    printf("bottom to up solution: [");
    while (length > 0) {
        printf("%d ", sol[length]);
        length = length - sol[length];
    }
    printf("]\n");
    free(sol);
    return 0;
} 