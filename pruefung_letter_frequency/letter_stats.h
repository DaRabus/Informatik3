#ifndef LETTER_STATS_H
#define LETTER_STATS_H
#include <set>
#include <string>

class LetterStats
{
public:
    LetterStats();

    void updateChar(char c);
    void updateString(const std::string &str);
    void updateFile(const std::string &filename);

    void print();

private:
    std::set<std::string> letters;

};

#endif // LETTER_STATS

