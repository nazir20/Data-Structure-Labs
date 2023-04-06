/*

1. Stack (yığın) veri yapısı, hangi mantığa göre çalışır, açıklayınız.
Cevap:
    Stack(Yığın) veri yapısı LIFO(Last In First Out)--Son giren, İlk Çıkan mantığına göre çalışıyor.
    Stack'e eklediğimiz son elaman ilk olarak ve ilk eklediğimiz eleman son olarak stack'ten alınabilir.
    Bu mantığın en bariz örneklerinden biri bilgisayar sisteminde ctrl+c ve ctrl+p komutlarının çalışma mantıpıdır.



2. Stack veri yapısı ile avantajlar ve dezavantajlar kısaca açıklayınız.
Cevap:
    Avantajları:
     * Yığın veri yapısının diziler veya bağlantılı listeler kullanılarak uygulanması kolaydır ve işlemlerinin anlaşılması ve uygulanması basittir.
     * Yığın, bitişik bir bellek bloğu kullanır, bu da onu diğer veri yapılarına kıyasla bellek kullanımında daha verimli hale getirir.
     * Yığın veri yapısı, öğeler yığının en üstüne eklenirken ve kaldırılırken öğelerin eklenmesi ve çıkarılması için hızlı erişim sağlar.
     * Yığın veri yapısı, metin editörleri, grafik tasarım araçları ve yazılım geliştirme ortamları gibi çeşitli uygulamalarda geri alma ve yineleme işlemlerini etkinleştirmek için kullanılır.

     Dezavantajları:
      * Yığın veri yapısı, elemanlarına rastgele erişime izin vermez ve sadece yığının tepesinden eleman eklemeye ve çıkarmaya izin verir. Yığının ortasındaki bir öğeye erişmek için üzerindeki tüm öğeler kaldırılmalıdır.
      * Yığın veri yapısı, yığına çok fazla öğe itilirse yığın taşmasına neden olabilir ve yığından çok fazla öğe çıkarsa yığının taşmasına neden olabilir.



3. FIFO (First-In, First-Out), LIFO (Last-In, First-Out) kavramlarını açıklayınız.
Cevap:
    FIFO: First In First Out -> Bu mantığa göre eklenen ilk eleman ilk olarak erişilebilir.
    LIFO: Last In First Out -> Bu mantığa göre eklenen son eleman ilk olarak erişilebilir.


4. LIFO mantığı ile çalışan bir diziye eleman ekleme ve diziden eleman çıkarma işlemlerini birer fonksiyon ile yazınız. Yazım diliniz C/C++ olabilir. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Yığını temsil edecek bir yapı */
struct Stack{
    int top;
    int capacity;
    int *stack_arr;
};

/* verilen kapasitede bir yığın oluşturma fonksiyonu */
struct Stack *createStack(int capacity){

    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->stack_arr = (int *)malloc(sizeof(stack->capacity * sizeof(int)));
    return stack;
    
}

/* Yığının boş olup olmadığını kontrol eden fonksiyon */
int isStackEmpty(struct Stack *stack){
    return stack->top == -1;
}

/* Yığının dolu olup olmadığını kontrol eden fonksiyon */
int isStackFull(struct Stack *stack){
    return stack->top == stack->capacity-1;
}

/* Yığına yeni eleman ekleme fonksiyonu*/
void addToStack(struct Stack *stack, int value){

    /* Yığın'a eleman ekleyebilmek için boş yeri olması gerekiyor */
    if(isStackFull(stack)){
        printf("Yığın dolu'dur. Eleman ekleyebilmek için bir elemanı silmeniz gerekiyor\n\n");
        return;
    }

    /* Yığında boş yer varsa, top değerini bir arttrıp elemanı ekle */
    stack->top++;
    stack->stack_arr[stack->top] = value;
    printf("Yeni eleman başarıyla yığına eklendi!\n\n");
}

/* Yığından eleman silme işlemi */
void removeFromStack(struct Stack *stack){

    if(isStackEmpty(stack)){
        printf("Yığın boş'tur. Eleman silemezsiniz\n\n");
        return;
    }

    stack->stack_arr[stack->top--];
    printf("Eleman başarıyla silindi\n\n");
}

/* Yığını yazdır */
void print_stack(struct Stack *stack){

    if(isStackEmpty(stack)){
        printf("\nYığın boş'tur\n");
        return;
    }

    printf("\nYığın = { ");
    for(int i = stack->top; i>=0; i--){
        printf("%d, ", stack->stack_arr[i]);
    }
    printf(" }\n\n");
}

void menu(){

    printf("\n- - - - - Menü - - - - - - \n");
    printf(" 0 - Çıkış\n");
    printf(" 1 - Yığın'a eleman ekle\n");
    printf(" 2 - Yığından eleman sil\n");
    printf(" 3 - Yığını yazdır\n");
    
}


int main(void) {

    /* variables */
    int stackCapacity, userChoice, newItem;
    bool shouldContinue = true;

    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("| - - - - - - - - - - - -  Yığın - - - - - - - - - - - - - -|\n");
    printf("| - - - - - - - - - - - Uygulaması - - - - - - - - - - - - -|\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n");
    
    do{
        printf("Yığın kapasitesini giriniz: ");
        scanf("%d", &stackCapacity);
        
        if(stackCapacity <=0)
            printf("Lütfen geçerli bir sayıı girirniz!\n");
        
    }while(stackCapacity <= 0);

    struct Stack *stack = createStack(stackCapacity);
    while(shouldContinue){

        menu();
        printf("Seçiminizi giriniz: ");
        scanf("%d", &userChoice);

        switch(userChoice){

            case 0:
                printf("\nÇıkış Yapıldı...\n");
                shouldContinue = false;
                break;

            case 1:
                printf("\nEklemek istediğiniz elemanı giriniz: ");
                scanf("%d", &newItem);
                addToStack(stack, newItem);
                print_stack(stack);
                break;

            case 2:
                removeFromStack(stack);
                print_stack(stack);
                break;

            case 3:
                print_stack(stack);
                break;
                
            default:
                printf("\nÇıkış Yapıldı...\n");
                shouldContinue = false;
                break;
        }
        puts("\n\n");
    }
    

    return 0;
}