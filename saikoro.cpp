#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <regex>
#include <sstream>
#include <string>

// Credit to Martin Broadhurst for the "split" method used as the basis for this function.
// Link: http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
template<typename T>
void split(const std::string& str, std::list<T>& rollInstructions, const char delimiter = ' ')
{
    rollInstructions.clear();

    std::stringstream input(str);
    std::string token;

    std::stringstream conversion;
    T convertedToken;

    while (std::getline(input, token, delimiter))
    {
        conversion << token;
        conversion >> convertedToken;

        rollInstructions.push_back(convertedToken);

        conversion.str(std::string());
        conversion.clear();
    }
}

void ParseInput(const std::list<std::string> & splitInput, std::list<std::list<unsigned int>> & rolls)
{
    // First number can be any integer in the range [1, 100].
    // Middle character can be 'd'.
    // Second number can be any integer in the range [2, 100].
    std::regex pattern("^(100|[1-9][0-9]?)([d])(100|[2-9][0-9]?)$");

    std::string token;
    for (auto s : splitInput)
    {
        if (std::regex_match(s, pattern))
        {
            std::list<unsigned int> currentRoll;
            split(s, currentRoll, 'd');
            rolls.emplace_back(currentRoll);
        }
    }
}

void RollDice(std::list<unsigned int> & rolls)
{
    unsigned int numRolls = rolls.front();
    unsigned int numSides = rolls.back();
    rolls.clear();

    std::random_device randomDevice;
    std::mt19937 engine(randomDevice());
    std::uniform_int_distribution<unsigned int> distribution(1, numSides);

    for (unsigned int i = 0; i < numRolls; i++)
    {
        rolls.emplace_back(distribution(engine));
    }
}

void PrintRolls(const std::list<unsigned int>& rolls)
{
    auto sum = std::accumulate(rolls.begin(), rolls.end(), 0);

    std::cout << sum << ": ";
    for (const auto roll : rolls)
    {
        std::cout << roll << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::string input;
    std::list<std::string> splitInput;
    std::list<std::list<unsigned int>> rolls;

    while (input != "end")
    {
        std::getline(std::cin, input);
        split(input, splitInput);
        ParseInput(splitInput, rolls);

        for (auto roll: rolls)
        {
            RollDice(roll);
            PrintRolls(roll);
        }

        std::cout << std::endl;

        splitInput.clear();
        rolls.clear();
    }

    return 0;
}