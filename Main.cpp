#include "Main.hpp"

int main(int argc, char **argv)
{
  if(strstr(argv[argc-1], ".pb")) {
    ifstream pb(argv[argc - 1]);
    string pbconfig;
    getline(pb, pbconfig);
    plugboard.setMap(process(pbconfig));

    for(int i = 1; i < argc - 1; i++) {
      ifstream rotor(argv[i]);

      if(!rotor.is_open()) {
        perror("The file cannot be opened");
      } else {
        string decrypt;
        getline(rotor, decrypt);
        Rotor* newRotor = new Rotor(process(decrypt));

        rotors.push_back(*newRotor);
      }
    }

    string message;
    //cout << "Please enter a message to be decrypted\n";
    cin >> message;
    cout << decrypt(message) << "\n";
  } else {
    perror("The encoding is invalid");
    return 1;
  }
}

string decrypt(string msg)
{
  string res = "";

  for(int i = 0; i < msg.size(); i++) {
    int num = findChar(charToInt(msg.at(i)));

    res += intToChar(num);
    rotors.at(0).rotate();
  }

  return res;
}

//enigma machine
int findChar(int x)
{
  x = plugboard.map(x);

  for(int i = 0; i < rotors.size(); i++) {
    x = rotors.at(i).rotor(x);
  }

  x = reflector(x);

  for(int j = rotors.size() - 1; j >= 0; j--) {
    x = rotors.at(j).reverseRotor(x);
  }
  
  cout << plugboard.map(x) << "\n";
  return plugboard.map(x);
}

//convert a string of ints into an array of ints
vector<int> process(string config)
{
  vector<int> res;
  string num = "";

  for(int i = 0; i < config.size(); i++) {
    if(config.at(i) != ' ') {
      num += config[i];
    }

    if(config.at(i) == ' ' || i == config.size() - 1) {
      res.push_back(atoi(num.c_str()));
      num = "";
    }
  }

  return res;
}

//returns a character that is 13 characters ahead of the input char
int reflector(int x)
{
  return (x + 13) % 26;
}
