#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
        assume it is sorted before!

 *   */
void twoSum(int* nums, int numsSize, int target) {

        int i = 0;
        int j = numsSize - 1;
        int res_i = 0;

        while (i < j ){

                if (nums[i] + nums[j] == target){
                        printf ("%d %d ", i, j);
                        printf ("\n");
                }
                if (nums[i] + nums[j] < target){
                        i++;
                }
                else {
                        j--;
                }

        }
}


int main (void){

        int num[] = {2,3,6,7,11,15};
        int target = 9;

        twoSum( num, sizeof(num)/sizeof(num[0]), target);


}
