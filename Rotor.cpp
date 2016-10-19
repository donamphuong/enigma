class Rotor
{
  int size = 26;
  int* map;

  public:
    Rotor(int* newMap) {
      map = newMap;
    }

    int rotor(int index) {
      return map[index];
    }

    int reverseRotor(int value) {
      for(int i = 0; i < size; i++) {
        if(value == map[i]) {
          return i;
        }
      }
      return -1;
    }

    void rotate() {
      int first = 0;

      for(int i = 0; i < size; i++) {
        if(i == 0) {
          first = i;
        } else {
          map[i - 1] = map[i];
        }
      }

      map[size - 1] = first;
    }
};
