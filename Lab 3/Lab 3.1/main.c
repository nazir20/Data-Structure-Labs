#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int **rptr;
    int *aptr, *testptr;
    int k;
    int nrows = 5, ncols = 5; /* Hem nrows hem de ncols sayısı önceden tanımlanmıştır */
    int row, col;
    
    /* aptr icin malloc() kullanarak belleği dinamik olarak ayır */
    aptr = (int*)malloc((nrows * ncols) * sizeof(int));
    
    /* Belleğin malloc tarafından başarılı bir şekilde tahsis edilip edilmediği kontrol ediliyor */
    if(aptr == NULL){
        puts("\nDizi icin yer ayrilmadi");
        exit(0);
    }else{

        /* rptr icin malloc() kullanarak belleği dinamik olarak ayır */
        rptr = (int**)malloc(nrows * sizeof(int*));
        /* Pointer işaretlenir */
        for(k = 0; k<nrows; k++){
            rptr[k] = aptr + (k * ncols);
        }  

        /* satır pointerlerinin nasıl arttırıldığını gösterilir */
        printf("\n\nPointerlerin arttirilmasi\n\n");
        printf("Index Pointer(hex).(dec)");
        for(row = 0; row<nrows; row++){
            printf("\n%d\t\t%p", row, rptr[row]);
            if(row > 0){
                printf("\t\t\t%d", (rptr[row] - rptr[row-1]));
            }
        }

        printf("\n\nDizinin yazdırılması\n");
        for(row = 0; row<nrows; row++){
            for(col = 0; col<ncols; col++){
                rptr[row][col] = row + col;
                printf("%d ", rptr[row][col]);
            }
            putchar('\n');
        }
        puts("\n");

        /* Burada bitişik bir bellek bolğunda 2 boyutlu bir dizi ile uğrasıldığı gösterilir */
        printf("Ve şimdi bellekte bitişik oldukları gösterilir\n");
        testptr = aptr;
        for(row = 0; row < nrows; row++ ){
            for(col = 0; col < ncols; col++){
                printf("%d ", *(testptr++));
            }
            putchar('\n');
        }

        /* Belleği boşalt */
        free(aptr);
        free(rptr);
        printf("\nBellek başarıyla boşaltmıştır.\n");
    }

    return 0;
}