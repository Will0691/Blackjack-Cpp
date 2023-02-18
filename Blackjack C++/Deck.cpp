#include "Deck.h"
#include <array>
#include <time.h>
#include <algorithm>

const int max_value = 13;
const int number_of_suits = 4;

Deck::Deck()
{
	this->reset();
}

void Deck::reset()
{
	this->m_cards.clear();

	for (size_t i = 0; i < max_value; i++)
	{
		for (Suits j = Hearts; j < number_of_suits; j=Suits(j+1))
		{
			this->m_cards.push_back(Card(i + 1, j));
		}
	}

	srand(unsigned(time(NULL)));
	std::random_shuffle(this->m_cards.begin(), this->m_cards.end());
}

Card& Deck::draw_card()
{
	Card card = this->m_cards.back();
	this->m_cards.pop_back();
	return card;
}
