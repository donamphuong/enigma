// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

#include "Rotor.cpp"
#include "Plugboard.cpp"

using namespace std;
int findChar(int x);
vector<int> process(string config);
int reflector(int x);
string decrypt(string msg);
void rotateRotors();
Rotor findRotor(int index);

vector<string> rotorsOrd;
map<string, Rotor> rotors;
Plugboard plugboard;
int numRotors, rotation;

int charToInt(char c)
{
  if(c >= 'A' && c <= 'Z') {
    return c - 'A';
  }
  exit(1);
}

char intToChar(int x)
{
   if(x >= 0 && x <= 25) {
     return x + 'A';
   }
   exit(1);
}
