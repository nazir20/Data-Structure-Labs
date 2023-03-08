#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// functions declaration
void print_menu();
void search_student(struct Ogrenci ogrenciler[], int ogrenci_sayisi);
void calculate_average(struct Ogrenci ogrenciler[], int ogrenci_sayisi);
bool compare_averages(struct Ogrenci ogrenci1, struct Ogrenci ogrenci2);
void sort_averages(struct Ogrenci ogrenciler[], int ogrenci_sayisi);

// student struct
struct Ogrenci{
    
    string ad;
    int ogrenci_no;
    float ortalama;
    
};


int main()
{
    int ogrenci_sayisi, menu;
    cout << "Öğrenci sayısını giriniz: ";
    cin >> ogrenci_sayisi;
    cout << "- -  - - - - - - - - - - - - \n\n";
    
    Ogrenci ogrenciler[ogrenci_sayisi];
    
    for(int i = 0; i<ogrenci_sayisi; i++){
        
        cout << "Öğrenci bilgilerini giriniz "<<i+1<<" : \n";
        cout << "Ad: ";
        cin>> ogrenciler[i].ad;
        cout << "Öğrenci numarası: ";
        cin >> ogrenciler[i].ogrenci_no;
        cout << "Ortalama: ";
        cin >> ogrenciler[i].ortalama;
        cout << "- - -\n";
        
    }
    
    do{
        
        print_menu();
        
        do{
            
            cout << "giriniz: ";
            cin >> menu;
            if(menu > 4 || menu <1){
                cout << "Geçersiz istek...\n(1-4) Arasında bir sayı giriniz!\n";
            }
            
        }while(menu > 4 || menu <1);
        
        if(menu ==1){
            
            search_student(ogrenciler, ogrenci_sayisi);
            
        }else if(menu == 2){
            
            sort_averages(ogrenciler, ogrenci_sayisi);
            
        }else if(menu ==3){
            
            calculate_average(ogrenciler, ogrenci_sayisi);
            
        }
        
    }while(menu != 4);
    
    cout << "Başarılı Çıkış...\n";
    
    return 0;
    
}



void print_menu(){
    
    cout << "\n\n***********************************************\n";
    cout << "*** Öğrenci numarasına gore öğrenci aramak için 1 girin.\n";
    cout << "*** Öğrencileri ortalamalarına göre sıralamak için 2 girin\n";
    cout << "*** Tüm öğrencilerin ortalamalarını hesaplamak için 3 girin\n";
    cout << "*** Çıkış yapmak için 4 girin\n";
    
}



void search_student(struct Ogrenci ogrenciler[], int ogrenci_sayisi){
    
    int ogrenci_numarasi;
    Ogrenci aranan_ogrenci;
    bool ogrenci_var = false;
    
    cout << "Aramak istediğiniz öğrenci\'nin öğrenci numarasını giriniz: ";
    cin >> ogrenci_numarasi;
    
    for(int i = 0; i<ogrenci_sayisi; i++){
        
        if(ogrenciler[i].ogrenci_no == ogrenci_numarasi){
            
            aranan_ogrenci = ogrenciler[i];
            ogrenci_var = true;
            
        }
    }
    
    if(ogrenci_var){
        
        cout << "Öğrenci Adı: "<< aranan_ogrenci.ad <<endl;
        cout << "Öğrenci Numarası: " << aranan_ogrenci.ogrenci_no<<endl;
        cout << "Öğrenci Ortalaması: "<< aranan_ogrenci.ortalama<<"\n\n";
        
    }else{
        
        cout << "Öğrenci bulunmadı...\n";
        
    }
    
}



void calculate_average(struct Ogrenci ogrenciler[], int ogrenci_sayisi){
    
    float tum_ortalama=0, toplam=0;
    
    for(int i = 0; i<ogrenci_sayisi; i++){
        
        toplam += ogrenciler[i].ortalama;
        
    }
    
    tum_ortalama = toplam/ogrenci_sayisi;
    cout << "Tüm Ortalama: "<< tum_ortalama<<endl;
    
}



bool compare_averages(struct Ogrenci ogrenci1, struct Ogrenci ogrenci2){
    
    return ogrenci1.ortalama > ogrenci2.ortalama ? 1: 0;
    
}



void sort_averages(struct Ogrenci ogrenciler[], int ogrenci_sayisi){
    
    sort(ogrenciler, ogrenciler+ogrenci_sayisi, compare_averages);
    
    cout << "\n\n---Öğrencilerin, ortalamalarına göre sıralanması---\n";
    for(int i = 0; i<ogrenci_sayisi; i++){
        
        cout << ogrenciler[i].ad << " | " << ogrenciler[i].ogrenci_no << " | "<< ogrenciler[i].ortalama <<endl;
        
    }
    
}

