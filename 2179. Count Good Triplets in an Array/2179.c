#include <stdlib.h> 
#include <string.h> 


/**
 * @brief 
 * @param bit 
 * @param n 
 * @param index 
 * @param val 
 */
void update(int* bit, int n, int index, int val) {
    index++; 
    while (index <= n) {
        bit[index] += val;
        
        index += index & (-index); 
    }
}

/**
 * @brief 
 * @param bit 
 * @param index 
 * @return 
 */
 
int query(int* bit, int index) {
    index++; 
    int sum = 0;
    while (index > 0) {
        sum += bit[index];
        
        index -= index & (-index);
    }
    return sum;
}


long long goodTriplets(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int n = nums1Size;
    long long totalGoodTriplets = 0;

    
    int* pos2_map = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        pos2_map[nums2[i]] = i;
    }

    
    int* A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        A[i] = pos2_map[nums1[i]];
    }
    
    free(pos2_map);

    long long* less_count = (long long*)calloc(n, sizeof(long long));
    int* bit_left = (int*)calloc(n + 1, sizeof(int)); 

    for (int j = 0; j < n; j++) {
        int val = A[j];
        
        if (val > 0) {
            less_count[j] = query(bit_left, val - 1);
        }

        update(bit_left, n, val, 1);
    }
    free(bit_left);

    long long* greater_count = (long long*)calloc(n, sizeof(long long));
    int* bit_right = (int*)calloc(n + 1, sizeof(int));

    for (int j = n - 1; j >= 0; j--) {
        int val = A[j];
                
        int total_seen = query(bit_right, n - 1);

        int leq_val = query(bit_right, val);

        greater_count[j] = total_seen - leq_val;
        update(bit_right, n, val, 1);
    }
    free(bit_right);

    for (int j = 0; j < n; j++) {
        totalGoodTriplets += less_count[j] * greater_count[j];
    }

    return totalGoodTriplets;
}