#include <string>
#include <vector>

class FileManager{
    std::string filename;
    public:
        std::vector<std::string> listWords();
        int appendToFile(std::string word);
        int overwriteFile(std::string data);
        FileManager(std::string filename);
};