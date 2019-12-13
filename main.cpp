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
      test.readIn("in.txt");
      cout << "The number of songs found in file are: " << test.getNumOfSongs() << endl;

      //split = ((test.getNumOfSongs())/(size-1));

      for(int r = 0; r < size-1; r++)
      {
        message = test.getInVect().at(r);
        MPI_Send(&message[0], message.size()+1, MPI_BYTE, r+1, /*TAG:*/0, MPI_COMM_WORLD);
      }
      //cout << test.getInVect().at(3) << endl;
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

      //MPI Recieves message and adds to vector m to run with checkSong
      MPI_Recv(&buf, count, MPI_BYTE, 0, /*TAG:*/0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      m.push_back(buf);

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
