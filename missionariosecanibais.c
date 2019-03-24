#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Declara��o das fun��es
void menu();
void jogar();
void instrucoes();

//Estruturas
typedef struct{
	int esquerda;
	int direita;
}Missionarios;

typedef struct{
	int esquerda;
	int direita;
}Canibais;

typedef struct{
	int passageiro1, passageiro2, passageiros;
}Barco;

int main(){
	setlocale (LC_ALL,"Portuguese");
	menu();
	return 0;
}

void jogar(){
	
	int ladoDireito = 6;
	int ladoEsquerdo = 0;
	int jogadas = 0;
	int vitoria = 1;
		
	Barco barco;
	Missionarios missionarios;
	Canibais canibais;
	missionarios.esquerda = 0;
	missionarios.direita = 3;
	canibais.esquerda = 0;
	canibais.direita = 3;
	
	barco.passageiros = 0;
		
	system("cls");
	printf("|---------MISSION�RIOS E CANIBAIS----------|");
	while((canibais.esquerda+missionarios.esquerda)<6){
		/*INICIO DO LADO DIREITO*/
		while (barco.passageiros < 2 ){
			printf("\nVOC� EST� DO LADO DIREITO!");
			printf("\nEscolha quem entra no barco: ");
			printf("\n1 - Mission�rio");
			printf("\n2 - Canibal");
			printf("\n3 - Ningu�m");
			printf("\nPrimeiro passageiro: ");
			scanf("%d", &barco.passageiro1);
			fflush(stdin);
			barco.passageiros++;
			
			if (barco.passageiro1 != 3){
				ladoDireito--;
				ladoEsquerdo++;
			}
			printf("\nSegundo passageiro: ");
			scanf("%d", &barco.passageiro2);
			fflush(stdin);
			barco.passageiros++;
			jogadas++;
		
			if (barco.passageiro2 != 3){
				ladoDireito--;
				ladoEsquerdo++;
			}
			if((barco.passageiro1 == 3)&&(barco.passageiro2 == 3)){
				printf("\nO barco n�o pode viajar sozinho!!!");
				barco.passageiros = 0;
				putchar('\n');
				system("pause");
				system("cls");
			}
		}
				
		if ((barco.passageiro1 == 1)&&(barco.passageiro2 == 1)){
				missionarios.direita--;
				missionarios.esquerda++;
				missionarios.direita--;
				missionarios.esquerda++;
		}
		
		else{
			if ((barco.passageiro1 == 1)&&(barco.passageiro2 == 2)){
				missionarios.direita--;
				canibais.direita--;
				missionarios.esquerda++;	
				canibais.esquerda++;
			}
			else if((barco.passageiro1 == 2)&&(barco.passageiro2 == 2)){
				canibais.direita--;
				canibais.esquerda++;
				canibais.direita--;
				canibais.esquerda++;
			}
			
			else if(((barco.passageiro1 == 2)&&(barco.passageiro2 == 3))||((barco.passageiro1 == 3)&&(barco.passageiro2 == 2))){
				canibais.direita--;
				canibais.esquerda++;
			}
		}
		if((canibais.direita > missionarios.direita)&&(missionarios.direita != 0)){
			printf("\nVoc� perdeu :(");
			printf("\nNumero de jogadas %d", jogadas);
			vitoria = 0;
			break;
			system("exit");
		}
		system("cls");
		printf("\nLado direito: %d", ladoDireito);
		printf("\nLado esquerdo: %d", ladoEsquerdo);
		printf("\nMissionarios na direita: %d // Missionarios na esquerda: %d", missionarios.direita, missionarios.esquerda);
		printf("\nCanibais na direita: %d // Canibais na esquerda: %d", canibais.direita, canibais.esquerda);
		printf("\nBarco: %d", barco.passageiros);
		barco.passageiros = 0;
		putchar('\n');
		system("pause");
		
		/*FIM DO LADO DIREITO*/
		//Condi��o para finalizar o jogo
		if(ladoEsquerdo == 6){
			break;
		}
		
		else{
			/*INICIO DO LADO ESQUERDO*/
		while (barco.passageiros < 2 ){
			printf("\nVOC� EST� DO LADO ESQUERDO!");
			printf("\nEscolha quem entra no barco: ");
			printf("\n1 - Mission�rio");
			printf("\n2 - Canibal");
			printf("\n3 - Ningu�m");
			printf("\nPrimeiro passageiro: ");
			scanf("%d", &barco.passageiro1);
			fflush(stdin);
			barco.passageiros++;
			
			if (barco.passageiro1 != 3){
				ladoDireito++;
				ladoEsquerdo--;
			}
			printf("\nSegundo passageiro: ");
			scanf("%d", &barco.passageiro2);
			fflush(stdin);
			barco.passageiros++;
			jogadas++;
			
			if (barco.passageiro2 != 3){
				ladoDireito++;
				ladoEsquerdo--;
			}
			if((barco.passageiro1 == 3)&&(barco.passageiro2 == 3)){
				printf("\nO barco n�o pode viajar sozinho!!!");
				barco.passageiros = 0;
				putchar('\n');
				system("pause");
				system("cls");
			}
		}
		
		if ((barco.passageiro1 == 1)&&(barco.passageiro2 == 2)){
			missionarios.direita++;
			canibais.direita++;
			missionarios.esquerda--;	
			canibais.esquerda--;
		}
		else if((barco.passageiro1 == 2)&&(barco.passageiro2 == 2)){
			canibais.direita++;
			canibais.esquerda--;
			canibais.direita++;
			canibais.esquerda--;
		}
		else if (((barco.passageiro1 == 1)&&(barco.passageiro2 == 3))||((barco.passageiro1 == 3)&&(barco.passageiro2 == 1))){
			missionarios.esquerda--;
			missionarios.direita++;
		}
		else if(((barco.passageiro1 == 2)&&(barco.passageiro2 == 3))||((barco.passageiro1 == 3)&&(barco.passageiro2 == 2))){
			canibais.direita++;
			canibais.esquerda--;
		}
		
		if((canibais.esquerda > missionarios.esquerda)&&(missionarios.esquerda != 0)){
			printf("\nVoc� perdeu :(");
			printf("\nNumero de jogadas %d", jogadas);
			vitoria = 0;
			break;
			system("exit");
		}
		system("cls");
		printf("\nLado direito: %d", ladoDireito);
		printf("\nLado esquerdo: %d", ladoEsquerdo);
		printf("\nMissionarios na direita: %d // Missionarios na esquerda: %d", missionarios.direita, missionarios.esquerda);
		printf("\nCanibais na direita: %d // Canibais na esquerda: %d", canibais.direita, canibais.esquerda);
		printf("\nBarco: %d", barco.passageiros);
		barco.passageiros = 0;
		putchar('\n');
		system("pause");		
		/*FIM DO LADO ESQUERDO*/
		}
		
	}
	if(vitoria != 0){
		printf("\nVENCEU!");
		printf("\nNumero de jogadas %d", jogadas);	
	}	
}
void instrucoes(){
	system("cls");
	printf("|----------INSTRU��ES----------|");
	printf("\n-> Voc� deve ajudar a travessia dos mission�rios e \ndos canibais at� o outro lado do rio.");
	putchar('\n');
	printf("\n-> Os mission�rios n�o podem ficar em menor n�mero, em qualquer \numa das margens, ou os canibais os devorar�o.");
	putchar('\n');
	printf("\n-> O barco deve ter pelo menos 1 passageiro para ir de uma margem para outra!");
	putchar('\n');
	printf("\nBOM JOGO!!!");
	putchar('\n');
	system("pause");
	fflush(stdin);
	menu();		
}
void menu(){
	char opcoes;
	system("cls");
	printf("|---------MISSION�RIOS E CANIBAIS----------|");
	printf("\n1. JOGAR");
	printf("\n2. INSTRU��ES");
	printf("\n3. JOGO ORIGINAL - VERS�O FLASH");
	printf("\n0. SAIR");
	putchar('\n');
	scanf("%c", &opcoes);
	
	switch(opcoes){
		
		case 48: {
			printf("Obrigado por jogar!!!");
			system("exit");
			break;
		}
		case 49:{
			jogar();
			break;
		}
		case 50:{
			instrucoes();
			break;
		}
		case 51:{
			system("start firefox.exe https://rachacuca.com.br/jogos/missionarios-e-canibais/");
			break;
		}
		default:{
			printf("Op��o inv�lida! ");
			system("pause");
			fflush(stdin);
			return menu();
			break;
		}
	}
}
