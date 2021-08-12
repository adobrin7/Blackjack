#pragma once

/*implementation of the logic for working with a deck of cards*/

#include "Card.h"

class CardDeck
{
private:
	Card m_deck[config::k_deckSize];
	int m_dealingCardIndex = 0;

public:
	CardDeck();
	Card& operator[](const int index);

	void printDeck() const;

	static void swapCards(Card& first, Card& second);
	void shuffle();

	const Card& dealCard();
};
