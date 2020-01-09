#ifndef DICTIONARY_H
#define DICTIONARY_H



#include <set>
#include <string>



class Dictionary
{
public:
	Dictionary();
	void loadFromFile(const std::string &filename);
	void checkFile(const std::string &inFilename,
		const std::string &outFilename);

private:

	std::set<std::string> words;

	bool wordIsOkay(const std::string &word);
    std::string normalizeWord(std::string &word);
	std::string toUppercase(const std::string &word);
};



#endif // DICTIONARY_H
