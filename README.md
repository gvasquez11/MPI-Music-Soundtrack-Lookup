# MPI-Music-Soundtrack-Lookup

<p align="center">
  Gregory Vasquez | Yashab Narang
  <br>gvasquez11@csu.fullerton.edu | ynara50@gmail.com &emsp;&emsp;&emsp;&#8201;&#8201;
</p>

<p>
&emsp;This program is written in C++ using MPI which processes lines in order to output a value.
Each line of the 'in.txt' contains a string that represents concatenated musical notes from
famous Star Wars compositions. This program will read in these lines and scan them to determine
which of these famous Star Wars songs is represented. Once it determines which song it is,
it will output a time stamp of where you can find the song in it's respective film.
</p>
<br>
<p>
Operating System Used: Linux(Tuffix)<br>
IDE: Atom<br>
Command to run program:<br>
mpicxx -o LookUp main.cpp<br>
mpirun -n 4 LookUp<br>
(4 can be replaced by any number of processes)
</p>
<br>
<p>
<b>How to test</b><br>
In the 'in.txt' put the string of any of the songs below and run the commands from above.<br>
Works for both even and odd amount of songs and splits up the work accordingly.<br>
Input of n = 1: Process 0 reads the songs and does all the work<br>
Input of n = 2: Process 0 reads the songs and process 1 does all the work.<br>
Input of n = 3 or more: Process 0 read the songs and process 2 and 3 splits the work evenly.<br>
Limitations: Program works only with the songs provided below.<br>
If there's an odd number then processes 1 takes a heavier load of songs and then splits
the others evenly between the other processes. If the number of processes is greater than the amount of songs
program will not run as expected.
</p>
<br>
<p>
<b>Current Possible Inputs</b><br>
Star Wars(Main Theme) - "DDDGDCBAGDCBAGDCBCA"<br>
Cantina Band - "EEBEC#BED#BEF#""<br>
Duel of the Fates - "ADADADAG#AAG#AGF#GF#F"<br>
Rey's Theme - "ACAAACAEGEACAAACAEGEA"<br>
The Imperial March (Darth Vader's Theme) - "GGGEbBbGEbBbGDDDEbBbGbEbBbGEbBbG"<br>
Anakin vs Obi, John Williams - "DDDDDDDDDDDDDEFFECED"<br>
The Imperial Suite - "FFFFFFFFFFFFFFAbFAbCCDb"<br>
</p>
