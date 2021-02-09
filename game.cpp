#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include "game.h"
using namespace std;

void Game::gaming(unsigned int& playerWin, unsigned int& dealerWin, unsigned int& countDraw, unsigned int& countGame, unsigned int& playerWin2) {
	Deck my_deck;
	my_deck.shuffle();
	//my_deck.print_deck();
	Player player1;
	Player player2;
	Dealer dealer;
	
	Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
	Hand::GameStatus currentGameStatusd = dealer.checkGameStatus();
	Hand::GameStatus currentGameStatus2 = player2.checkGameStatus();

	char playing = 'a';
	bool game = true;
	bool pl1 = true; bool pl2 = true; bool dl = true;



	using namespace std;

	while (true) {
		if (currentGameStatus == Hand::GAME_CONTINUE) {

			while (true) {
				cout << "player1 your turn" << endl;
				player1.playp1(my_deck);
				currentGameStatus = player1.checkGameStatus();

				if (currentGameStatus == Hand::WIN_) {
					cout << "Player1 win!" << endl; cout << endl; playerWin++;
					/*pl1 = false;*/ break;
				}
				else if (currentGameStatus == Hand::LOOSE_) {
					cout << "Player1 lose!" << endl; cout << endl;
					/*pl1 = false;*/ currentGameStatus = Hand::GAME_CONTINUE;  break;
				}
			}
			////
			if (currentGameStatus == Hand::GAME_CONTINUE) {
				while (true) {
					cout << "player2 your turn!" << endl;
					player2.playp2(my_deck);
					 currentGameStatus2 = player2.checkGameStatus();


					 if (currentGameStatus2 == Hand::WIN_) {
						 cout << "Player2 win!" << endl; cout << endl; playerWin2++;
						 /*pl1 = false;*/break;
					 }
					 else if (currentGameStatus2 == Hand::LOOSE_) {
						 cout << "Player2 lose!" << endl; cout << endl;
						 /*pl2 = false;*/ currentGameStatus2 = Hand::GAME_CONTINUE; break;
					 }
					 else break;
				}

				/////

				if (currentGameStatus2 == Hand::GAME_CONTINUE) {

					int playerScore1 = player1.calculateScore();
					int dealerScore = dealer.calculateScore();
					int playerScore2 = player2.calculateScore();

					cout << "dealer plays" << endl;
					dealer.playd(my_deck);
					  currentGameStatusd = dealer.checkGameStatus();

					if (currentGameStatusd == Hand::WIN_) {
						cout << "Dealer win!" << endl; cout << endl; dealerWin++;
						/*dl = false;*/break;
					}
					else if (currentGameStatusd == Hand::LOOSE_) {
						cout << "dealer lose!" << endl; cout << endl;
						/*dl = false;*/ break;
					}
					else if (playerScore1<dealerScore>playerScore2) {
						cout << "Dealer win!" << endl; dealerWin++;
					}

					else if (dealerScore<playerScore1>playerScore2) {
						cout << "Player1  win!" << endl; playerWin++;
					}

					else if (dealerScore<playerScore2>playerScore1) {
						cout << "Player2  win!" << endl; playerWin2++;
					}
					else if (currentGameStatus== Hand::LOOSE_ &&currentGameStatus2==Hand::LOOSE_) {
						cout << "dealer  win!" << endl; playerWin2++;
					}

					else if (currentGameStatus == Hand::LOOSE_&& currentGameStatusd == Hand::LOOSE_) {
						cout << "dealer  win!" << endl; dealerWin++;
					}

					else if (currentGameStatus2 == Hand::LOOSE_&& currentGameStatusd == Hand::LOOSE_) {
						cout << "dealer  win!" << endl; playerWin2++;
					}

					else if (dealerScore == playerScore1 && dealerScore == playerScore2 && playerScore1 == playerScore2)
					{
						cout << "Draw!" << endl; cout << endl; countDraw++; break;
					}

					
					////
					else break;
				}

			}
			countGame++;
		}
	}
}