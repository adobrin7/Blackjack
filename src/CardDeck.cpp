#include "CardDeck.h"

CardDeck::CardDeck()
{
	// creates all ranks for each card suit

	int card = 0;
	for (int suit = 0; suit < Card::MAX_SUITS; ++suit)
	{
		for (int rank = 0; rank < Card::MAX_RANKS; ++rank)
		{
			m_deck[card] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
			++card;
		}
	}
}

Card& CardDeck::operator[](const int card)
{
	// returns card from the deck

	assert(card >= 0 && card < config::k_deckSize);	// card in deck
	return m_deck[card];
}


void CardDeck::printDeck() const
{
	// prints column of card defenitions

	for (int card = 0; card < config::k_deckSize; ++card)
	{
		m_deck[card].print();
		std::cout << "\n";
	}
}

void CardDeck::swapCards(Card& first, Card& second)
{
	// exchange card values using default = operator

	Card temp = first;
	first = second;
	second = temp;
}
void CardDeck::shuffle()
{
	// swaps every fourth card in the deck with random card

	for (int currentCard = 0; currentCard < config::k_deckSize; currentCard += 4)
	{
		int randomCard = rand() % (config::k_deckSize - 1);	// index needed
		swapCards(m_deck[currentCard], m_deck[randomCard]);
	}
	m_dealingCardIndex = 0;	// after shuffling dealing card is on top again
}

const Card& CardDeck::dealCard()
{
	// returns card from top of deck, changes top index

	assert(m_dealingCardIndex < 52);
	return m_deck[m_dealingCardIndex++];
}