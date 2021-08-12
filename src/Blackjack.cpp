/*starts and continues game while user wants to play,
announces result every round*/

#include "CardDeck.h"

char getPlayerChoice()
{
	// reads, checks and returns players input

	while (true)
	{
		std::cout << "To hit new card enter 'h', to stand enter 's': ";
		char choice;
		std::cin >> choice;
		if (choice == 'h')
			return 'h';
		else if (choice == 's')
			return 's';
	}
}

enum class RoundResult
{
	WON,
	LOST,
	DRAW
};

RoundResult startRound(CardDeck& cardDeck)
{
	// starts game according to standard rools

	int dealerTotal = 0;
	dealerTotal += cardDeck.dealCard().getRankValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	int playerTotal = 0;
	playerTotal += cardDeck.dealCard().getRankValue();
	playerTotal += cardDeck.dealCard().getRankValue();

	while (true)
	{
		std::cout << "You have: " << playerTotal << '\n';
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += cardDeck.dealCard().getRankValue();

		if (playerTotal > 21)
			return RoundResult::LOST;
	}

	while (dealerTotal < 17)
		dealerTotal += cardDeck.dealCard().getRankValue();

	std::cout << "The dealer now has: " << dealerTotal << '\n';

	if (dealerTotal > 21)
		return RoundResult::WON;
	else if (dealerTotal == playerTotal)
		return RoundResult::DRAW;
	else if (dealerTotal > playerTotal)
		return RoundResult::LOST;

	return RoundResult::WON;
}

bool askToContinue()
{
	// asks player to continue, checks input

	while (true)
	{
		std::cout << "Play again? (y/n): ";
		char choice;
		std::cin >> choice;
		std::cin.ignore(32767, '\n');
		if (choice == 'n')
			return false;
		else if (choice == 'y')
			return true;
	}
}

int main()
{
	srand(time(NULL));
	CardDeck cardDeck;

	std::cout << "Welcome to the game!\n";
	do
	{
		system("cls");
		cardDeck.shuffle();

		switch (startRound(cardDeck))
		{
		case RoundResult::WON:	std::cout << "You won!\n";	break;
		case RoundResult::DRAW:	std::cout << "Draw!\n";		break;
		case RoundResult::LOST:	std::cout << "You lost\n";	break;
		}
	} while (askToContinue());

	return 0;
}
