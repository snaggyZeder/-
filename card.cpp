//#include "card.h"
#include <iostream>
#include "card.h"
using namespace std;
Card::Card() {
	m_suit = CARD_DIAMONDS;
	m_rank = CARD_2;
}
Card::Card(CardRank f_rank, CardSuits f_suit) {
	m_rank = f_rank;
	m_suit = f_suit;
}
void Card::print_card() {
	switch (m_rank) {
	case  CARD_2: cout << 2;
	case  CARD_3: cout << 3;
	case  CARD_4: cout << 4;
	case CARD_5: cout << 5;
	case CARD_6:  cout << 6;
	case CARD_7:  cout << 7;
	case CARD_8: cout << 8;
	case CARD_9: cout << 9;
	case CARD_10: cout << 10;
	case CARD_J: cout << "Ja ";
	case CARD_Q: cout << "Qu ";
	case CARD_K: cout << "Ki ";
	case CARD_A: cout << "A ";
	}
	//
	switch (m_suit){
	case CARD_DIAMONDS: cout << "D, ";
	case  CARD_HEARTS: cout << "H,";
	case CARD_SPADES: cout << "S,";
	case CARD_CLUBS: cout << "C,";
}
}

int Card::get_score() {
	switch (m_rank){
	case CARD_2: return 2;
	case CARD_3: return 3;
	case CARD_4: return 4;
	case CARD_5: return 5;
	case CARD_6: return 6;
	case CARD_7:return 7;
	case CARD_8: return 8;
	case CARD_9: return 9;
	case CARD_10: return 10;
	case CARD_J: return 10;
	case CARD_Q: return 10;
	case CARD_K: return 10;
	case CARD_A: return 11;
}
}

Card::CardRank Card::get_rank() {
	return m_rank;
}

Card::CardSuits Card::get_suits() {
	return m_suit;
}