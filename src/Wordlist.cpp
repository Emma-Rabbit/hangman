#include <iostream>
#include "helpers.hpp"
#include "Wordlist.hpp"

int Wordlist::addWord(std::string word){
	for(int words = 0; words < wordlist.size(); words++){
		if(wordlist[words] == word){
			std::cout << "This word is already on the list" << std::endl;
			return 1;
		}
	}
	wordlist.push_back(word);
	if(fm->appendToFile(word)){
		std::cout << "Could not add the word to file!" << std::endl;
	}
	std::cout << "Word added!" << std::endl;
	return 0;
}

int Wordlist::deleteWord(std::string word) {
	int index = -1;
	for(int words = 0; words < wordlist.size(); words++){
		if(wordlist[words] == word){
			index = words;
			break;
		}
	}
	if(index < 0){
		std::cout << "Word list doesn't contain this word" << std::endl;
		return 1;
	}
	wordlist.erase(wordlist.begin() + index);

	if(fm->overwriteFile(vecToStr(wordlist))){
		std::cout << "Could not overwrite file!" << std::endl;
	}

	return 0;
}

void Wordlist::listWords(){
	for(int words = 0; words < wordlist.size(); words++){
		std::cout << wordlist[words] << std::endl;
	}
}

std::vector<std::string> Wordlist::getWordVector(){
	return wordlist;
}

std::string Wordlist::pickWord(){
	srand(time(0));
	std::cout << time(0) << std::endl;
	int n = rand() % wordlist.size();
	std::string word = wordlist[n];
	std::cout << word << std::endl;
	return word;
}

Wordlist::Wordlist(std::string filename){
	FileManager *fm = new FileManager(filename);
	this->fm = fm;
	try{
		this->wordlist = fm->listWords();
	}
	catch(int e){
		std::cout << "Could not load word list file!" << std::endl;
	}
}