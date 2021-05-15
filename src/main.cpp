#include <ostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Wordlist.hpp"
#include "Game.hpp"

int loop();
void printHelp();
void initGame(std::string);

int main(){
	std::cout << "Welcome to Hangman!" << std::endl;
	loop();
	return 0;
}

int loop(){
	Wordlist *wl = new Wordlist("wordlist");

	bool on = true;
	char x;
	std::cout << "Press h to print help" << std::endl;
	std::string word;
	while(on){
		std::cin >> x;
		switch(x){
			case 'h':
				printHelp();
				break;
			case 'a':
				std::cout << "Type the word to add" << std::endl;
				std::cin >> word;
				wl->addWord(word);
				break;
			case 'd':
				std::cout << "Type the word to delete" << std::endl;
				std::cin >> word;
				wl->deleteWord(word);
				std::cout << "Word deleted!" << std::endl;
				break;
			case 'l':
				std::cout << "List of words:" << std::endl;
				wl->listWords();
				break;
			case 'p':
				initGame(wl->pickWord());
				break;
			case 'q':
				on = false;
				break;
		}
	}
	return 0;
}

void initGame(std::string word){
	Game *game = new Game(word);
	game->gameLoop();
	delete game;
}

void printHelp(){
	std::cout << " h - print help" << std::endl
		<< " a - add a word" << std::endl
		<< " d - delete a word" << std::endl
		<< " l - list words" << std::endl
		<< " p - play game" << std::endl
		<< " q - quit" << std:: endl;
}