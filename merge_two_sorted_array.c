void merge(int* nums1, int m, int* nums2, int n) {

        int i, j, result;

        i = m -1;
        j = m -1;
        result = n-1;

        while ( i >= 0 && j >= 0){
                if (nums1[i] > nums2[j]){
                        nums2[result--] = nums1[i--];
                }
                else {
                        nums2[result--] = nums2[j--];
                }
        }
        while (i >= 0 ){
                nums2[result--] = nums1[i--];
        }

        while (j >= 0 ){
                nums2[result--] = nums2[j--];
        }

}

int main (void){

        int num1[] = {0,2,6,7,11,15};
        int num2[] = {1,3,4,5,10,18, 0, 0, 0, 0, 0, 0};

        int size1 = sizeof(num1)/sizeof(num1[0]);
        int size2 = sizeof(num2)/sizeof(num2[0]);
        for (int i = 0; i < size1; i++ ){

                printf ("%d ", num1[i]);
        }
        printf ("\n");
        for (int i = 0; i < size2; i++ ){

                printf ("%d ", num2[i]);
        }
        printf ("\n");
        merge( num1, size1, num2, size2);
        for (int i = 0; i < size2; i++ ){

                printf ("%d ", num2[i]);
        }
}
