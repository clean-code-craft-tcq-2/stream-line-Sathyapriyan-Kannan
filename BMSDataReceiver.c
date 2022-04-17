#include <stdio.h>
#include <stdlib.h>
#include "BMSDataReceiver.h"

void ReadDataFromConsole(int current[], int temperature[])
{
    char unusedData[50];
    for(int i=0; i<NoOfSamples; i++)
    {
        scanf("%50s",unusedData);
        scanf("%d",&current[i]);
        scanf("%50s",unusedData);
        scanf("%50s",unusedData);
        scanf("%d",&temperature[i]);
    }
}

void receiverSideHandling(int current[], int temperature[])
{
  printf("Running Receiver\n");
  ReadDataFromConsole(current,temperature);
   for(int i=0; i<NoOfSamples; i++)
   {
      printf("Current: %d, Temperature: %d\n",current[i],temperature[i]);
   }
}
