#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

double calcularProbabilidadeA(double carroA, double carroB);
double calcularProbabilidadeB(double carroA, double carroB);


int main(){
		double carroA, carroB;
		int opcao;
		setlocale(LC_ALL, "Portuguese");
		
		printf("TRABALHO DE PROBABILIDADE E ESTAT�STICA - C�SSIO GAMARRA\n\n");
		system("pause");
		system("cls");
		
		//Garantindo que n�o tenham valores de sujeira de mem�ria no sistema
		carroA = 0;
		carroB = 0;
		
		printf("Mike tem dois velhos autom�veis.\nNas manh�s frias, h� %.2f%% de probabilidade de um deles n�o pegar, \ne %.2f%% do outro n�o pegar.", carroA, carroB);
		
		//Solicitando os valores para o enunciado
		printf("\n\nDigite a probabilidade do carro A: ");
		scanf("%lf", &carroA);
		printf("\nDigite a probabilidade do carro B: ");
		scanf("%lf", &carroB);
		
		//Garantindo que os valores sejam positivos
		if(carroA < 0){
			carroA = carroA * -1;
		}
		if(carroB < 0){
			carroB = carroB * -1;	
		}
	
		//Atualizando os valores do enunciado e printando as quest�es
		printf("\n\nMike tem dois velhos autom�veis.\nNas manh�s frias, h� %.2f%% de probabilidade de um deles n�o pegar, \ne %.2f%% do outro n�o pegar.", carroA, carroB);
		printf("\n\na) Qual a probabilidade de nenhum pegar?");
		printf("\nb) Qual a probabilidade de apenas um pegar?");
		printf("\n\n1 - Resultado Quest�o A | 2 - Resultado Quest�o B: ");
		scanf("%d", &opcao);
		
		//Exibindo o resultado da quest�o A
		if(opcao == 1){
			printf("\nA probabilidade de nenhum pegar � de ");
			printf("%.2lf%%", calcularProbabilidadeA(carroA,carroB));
		}
		//Exibindo o resultado da quest�o B
		else if(opcao == 2){
			printf("\nA probabilidade de apenas um pegar � de ");
			printf("%.2lf%%", calcularProbabilidadeB(carroA,carroB));
		}
		
		else{
			printf("\nOp��o inv�lida!\n");
			system("pause");
			system("cls");
			main();
		}
	
    return 1;
}

//Calculo da probabilidade para a quest�o A
double calcularProbabilidadeA(double carroA, double carroB){
	double resultado = 0;
	double probCarroA, probCarroB;
	
	probCarroA = carroA/100.0;
	probCarroB = carroB/100.0;
	
	/*Quest�o A: � necess�rio multiplicar a probabilidade do carro A n�o pegar
	*com a probabilidade do carro B n�o pegar.
	*/
	resultado = (probCarroA * probCarroB)*100;
	
	return resultado;
}

//Calculo da probabilidade para a quest�o B
double calcularProbabilidadeB(double carroA, double carroB){
	double resultado = 0;
	double probCarroA, probCarroB, situacaoA, situacaoB;
	
	//Convertendo os valores para trabalhar com a porcentagem
	probCarroA = carroA/100.0;
	probCarroB = carroB/100.0;
	
	//As situa��es s�o: o carro A pegar e o carro B pegar
	//Sendo 100% menos a probabilidade do carro n�o pegar
	situacaoA = 100-carroA;
	situacaoB = 100-carroB;
	
	/* O c�lculo utilizado �:
	*	A probabilidade do carro A n�o pegar multiplica a probabilidade do carro B Pegar
	* 	A probabilidade do carro B n�o pegar multiplica a probabilidade do carro A Pegar
	*	Realiza a soma desses valores, obtendo a probabilidade de apenas um deles pegar
	*/
	resultado = (probCarroA*situacaoB)+(probCarroB*situacaoA); 
	
	return resultado;
}

