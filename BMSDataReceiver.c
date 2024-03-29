#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BMSDataReceiver.h"

void printOnConsole(char message[])
{
    printf("%s\n",message);
}

float calcMovingAverage(int data[], int size, int winLength)
{
    float sum = 0.0, average = 0.0;
    if(size < winLength)
    {
        for(int i=0; i<= size; i++)
        {
            sum += data[i];
        }
    }
    else
    {
        for(int i=size; i>(size-5);i--)
        {
            sum += data[i];
        }
    }
    average = sum/(float)winLength;
    return average;
}

int findMinimum(int data[], int size)
{
    int Minimum = data[0];
    for(int i=1; i<=size; i++)
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
    for(int i=1; i<=size; i++)
    {
        if(Maximum < data[i])
        {
            Maximum = data[i];
        }
    }
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
}

void receiverSideHandling(int current[], int temperature[], int totalNumberOfSamples, int winLength, void (*fn_ptrPrintOutput)(char message[]),
                         void (*fn_ptrReadData)(int current[], int temperature[], int index))
{
  int maxTemp, minTemp, maxCurrent, minCurrent;
  float movingAvgofCurrent, movingAvgofTemperature;
  char message[200];
  for(int i=0; i<totalNumberOfSamples; i++)
  {
        fn_ptrReadData(current,temperature,i);
        maxTemp = findMaximum(temperature,i);
        minTemp = findMinimum(temperature,i);
        maxCurrent = findMaximum(current,i);
        minCurrent = findMinimum(current,i);
        movingAvgofCurrent = calcMovingAverage(current,i,winLength);
        movingAvgofTemperature = calcMovingAverage(temperature,i,winLength);
        sprintf(message,"MinTemperature: %d, MaxTemperature: %d, AverageTemperature: %.2f, MinCurrent: %d, MaxCurrent: %d, AverageCurrennt: %.2f",
                minTemp,maxTemp,movingAvgofTemperature,minCurrent,maxCurrent,movingAvgofCurrent);
        fn_ptrPrintOutput(message);
  }
}
