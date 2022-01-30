#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <vector>
#include <cstring>
#include <string>
#include <random>

using namespace std;

int random_number(){
  random_device generator;
  uniform_int_distribution<int> distribution(0,10000);
  int number = distribution(generator);

  return number;

}

string getWordRaw(string location){
  string line;
  vector<string> lines;

  srand(random_number());

  string word;
  ifstream file(location);

  int totalLines=0;
  while(getline(file,line)){

    totalLines++;
    lines.push_back(line);
  }
    
  word = lines[rand()%totalLines];
  

  return word;
}


string getWord(string location){
  string line;
  vector<string> lines;

  srand(random_number());

  string word;
  ifstream file(location);

  int totalLines=0;
  while(getline(file,line)){

    totalLines++;
    lines.push_back(line);
  }
    
  word = lines[rand()%totalLines];

  for(auto& x: word){
    x = tolower(x);
  }
  

  return word;
}

string getWordCaps(string location){
  string line;
  vector<string> lines;

  srand(random_number()); 

  string word;
  ifstream file(location);

  int totalLines=0;
  while(getline(file,line)){

    totalLines++;
    lines.push_back(line);
  }

  word = lines[rand()%totalLines];
  for(auto& x: word){
    x = tolower(x);
  }
  word[0] = toupper(word[0]);

  return word;
}

string elfName(){
  string name;
  name = getWordCaps("Elf/words.txt") + getWord("Elf/words.txt") + getWord("Elf/words.txt");
  return name;
}


string orcName(){

  string word;
  word = getWordCaps("Orc/word.txt") + getWord("Orc/word.txt") + " the " + getWordCaps("Orc/adjective.txt");

  return word;

}

string dwarfName(){

  string word = getWordCaps("Dwarf/word.txt"); 
  word = word + getWord("Dwarf/word.txt"); 
  word = word + " ";
  word = word + getWordCaps("Dwarf/word.txt");
  word = word + getWord("Dwarf/suffix.txt");

  return word;

}

string randomName(){

  string name;

  name = getWordCaps(getWordRaw("all.txt")) + getWord(getWordRaw("all.txt")) + " " + getWordCaps(getWordRaw("all.txt")) + getWord(getWordRaw("all.txt"));
  return name;
}

string humanMaleName(){
  string name;
  name = getWordCaps("Human/male.txt") + " " + getWordCaps("Human/surname.txt");
  return name;
}

string humanFemaleName(){
  string name;
  name = getWordCaps("Human/female.txt") + " " + getWordCaps("Human/surname.txt");
  return name;
}

string randomRaceName(){
  srand(random_number());
  string name;
  int number = rand() % 6 + 1;
  switch(number){
    case 1:
      name = elfName();
      break;

    case 2:
      name = orcName();
      break;

    case 3:
      name = dwarfName();
      break;

    case 4:
      name = randomName();
      break;

    case 5:
      name = humanMaleName();
      break;

    case 6:
      name = humanFemaleName();
      break;
  }

  return name;

}

string senGen(){
  string sentence;
  string weaponType = getWordRaw("weaponType.txt");
  sentence = randomRaceName() + " " + getWord("action/attack" + weaponType) + " " + randomRaceName() + " with their " + getWord("item/weapon" + weaponType);
  return sentence;
}


int main (){

  int choice;

  cout<<"===NAME-GENERATOR==="<<endl;
  cout<<"(1) Elf"<<endl;
  cout<<"(2) Orc"<<endl;
  cout<<"(3) Dwarf"<<endl;
  cout<<"(4) Random"<<endl;
  cout<<"(5) Human Male"<<endl;
  cout<<"(6) Human Female"<<endl;
  cout<<"(7) Sentence"<<endl;
  cin >> choice;

  switch (choice){
    case 1:
      system("CLS");
      while(1){
      cout << elfName() <<endl;
      _getwch();
      }

    case 2:
      system("CLS");
      while(1){
      cout << orcName() <<endl;
      _getwch();
      }

    case 3:
      system("CLS");
      while(1){
      cout << dwarfName() <<endl;
      _getwch();
      }

    case 4:
      system("CLS");
      while(1){
      cout << randomName() <<endl;
      _getwch();
      }

    case 5:
      system("CLS");
      while(1){
      cout << humanMaleName() <<endl;
      _getwch();
      }

    case 6:
      system("CLS");
      while(1){
      cout << humanFemaleName() <<endl;
      _getwch();
      }

    case 7:
      system("CLS");
      while(1){
      cout << senGen() <<endl;
      cout<<""<<endl;
      _getwch();
      }
  }



}