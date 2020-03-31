#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
 
void quick_sort(int *a, int left, int right);
int main(int argc, char** argv)
{
 int i, vet[MAX];
 
 
 
 //Gera Valores Randomicos
	srand (time(NULL));
 	for(i = 0; i < MAX; i++){
 	 printf("", rand() % 100);
  	vet[i] = rand();

 }
 
 //--------------------------
   	clock_t timer;
	timer = clock(); //INICIA A CONTAGEM AI
 //-------------------------
 
 
 // Ordena os valores gerados
 quick_sort(vet, 0, MAX - 1);
 // Imprime os valores ordenados
 printf("Valores ordenados\n");
 for(i = 0; i < MAX; i++)
 {
  printf("\n%d", vet[i]);
  
  	
 }
 
 //-------------------------
 	system("cls");
 	timer = clock() - timer; //PARA
 	printf(" > As defenicoes da execucao sao de: %d", MAX);//Mostra as definicoes de MAX ou SIZE ....
	printf("\n > O Quick Sort levou %f milesegundos para terminar \n\n\n\n  ", ((float)timer)/CLOCKS_PER_SEC); //COLOCA NA TELA O VALOR
	system("pause"); //PARA TUDO
	
 //-------------------------	
 
 
 system("pause");
 return 0;
}

//**************************


void quick_sort(int *a, int left, int right) {
	
	
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }

}
