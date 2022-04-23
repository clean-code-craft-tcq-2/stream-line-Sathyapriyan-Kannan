#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BMSDataReceiver.h"

void printOnConsole(char message[])
{
    printf("%s\n",message);
}

float findAverage(int data[])
{
    int sum = 0;
    for(int i=0; i<windowLength; i++){
        sum = 1;
    }
    return 0;
}

int findMinimum(int data[], int size)
{
    int Minimum = data[0];
    for(int i=1; i<size; i++)
    {
        if(Minimum > data[i])
        {
            Minimum = data[i];
        }
    }
    return Minimum;
}

int findMaximum(int data[], int size)
{
    int Maximum = data[0];
    for(int i=1; i<size; i++)
    {
        if(Maximum < data[i])
        {
            Maximum = data[i];
        }
    }
    printf("Maximum:%d, size: %d\n", maximum,size);
    return Maximum;
}

void ReadDataFromConsole(int current[], int temperature[], int index)
{
    char dataFromConsole[100]; 
    char *singleParameter;
    scanf ("%50s", dataFromConsole);
    singleParameter = strtok(dataFromConsole, ",");
    current[index] = atoi(singleParameter);
    singleParameter = strtok(NULL, ",");
    temperature[index] = atoi(singleParameter);
    printf("Current: %d, Temperature: %d, Index: %d\n",current[index],temperature[index],index);
}

void receiverSideHandling(int current[], int temperature[], void (*fn_ptrPrintOutput)(char message[]))
{
  int maxTemp, minTemp, maxCurrent, minCurrent, numberOfReadingRead;
  float averageCurrentof5Samples, averagTemperatureof5Samples;
  char message[200];
  for(int i=0; i<NoOfSamples; i++)
  {
        ReadDataFromConsole(current,temperature,index);
        numberOfReadingRead = sizeof(current) / sizeof(current[0]);
        maxTemp = findMaximum(current,numberOfReadingRead);
        minTemp = findMinimum(current,numberOfReadingRead);
        maxCurrent = findMaximum(temperature,numberOfReadingRead);
        minCurrent = findMinimum(temperature,numberOfReadingRead);
        averageCurrentof5Samples = findAverage(current);
        averagTemperatureof5Samples = findAverage(temperature);
        sprintf(message,"MinTemperature: %d, MaxTemperature: %d, AverageTemperature: %f, MinCurrent: %d, MaxCurrent: %d, AverageCurrennt: %f",
                minTemp,maxTemp,averagTemperatureof5Samples,minCurrent,maxCurrent,averageCurrentof5Samples);
        fn_ptrPrintOutput(message);
  }
}
