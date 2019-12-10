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
  LookUp(string fileName); //Construcotr to automatically read input fileName
  void display(const vector<Song>& sv);
  void displayTSMT(const vector<Song> & s);
  vector<Song> getSongVec();

private:
  vector<Song> songVec;

};


LookUp::LookUp(string fileName) //Construcotr to automatically read input fileName
{
  ifstream ifile(fileName);
  if(!ifile.is_open())
  cout << "Failed to open!" << endl;

  string line;
    Song s;
    while(getline(ifile, line))
    {
      stringstream ss(line);
      getline(ss, s.title, ',');
      getline(ss,s.composer, ',');
      getline(ss,s.movie, ',');
      getline(ss,s.timeStamp, ',');
      getline(ss, s.musicTranscription);
      songVec.push_back(s);
    }

}

void LookUp::display(const vector<Song>& sv)
{
  if(sv.empty())
      cout << "Error. No Values" << endl;
  else
  {
    for (int i = 0; i < sv.size(); i++)
    {
            cout << "Title:" << sv[i].title
                 << "  Composer:" << sv[i].composer
                 << "  Movie:" << sv[i].movie
                 << "  Time Stamp:" << sv[i].timeStamp
                 << "  Music Transcription:" << sv[i].musicTranscription << endl;
    }
  }
}

void LookUp::displayTSMT(const vector<Song> & s)
  {
    if(s.empty())
        cout << "Error. No Values" << endl;
    else
    {
      for (int i = 0; i < s.size(); i++)
      {
              cout << left <<"Title: " << setw(43) <<s[i].title
                           << "Movie: " << setw(25)<< s[i].movie
                           <<"Time Stamp: " << setw(20) << left << s[i].timeStamp << endl;
              //cout << left << setw(10) << "Music Transcription: " << s[i].musicTranscription << endl;
      }
    }
  }

vector<Song> LookUp::getSongVec()
{
  return songVec;
}
