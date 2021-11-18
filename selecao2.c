#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int selecao2(int* array, int i, int tamanho){
	int q;
	if(tamanho == 1) return array[0];
	q = particao(array, tamanho);
	if(i < q) return selecao2(array, i, q);
	else if(i > q) return selecao2(&array[q + 1], i - (q + 1), tamanho - (q + 1));
	else return array[q];
}

int main(){
	clock_t begin = clock();
	double tempo = 0.0;
	int tamanho, i;
	FILE * fp = fopen("selecao2saidas.txt", "a");
	scanf("%d", &tamanho);
	int* array = (int*) malloc(sizeof(int) * tamanho);
	for(int j = 0; j < tamanho; j++){
		scanf("%d", &array[j]);
	}
	scanf("%d", &i);
	int resultado = selecao2(array, i - 1, tamanho);
	clock_t end = clock();
	tempo += (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(fp, "Tempo de exec : %f        Tamanho : %d        Resultado : %d\n", tempo, tamanho, resultado);
	return 0;
}
