#include "FileManager.hpp"
#include <vector>
#include <string>

class Wordlist{
	FileManager *fm;
	std::vector<std::string> wordlist;

	public:
		int addWord(std::string word);
		int deleteWord(std::string word);
		void listWords();
		std::vector<std::string> getWordVector();
		std::string pickWord();
		Wordlist(std::string filename);
};