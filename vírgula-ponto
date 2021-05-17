//Transforma vírgulas em pontos para trabalhar um conjunto de valores(utilizar "!" como ponto de parada)
#include<stdio.h>

int main(){
	int t = 1; //t é o total de chars
	int n = 0; //n é o total de vírgulas
	int i;
	for(i = 0; i < t ; i++){
		char a;
		scanf("%c", &a);
		if(a != 33 && a != 44){
			printf("%c", a);
			t++;
		}
		if (a == 44){
			a = 46;
			printf("%c", a);
			n++;
			t++;
		}
	}
	printf("\nO total de vírgulas é %d", n);
	return 0;
}
