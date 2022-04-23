#define NoOfSamples 50
#define WindowLength 5

void receiverSideHandling(int current[], int temperature[], int totalNumberOfSamples, int winLength, void (*fn_ptrPrintOutput)(char message[]),
                          void (*fn_ptrReadData)(int current[], int temperature[], int index));
void ReadDataFromConsole(int current[], int temperature[], int index);
int findMaximum(int data[], int size);
int findMinimum(int data[], int size);
float calcMovingAverage(int data[], int size, int winLength);
void printOnConsole(char message[]);
