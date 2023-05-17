#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

class Pet
{
public:
  Pet(); //pet constructor-sets name, hunger, tiredness to default values
  Pet(string name); //pet constructor-sets name to value passed
  virtual bool isHungry() = 0; //returns T if pet is hungry
  virtual bool isTired() = 0; //returns T if pet is tired
  virtual void makeNoise() = 0; //pet makes animal noise
  virtual void print() = 0; //shows pet using ascii art
  virtual void output() = 0; //says if pet is hungry/tired or whatever
  virtual void eat() = 0; //performs the eat action
  virtual void sleep() = 0; //performs the sleep action
  string getName(); //returns pet's name
  int getHunger(); //returns pet's hunger
  int getTiredness(); //returns pet's tiredness
protected:
  string name; //name of the pet
  int hunger, tiredness; //how hungry/tired pet is out of 100
};

class Dragon : public Pet
{
public:
  Dragon(); //dragon constructor-sets name, hunger, tiredness, fly to default values
  Dragon(string e); //dragon constructor-sets to values passed
  bool isHungry() override; //returns T if the dragon is hungry
  bool isTired() override; //returns T if the dragon is tired
  bool wantFly(); //returns T if the dragon wants to fly
  void makeNoise() override; //outputs dragon noise
  void print() override; //outputs picture of dragon using ascii art
  void output() override; //says if the dragon is hungry/tired/wants to fly
  void eat() override; //performs the eat action
  void sleep() override; //performs the sleep action
  void fly(); //performs the fly action
private:
  int _fly; //how bad the dragon wants to fly out of 100
};

class Dolphin : public Pet
{
public:
  Dolphin(); //dolphin constructor-sets name, hunger, tiredness, play to default values
  Dolphin(string name); //dolphin constructor-sets to values passed
  bool isHungry() override; //returns T if the dolphin is hungry
  bool isTired() override; //returns T if the dolphin is tired
  bool wantPlay(); //returns T if the dolphin wants to play
  void makeNoise() override; //outputs dolphin noise
  void print() override; //outputs picture of dolphin using ascii art
  void output() override; //says if the dolphin is hungry/tired/wants to play
  void eat() override; //performs the eat action
  void sleep() override; //performs the sleep action
  void play(); //performs the play action
private:
  int _play; //how bad the dolphin wants to play out of 100
};

class Dinosaur : public Pet
{
public:
  Dinosaur(); //dinosaur constructor-sets name, hunger, tiredness, walk to default values
  Dinosaur(string e); //dinosaur constructor-sets to values passed
  bool isHungry() override; //returns T if the dinosaur is hungry
  bool isTired() override; //returns T if the dinosaur is tired
  bool wantWalk(); //returns T if the dinosaur wants to walk
  void makeNoise() override; //outputs dinosaur noise
  void print() override; //outputs picture of dinosaur using ascii art
  void output() override; //says if the dinosaur is hungry/tired/wants to walk
  void eat() override; //performs the eat action
  void sleep() override; //performs the sleep action
  void walk(); //performs the walk action
private:
  int _walk; //how bad the dinosaur wants to walk out of 100
};

class Dan : public Pet
{
public:
  Dan(); //Dan constructor-sets name, hunger, tiredness, walk to default values
  Dan(string name); //Dan constructor-sets to values passed
  bool isHungry() override; //returns T if the dinosaur is hungry
  bool isTired() override; //returns T if the dinosaur is tired
  bool wantTeach(); //returns T if Dan wants to teach
  void makeNoise() override; //outputs Dan noise
  void print() override; //outputs picture of Dan using ascii art
  void output() override; //says Dan is hungry/tired/wants to teach
  void eat() override; //performs the eat action
  void sleep() override; //performs the sleep action
  void teach(); //performs the teach action
private:
  int _teach; //how bad Dan wants to teach out of 100
};

Pet::Pet()
{
  name = "Chang H. Yun";
  hunger = 100;
  tiredness = 100;
}

Pet::Pet(string name)
{
  this -> name = name;
  hunger = 100;
  tiredness = 100;
}

string Pet::getName() {  return name;  }
int Pet::getHunger() {  return hunger;  }
int Pet::getTiredness() {  return tiredness;  }
Dragon::Dragon() : Pet() {  _fly = 100;  }
Dragon::Dragon(string e) : Pet(e) {  _fly = 100;  }
void Dragon::makeNoise()  {  cout << "Baaaghh" << endl;  }
bool Dragon::isHungry() 
{
  return hunger < 20; //if the hunger is less than 20, return true
}

bool Dragon::isTired() 
{
  return tiredness < 20; //if the tiredness is less than 20, return true
}

bool Dragon::wantFly() 
{
  return _fly < 20; //if fly is less than 20, return true
}

void Dragon::print()
{
  cout << "                \\||/" << endl;
  cout << "                |  @___oo" << endl;
  cout << "      /\\  /\\   / (__,,,,|" << endl;
  cout << "     ) /^\\) ^\\/ _)" << endl;
  cout << "     )   /^\\/   _)" << endl;
  cout << "     )   _ /  / _)" << endl;
  cout << " /\\  )/\\/ ||  | )_)" << endl;
  cout << "<  >      |(,,) )__)" << endl;
  cout << " ||      /    \\)___)\\" << endl;
  cout << " | \\____(      )___) )___" << endl;
  cout << "  \\______(_______;;; __;;;" << endl; //print a picture of the dragon using ascii art
  cout << endl << "I am " << this->name << endl; //put the pet's name somewhere
}

void Dragon::output()
{
  if(isHungry()) //if the dragon is hungry, print that
  {
    cout << name << " is hungry." << endl;
  }
  
  if(isTired()) //if the dragon tired, print that
  {
    cout << name << " is tired." << endl;
  }
  
  if(wantFly()) //if the dragon wants to fly, print that
  {
    cout << name << " wants to fly." << endl;
  }
}

void Dragon::eat()
{
  cout << "nom" << endl;
  hunger = 100;
  tiredness -= 30;
  _fly -= 30;
  cout << name << " ate." << endl;
  output();
}

void Dragon::sleep()
{
  cout << "zzzzzzzzzzz" << endl;
  tiredness = 100;
  hunger -= 35;
  _fly -= 20;
  cout << name << " slept." << endl;
  output();
}

void Dragon::fly()
{
  cout << "Whoosh! You are flying " << name << "." << endl;
  hunger -= 15;
  tiredness -= 20;
  _fly = 100;
  cout << name << " flew." << endl;
  output();
}

Dolphin::Dolphin() : Pet() {  _play = 100;  }
Dolphin::Dolphin(string e) : Pet(e) {  _play = 100;  }
void Dolphin::makeNoise()  {  cout << "eeeeeeeeeeee" << endl;  }
bool Dolphin::isHungry() 
{
  return hunger < 30; //if the hunger is less than 30, return true
}

bool Dolphin::isTired() 
{
  return tiredness <  10; //if the tiredness is less than 10, return true
}

bool Dolphin::wantPlay() 
{
  return _play < 50; //if play is less than 50, return true
}

void Dolphin::print()
{
  cout << "                                                           __\n                              .__                         / |\n                             /  /                         |  \\\n                            /   |                     ,-------'_\n                       ____/     \\_________,     ,_--\"      _/  \\_\n         _______------'                     `---\"          ,-\\___/\n     _--\"                                               ,-\"\n ___(___                                          ,__--\"\n(-------0                                   __---\"\n `--___                                    /\n       `--___\\                _______-----'\n             \\\\    (____-----'\n              \\\\    \\_\n               `\"`..__\\" << endl; //print a picture of the dolphin using ascii art
 cout << endl << "I am " << this->name << endl; //put the pet's name somewhere
}

void Dolphin::output()
{
  if(isHungry()) //if the dolphin is hungry, print that
  {
    cout << name << " is hungry." << endl;
  }
  
  if(isTired()) //if the dolphin is tired, print that
  {
    cout << name << " is tired." << endl;
  }
  
  if(wantPlay()) //if the dolphin wants to play, print that
  {
    cout << name << " wants to play." << endl;
  }
}

void Dolphin::eat()
{
  cout << "nom" << endl;
  hunger = 100;
  tiredness -= 20;
  _play -= 50;
  cout << name << " ate." << endl;
  output();
}

void Dolphin::sleep()
{
  cout << "zzzzzzzzzzz" << endl;
  tiredness = 100;
  hunger -= 25;
  _play -= 30;
  cout << name << " slept." << endl;
  output();
}

void Dolphin::play()
{
  cout << "Yay! You are playing with " << name << "." << endl;
  hunger -= 35;
  tiredness -= 50;
  _play = 100;
  cout << name << " is done playing." << endl;
  output();
}

Dinosaur::Dinosaur() : Pet() {  _walk = 100;  }
Dinosaur::Dinosaur(string e) : Pet(e) {  _walk = 100;  }
void Dinosaur::makeNoise()  {  cout << "Roar" << endl;  }
bool Dinosaur::isHungry() 
{
  return hunger < 50; //if the hunger is less than 50, return true
}

bool Dinosaur::isTired() 
{
  return tiredness < 10; //if the tiredness is less than 10, return true
}

bool Dinosaur::wantWalk() 
{
  return _walk; //if walk is less than 30, return true
}

void Dinosaur::print()
{
  cout << "   _\n .~q`,\n{__,  \\\n    \\' \\\n     \\  \\\n      \\  \\\n       \\  `._            __.__\n        \\    ~-._  _.==~~     ~~--.._\n         \\        '                  ~-.\n          \\      _-   -_                `.\n           \\    /       }        .-    .  \\\n            `. |      /  }      (       ;  \\\n              `|     /  /       (       :   '\\\n               \    |  /        |      /       \\    =\n                |     /`-.______.\\     |^-.      \\\n                |   |/           (     |   `.      \\_\n                |   ||            ~\\   \\      '._    `-.._____..----.._=__\n                |   |/             _\\   \\      =~-.__________.-~~~~~~~~~'''\n              .o'___/            .o______}" << endl; //print a picture of the dinosaaur using ascii art
  cout << endl << "I am " << this->name << endl; //put the pet's name somewhere
}

void Dinosaur::output()
{
  if(isHungry()) //if the dinosaur is hungry, print that
  {
    cout << name << " is hungry." << endl;
  }
  
  if(isTired()) //if the dinosaur is tired, print that
  {
    cout << name << " is tired." << endl;
  }
  
  if(wantWalk()) //if the dinosaur wants to walk, print that
  {
    cout << name << " wants to walk." << endl;
  }
}

void Dinosaur::eat()
{
  cout << "nom" << endl;
  hunger = 100;
  tiredness -= 40;
  _walk -= 10;
  cout << name << " ate." << endl;
  output();
}

void Dinosaur::sleep()
{
  cout << "zzzzzzzzzzz" << endl;
  tiredness = 100;
  hunger -= 15;
  _walk -= 30;
  cout << name << " slept." << endl;
  output();
}

void Dinosaur::walk()
{
  cout << "Stomp! You are walking " << name << "." << endl;
  hunger -= 45;
  tiredness -= 40;
  _walk = 100;
  cout << name << " walked." << endl;
  output();
}

Dan::Dan() : Pet() {  _teach = 100;  }
Dan::Dan(string e) : Pet(e) {  _teach = 100;  }
void Dan::makeNoise()  {  cout << "Computer Science" << endl;  }
bool Dan::isHungry() 
{
  return hunger < 30; //if the hunger is less than 30, return true
}

bool Dan::isTired() 
{
  return tiredness < 10; //if the tiredness is less than 10, return true
}

bool Dan::wantTeach() 
{
  return _teach < 40; //if teach is less than 40, return true
}

void Dan::print()
{
  cout << "            ,,,,,,,\n            :: (,,\n            :  _ >\n          __/\\___/\n         /  \\__/ \\\n        |         |\n        | Y      ,|\n        |_|      ||\n        \\ \\      |T\n         \\ \\_     \\\n         /\\_\\)-.-'(\n         \\_,  ___ |\n         |     |  |\n         |     |  |\n         |_____|__|\n         |     |  |\n_________|  _..| .|__________\n        / -'____) _\_\n        >-''/    \\'__\\\n        |________|---'\n        '--'-----'" << endl; //print a picture of Dan using ascii art
  cout << endl << "I am " << this->name << endl; //put the pet's name somewhere
}

void Dan::output()
{
  if(isHungry()) //if Dan is hungry, print that
  {
    cout << name << " is hungry." << endl;
  }
  
  if(isTired()) //if Dan is tired, print that
  {
    cout << name << " is tired." << endl;
  }
  
  if(wantTeach()) //if Dan wants to teach, print that
  {
    cout << name << " wants to teach." << endl;
  }
}

void Dan::eat()
{
  cout << "nom" << endl;
  hunger = 100;
  tiredness -= 50;
  _teach -= 20;
  cout << name << " ate." << endl;
  output();
}

void Dan::sleep()
{
  cout << "zzzzzzzzzzz" << endl;
  tiredness = 100;
  hunger -= 35;
  _teach -= 30;
  cout << name << " slept." << endl;
  output();
}

void Dan::teach()
{
  cout << "1437! " << name << " The Dan is teaching." << endl;
  hunger -= 35;
  tiredness -= 30;
  _teach = 100;
  cout << name << " taught." << endl;
  output();
}

void battle(Pet* a,Pet* b)
{
  srand(time(0));
  int x = rand() % 50;
  string c = "";
  switch (x) 
  {
    case 0:
      c = "punch";
      break;

    case 1:
      c = "kick";
      break;

    case 2:
      c = "Dinkleberg";
      break;
    
    case 3:
      c = "drone";
      break;

    case 4:
      c = "inheritance";
      break;

    case 5:
      c = "Dr. Gabriel";
      break;

    case 6:
      c = "a job at a FAANG company";
      break;

    case 7:
      c = "it";
      break;

    case 8:
      c = "himself";
      break;
    
    case 9:
      c = "Discrete Mathematics";
      break;

    case 10:
      c = "Venkat Subramaniam";
      break;

    case 11:
      c = "rocks";
      break;

    case 12:
      c = "COSC 2436: Data Structures with Nouhad Rizk";
      break;

    case 13:
      c = "C++";
      break;
    
    case 14:
      c = "this project";
      break;

    case 15:
      c = "Problem #1: Real Estate Management System";
      break;

    case 16:
      c = "pointers";
      break;

    case 17:
      c = "arrays";
      break;

    case 18:
      c = "ints, floats, chars, and strings";
      break;

    case 19:
      c = "hot breath";
      break;
    
    case 20:
      c = "suffocation";
      break;

    case 21:
      c = "time travel";
      break;

    case 22:
      c = "stab";
      break;

    case 23:
      c = "CougarCS";
      break;

    case 24:
      c = "Hamlet";
      break;

    case 25:
      c = "some move";
      break;
    
    case 26:
      c = "Algorithms";
      break;

    case 27:
      c = "snakes";
      break;

    case 28:
      c = "herself";
      break;

    case 29:
      c = "Honda CRVs";
      break;

    case 30:
      c = "another pet";
      break;

    case 31:
      c = "AP Physics C: Electricity and Magnetism";
      break;
    
    case 32:
      c = "Gucci Gang";
      break;

    case 33:
      c = "Mario";
      break;

    case 34:
      c = "ZyBooks";
      break;

    case 35:
      c = "The Cat in the Hat";
      break;

    case 36:
      c = "Green Eggs & Ham";
      break;

    case 37:
      c = "1984 by George Orwell";
      break;
    
    case 38:
      c = "Polyphemus from The Odyssey";
      break;

    case 39:
      c = "the Demogorgon";
      break;

    case 40:
      c = "Pirates of the Caribbean";
      break;

    case 41:
      c = "a C-";
      break;

    case 42:
      c = "cout << endl;";
      break;

    case 43:
      c = "its tail";
      break;
    
    case 44:
      c = "its footstep";
      break;

    case 45:
      c = "a heavy object";
      break;

    case 46:
      c = "fire";
      break;
    
    case 47:
      c = "Java";
      break;
    
    case 48:
      c = "that thing";
      break;
    
    default:
      c = "polymorphism";
      break;
  }
    int y = rand() % 2;
    string tring = "", ring = "";
    if(y == 0)
    {
      tring = a->getName();
      ring = b->getName();
    }
    else
    {
      tring = b->getName();
      ring = a->getName();
    }

cout << tring << " used " << c << " to defeat " << ring << ".";
  
}

void OUTPUT_FILE(string name)
{
  ofstream fout("pet.txt");
  fout << name;
  fout.close();
}

int main()
{
  //4 species
  //Initialize a pet by <species>* <variable> = new <species>;
  //i.e. like Dragon* dragon1 = new Dragon;;
  //You can set his name in quotation marks after in parentheses
  //Like Dragon* dragon1 = new Dragon("Smogg"); to name him Smogg
  //Or the dragon will get the default name of Chang H. Yun
  //To see your pet, say dragon1->print();
  //Dragons fly
  //Dolphins play
  //Dinosaurs walk
  //Dans teach
  //Do something with the animal
  //Like dragon1->fly();
  //The output will tell if the pet is hungry, tired, or wants to do something
  //If the pet is hungry, say dragon1->eat();
  //If the pet is tired say dragon1->sleep();
  //Likewise for dragons, there is ->fly()
  //For dolphins, there is ->play()
  //For dinosaurs, there is ->walk()
  //For Dans, there is ->teach()
  //To see how hungry or tired dragon1 is
  //Say dragon1->getHunger() << endl; or cout << dragon1->getTiredness() << endl;
  //Closer to 100 is better
  //To make the per make noise, use ->makeNoise()
  //Like dragon1->makeNoise();
  //to battle 2 pets say battle() and the pets in parentheses
  //Like battle(dragon1,dinosaur1);
  //The results will be in the terminal
  //Say OUTPUT_FIlE("name") for each name to save name in pet.txt
  //Press run everytime
  //Type the code below
  //After you're done, delete your pets
  //Like delete dragon1;
  //And delete dinosaur1;
  return 0;
}