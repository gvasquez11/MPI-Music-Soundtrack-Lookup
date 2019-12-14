#include <iomanip>
#include <string>
#include <iostream>
#include <mpi.h>
using namespace std;

#include "LookUp.cpp"

int main(int argc, char** argv)
{

  MPI_Init(NULL, NULL);

  int size, rank, split;
  string message;
  vector<string> m;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  LookUp test("data.txt");

  if (size == 1)
  {
    test.readIn("in.txt");
    cout << "The number of songs found in file are: " << test.getNumOfSongs() << endl;
    test.checkSong(test.getSongVec(), test.getInVect());
  }
  else
  {
    if(rank == 0)
    {
      //printf("%d of %d:\n", rank, size-1);

      test.readIn("in.txt");
      cout << "The number of songs found in file are: " << test.getNumOfSongs() << endl;

      split = (test.getNumOfSongs()/(size-1));
      cout << "split = " << split << endl;

      for(int r = 0; r < size-1; r++)
      {
        message = "";
        for(int s = 0; s < split; s++)
        {
          message.append(test.getInVect().at(s+(r*split)));
          message.append(" ");
        }
        cout << "Sending " << message << endl;
        MPI_Send(&message[0], message.size()+1, MPI_BYTE, r+1, /*TAG:*/0, MPI_COMM_WORLD);
      }

      //test.checkSong(test.getSongVec(), test.getInVect());
      //cout << test.getInVect().at(3) << endl;

      //printf("%d of %d Complete!\n", rank, size-1);
    }
    else
    {
      //START code from https://stackoverflow.com/questions/21378302/how-to-send-stdstring-in-mpi?rq=1
      MPI_Status status;
      MPI_Probe(0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
      int count;
      MPI_Get_count(&status,MPI_CHAR,&count);
      char buf [count];
      //END code

      //Rank 1 to Size MPI Recieves message and adds to vector m to hopefully run with checkSong
      MPI_Recv(&buf, count, MPI_BYTE, 0, /*TAG:*/0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

      char *token = strtok(buf, " ");
      while (token != NULL)
      {
          m.push_back(token);
          token = strtok(NULL, " ");
      }

      //m.push_back(buf);

      //Just to test the vector m (you can comment it later)
      //for (int i = 0; i < m.size(); i++)
        //cout << "Rank " << rank << " holds " << m[i] << "\n";

      test.checkSong(test.getSongVec(), m);

      //printf("%d of %d Complete!\n", rank, size-1);
    }
  }

  MPI_Finalize();
  return 0;
}
