#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Rotor
{
  vector<int> map;
  int rotation = 0;

  public:
    Rotor(vector<int> newMap) {
      map = newMap;
    }

    int rotor(int index) {
      return map.at(index);
    }

    int reverseRotor(int value) {
      for(int i = 0; i < map.size(); i++) {
        if(map.at(i) == value) {
          return i;
        }
      }
      exit(1);
    }

    void rotate() {
      ::rotate(map.begin(), map.begin()+1, map.end());
      //printVector();
    }

    void printVector() {
      for(int i = 0; i < map.size(); i++) {
        cout << map.at(i) << " ";
      }
      cout << "\n";
    }

};
