#include <stdio.h>
#include <stdlib.h>
#include <time.h>




// On fait un peu de ménage dans cette foncton

void clean(void)
{
	
	for (int i = 0; i < 1000; i++)
		printf("\n");
}





//					##### Mode de jeu 1 joueur #####
//		   Dans ce mode de jeu un code est généré aléatoirement à vous de le trouver 

void one_player(int max)
{
	int min = 1;
	int nombre_mystere = 0;
	int player_guess = 0;
	int counter = 0;

	srand(time(NULL));
	nombre_mystere = (rand() % (max - min + 1)) + min;
	
	do
	{
		counter++;
		printf("Quel est le nombre ? (entre %d et %d) : ", min, max);
		scanf("%d",&player_guess);
		if (player_guess > nombre_mystere)
			printf("C'est moins !\n\n");
		else if (player_guess < nombre_mystere)
			printf("C'est plus !\n\n");
		else
			if (counter == 1)
				printf("\n\nFélicitation vous avez trouvé du premier coup !\n\n");
			else
				printf("\n\nBravo vous avez trouvé le nombre mystere en %d coups !\n\n",counter);
	}
	while (player_guess != nombre_mystere);
}





//					##### Mode de jeu 2 joueurs #####
//		Dans ce mode de jeu le joueur 1 tape un nombre, et donc le joueur 2 doit le trouver

void two_players(int max)
{
	int min = 1;
	int nombre_mystere = 0;
	int player_guess = 0;
	int counter = 0;

	printf("Player one put number ! (entre %d et %d) : ", min, max);
	do
	{
		scanf("%d",&nombre_mystere);
		if (nombre_mystere < min || nombre_mystere > max)
			printf("\nError ! wrong number\nPlayer one put number (entre %d et %d) : ", min, max);
	}
	while (nombre_mystere < min || nombre_mystere > max);

	clean();
	
	do
	{
		counter++;
		printf("Quel est le nombre ? (entre %d et %d) : ", min, max);
		scanf("%d",&player_guess);
		if (player_guess > nombre_mystere)
			printf("C'est moin !\n\n");
		else if (player_guess < nombre_mystere)
			printf("C'est plus !\n\n");
		else
			if (counter == 1)
				printf("\n\nFélicitation vous avez trouvé du premier coup !\n\n");
			else
				printf("\n\nBravo vous avez trouvé le nombre mystere en %d coups !\n\n",counter);
	}
	while (player_guess != nombre_mystere);
}






int main(void)
{
	int end = 1;
	
	do
	{





//					##### PARTIE 1 #####
//			     initialisation du mode de jeu + difficulté





		int mode_jeux = 0;
		int level = 0;
		int max = 0;
		
		clean();	
		printf("########## LE JEU DU NON RETOUR ##########\n (tete de mort qui fait très peur)\n\n\n");
	
		while (mode_jeux != 1 && mode_jeux != 2)
		{
			printf("choisissez le mode de jeu :\n");
			printf("1 joueur --> Tapez (' 1 ')\n");
			printf("2 joueur --> Tapez (' 2 ')\n");
			scanf("%d",&mode_jeux);
		}
		while (level < 1 || level > 3)
		{
			printf("\n\nChoisissez le niveau : \n");
			printf("level 1 = Trouvez le nombre entre 1 à 100 --> Tapez (' 1 ')\n");
			printf("level 2 = Trouvez le nombre entre 1 à 1000 --> Tapez (' 2 ')\n");
			printf("level 3 = Trouvez le nombre entre 1 à 10000 --> Tapez (' 3 ')\n");
			scanf("%d",&level);
		}
		
		clean();		
	
		switch (level)
		{
			case 1:
				max = 100;
				break;
			case 2:
				max = 1000;
				break;
			case 3:
				max = 10000;
				break;
			default:
				printf("Je crois qu'il y a un bug la");
				break;
		}





//					##### PARTIE 2 #####
//				  La partie commence ca va chier !





		printf("Vous avez choisi le mode de jeu %d joueur, level %d.\n\nQue le massacre commence !!!\n\n",mode_jeux,level);
		if (mode_jeux == 1)
			one_player(max);
		else if (mode_jeux == 2)
			two_players(max);





//					##### PARTIE 3 #####
//				 Et zéééé rebarrtiiiii !!! (ou pas)





		printf("Voulez-vous rejouer ?\n");
		printf("Oui --> Tapez (' 1 ')\n");
		printf("Non --> Tapez (' 0 ')\n");
		scanf("%d", &end);
	} while (end);

	printf("\n\n\nMerci d'avoir joué !!!");

	return (0); // ca veut dire que le programme s'est bien déroulé, nan mé je di sa o ka ou.
}
