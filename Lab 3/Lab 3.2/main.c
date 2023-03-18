#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int nrows = 5, ncols = 5; /* Satır ve sütunların sayısı önceden tanımlanmıştır */
    int row, *rowPtr;

    /* malloc() kullanarak belleği dinamik olarak ayır */
    rowPtr = (int *)malloc(nrows * sizeof(int));
    
    /* Belleğin malloc tarafından başarılı bir şekilde tahsis edilip edilmediği kontrol ediliyor */
    if(rowPtr == NULL){
        puts("\n Pointer için satır ayırılamadı\n");
        exit(0);
    }else{
        
        printf("Malloc kullanılarak bellek başarıyla ayrıldı.\n");
        printf("\nIndex | Pointer(hex) | Pointer(dec) | .dec");
        
        for(row = 0; row < nrows; row++){
            
            rowPtr[row] = (int *)malloc(ncols * sizeof(int*));
            if(rowPtr[row] == NULL){
                printf("\n Satır için yer ayrılmaması [%d]\n", row);
                exit(0);
            }

            /* Dizinin yazdırılması */
            printf("\n%d %p %d", row, rowPtr[row], rowPtr[row]);
            if(row > 0){
                printf(" %d", (int)(rowPtr[row]-rowPtr[row-1]));
            }
        } 
        
        /* Belleği boşalt */
        free(rowPtr);
        printf("\nBellek başarıyla boşaltmıştır.\n");
    }
    return 0;
}