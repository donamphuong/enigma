#include "Main.hpp"

int main(int argc, char **argv)
{
  if(strstr(argv[argc-1], ".pb")) {
    ifstream pb(argv[argc - 1]);
    string pbconfig;
    getline(pb, pbconfig);
    plugboard.setMap(process(pbconfig));

    if(argc > 2) {
      numRotors = 0, rotation = 0;
      for(int i = 1; i < argc - 1; i++) {
        ifstream rotor(argv[i]);

        if(!rotor.is_open()) {
          perror("The file cannot be opened");
        } else {
          string decrypt;
          getline(rotor, decrypt);
          Rotor* newRotor = new Rotor(process(decrypt));

          rotorsOrd.push_back(argv[i]);
          rotors.emplace(make_pair(argv[i], *newRotor));
        }
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

    if(rotation%26 != 0) {
      int num = findChar(charToInt(msg.at(i)));
      res += intToChar(num);
    }

    rotateRotors();
  }

  return res;
}

void rotateRotors() {
  if(!rotorsOrd.empty()) {
    int size = rotorsOrd.size();

    for(int i = 0; i <= numRotors; i++) {
      rotors.find(rotorsOrd.at(i%size))->second.rotate();

      if((rotation + 1)%26 == 0) {
        for(int i = 0 ; i <numRotors; i++) {
          rotors.find(rotorsOrd.at(i%size))->second.rotate();
        }
        numRotors = (rotation + 1)/26;
      }

      rotation++;
    }
  }
}

//enigma machine
int findChar(int x)
{
  int index;
  cout << x << " ";
  x = plugboard.map(x);
  cout << x << " ";

  for(int i = 0; i < rotorsOrd.size(); i++) {
    index = i - 1 >= 0 ? rotation%26 : 0;
    x = findRotor(i).rotor(x < rotation%26 && index > 0 ? 26 + x - index : x - index);
    cout << "rotation : (" << rotation << ") " << x << " ";
  }

  x = reflector(x);
  cout << x << " ";
  for(int j = rotorsOrd.size() - 1; j >= 0; j--) {
    index = j + 1 < rotorsOrd.size() ? rotation%26 : 0;
    x = findRotor(j).reverseRotor((x + index)%26);
    cout /*<< "index: (" << index << ") "*/ << x << " ";
  }
  cout << "\n";
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

Rotor findRotor(int index) {
  return rotors.find(rotorsOrd.at(index))->second;
}

//returns a character that is 13 characters ahead of the input char
int reflector(int x)
{
  return (x + 13) % 26;
}
