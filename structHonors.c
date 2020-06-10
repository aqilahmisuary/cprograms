/*
Write a function that randomly shuffles a deck of cards
*/
#include <stdio.h>
#include <stdlib.h>

typedef enum suit {Club, Diamond, Heart, Spade} suit;
typedef enum rank {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King} rank;
typedef struct card {enum suit s; enum rank r;} card;

int printRank(enum rank r)
{
	printf("\nCard Generated: ");
	switch(r){
	case Ace: printf("Ace of "); break;
	case Two: printf("Two of "); break;
	case Three: printf("Three of "); break;
	case Four: printf("Four of "); break;
	case Five: printf("Five of "); break;
	case Six: printf("Six of "); break;
	case Seven: printf("Seven of "); break;
	case Eight: printf("Eight of "); break;
	case Nine: printf("Nine of "); break;
	case Ten: printf("Ten of "); break;
	case Jack: printf("Jack of "); break;
	case Queen: printf("Queen of "); break;
	case King: printf("King of "); break;
	default: printf("There is an error"); break;
	}
	return 0;
}

int printSuit(enum suit s)
{
	switch(s){
	case Club: printf("Clubs\n"); break;
	case Diamond: printf("Diamonds\n"); break;
	case Heart: printf("Hearts\n"); break;
	case Spade: printf("Spades\n"); break;
	default: printf("Error printing Suit"); break;
	}
	return 0;
}

int main ()
{
	struct card randomCard;

	//Deal out 7 cards	
	for(int i = 0; i < 7; i++)
	{
	//Generate random number in a range
	randomCard.s = (rand() % (3 + 0 - 0) + 0);
	randomCard.r = (rand() % (12 + 0 - 0) + 0);
	//Print rank
	printRank(randomCard.r);
	printSuit(randomCard.s);
	}
	
	return 0;
}

