#include <iomanip>
#include <string>
#include <iostream>
#include <mpi.h>
#include <fstream>
#include <vector>

using namespace std;
int ROWS = 4;
int COLS = 2;
int CAPACITY = 20;
string FNAME = "in.txt";

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
  LookUp(string fileName) //Construcotr to automatically read input fileName
  {
    ifstream ifile(fileName);
    if(ifile.is_open())
    {
      Song s;
      while(getline(cin,s.title, ','))
      {
        getline(cin,s.composer, ',');
        getline(cin,s.movie, ',');
        getline(cin,s.timeStamp, ',');
        getline(cin, s.musicTranscription);
        songVec.push_back(s);
      }
    }

  }
  void display(const vector<Song>& sv)
  {
    if(sv.empty())
        cout << "Error. No Values" << endl;
    else
    {
      for (int i = 0; i < sv.size(); i++)
      {
              cout << "Title: " << sv[i].title
                   << "   Composer: " << sv[i].composer
                   << "   Movie: " << sv[i].movie
                   << "   Time Stamp: " << sv[i].timeStamp
                   << "   Music Transcription: " << sv[i].musicTranscription << endl;
      }
    }
        cout << endl;

  }
  vector<Song> getSongVec()
  {
    return songVec;
  }

private:
  vector<Song> songVec;

};

int main()
{
LookUp test("data.txt");
test.display(test.getSongVec());




return 0;
}
