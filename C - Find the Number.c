// -------------------  App Info  ------------------------

// C - Find the Number
// Version 1.0.0
// Date: 2021-04-24

// -------------------  App Info  ------------------------



#include <stdio.h>
#include <stdlib.h>

int main()
{

	char replay = 'y';

	printf("Hello Players!\nLet's play \"Find the Number\"");
	printf("\n\nPlayer1 will enter a number and Player2 will try and guess it :D\n\n");

	
	do{

	int num1, num2 = 0;
	int counter = 0;
	int counterLow = 0;
	int counterHigh = 0;

	// Player1 enter a number from 1 to 100
	printf("Player1, enter your number: ");
	scanf("%d", &num1);


	// clear screen clrscr();
	system("clear");


	// Player2 guess player1's number
	printf("Thank you, Player1!");
	printf("\n\nAlright, Player2, time to guess the number: ");
	

	while (num1 != num2) {

		scanf("%d", &num2);

		system("clear");

		int num2_current;
		int num2_lower;
		int num2_higher;


		if(num2 < num1){
			printf("You guessed: %d", num2);
			printf("\nYou guessed lower");
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
			printf("You guessed: %d", num2);
			printf("\nYou guessed higher");
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
		
		
		if (counterLow > 0) printf("\n\nClosest lower you've guessed is %d", num2_lower);
		if (counterHigh > 0) printf("\n\nClosest higher you've guessed is %d", num2_higher);
		printf("You have %d guesses so far.", counter);
		printf("\n\nCome on, try again: ");
		

	}
	printf("\n ");				// Added due to issue with system("clear") command showing the previous printf() line
	system("clear");

	printf("\nCongrats, Player2! You found the number!\nNumber \"%d\"", num2);

	printf("\n\nPlayer2 stats:\nTotal number of guesses: %d\nLower number guesses: %d\nHigher number guesses: %d", counter, counterLow, counterHigh);

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