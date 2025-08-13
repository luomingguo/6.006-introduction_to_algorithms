#include <stdio.h>
#include <assert.h>
#include <string.h>

void compute_prefix(int *next, const char *pattern, int size) {
    assert(next);
    assert(pattern);
    assert(size > 1);
    next[0] = 0;
    int k = 0;
    for (int i = 1; i < size; i++) {
        while(k > 0 && pattern[k] != pattern[i]) {
            k = next[k-1];
        }
        if(pattern[k] == pattern[i]) {
            k++;
        }
        next[i] = k;
    }

    return;
}


void kmp_match(const char* text, int t_len, const char* pattern, int p_len) {

    int next[p_len];
    memset(next, 0, sizeof(next));
    compute_prefix(next, pattern, p_len);


    printf("next = [");
    for (int i = 0; i < strlen(pattern); i++) {
        printf(" %d", next[i]);
    }
    printf("]\n");


    int q = 0;
    for(int i = 0; i < t_len; i++) {
        while(q > 0 && pattern[q] != text[i]) {
            q = next[q-1];
        }
        if(pattern[q] == text[i]) {
            q++;
        }
        if(q == p_len) {
            printf("Pattern occurs with shift: %d\n", i - p_len + 1);
            q = next[q-1];
        }
        
    }
}



int main(int argc, char **argv) {
    char text[] = "aabaaaabaaf";
    const char pattern[] = "ababc";
    kmp_match(text, strlen(text), pattern, strlen(pattern));
    return 0;
} 