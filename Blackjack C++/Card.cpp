#include "Card.h"
#include <sstream>

Card::Card(int value, Suits suit)
{
	this->m_value = value;
	this->m_suit = suit;
}

const int Card::getValue()
{
	return (this->m_value >= 10) ? 10 : this->m_value;
}

const std::string Card::getSuit()
{
	switch (this->m_suit)
	{
	case Suits::Hearts:
		return "Hearts";
	case Suits::Diamonds:
		return "Diamonds";
	case Suits::Spades:
		return "Spades";
	default:
		return "Clubs";
	}
}

const std::string Card::toString()
{
	std::stringstream sstream;

	switch (this->m_value)
	{
	case 1:
		sstream << "Ace (1 or 11)";
		break;

	case 11:
		sstream << "Jack (10)";
		break;

	case 12:
		sstream << "Queen (10)";
		break;

	case 13:
		sstream << "King (10)";
		break;

	default:
		sstream << this->m_value;
		break;
	}
	sstream << " of " << this->getSuit();
	return sstream.str();
}
