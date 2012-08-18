#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void merge(int *ar1, int len1, int *ar2, int len2, int *output);
void print_array(int array[], int length);
int *merge_sort(int *ar, int len, int *swap_space);


int main() {

    int len, i; 
//    int array[] = {6,1,8,3,5,7,2,4};
//    int array[] = {7,6,5,4,3,2,1,0};
//    int array[] = {6,5,4,3,2,1,0};
//    int array[] = {6,1,5,6,-3,2,1,0};
//    len = 8; 
    len = 2000000;
    len = 20;
    int array[len];
    for(i = 0; i < len; ++i)
        array[i] = len - i;

//    int *for_merging = (int *) malloc(len * sizeof(int));
    void *heap_array = malloc(len * sizeof(int));
    int *for_merging = (int *) heap_array; 
    merge_sort(array, len, for_merging);
    free(heap_array);
    
    print_array(array, len);
    return 0;
}

int *merge_sort(int *ar, int len, int *swap_space) {
    int *ar1 = ar;
    int len1 = len/2;
    int *ar2 = &ar[len/2];
    int len2 = len - len1;
    if (len <= 1)
        return ar;
    else {
        merge(merge_sort(ar1, len1, swap_space), len1, merge_sort(ar2, len2, swap_space), len2, swap_space);
        memcpy(ar, swap_space, len * sizeof(int));
    }
    return ar;
}

void print_array(int *array, int length){
    int i;
    for (i=0; i<length; i++)
        printf("%i ", array[i]);
    printf("\n");
}

void merge(int *ar1, int len1, int *ar2, int len2, int *output) {
//    printf("Merging lengths %i and %i. \n", len1, len2);
    int index1 = 0;
    int index2 = 0;
    int len = len1 + len2;
    int i;
    for (i = 0; i<len; i++) {
        if (index1 >= len1) {
            output[i] = ar2[index2];
            ++index2;
        }
        else if (index2 >= len2) {
            output[i] = ar1[index1];
            ++index1;
        }
        else if (ar1[index1]<ar2[index2]) {
            output[i] = ar1[index1];
            ++index1;
        }
        else {
            output[i] = ar2[index2];
            ++index2;
        }
    }
}
