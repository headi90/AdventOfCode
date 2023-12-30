#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <iostream>
#include <vector> // Add missing include statement for the 'vector' library

#include "../common.hpp"

using Hand = std::pair<std::string, long long>;
using Hands = std::vector<Hand>;

const std::map<char, long long> cardsVals1 = {
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'J', 11},
    {'Q', 12},
    {'K', 13},
    {'A', 14},
};

const std::map<char, long long> cardsVals2 = {
    {'J', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'Q', 11},
    {'K', 12},
    {'A', 13},
};

bool isAllCarsDifferent(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());
  auto it = std::unique(cards.begin(), cards.end());
  return it == cards.end();
}

bool isPair(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());

  for (auto i = 0; i < cards.size() - 1; i++)
  {
    if (cards[i] == cards[i + 1])
    {
      return true;
    }
  }
  return false;
}

bool isTwoPairs(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());

  int pairs = 0;
  for (auto i = 0; i < cards.size() - 1; i++)
  {
    if (cards[i] == cards[i + 1])
    {
      pairs++;
      i++;
    }
  }
  return pairs == 2;
}

bool isThreeOfKind(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());

  for (auto i = 0; i < cards.size() - 2; i++)
  {
    if (cards[i] == cards[i + 1] && cards[i] == cards[i + 2])
    {
      return true;
    }
  }
  return false;
}

bool isFullHouse(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());

  if (cards[0] == cards[1] && cards[1] == cards[2] && cards[3] == cards[4])
  {
    return true;
  }
  if (cards[0] == cards[1] && cards[2] == cards[3] && cards[3] == cards[4])
  {
    return true;
  }
  return false;
}

bool isFourOfKind(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());

  for (auto i = 0; i < cards.size() - 3; i++)
  {
    if (cards[i] == cards[i + 1] && cards[i] == cards[i + 2] && cards[i] == cards[i + 3])
    {
      return true;
    }
  }
  return false;
}

bool isFiveOfKind(const std::string &hand)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end());

  for (auto i = 0; i < cards.size() - 4; i++)
  {
    if (cards[i] == cards[i + 1] && cards[i] == cards[i + 2] && cards[i] == cards[i + 3] && cards[i] == cards[i + 4])
    {
      return true;
    }
  }
  return false;
}

bool compareCards(const char &a, const char &b, const std::map<char, long long> &cardsVals)
{
  return cardsVals.at(a) < cardsVals.at(b);
}

bool compareCards2(const char &a, const char &b)
{
  return compareCards(a, b, cardsVals2);
}

int getHandValue(const std::string &hand)
{
  if (isFiveOfKind(hand))
  {
    return 7;
  }
  if (isFourOfKind(hand))
  {
    return 6;
  }
  if (isFullHouse(hand))
  {
    return 5;
  }
  if (isThreeOfKind(hand))
  {
    return 4;
  }
  if (isTwoPairs(hand))
  {
    return 3;
  }
  if (isPair(hand))
  {
    return 2;
  }
  if (isAllCarsDifferent(hand))
  {
    return 1;
  }
  return 0;
}

bool compareHands1(const Hand &a, const Hand &b)
{
  auto aHandValue = getHandValue(a.first);
  auto bHandValue = getHandValue(b.first);

  if (aHandValue == bHandValue)
  {
    for (auto i = 0; i < a.first.size(); i++)
    {
      if (a.first[i] == b.first[i])
      {
        continue;
      }
      return compareCards(a.first[i], b.first[i], cardsVals1);
    }
  }

  return aHandValue < bHandValue;
}

int countJokersOnHand(const std::string &hand)
{
 return std::count(hand.begin(), hand.end(), 'J');
}

char getMostCommonCard(const std::string &hand, int jokers)
{
  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));

  std::sort(cards.begin(), cards.end(), compareCards2);

  int max = 0;
  char maxCard = cards[jokers];
  for(auto i = jokers; i < cards.size(); i++){
    auto count = std::count(cards.begin(), cards.end(), cards[i]);
    if(count > max){
      max = count;
      maxCard = cards[i];
    }
  }
  return maxCard;
}

std::string modifyHandWithJokers(const std::string &hand)
{
  auto jokers = countJokersOnHand(hand);

  if (jokers == 0 || isFiveOfKind(hand))
  {
    return hand;
  }

  std::vector<char> cards{};
  std::copy(hand.begin(), hand.end(), std::back_inserter(cards));
  std::sort(cards.begin(), cards.end(), compareCards2);

  auto mostCommonCard = getMostCommonCard(hand, jokers);

  for(auto i = 0; i < jokers; i++){
    cards[i] = mostCommonCard;
  }

  return std::string(cards.begin(), cards.end());
}

bool compareHands2(const Hand &a, const Hand &b)
{
  auto aHand = modifyHandWithJokers(a.first);
  auto bHand = modifyHandWithJokers(b.first);

  auto aHandValue = getHandValue(aHand);
  auto bHandValue = getHandValue(bHand);

  if (aHandValue == bHandValue)
  {
    for (auto i = 0; i < a.first.size(); i++)
    {
      if (a.first[i] == b.first[i])
      {
        continue;
      }
      return compareCards(a.first[i], b.first[i], cardsVals2);
    }
  }

  return aHandValue < bHandValue;
}

long solve1(std::vector<std::string> &input)
{
  long result = 0;
  Hands hands{};

  for (auto &line : input)
  {
    auto cardsScore = split(line, ' ', false);
    auto score = stringToNum<long long>(cardsScore[1]);
    hands.push_back(std::make_pair(cardsScore[0], score));
  }

  std::sort(hands.begin(), hands.end(), compareHands1);

  for(auto i = 0; i < hands.size(); i++){
    auto v = (i+1) * hands[i].second;
    result += v;
  }

  return result;
}

long solve2(std::vector<std::string> &input)
{
  long result = 0;
  Hands hands{};

  for (auto &line : input)
  {
    auto cardsScore = split(line, ' ', false);
    auto score = stringToNum<long long>(cardsScore[1]);
    hands.push_back(std::make_pair(cardsScore[0], score));
  }

  std::sort(hands.begin(), hands.end(), compareHands2);

  for(auto i = 0; i < hands.size(); i++){
    auto v = (i+1) * hands[i].second;
    result += v;
  }

  return result;
}


int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
    return 1;
  }
  std::string input_file(argv[1]);

  auto input = readFile(input_file);

  auto answer1 = solve1(input);

  auto answer2 = solve2(input);

  std::cout << '\n'
            << "Answer 1: "
            << answer1 << "\nAnswer 2: " << answer2 << std::endl;

  return 0;
}
