#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>
#include "Sorts.h"
using namespace std;

unsigned long getTime() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000ul + tv.tv_usec;
}

typedef void (*SortFunction)(int a[], int n);

int main(int argc, char *argv[]) {
  if(argc < 6) {
    cerr << "Usage: " << argv[0]
         << " <algorithm> <mink> <maxk> <iterations> <sequence [seed]>" << endl
         << "algorithm\t<B|S|Q|R|i>\n"
         << "\t\t(B)ubble\n"
         << "\t\t(S)election\n"
         << "\t\t(Q)uick\n"
         << "\t\t(R)adix \n"
         << "mink\t\tminimum exponent for size, 2^(2*i)\n"
         << "maxk\t\tmaximum exponent for size, 2^(2*i)\n"
         << "iterations\tnatural number for iterations\n"
         << "sequence\t<R|A|D>\n"
         << "\t\t(R)andom\n\t\t(A)scending\n\t\t(D)escending\n"
         << "seed\t\toptional parameter for R sequence"
         << " time(NULL) if not specified\n";
    return -1;
  }

  int seed = time(NULL);

  int m = 0; //number of algorithms
  while(argv[1][m] != '\0')
  {
    char algorithm = argv[1][m];
    string algstr;
    SortFunction f;
    switch(algorithm)
    {
      case 'B': f = &bubbleSort; algstr = "BubbleSort"; break;
      case 'S': f = &selectionSort; algstr = "SelectionSort"; break;
      case 'Q': f = &quickSort; algstr = "QuickSort"; break;
      case 'R': f = &radixSort; algstr = "RadixSort"; break;
      default : cerr << "Invalid algorithm choice - '"
                     << algorithm << "'\n";
                exit(-1);
    }

    const int mink = atoi(argv[2]);
    const int maxk = atoi(argv[3]);
    const int iterations = atoi(argv[4]);;
    const char sequence = argv[5][0];
    if(argc == 7)
      seed = atoi(argv[6]);
    srand(seed);
    cout << algstr << endl;
    for(int i = mink; i <= maxk; i++)
    {
      unsigned long totaltime = 0;
      //modified for report
      int n = (int)pow((double)2,(2*(double)i));
      int *a = new int[n];
      if(a == NULL)
      {
        cerr << "Can't allocate an array of size " << n << endl;
        exit(-1);
      }
      for(int j = 0; j < iterations; j++)
      {
        switch(sequence)
        {
          case 'R':
            for(int x = 0; x < n; x++)
              a[x] = rand();
            break;
          case 'A':
            for(int x = 0; x < n; x++)
              a[x] = x;
            break;
          case 'D':
            for(int x = 0; x < n; x++)
              a[x] = n-x;
            break;
        }//end switch

        unsigned long start = getTime();
        (f)(a,n);
        totaltime += getTime() - start;
      }//end j for loop

      delete [] a;

      double avgtime = totaltime/(double)iterations;

      cout << "t_" << left << setw(11) << n
           << " = " << right << setw(15)
           << avgtime << " microseconds"
           << right << setw(15) 
           << (avgtime/1000000.0) << " seconds\n"
           << left;
    }//end i for loop

    m++;
  }//end while

  return 0;
}//end main

