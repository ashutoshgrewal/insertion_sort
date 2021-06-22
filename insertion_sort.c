#include <stdio.h>
#include <inttypes.h>
#include <string.h>

static inline void
print_arr (int a[], uint64_t size_of_arr)
{
    printf("\n");
    for (int i = 0; i < size_of_arr; i++) {
        printf("%d, ", a[i]);
    }
}

static void
sort_arr (int a[], uint64_t size_of_arr)
{
    int element;
    /*
     * Iterate all the elements of the (unsorted) array.
     */
    for (int i = 0; i < size_of_arr; i++) {
        /*
         * Insert the new element in sorted part of the array.
         */
        printf("\ni = %d", i);
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) {
                /*
                 * Elements are in sorted order, do nothing.
                 */
            } else {
                element = a[i];
                memmove(&a[j+1], &a[j], (i-j)*sizeof(int));
                a[j] = element;
            }
        }
        print_arr(a, size_of_arr);
    }
}

int
main() {
    int a[] = {1, 11, 93, -3, 72, 4, 11, 23, 300, 31, 21, 31};

    uint64_t size_of_arr =  sizeof(a)/sizeof(int);

    print_arr(a, size_of_arr);

    sort_arr(a, size_of_arr);

    print_arr(a, size_of_arr);

}

