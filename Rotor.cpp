#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Rotor
{
  vector<int> map;
  int offset = 0;
  int rotation = 0;

  public:
    Rotor(vector<int> newMap) {
      for(int i = 0; i < newMap.size(); i++) {
        map.push_back(newMap.at(i) - i);
      }
    }

    int rotor(int index) {
      int val = map.at(transform(index + offset)) + index;
      return transform(val);
    }

    int reverseRotor(int value) {
      for(int i = 0; i < map.size(); i++) {
        int val =  i + map.at(transform(i + offset));

        if(value == transform(val)) {
          return i;
        }
      }
      exit(1);
    }

    int transform(int x) {
      if(x < 0) {
        x += 26;
      }
      return x%26;
    }

    void printVector() {
      for(int i = 0; i < map.size(); i++) {
        cout << map.at(i) << " ";
      }
      cout << "\n";
    }

    void rotate() {
      offset = (offset+1)%26;
      rotation++;
    }

    int getOffset() {
      return offset;
    }

    int getRotation() {
      return rotation;
    }

    void setOffset(int value) {
      offset = value;
    }
};
