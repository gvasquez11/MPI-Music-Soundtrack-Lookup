#include <iomanip>
#include <string>
#include <iostream>
#include <mpi.h>
using namespace std;

#include "LookUp.cpp"


int main(int argc, char** argv)
{

  MPI_Init(NULL, NULL);

  int size, rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  printf("Rank %d"" out of %d processors:\n", rank, size);

  if(rank == 0)
  {
    cout << "Rank 0!" << endl;
    LookUp test("data.txt");
    //test.display(test.getSongVec());
    test.displayTSMT(test.getSongVec());
  }
  else
    cout << "Not Rank 0!" << endl;

  MPI_Finalize();
  return 0;
}
