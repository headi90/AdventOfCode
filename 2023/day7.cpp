#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <iostream>
#include <vector> // Add missing include statement for the 'vector' library

#include "../common.hpp"

using Hand = std::pair<std::string, long long>;
using Hands = std::vector<Hand>;

const std::map<char, long long> cards = {
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

bool isAllCarsDifferent(const std::string &hand)
{
  std::vector<char> cards{};
  for (auto &c : hand)
  {
    cards.push_back(c);
  }
  std::sort(cards.begin(), cards.end());
  auto it = std::unique(cards.begin(), cards.end());
  return it == cards.end();
}

bool isPair(const std::string &hand)
{
  std::vector<char> cards{};
  for (auto &c : hand)
  {
    cards.push_back(c);
  }

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
  for (auto &c : hand)
  {
    cards.push_back(c);
  }

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
  for (auto &c : hand)
  {
    cards.push_back(c);
  }

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
  for (auto &c : hand)
  {
    cards.push_back(c);
  }

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
  for (auto &c : hand)
  {
    cards.push_back(c);
  }

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
  for (auto &c : hand)
  {
    cards.push_back(c);
  }

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

bool compareCards(const char &a, const char &b)
{
  return cards.at(a) < cards.at(b);
}

//get hand value
// 1. all cards are different
// 2. pair
// 3. two pairs
// 4. three of kind
// 5. full house
// 6. four of kind
// 7. five of kind
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

bool compareHands(const Hand &a, const Hand &b)
{
  Hand aHand = a;
  Hand bHand = b;

  auto aHandValue = getHandValue(aHand.first);
  auto bHandValue = getHandValue(bHand.first);

  // std::cout << aHand.first << " " << aHandValue << " " << bHand.first << " " << bHandValue << std::endl;

  if (aHandValue == bHandValue)
  {
    for (auto i = 0; i < aHand.first.size(); i++)
    {
      if (aHand.first[i] == bHand.first[i])
      {
        continue;
      }
      return cards.at(aHand.first[i]) < cards.at(bHand.first[i]);
    }
  }

  return aHandValue < bHandValue;
  
  return false;
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

  // std::cout << "before sort" << std::endl; 
  // for(auto &hand: hands){
  //   std::cout << hand.first << " " << hand.second << std::endl;
  // }
  // std::cout << std::endl;

  std::sort(hands.begin(), hands.end(), compareHands);

  // std::cout << "\nafter sort" << std::endl;
  // for(auto &hand: hands){
  //   std::cout << hand.first << " " << hand.second << std::endl;
  // }
  // std::cout << std::endl;

  // std::vector<std::string> hands1{
  //     "23456", "22345", "23445", "22344", "77884", "65477", "74537", "AAA23", "23242",
  //     "32323", "23232", "AAKKK", "KKAAA", "22222", "KKKKK", "AAAAA", "KKAKK", "23333", "33332", "33322", "33222", "22223", "22233", "22333", "23332", "23322", "22322"};

  // for (auto &hand : hands1)
  // {
  //   std::cout << hand << " " << isAllCarsDifferent(hand) << " " << isPair(hand) << " " << isTwoPairs(hand) << " " << isThreeOfKind(hand) << " " << isFullHouse(hand) << " " << isFourOfKind(hand) << " " << isFiveOfKind(hand) << std::endl;
  // }

  for(auto i = 0; i < hands.size(); i++){
    auto v = (i+1) * hands[i].second;
    result += v;
    std::cout << hands[i].first << " " << hands[i].second << " " << v << std::endl;
    }

  return result;
}

int solve2(std::vector<std::string> &input)
{
  long result = 0;

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
