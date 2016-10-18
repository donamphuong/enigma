// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  ifstream plugboard(argv[argc - 1]);
  int** rotors;

  char* plugboardConfig;
  getline(plugboard, plugboardConfig);
  //int* pairs = processPlugboard(plugboardConfig);

  for(int i = 0; i < argc - 1; i++) {
    ifstream rotor(argv[i]);
    if(!rotor.is_open()) {
      perror("The file cannot be opened");
    } else {
      char* decrypt;
      getline(rotor, decrypt);
      //rotors[i] = process(decrypt);
    }
  }


}

int rotor(int* map, int x)
{
  return map[x];
}

int plugboard(int* pairs, int x)
{
  for(int i = 0, length = sizeof(pairs)/sizeof(int); i < length; i++) {
    if(pairs[i] == x) {
      return x % 2 == 0 ? pairs[i + 1] : pairs[i - 1];
    }
  }
  return x;
}

int reflector(int x)
{
  return (x + 13) % 26;
}
