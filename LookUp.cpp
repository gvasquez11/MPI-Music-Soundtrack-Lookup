#include <iomanip>
#include <string>
#include <iostream>
#include <mpi.h>
#include <fstream>
#include <vector>;

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
    //fileName = FNAME;
    int rank = 0;
    MPI_Comm comm = MPI_COMM_WORLD;

    // Initialize MPI and get the process rank
    MPI_Init(NULL,NULL);
    MPI_Comm_rank(comm,&rank);

    // Build the filename for the given process
    string filename = "input_" + rank + ".txt";

    // Open the file stream and read or write
    ifstream in(filename.c_str());
    read_file(in);
    in.close();

    // Finalize MPI and exit
    MPI_Finalize();
  }
  void dataReadIn(string fileName)
  {
    fileName = "data.txt";
    ifstream ifile(fileName);
    if(ifile.is_open())
    {
      Song s;
      while(getline(in,s.title, ','))
      {
        getline(in,s.composer, ',');
        getline(in,s.movie, ',');
        getline(in,s.timeStamp, ',');
        getline(in, s.musicTranscription);
        songVec.push_back(s);

      }
    }
  }

private:
  vector<Song> songVec;

};

int main()
{







}
