#pragma once
#include "Card.h"
#include <vector>

class Deck
{
	std::vector<Card> m_cards;

public:
	Deck();
	void reset();
	Card& draw_card();
};

