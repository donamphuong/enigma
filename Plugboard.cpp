#include <vector>

using namespace std;

class Plugboard
{
  vector<int> pairs;

  public:
    int map(int index);
    void setMap(vector<int> newPairs);
};

int Plugboard::map(int x)
{
  for(int i = 0; i < pairs.size();i++) {
    if(pairs.at(i) == x) {
      return x % 2 == 0 ? pairs.at(i+1) : pairs.at(i-1);
    }
  }
  return x;
}

void Plugboard::setMap(vector<int> newPairs)
{
  pairs = newPairs;
}
