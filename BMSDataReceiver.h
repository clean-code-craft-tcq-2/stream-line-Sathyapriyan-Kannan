#define NoOfSamples 50

void receiverSideHandling(int current[], int temperature[], void (*fn_ptrPrintOutput)(char message[]));
void ReadDataFromConsole(int current[], int temperature[]);
int findMaximum(int data[]);
int findMinimum(int data[]);
float findAverage(int data[]);
void printOnConsole(char message[]);
