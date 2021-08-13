//Caracteriza um triangulo de lados l1, l2, l3
//Nome : Gabriel Salami Marchetti . Numero USP : 12543270

#include<stdio.h>
#include<math.h> //Biblioteca utilizada para implementar funcoes trigonometricas.
#define PI 3.14159265

//As funcoes criadas foram explicitadas apos o corpo do programa.

int ce(double l1, double l2, double l3);

int cl(double l1, double l2, double l3);

int ca(double l1, double l2, double l3);

double areatriangulo(double l1, double l2, double l3);

int main(){
	int i;
	double l[3];
	for(i = 0; i < 3; i++){
		scanf("%lf", &l[i]);
		if(l[i] <= 0){	//O programa para imediatamente ao inserir um lado menor ou igual a zero.
			printf("Medidas dos lados formam um triangulo INVALIDO\n");
			return 1;
		}
	}
	if(ce(l[0], l[1], l[2]) == 1){ //Chama a funcao ce.
		printf("Medidas dos lados formam um triangulo INVALIDO\n");
		return 1;
	}
	printf("Medidas dos lados formam um triangulo VALIDO\n");
	switch(cl(l[0], l[1], l[2])){ //Chama a funcao cl e compara seu valor.

	case 1 :
		printf("Classificacao em funcao dos lados: EQUILATERO\n");
		break;

	case 2 :
		printf("Classificacao em funcao dos lados: ISOSCELES\n");
		break;

	case 3 :
		printf("Classificacao em funcao dos lados: ESCALENO\n");
		break;
	}
	switch(ca(l[0], l[1], l[2])){ //Chama a funcao ca e compara seu valor.

	case 1 :
		printf("Classificacao em funcao dos angulos: RETO\n");
		break;

	case 2 :
		printf("Classificacao em funcao dos angulos: AGUDO\n");
		break;

	case 3 :
		printf("Classificacao em funcao dos angulos: OBTUSO\n");
		break;
	}
	printf("Area do triangulo: %g\n", areatriangulo(l[0], l[1], l[2])); //Aplica a funcao areatriangulo para a impressao da area
	return 0;
}

int ce(double l1, double l2, double l3){ //Verifica a condicao de existencia(ce) de um triangulo (l1 < l2 + l3 , ...).
	if(l1 >= l2 + l3 || l2 >= l1 + l3 || l3>= l1 + l2){
		return 1; //Retorna 1 em caso de invalidez.
	}
	else{
		return 0; //Retorna 0 caso valido.
	}
}

int cl(double l1, double l2, double l3){ //Verifica a classificacao em funcao dos lados(cl) do triangulo.
	if(l1 == l2 && l1 == l3){
		return 1; //Retorna 1 caso seja equilatero.
	}
	else if((l1 == l2 && l1 != l3) || (l1 == l3 && l1 != l2) || (l2 == l3 && l2 != l1)){
		return 2; //Retorna 2 caso seja isosceles.
	}
	else;
	return 3; //Retorna 3 caso seja escaleno.
}

int ca(double l1, double l2, double l3){ //Verifica a classificacao em funcao dos angulos(ca) do triangulo.
	double a, b, c; //Variaveis referentes aos angulos do triangulo.
	a = acos((l1 * l1 + l2 * l2 - l3 * l3)/(2 * l1 * l2)); //Calcula os angulos aplicando a funcao arccos na lei dos cossenos.
	b = acos((l1 * l1 + l3 * l3 - l2 * l2)/(2 * l1 * l3));
	c = acos((l2 * l2 + l3 * l3 - l1 * l1)/(2 * l2 * l3));
	if(l1 * l1 == l2 * l2 + l3 * l3 || l2 * l2 == l1 * l1 + l3 * l3 || l3 * l3 == l2 * l2 + l1 * l1){
		return 1; //Retorna 1 caso seja reto.
	}
	else if(a < PI/2 && b < PI/2 && c < PI/2){
		return 2; //Retorna 2 caso seja agudo.
	}
	else;
	return 3; //Retorna 3 caso seja obtuso.
}

double areatriangulo(double l1, double l2, double l3){ //Calcula a area do triangulo
	double a; //Variavel referente a um angulo do triangulo.
	a = acos((l1 * l1 + l2 * l2 - l3 * l3)/(2 * l1 * l2)); //Calcula o angulo aplicando a funcao arccos na lei dos cossenos.
	return ((l1 * l2 * sin(a))/ 2);
}
