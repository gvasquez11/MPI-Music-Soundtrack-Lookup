#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <mpi.h>

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
  void checkSong(const vector<Song> & s, const vector<string> & sv);
  void readIn(string iFile);
  int getNumOfSongs();
  vector<string> getInVect();

private:
  vector<Song> songVec;
  vector<string> inSongVect;
  int songsInFile = 0;

};

LookUp::LookUp(string fileName) //Constructor to automatically read input fileName
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
    for (int di = 0; di < sv.size(); di++)
    {
            cout << "Title:" << sv[di].title
                 << "  Composer:" << sv[di].composer
                 << "  Movie:" << sv[di].movie
                 << "  Time Stamp:" << sv[di].timeStamp
                 << "  Music Transcription:" << sv[di].musicTranscription << endl;
    }
  }
}

void LookUp::displayTSMT(const vector<Song> & s)
  {
    if(s.empty())
        cout << "Error. No Values" << endl;
    else
    {
      for (int dti = 0; dti < s.size(); dti++)
      {
              cout << left <<"Title: " << setw(43) <<s[dti].title
                           << "Movie: " << setw(25)<< s[dti].movie
                           <<"Time Stamp: " << setw(20) << left << s[dti].timeStamp << endl;
              //cout << left << setw(10) << "Music Transcription: " << s[dti].musicTranscription << endl;
      }
    }
  }

vector<Song> LookUp::getSongVec()
{
  return songVec;
}

vector<string> LookUp::getInVect()
{
  return inSongVect;
}

void LookUp::checkSong(const vector<Song> & s, const vector<string> & sv)
{
  for(int ci = 0; ci < s.size(); ci++)
  {
    for(int cj = 0; cj < sv.size() ; cj++)
    {
    if(s[ci].musicTranscription == sv[cj])
    cout << "Song " <<cj +1 <<" read by process is the trancriped song of " << s[ci].title << " which is in the movie " << s[ci].movie << " at time " << s[ci].timeStamp << endl;
    }
  }
}

void LookUp::readIn(string filename)
{

  ifstream in(filename.c_str());
  if(!in)
    cout << "ERROR: Could not open file." << endl;
  else
  {
      string str;
      // Read the next line from File untill it reaches the end.
      while (getline(in, str))
      {
      // Line contains string of length > 0 then save it in vector
      if(str.size() > 0)
        {
          inSongVect.push_back(str);
          songsInFile++;
        }

      }
  }

  in.close();
}

int LookUp::getNumOfSongs()
{
  return songsInFile;
}
