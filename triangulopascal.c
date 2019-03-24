#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Fun��es utilizadas

int fatorial(int n);
int binomio(int n, int k);
void desenharTriangulo();
void linhaN();
void menu();

//Vari�vel global do n�mero calculado.
int numero;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("Tri�ngulo de Pascal - C�ssio Gamarra");
	printf("\nDigite o valor para calcular: ");
	scanf("%d", &numero);
	
	//Caso o n�mero digitado seja menor que 0 ou maior que 10, retorna um erro.
	if((numero > 10)||(numero < 0)){
		printf("\nValor inv�lido! ");
		system("pause");
		system("cls");
		main();
	}
	else{
		menu();
	}
	
	
	return 0;
}
void menu(){
	int escolha;
	putchar('\n');
	printf("\nO que deseja exibir?");
	printf("\n1 - Desenhar Tri�ngulo");
	printf("\n2 - Linha 'N' do tri�ngulo");
	printf("\n0 - Sair");
	printf("\nESCOLHA: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 0:{
			printf("Obrigado por usar o sistema!");
			break;
		}
		case 1:{
			desenharTriangulo();
			break;
		}
		case 2:{
			linhaN();
			break;
		}
		default:{
			printf("Voc� digitou um valor inv�lido! ");
			system("pause");
			system("cls");
			menu();
		}
	}
}

//Fun��o para desenhar o Tri�ngulo de Pascal
void desenharTriangulo(){
	int n, k;
	
	printf("\nTri�ngulo at� a linha %d", numero);
	putchar('\n');
	//La�o de repeti��o que percorre o N e o K enquanto esse for menor que o n�mero solicitado, usando a fun��o do bin�mio.
	for (n = 0; n <= numero; n++){
		for (k=0; k <= n; k++){
			printf("%d ", binomio(n, k));
		}
	putchar('\n');
	}
	system("pause");
}


//Fun��o para mostrar apenas uma linha do Tri�ngulo de Pascal
void linhaN(){
	int k;
	printf("\nLinha %d do tri�ngulo: ", numero);
	
	//Nesse caso, o la�o de repeti��o precisa percorrer apenas o K da fun��o anterior, pois imprime apenas uma linha.
	for(k=0; k<= numero; k++){
		printf("%d ", binomio(numero, k));
	}
	printf("\n");
	system("pause");
}

//Fun��o para realizar o calculo do Fatorial, necess�rio para o bin�mio.
int fatorial(int n){
	int fat, i;
	
	fat = 1;
	
	for (i=1; i<=n;i++){
		fat = fat * i;
	}
	
	return fat;
}

//Fun��o para calcular o coeficiente binomial. Usando a f�rmula (n k) = n!/ n!(n-k)!

int binomio(int n, int k){
	int coeficiente;
	coeficiente = fatorial(n)/(fatorial(k) * fatorial(n-k)); //F�rmula.
	return coeficiente;
}
