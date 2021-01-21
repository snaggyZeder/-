#include"deck.h"
#include"card.h"
#include<vector>
#include"hand.h"
#include"player.h"
#include <string>
#include"dealer.h"
using namespace std;

void Dealer::playd(Deck& fdeck) {
	
	do {
		takeOneCard(fdeck);
	} while (calculateScore() < 17);
	printHand();
	cout << "dialer summ is " << calculateScore() << endl;
}