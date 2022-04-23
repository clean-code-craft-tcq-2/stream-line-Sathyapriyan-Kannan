#define NoOfSamples 50
#define WindowLength 5

void receiverSideHandling(int current[], int temperature[], void (*fn_ptrPrintOutput)(char message[]));
void ReadDataFromConsole(int current[], int temperature[], int index);
int findMaximum(int data[], int size);
int findMinimum(int data[], int size);
float findAverage(int data[], int size);
void printOnConsole(char message[]);
