#pragma once
#include "Card.h"

#include <vector>
#include <string>

class Hand
{
	std::vector<Card> m_cards;
	
public:
	void reset();
	void addCard(const Card card);
	const std::vector<Card>& getCards();
	const int getValue();
	const std::string toString();
	const bool isBusted();
};

