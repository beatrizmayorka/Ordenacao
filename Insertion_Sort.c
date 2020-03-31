#include <stdio.h>
#include <stdlib.h>      
#include <time.h>      
#include <string.h>

#define MAX_NUMBER 100
#define SIZE 100

int * insertionSort(int arr[]);

void swap(int *xp, int *yp);


void  measure(int elements[SIZE],char algorithm[], int * (*f)(int*));
  
void showValues(int elements[SIZE]);
void startValues(int elements[SIZE]);

int main() {
	int values[SIZE];

	startValues(values);
	
	measure(values,"Insertion",insertionSort);

}


int * insertionSort(int arr[]) { 
    int i, key, j, n; 
    n = SIZE;
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
    return arr;  
}  


void showValues(int elements[SIZE]) {
   int i;
   for( i = 0; i < SIZE; i++) {
       printf("%d -> %d \n",i,elements[i]);
   }
}

void measure(int elements[SIZE],char algorithm[], int * (*f)(int*)) {

    size_t temp_size = sizeof(*(elements)) * (SIZE);
    clock_t begin,end;
    double time_spent;
    
    int * copy = malloc(temp_size);
    memcpy(copy, elements, temp_size);
    
    // EXECUTA A ORDENAÇAO E MEDE
    
    begin = clock();
    
    (*f)(copy);

    end = clock();
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(" > As defenicoes da execucao sao de: %d", SIZE); // Mostra as definicoes de MAX ou SIZE ....
    printf("\n > O %s levou %fs para terminar \n\n\n\n  ", algorithm, time_spent); // COLOCA NA TELA O VALOR
    free( copy );
}

// GERA VALORES RANDOMICOS

void startValues(int elements[SIZE]) {
   int i;
   srand (time(NULL));	  
   for( i = 0; i < SIZE; i++) {
       elements[i] = rand() % MAX_NUMBER;	
   }
}

void swap(int *xp, int *yp)  {  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
