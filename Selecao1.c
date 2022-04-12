/*

Sorting algorithm used to measure it's time complexity and
plotting the graph of how long it take to sort an array.

Then it was compared with Selecao2.c to study their diferences.

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int particao(int* array, int tamanho);
void quicksort(int* array, int tamanho);

void troca(int* a, int* b) {
	int aux;
  	aux = *a;
  	*a = *b;
  	*b = aux;
}

int particao(int* array, int tamanho){
	int pivo = array[tamanho - 1];
	int i = -1;
	int j;
	for(j = 0; j < tamanho - 1; j++){
		if(array[j] <= pivo){
			troca(&array[++i], &array[j]);
		}
	}
	troca(&array[i + 1], &array[j]);
	return i + 1;
}


void quicksort(int* array, int tamanho){
	if(tamanho > 0){
		int q = particao(array, tamanho);
		quicksort(array, q);
		quicksort(&array[q + 1], tamanho - (q + 1));
	}
}

int main(){
	clock_t begin = clock();
	double tempo = 0.0;
	int tamanho, i;
	FILE * fp = fopen("selecao1saidas.txt", "a");
	scanf("%d", &tamanho);
	int* array = (int*) malloc(sizeof(int) * tamanho);
	for(int i = 0; i < tamanho; i++){
		scanf("%d", &array[i]);
	}
	quicksort(array, tamanho);
	scanf("%d", &i);
	clock_t end = clock();
	tempo += (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(fp, "Tempo de exec : %f        Tamanho : %d        Resultado : %d\n", tempo, tamanho, array[i - 1]);
	return 0;
}
