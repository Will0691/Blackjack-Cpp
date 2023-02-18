#pragma once
#include "Deck.h"
#include "Hand.h"

class Game
{
	Deck m_gamedeck;
	Hand m_dealer_hand;
	Hand m_player_hand;

	void p_reset();
	void p_init_dealer_hand();

	const void p_print_hand_player();
	const void p_print_hand_dealer();

	void p_hit_player();
	const void p_hold();

	const int p_get_player_input();
	const bool p_will_player_quit();

public:
	Game();
	void run();
};

