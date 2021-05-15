#include <string>
#include <iostream>
#include "Game.hpp"

void Game::setWord_(){
	for(int i = 0; i < word.size(); i++){
		word_.append("_");
	}
}

bool Game::replaceGuessed(){
	bool correctGuess = false;
	char c = guessed[guessed.size() - 1];
	for(int i = 0; i < word.size();i++){
		if(word[i] == c){
			word_[i] = c;
			guessedCount++;
			correctGuess = true;
		}
	}
	return correctGuess;
}

void Game::printWord(){
	for(int i = 0; i < word_.size(); i++){
		std::cout << word_[i] << " ";
	}
	std::cout << std::endl << std::endl;
}

void Game::input(){
	bool inputneeded;
	char x;
	do{
		inputneeded = false;
		std::cin >> x;
		for(int c = 0; c < guessed.size(); c++){
			if(guessed[c] == x){
				std::cout << "You already picked this character!" << std::endl;
				inputneeded = true;
				break;
			}
		}
	}while(inputneeded);
	guessed.push_back(x);
	std::cout << std::endl;
}

bool Game::statusCheck(){
	if(guessedCount == word.size()){
		std::cout << "You won!" << std::endl;
		return true;
	}
	if(mistakeCount == maxmistakes){
		std::cout << "You lost! " << std::endl;
		return true;
	}
	return false;
}


int Game::gameLoop(){
	setWord_();
	printWord();
	while(gameOn){
		turnCount++;
		std::cout << "Turns: " << turnCount << std::endl
		<< "Mistakes: " << mistakeCount << "/" << maxmistakes <<  std::endl;
		input();
		if(!replaceGuessed()){
			mistakeCount++;
		}
		printWord();
		gameOn = !statusCheck();
	}
	return 0;
}

Game::Game(std::string word){
	this->word = word;
}
