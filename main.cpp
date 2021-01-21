//#include"deck.h"
//#include"card.h"
//#include"dealer.h"
//#include"hand.h"
//#include <iostream>
//#include "player.h"
//
//using namespace std;
//
//int main() {
//	Deck my_deck;
//	my_deck.shuffle();
//	//my_deck.print_deck();
//	Player player1;
//	Dealer dealer1;
//	bool play = true;
//	Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
//	while (play) {
//		player1.playp(my_deck);
//		currentGameStatus = player1.checkGameStatus();
//		switch (currentGameStatus) {
//		case Hand::WIN_: cout << "player1 win!" << endl; play = false;
//		case Hand::LOOSE_:  cout << "player1 LOOSE!" << endl; play = false;
//		case Hand::GAME_CONTINUE:
//			cout << "dialer1 takes  cards" << endl;
//			dealer1.playd(my_deck);
//			currentGameStatus = dealer1.checkGameStatus();
//			if (currentGameStatus==Hand::GAME_CONTINUE) {
//			if(currentGameStatus == Hand::WIN_) cout << "dialer1 win!" << endl;break;
//			if(currentGameStatus == Hand::LOOSE_) cout << "dialer1 LOOSE!" << endl; break;
//				/*case Hand::GAME_CONTINUE:int playerScore = player1.calculateScore();
//				int dialerScore = dealer1.calculateScore();
//				if (playerScore > dialerScore) { cout << "player1 win!" << endl; break; }
//				else if (playerScore < dialerScore) { cout << "player1 loose!" << endl; break; }
//				else if (playerScore == dialerScore) { cout << "draw!" << endl; break; }play = false;
//						}*/
//			}
//
//		}
//
//		return 0;
//	}
//}



#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
using namespace std;
int main() {
    Deck my_deck;//создаем колоду
    my_deck.shuffle();//тусуем колоду
    //my_deck.print_deck();
    Player player1;//создаем игрока
    Dealer dealer;//создаем дилера
    Hand::GameStatus currentGameStatus = Hand::GAME_CONTINUE;
    while (true) {
        //
        player1.playp(my_deck);
        currentGameStatus = player1.checkGameStatus();
        /*
        switch(currentGameStatus){
         case Hand::GAME_WIN: break;
         case Hand::GAME_LOSE: break;
         case Hand::GAME_CONTINUE:
         switch(currentGameStatus){
          case Hand::GAME_WIN: break;
          case Hand::GAME_LOSE: break;
          case Hand::GAME_CONTINUE:
        }
        */
        //проверяем как сыграл игрок
        //набрал 21 - выиграл сразу
        if (currentGameStatus == Hand::WIN_) {
            cout << "Player1 win!" << endl;
            break;
        }
        else
            //перебор - срызу проиграл
            if (currentGameStatus == Hand::LOOSE_) {
                cout << "Player1 lose!" << endl;
                break;
            }
            else
                //игрок набрал меньше 21 очка, играет дилер
                if (currentGameStatus == Hand::GAME_CONTINUE) {
                    //дилер набирает карты в руку
                    dealer.playd(my_deck);
                    currentGameStatus = dealer.checkGameStatus();
                    //проверяем, как сыграл дилер
                    //если дилер набрал от 17 до 20 очков
                    if (currentGameStatus == Hand::GAME_CONTINUE) {
                        //вычисляем очки игрока и дилера
                        int playerScore = player1.calculateScore();
                        int dealerSCore = dealer.calculateScore();
                        //у игрока больше очков - победил игрок
                        if (playerScore > dealerSCore) {
                            cout << "Player1 win!" << endl;
                            break;
                        }
                        //у дилера больше - победил дилер
                        if (dealerSCore > playerScore) {
                            cout << "Dealer win!" << endl;
                            break;
                        }
                        //поровну - ничья
                        if (dealerSCore == playerScore) {
                            cout << "Draw!" << endl;
                            break;
                        }
                    }
                    else
                        //у дилера 21 очков - сразу выигрыш
                        if (currentGameStatus == Hand::WIN_) {
                            cout << "Dealer win!" << endl;
                            break;
                        }
                        else
                            //у дилера перебор - сразу проигрыш
                            if (currentGameStatus == Hand::LOOSE_) {
                                cout << "Dealer lose!" << endl;
                                break;
                            }
                }
    }
    return 0;
}