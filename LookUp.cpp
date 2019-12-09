#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

int CAPACITY = 20;

struct Song
{
  string title;
  string composer;
  string movie;
  string timeStamp;
  string musicTranscription;
};

class LookUp
{

public:
  LookUp(string fileName); //Construcotr to automatically read input fileName

private:
  Song songArr* = new Song[CAPACITY];

}
