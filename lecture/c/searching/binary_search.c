#include <stdio.h>

typedef int elem_type;

int binary_serarch(elem_type* set, int n, elem_type key) {
    int low = 0;
    int high = n-1;
    int mid;
    while (low <= high) {
        mid  = (low + high) / 2;
        if (set[mid] == key) {
            return mid;
        }
        else if(set[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
    
}

int main() {
    elem_type set[] = {11, 22, 33, 44, 55, 66, 77, 88};
    int target = 44;
    int idx = binary_serarch(set, sizeof(set)/sizeof(int), target);
    if (idx >= 0)
        printf("found %d set[%d]\n", target, idx);
    else
        printf("no found %d in set\n", target);
    
    return 0;
}