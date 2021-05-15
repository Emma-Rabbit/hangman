#include <ostream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "FileManager.hpp"

std::vector<std::string> FileManager::listWords(){
	std::ifstream file(filename);
	if(!file.is_open()){
		throw 1;
	}
	
	std::string data;
	std::vector<std::string> vec;
	while(std::getline(file, data)){
		vec.push_back(data);
	}

	file.close();

	return vec;
}

int FileManager::appendToFile(std::string word){
	std::ofstream file(filename, std::ios_base::app);
	if(file.is_open()){
		file << word << '\n';
		file.close();
	}
	else{
		return 1;
	}
	return 0;
}

int FileManager::overwriteFile(std::string data){
	std::ofstream file(filename);
	if(!file.is_open()){return 1;}

	file << data;
	file.close();
	return 0;
}

FileManager::FileManager(std::string filename){
	this->filename = filename;
}