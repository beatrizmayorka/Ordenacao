#include <stdio.h>
#include <stdlib.h>      
#include <time.h>      
#include <string.h>

#define MAX_NUMBER 100
#define SIZE 100


int * bubbleSort(int elements[]);

void swap(int *xp, int *yp);

void  measure(int elements[SIZE],char algorithm[], int * (*f)(int*));
  
void showValues(int elements[SIZE]);
void startValues(int elements[SIZE]);

int main() {
	int values[SIZE];

	startValues(values);
	
	measure(values,"Bolha",bubbleSort);

}

int * bubbleSort(int arr[])  {  
    int i, j;  
    int n = SIZE;
    
    for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++)  
         if (arr[j] > arr[j+1])  
              swap(&arr[j], &arr[j+1]);
              
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
    
    // executa a ordenação e mede
    
    begin = clock();
    
    (*f)(copy);

    end = clock();
    
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf(" > As defenicoes da execucao sao de: %d", SIZE); //Mostra as definicoes de MAX ou SIZE ....
    printf("\n > O %s levou %fs para terminar \n\n\n\n  ", algorithm, time_spent); //COLOCA NA TELA O VALOR
    free( copy );
}

//Gera Valores Randomicos

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
