#include <vector>
#include <string>

std::string vecToStr(std::vector<std::string> wordvec){
	std::string wordlist;
	for(int words = 0; words < wordvec.size(); words++){
		wordlist.append(wordvec[words]+'\n');
	}
	return wordlist;
}