#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void mover(int n, char origem, char destino);
void torreHanoi(int n, char origem, char destino, char aux);

/* As duas fun��es funcionam da seguinte maneira:
*	- Fun��o mover: imprime na tela os movimentos realizados durante o jogo.
*	- Fun��o torreHanoi: realiza os movimentos
*	- Origem: pino de origem / Destino: pino de destino / Aux: pino auxiliar
*/

int count, n; //Contador do n�mero de movimentos, n�mero de discos

int main(){
	int discos, escolha;
	setlocale(LC_ALL, "Portuguese");
		
	printf("\t\t\tTORRES DE HANOI - C�SSIO GAMARRA");
	printf("\n\nDigite o n�mero de discos: ");
	scanf("%d", &discos); //Recebe o n�mero de discos, pode ser limitado caso necess�rio
	putchar('\n');
	torreHanoi(discos, 'A', 'C', 'B'); //N�mero de discos, origem, auxiliar e destino final
	printf("\n\nN�mero de jogadas: %d", count);//N�mero de jogadas realizadas
	
	printf("\n\nDeseja conferir o resultado? 1 - SIM / 2 - N�O: "); //Caso deseje conferir que os movimentos est�o corretos.
	scanf("%d", &escolha);
	switch(escolha){
		case 1:{ //Abre o navegador firefox no site "S� Matem�tica", na p�gina do jogo da torre de hanoi
			printf("\nAbrindo...");
			system("start firefox.exe https://www.somatematica.com.br/jogos/hanoi/");
			break;
		}
		case 2:{
			printf("\nObrigado por utilizar o programa! ");
			system("pause");
			system("exit");
			break;
		}
		default:{
			printf("\nEscolha inv�lida!");
			break;
		}
	}
	
	return 0;
}

void mover(int n, char origem, char destino){
	printf("Move o disco %d do pino %c para o pino %c\n", n, origem, destino);
}

void torreHanoi(int n, char origem, char destino, char aux){
	if (n > 0){
		torreHanoi(n - 1, origem, aux, destino);
		mover(n, origem, destino);
		torreHanoi(n - 1, aux, destino, origem);
		count++;
	}
}
