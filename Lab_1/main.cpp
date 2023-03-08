#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
*
* @PROBLEM_1
* 1- Sıralı verilen iki diziyi birleştiren program kodunu yazınız.
* Input: dizi_1[] = { 1, 3, 4, 5}, dizi_2[] = {2, 4, 6, 8}
* Output: dizi_3[] = {1, 2, 3, 4, 4, 5, 6, 8}
*
*/

void combine_arrays(int arr1[],int arr1_length, int arr2[], int arr2_length){

    int combined_arr[arr1_length + arr2_length];
    int combined_arr_len = sizeof(combined_arr)/sizeof(int);
    int i =0, j = 0, k = 0;

    while(i<arr1_length){
        combined_arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j<arr1_length){
        combined_arr[k] = arr2[j];
        j++;
        k++;
    }

    /**Here we take two parameters, the beginning of the
    array and the length n up to which we want the array to
    be sorted*/
    sort(combined_arr, combined_arr + combined_arr_len);

    cout<<"dizi_3[] = {";
    
    for(int item: combined_arr){
        
        cout << item<<", ";
        
    }
    
    cout<<"}\n";
}






/**
*
* @PROBLEM_2
* 2- Sıralanmış bir diziden yinelenmiş olan sayıları kaldıran program kodunu yazınız.
* Input: dizi_1[] = { 0,0,1,1,1,2,2,3,3,4}
* Output: dizi_2[] = { 0,1,2,3,4}
*
*/

int remove_duplicates(int arr[], int arr_len){

    int new_arr[arr_len];
    int j = 0;

    for(int i = 0; i<arr_len-1; i++){
        // If current element is not equal to next element
        // then store that current element
        if(arr[i] != arr[i+1]){
            new_arr[j++] = arr[i];
        }
    }

    // Store the last element as whether it is unique or
    // repeated, it hasn't stored previously
    new_arr[j++] = arr[arr_len - 1];

    // Modify original array
    for (int i = 0; i < j; i++){
        arr[i] = new_arr[i];
    }
    return j;
}



/**
*
* @PROBLEM_3
* 3-  Klavyeden -1 giriline kadar, girilen sayıların ortalamalarını gösteren programı yazınız.
*
*/

void solve_problem_3(){

    int number, sum = 0;
    float average = 0;
    vector<int> entered_numbers;
    
    cout << "This program gives the average of numbers you\'re until you enter -1.\n";
    do{
        
        cout << "Enter a number: ";
        cin >> number;
        if(number != -1){
            sum += number;
            entered_numbers.push_back(number);
        }
        
    }while(number != -1);
    
    average = static_cast<float>(sum) / static_cast<float>(entered_numbers.size());
    
    if(entered_numbers.size() == 1){
        cout << "Exit successfully!\n";
    }else{
        cout << "Entered Numbers = {";
        for(int num: entered_numbers){
            cout << num << ", ";
        }
        cout<< "}\n";
        cout << "Sum of numbers = "<< sum <<endl;
        cout << "Average of numbers = " << average << endl;
    }
    
}



/**
*
* @PROBLEM_4
* 4- C/C++ ile Fonksiyon kullanarak Vize ve Final notu girilen öğrencinin ortalamasını hesaplayınız.
*
*/

void calculate_vize_final(){
    
    int vize, final;
    float ortalama = 0;
    
    cout << "--Vize ve Final notu girilen öğrencinin ortalamasını hesaplayan Program--\n";
    
    do{
        cout << "Vize notunuzu giriniz: ";
        cin >> vize;
        if(vize < 0 || vize > 100){
            cout << "Lütfen geçerli vize notu giriniz! (0-100): ";
            cin >> vize;
        }
    }while(vize < 0 || vize > 100);
    
    do{
        cout << "Final notunuzu giriniz: ";
        cin >> final;
        if(final < 0 || final > 100){
            cout << "Lütfen geçerli final notu giriniz! (0-100): ";
            cin >> final;
        }
    }while(final < 0 || final > 100);
    
    ortalama = static_cast<float>(vize * 0.4) +  static_cast<float>(final * 0.6);
    cout << "Vize Notu: "<<vize << endl;
    cout << "Final Notu: "<< final << endl;
    cout << "Ortalama: " << ortalama<<endl;
    
}




int main(){

    /** @first problem's solution */
    
    cout << "Problem 1 solution: \n- - - - - - - \n";
    int dizi_1[] = { 1, 3, 4, 5};
    int dizi_2[] = {2, 4, 6, 8};
    int dizi1_len = sizeof(dizi_1)/sizeof(int);
    int dizi2_len = sizeof(dizi_2)/sizeof(int);
    combine_arrays(dizi_1,dizi1_len, dizi_2, dizi2_len);
    


    /** @second problem's solution */
    
    cout << "\n\nProblem 2 solution: \n- - - - - - - \n";
    int arr[] = { 0,0,1,1,1,2,2,3,3,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    // removeDuplicates() returns new size of array.
    n = remove_duplicates(arr, n);
    cout << "dizi_3[] = {";
    for(int i = 0; i<n; i++){
        cout << arr[i] << ", ";
    }
    cout << "}"<<endl;
    


    /** @Third Problem's solution */
    
    cout << "\n\nProblem 3 solution: \n- - - - - - - \n";
    solve_problem_3();
    
    
    
    /** @Forth Problem's solution */
    
    cout << "\n\nProblem 4 solution: \n- - - - - - - \n";
    calculate_vize_final();

    return 0;

}
