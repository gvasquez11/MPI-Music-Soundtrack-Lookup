# MPI-Music-Soundtrack-Lookup

<p align="center">
  Gregory Vasquez | Yashab Narang
  <br>gvasquez11@csu.fullerton.edu | ynara50@gmail.com &emsp;&emsp;&emsp;&#8201;&#8201;
</p>

This program is written in C++ MPI which processes lines in order to output a value.
Each line of the 'in.txt' contains a string that represents concatenated musical notes from
famous Star Wars compositions. This program will read in these lines and scan them to determine
which of these famous Star Wars songs is represented. Once it determines which song it is,
it will output a time stamp of where you can find the song in it's respective film.

Operating System Used: Linux(Tuffix)
IDE: Atom
Command to run program:
mpicxx -o LookUp main.cpp
mpirun -n 4 LookUp
or any value after -n for the number of processes.


How to test
In the 'in.txt' put the string of any of the songs below and run the commands from above.
Works for both even and odd amount of songs and splits up the work accordingly.
Input of n = 1: Process 0 reads the songs and does all the work
Input of n = 2: Process 0 reads the songs and process 1 does all the work.
Input of n = 3 or more: Process 0 read the songs and process 2 and 3 splits the work evenly.
Limitations: Program works only with the songs provided below.
If there's an odd number then processes 1 takes a heavier load of songs and then splits
the others evenly between the other processes. If the number of processes is greater than the amount of songs
program will not run as expected. 

Star Wars(Main Theme) - "DDDGDCBAGDCBAGDCBCA"
Cantina Band - "EEBEC#BED#BEF#""
Duel of the Fates - "ADADADAG#AAG#AGF#GF#F"
Rey's Theme - "ACAAACAEGEACAAACAEGEA"
The Imperial March (Darth Vader's Theme) - "GGGEbBbGEbBbGDDDEbBbGbEbBbGEbBbG"
Anakin vs Obi, John Williams - "DDDDDDDDDDDDDEFFECED"
The Imperial Suite - "FFFFFFFFFFFFFFAbFAbCCDb"
