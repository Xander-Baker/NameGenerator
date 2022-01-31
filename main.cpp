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

string lizardName(){

  string word = getWordCaps("Lizard/word.txt"); 
  word = word + getWord("Lizard/word.txt");
  word = word + " ";
  int number = rand() % 6;
  if (number == 5){
    word = word + "von ";
  }
  word = word + getWordCaps("Lizard/word.txt");
  word = word + getWord("Lizard/suffix.txt");

  return word;

}

string goblinName(){

  string word = getWordCaps("Goblin/prefix.txt"); 
  word = word + getWord("Goblin/suffix.txt");

  return word;

}

string cowName(){

  string word = getWordCaps("Cow/word.txt"); 
  word = word + getWord("Cow/word.txt");

  return word;

}

string cephName(){

  string word = getWordCaps("Cephalopoid/word.txt"); 
  word = word + getWord("Cephalopoid/word.txt");

  return word;

}

string pigeonName(){

  string word = getWordCaps("Pigeon/word.txt") + getWord("Pigeon/word.txt") + " " + getWordCaps("Pigeon/word.txt") + getWord("Pigeon/suffix.txt"); 

  return word;

}

string gorillaName(){

  string word = getWordCaps("Gorilla/word.txt")+ " " + getWord("Gorilla/word.txt") + " " + getWord("Gorilla/word.txt"); 

  return word;

}

string catName(){

  string word = getWordCaps("cat/prefix.txt") + getWord("cat/word.txt") + " " + getWordCaps("cat/word.txt") + getWord("cat/word.txt"); 

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
  int number = rand() % 13 + 1;
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

    case 7:
      name = lizardName();
      break;

    case 8:
      name = goblinName();
      break;
    
    case 9:
      name = gorillaName();
      break;

    case 10:
      name = cephName();
      break;

    case 11:
      name = pigeonName();
      break;

    case 12:
      name = catName();
      break;

    case 13:
      name = cowName();
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

string getName(string input){
  string name;
  if(input == "Elf"){
    name = elfName();
  }

  if(input == "Orc"){
    name = orcName();
  }

  if(input == "Dwarf"){
    name = dwarfName();
  }

  if(input == "Human Male"){
    name = humanMaleName();
  }

  if(input == "Human Female"){
    name = humanFemaleName();
  }

  if(input == "Random"){
    name = randomName();
  }

  return name;
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
  cout<<"(7) Lizard"<<endl;
  cout<<"(8) Goblin"<<endl;
  cout<<"(9) Cow"<<endl;
  cout<<"(10) Cephalopoid"<<endl;
  cout<<"(11) Pigeon"<<endl;
  cout<<"(12) Gorilla"<<endl;
  cout<<"(13) cat"<<endl;
  cout<<"(14) Sentence"<<endl;
  cin >> choice;

  switch (choice){
    case 1:
      system("CLS");
      while(1){
      cout << getName("Elf") <<endl;
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
      cout << lizardName() <<endl;
      _getwch();
      }

    case 8:
      system("CLS");
      while(1){
      cout << goblinName() <<endl;
      _getwch();
      }
    
    case 9:
      system("CLS");
      while(1){
      cout << cowName() <<endl;
      _getwch();
      }

    case 10:
      system("CLS");
      while(1){
      cout << cephName() <<endl;
      _getwch();
      }

    case 11:
      system("CLS");
      while(1){
      cout << pigeonName() <<endl;
      _getwch();
      }

    case 12:
      system("CLS");
      while(1){
      cout << gorillaName() <<endl;
      _getwch();
      }

    case 13:
      system("CLS");
      while(1){
      cout << catName() <<endl;
      _getwch();
      }

    case 14:
      system("CLS");
      while(1){
      cout << senGen() <<endl;
      cout<<""<<endl;
      _getwch();
      }
  }



}