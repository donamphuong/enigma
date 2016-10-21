#include "Main.hpp"

int main(int argc, char **argv)
{
  if(strstr(argv[argc-1], ".pb")) {
    ifstream pb(argv[argc - 1]);

    if(!pb.good()) {
      exit(1);
      perror("The file does not exit!");
    }

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

    //if(rotation%26 != 0) {
      int num = findChar(charToInt(msg.at(i)));
      res += intToChar(num);
    //}

    rotateRotors();
  }

  return res;
}

void rotateRotors() {
  int size = rotorsOrd.size();

  for(int i = 0; i <= numRotors; i++) {
    if(i < size) {
      rotors.find(rotorsOrd.at(i))->second.rotate();
    }

    if(rotation%26 == 0) {
      numRotors = rotation/26;
    }
    rotation++;
  }
}

//enigma machine
int findChar(int x)
{
  int offset;
  //cout << "rotation(" << rotation << ") "<< x << " ";
  x = plugboard.map(x);
  //cout << x << " ";

  for(int i = 0; i < rotorsOrd.size(); i++) {
    Rotor r = findRotor(i);
    x = r.rotor(x);
    //cout << x << " ";
  }

  x = reflector(x);
  //cout << x << " ";

  for(int j = rotorsOrd.size() - 1; j >= 0; j--) {
    Rotor r = findRotor(j);
    offset = j + 1 < rotorsOrd.size() ? 0 : r.getOffset();
    x = r.reverseRotor(x);

    //cout << x << " ";
  }

  //cout << "\n";
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

//find rotor in map
Rotor findRotor(int index) {
  return rotors.find(rotorsOrd.at(index))->second;
}

//returns a character that is 13 characters ahead of the input char
int reflector(int x)
{
  return (x + 13) % 26;
}
