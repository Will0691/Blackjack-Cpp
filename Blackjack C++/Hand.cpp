#include "Hand.h"
#include <sstream>
const int max_playable_value = 21;
const int ace_threshold = 11;
const int ace_value = 10;

void Hand::reset()
{
	this->m_cards.clear();
}

void Hand::addCard(const Card card)
{
	this->m_cards.push_back(card);
}

const std::vector<Card>& Hand::getCards()
{
	return this->m_cards;
}

const int Hand::getValue()
{
	bool hasAce = false;
	int value = 0;

	for (size_t i = 0; i < this->m_cards.size(); i++)
	{
		value += this->m_cards[i].getValue();
		if (this->m_cards[i].getValue() == 1) { hasAce = true; }
	}

	if (hasAce && value <= ace_threshold) {
		value += ace_value;
	}

	return value;
}

const std::string Hand::toString()
{
	std::stringstream result;
	for (size_t i = 0; i < this->m_cards.size(); i++)
	{
		if (i > 0) { result << ", "; }
		result << this->m_cards[i].toString();
	}
	result << std::endl;
	result << "\tTotal Value: " << this->getValue();
	return result.str();
}

const bool Hand::isBusted()
{
	return this->getValue() > max_playable_value;
}
