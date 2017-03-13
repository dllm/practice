#include <stdio.h>
#include <stdlib.h>



 

int main() {
    
    int a[] = {1,2,3,4,5};
    int size = sizeof (a) / sizeof (a[0]);
    
    
   
    int products[size];

// Get the products below the current index
    int p=1;
    

    for(int i=0;i<size;++i) {
        products[i]=p;
        p*=a[i];
    }

// Get the products above the curent index
    p=1;
    for(int i=size-1;i>=0;--i) {
        products[i]*=p;
        p*=a[i];
    }
 
    
    for (int i = 0 ; i < size ; i++) {
        
        printf ("%d ", products[i]);
        
    }
    
    
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
return 0;
}
