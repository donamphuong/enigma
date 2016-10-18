// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int* process(string config);

int main(int argc, char **argv)
{
  //ifstream plugboard(argv[argc - 1]);
  int** rotors;

  //string plugboardConfig;
  //getline(plugboard, plugboardConfig);
  //processPlugboard(plugboardConfig);
  
  for(int i = 0; i < argc - 1; i++) {
    ifstream rotor(argv[i]);
    if(!rotor.is_open()) {
      perror("The file cannot be opened");
    } else {
      string decrypt;
      getline(rotor, decrypt);
      cout << decrypt << "\n";
      rotors[i] = process(decrypt);
    }
  }


}

int* process(string config) 
{
  int* res = new int[26];
  string num = "";
  int index = 0;  

  for(int i = 0; i < config.size(); i++) {
    if(config.at(i) != ' ') {
      num += config[i];
    } 
    
    if(config.at(i) == ' ' || i == config.size() - 1) {
      res[index] = atoi(num.c_str());
      num = "";
      index++;
    }
  }
  
  return res;
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
