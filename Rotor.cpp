#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Rotor
{
  vector<int> map;
  int offset = 0;

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

    void printVector() {
      for(int i = 0; i < map.size(); i++) {
        cout << map.at(i) << " ";
      }
      cout << "\n";
    }

    void rotate() {
      offset = (offset+1)%26;
      //if(offset == 0) {
        //offset = 1;
      //}
    }

    int getOffset() {
      return offset;
    }
};
