#pragma once

/*provides the logic of interaction with card values*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Configuration.h"

class Card 
{
public:
	static enum Suit
	{
		SUIT_CLUB,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_SPADE,
		MAX_SUITS
	};
	static enum Rank
	{
		RANK_2,
		RANK_3,
		RANK_4,
		RANK_5,
		RANK_6,
		RANK_7,
		RANK_8,
		RANK_9,
		RANK_10,
		RANK_JACK,
		RANK_QUEEN,
		RANK_KING,
		RANK_ACE,
		MAX_RANKS
	};

private:
	Rank m_rank;
	Suit m_suit;

public:
	Card(Rank rank = MAX_RANKS, Suit suit = MAX_SUITS)
		: m_rank(rank), m_suit(suit)
	{
	}
	void print() const;
	int getRankValue() const;
};
