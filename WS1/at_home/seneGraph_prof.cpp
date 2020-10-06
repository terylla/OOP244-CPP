#include <iostream>
#include "tools.h"
#include "graph.h"
#include "tools.h"
#include "graph.h"
#include "tools.h"
#include "graph.h"
#include "tools.h"
#include "graph.h"
#include "tools.h"
#include "graph.h"

using namespace std;
using namespace sdds;
void samplesFirst();
// SeneGraph program
int main() {
   int noOfSamples = 0;
   int samples[MAX_NO_OF_SAMPLES] = { 0 };
   bool done = false;
   line(33, "Welcome to SDDS SeneGraph");
   while (!done) {
      switch (menu(noOfSamples)) {
      case 1:
         cout << "Enter number of available samples: ";
         noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
         break;
      case 2:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else {
            cout << "Please enter the sample values: " << endl;
            getSamples(samples, noOfSamples);
         }
         break;
      case 3:
         if (noOfSamples == 0) {
            samplesFirst();
         }
         else if (samples[0] == 0) {
            cout << "Samples missing. Please enter the sample values!" << endl;
         }
         else {
            printGraph(samples, noOfSamples);
         }
         break;
      case 0:
         cout << "Thanks for using SDDS SeneGraph" << endl;
         done = true;
      }
   }
   return 0;
}
// prints samples error message
void samplesFirst() {
   cout << "Number of Samples must be set first!" << endl;
}