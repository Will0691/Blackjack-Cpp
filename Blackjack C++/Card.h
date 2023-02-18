#pragma once
#include <string>

enum Suits
{
	Hearts = 0, Diamonds = 1, Spades = 2, Clubs = 3
};

class Card
{
	int m_value;
	int m_suit;

public:
	Card(int value, Suits suit);
	
	const int getValue();
	const std::string getSuit();
	const std::string toString();
};

