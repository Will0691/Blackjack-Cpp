#include "Game.h"
#include <iostream>
#include <vector>

const int dealer_hit_threshold = 17;
const int max_hand_value = 21;

void Game::p_reset()
{
	do {
		this->m_gamedeck.reset();

		this->m_dealer_hand.reset();
		this->p_init_dealer_hand();

		this->m_player_hand.reset();
		this->m_player_hand.addCard(this->m_gamedeck.draw_card());
		this->m_player_hand.addCard(this->m_gamedeck.draw_card());
	} 
	//Not allowing the player to instantly win or lose without having had the chance to even do anything
	while (this->m_player_hand.getValue() >= 21);
}

void Game::p_init_dealer_hand()
{
	while (this->m_dealer_hand.getValue() < dealer_hit_threshold)
	{
		this->m_dealer_hand.addCard(this->m_gamedeck.draw_card());
	}
}

const void Game::p_print_hand_player()
{
	std::cout << "Your Cards: " << this->m_player_hand.toString() << std::endl;
}

const void Game::p_print_hand_dealer()
{
	std::vector<Card> dealer_cards = this->m_dealer_hand.getCards();
	std::cout << "Your dealer currently has " << dealer_cards.size() << " cards in their hand" << std::endl;
	std::cout << "\tOne of the cards is: " << dealer_cards[0].toString() << std::endl;
}

void Game::p_hit_player()
{
	Card card = this->m_gamedeck.draw_card();
	this->m_player_hand.addCard(card);
	std::cout << "You added " << card.toString() << " to your hand" << std::endl;
}

const void Game::p_stand()
{
	std::cout << "Your hand: " << this->m_player_hand.toString() << std::endl;
	std::cout << "Dealer hand: " << this->m_dealer_hand.toString() << std::endl;

	if (this->m_dealer_hand.isBusted()){
		std::cout << "Dealer busted!" << std::endl << "You Win!" << std::endl;
	}
	else
	{
		int player_value = this->m_player_hand.getValue();
		int dealer_value = this->m_dealer_hand.getValue();

		std::string message = (player_value == dealer_value) ? "Draw..." : (player_value > dealer_value) ? "You Win!" : "You Lost :(";
		std::cout << message << std::endl;
	}
}

const int Game::p_get_player_input()
{
	int input = 0;
	while (input == 0)
	{
		std::cout << "What will you do?" << std::endl;
		std::cout << "1. Hit" << '\t' << "2. Stand" << std::endl;
		std::string s;
		std::cin >> s;
		if (s == "1") { input = 1; }
		else if (s == "2") { input = 2; }
		else { std::cout << "Invalid Choice! Please try again" << std::endl; }
	}
	return input;
}

const bool Game::p_will_player_quit()
{
	std::string input;
	while (input != "Y" && input != "N")
	{
		std::cout << "Do you want to play again?" << std::endl;
		std::cout << "Y/N" << std::endl;
		std::cin >> input;
		
		if (input == "Y" or input == "N") break;

		if (input == "y") { input = "Y"; break; }
		else if (input == "n") { input = "N"; break; }
		else { std::cout << "Invalid Choice! Please try again" << std::endl; }
	}
	return input == "N";
}

Game::Game()
{
	this->p_reset();
}

void Game::run()
{
	bool quit = false;
	bool show_quit_prompt = false;

	while (true)
	{
		if (show_quit_prompt) { 
			if (this->p_will_player_quit()) { break; }
			else { show_quit_prompt = false; this->p_reset(); }
		}

		this->p_print_hand_player();
		this->p_print_hand_dealer();

		int input = this->p_get_player_input();
		switch (input)
		{
		case 1:
			this->p_hit_player();
			if (this->m_player_hand.getValue() == max_hand_value)
			{
				std::cout << "You hit a value of 21!\nAutomatically standing now!" << std::endl;
				input = 2;
			} else if (this->m_player_hand.isBusted()) {
				std::cout << "Busted!" << std::endl;
				this->p_print_hand_player();
				show_quit_prompt = true;
				break;
			}
			else { break; }
		case 2:
			show_quit_prompt = true;
			this->p_stand();
			break;
		default:
			break;
		}
	}
	std::cout << "Bye!" << std::endl;
}
