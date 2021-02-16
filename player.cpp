#include"deck.h"
#include"card.h"
#include<vector>
#include"hand.h"
#include"player.h"
#include <string>
#include <iostream>
using namespace std;


void Player::playp1(Deck& fDeck) {
	char choice = 'y';
	int score = 0;
	Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;

	
	while (choice == 'y') {
		takeOneCard(fDeck);
		printHand();
		score = calculateScore();
		cout << endl;
		cout << "Player1 summ is =" << score << endl; 
		cout << endl;

		if (score >= 21) { break; }


		do { cout << " (enter your choice, y - yes, n - no) ";  cin >> choice; }
		while (choice != 'y' && choice != 'n');

		if (choice == 'n') {
		cout << "its final sum of your cards player1 =" << score << endl; cout << endl; 
		currentGameStatus = GAME_SKIP; 
		break; 
		}
	}
}

void Player::playp2(Deck& fDeck) {
	char choice = 'y';
	int score = 0;
	Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;


	
	while (choice == 'y') {
		takeOneCard(fDeck);
		printHand();
		score = calculateScore();
		cout << "Player2 summ is =" << score << endl;
		cout << endl;

		if (score >= 21) { break;}

	do { cout << " (enter your choice, y - yes, n - no) "; cout << endl;  cin >> choice; } 
	while (choice != 'y' && choice != 'n');

	if (choice == 'n') { cout << "its final sum of your cards player1 =" << score << endl; cout << endl;
	currentGameStatus = GAME_SKIP;
	break; 
	}
}
}