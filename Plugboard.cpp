class Plugboard
{
  int* pairs;

  public:
    int map(int index);
    void setMap(int* newPairs);
};

int Plugboard::map(int x)
{
  for(int i = 0, length = sizeof(pairs)/sizeof(int); i < length; i++) {
    if(pairs[i] == x) {
      return x % 2 == 0 ? pairs[i + 1] : pairs[i - 1];
    }
  }
  return x;
}

void Plugboard::setMap(int* newPairs)
{
  pairs = newPairs;
}
