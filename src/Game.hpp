#include <string>

class Game{
	std::string word;
	std::string word_ = "";
 	std::string guessed;
	int turnCount = 0;
	int guessedCount = 0;
	int mistakeCount = 0;
	const int maxmistakes = 7;
	bool gameOn = true;

	void setWord_();
	bool replaceGuessed();
	void printWord();
	void input();
	bool statusCheck();

	public:
		int gameLoop();
        Game(std::string);
};