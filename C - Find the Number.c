// -------------------  App Info  ------------------------

// C - Find the Number
// Version 1.1.0
// Date: 2021-05-12

// -------------------  App Info  ------------------------



#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strcspn, to remove trailing newline character from fgets() input


int main()
{

	char replay = 'y';
	char nameQuestion;

	char player1[20];
	char player2[20];



	printf("Hello Players!\nLet's play \"Find the Number\"");
	printf("\n\nPlayer1 will enter a number and Player2 will try and guess it :D");

	// do{
	// printf("\n\nDo you wish to speak your names, or remain mysterious? :O\n(y/n)");
	// scanf(" %c", &nameQuestion);
	// if(nameQuestion == 'y') {
	

	// }
	// }
	// while (nameQuestion != 'y' && nameQuestion != 'n');


		printf("\n\nLet's get to know our players.\nPlayer1, what is your name?\n");
		fgets(player1, 20, stdin);
		player1[strcspn(player1, "\n")] = 0;
		printf("Player2, your name as well?\n");
		fgets(player2, 20, stdin);
		player2[strcspn(player2, "\n")] = 0;

		
		system("clear");
		printf("\nOkay, %s and %s, let's play!\n\n", player1, player2);
	


	
	do{

	int num1, num2 = 0;
	int counter = 0;
	int counterLow = 0;
	int counterHigh = 0;
	int gameMode;
	int maxTries = 1000;


		do{
		printf("Enter the number to select game mode:\n");
		printf("1. Easy mode - Unlimited tries\n2. Hard mode - Only 5 tries :O\n3. Custom mode - Select the number of tries\n\n");
		scanf("%d", &gameMode);

		// clear screen clrscr();
		system("clear");
		if (gameMode < 1 || gameMode > 3) printf("\nPick an available game mode, 1, 2, or 3 !!!\n\n");
		} while (gameMode < 1 || gameMode > 3);


		if(gameMode==1) printf("You have selected \"Easy mode - Unlimited tries\"");

		if(gameMode==2){
			printf("You have selected \"Hard mode - Only 5 tries\"");
			maxTries = 5;	
		} 

		if(gameMode==3) printf("You have selected \"Custom mode\"");


		if(gameMode==3){
			do{
			printf("\nEnter the number of tries, from 1 to 100: ");
			scanf("%d", &maxTries);

			system("clear");
			if (maxTries < 1 || maxTries > 100) printf("\nThat number is no good :/\n\n");
			} while (maxTries < 1 || maxTries > 100);
		}
	
		
		do{
		// Player1 enter a number from 1 to 100
		printf("\n\nLet's start!\n\n%s, enter a number from 1 to 100: ", player1);
		scanf("%d", &num1);

		// clear screen clrscr();
		system("clear");
		if (num1 < 1 || num1 > 100) printf("\nThat number is no good :/\n\n");
		} while (num1 < 1 || num1 > 100);

	// Player2 guess player1's number
	printf("Thank you, %s!", player1);
	printf("\n\nAlright, %s, time to guess the number: ", player2);
	

	while (num1 != num2 && counter<maxTries) {

	

		scanf("%d", &num2);

		system("clear");

		int num2_current;
		int num2_lower;
		int num2_higher;


		if(num2 < num1){
			printf("You guessed: %d\nYour guess was lower.", num2);
			num2_current = num2;
			counterLow++;
			if (counterLow==1) num2_lower = num2_current;
			else {
				if (num2_current > num2_lower){
					num2_lower = num2_current;
				}
			}
		}

		if(num2 > num1){
			printf("You guessed: %d\nYour guess was higher.", num2);
			num2_current = num2;
			counterHigh++;
			if (counterHigh==1) num2_higher = num2_current;
			else {
				if (num2_current < num2_higher){
					num2_higher = num2_current;
				}
			}
		}


		counter++;
		
		
		if (counterLow > 0) printf("\n\nClosest lower you've guessed is %d.", num2_lower);
		if (counterHigh > 0) printf("\n\nClosest higher you've guessed is %d.", num2_higher);
		printf("\n\nYou have made %d guesses so far.", counter);
		if(gameMode != 1) printf("\n\nYou have %d guesses left.", maxTries-counter);
		printf("\n\nCome on, try again: ");
		


	}
	printf("\n ");				// Added due to issue with system("clear") command showing the previous printf() line
	system("clear");

	if (num1==num2) printf("\nCongrats, %s! You found the number!\nNumber \"%d\"", player2, num2);
	else printf("\nSorry, %s! You run out of guesses... :/\n%s's Number was \"%d\"\nBetter luck next time!", player2, player1, num1);

	printf("\n\n%s's stats:\nTotal number of guesses: %d\nLower number guesses: %d\nHigher number guesses: %d", player2, counter, counterLow, counterHigh);

	printf("\n\nWould you like to play again?\n(Y/N): ");
	scanf(" %c", &replay);
	system("clear");
	} while (replay=='y' || replay == 'Y');


	printf("Thank you for playing!\nCome back any time :)");

	// Number is smaller, or larger than Player1's


	// Player2 you found the number, congrats





    // printf("Hello World");

    return 0;
}