//Realiza o calculo da raiz quadrada de um numero atraves do metodo da bisseccao
/* Aluno : Gabriel Salami Marchetti
   Numero USP : 12543270
*/

#include <stdio.h>
#include <math.h> //Utilizado apenas para valor absoluto(fabs)

void resposta1(double n, double x);


int main (){
	double n, e;
	do{
		printf("Digite um número n (maior do que 1) para ter sua raiz quadrada calculada: ");
		scanf("%lf", &n);
	}while(n <= 0);
	do{
		printf("\nDigite a margem de erro e (maior do que 0): ");
			scanf("%lf", &e);
	}while(e <= 0);
		resposta1(n, e);
	return 0;
}

void resposta1(double n, double e){
	int it = 0;
	double y;
	double ya = 0;
	double xa = 0;
	double media = 0;
	double p = n;
	double x = n;
	while(1 > 0){
		if(fabs(media * media - n) == 0 || fabs(media * media - n) < e){
			printf("\nNumero de iteracoes: %d\nDiferenca absoluta: %.10f\nRaiz quadrada: %.10f", it, fabs(media * media - n), media);
			break;
		}
		if(p * p >= n){
			it++;
			y = 0;
			media = (x + y) / 2;
			printf("\n%.3d: intervalo = [ %f, %f] x = %f\n", it - 1, y, x, media);
			x = x / 2;
			y = x;
			p = x;
		}
		else if((p * p) <= n){
			it++;
			ya = y;
			xa = x * 2;
			media = (xa + ya) / 2;
			if((media * media) >= n){
				x = media / 2;
				printf("\n%.3d: intervalo = [ %f, %f] x = %f\n", it - 1, ya, xa , media);
				p = y;
			}
		if((media * media) <= n){
				y = media;
				printf("\n%.3d: intervalo = [ %f, %f] x = %f\n", it - 1, ya, xa, media);
			}
		}
	}
}
