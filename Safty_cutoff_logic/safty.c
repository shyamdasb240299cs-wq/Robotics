#include <stdio.h>
#include <stdlib.h>

int main() {

    int t[6];
    int total = 0;

    for(int i=0;i<6;i++) {
        printf("Enter value for T%d: ", i+1);
        scanf("%d", &t[i]);
        total += t[i];
    }

    printf("Input: [");
    for(int i=0;i<6;i++) {
        printf("%d", t[i]);
        if(i<5) printf(", ");
    }
    printf("]\n");

    for(int i=0;i<6;i++) {
        if(t[i] > 230) {
            printf("VIOLATION: T%d exceeds max (%d > 230)\n", i+1, t[i]);
            t[i] = 230;
        }
    }

    for(int i=0;i<5;i++) {
        if(abs(t[i] - t[i+1]) > 80) {
            printf("VIOLATION: Difference between T%d and T%d\n", i+1, i+2);
            t[i] = t[i] * 0.9;
            t[i+1] = t[i+1] * 0.9;
        }
    }
    if(total > 900) {
        printf("VIOLATION: Total power %d > 900\n", total);
        for(int i=0;i<6;i++) {
            t[i] = t[i] * 0.9;
        }
    }
    printf("Clamped: [");
    for(int i=0;i<6;i++) {
        printf("%d", t[i]);
        if(i<5) printf(", ");
    }
    printf("]\n");

    return 0;
}