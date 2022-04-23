#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BMSDataReceiver.h"

void printOnConsole(char message[])
{
    printf("%s\n",message);
}

float findAverage(int data[], int size)
{
    int sum = 0;
    float average = 0;
    if(size < WindowLength)
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
    average = sum/WindowLength;
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
    printf("Temperature:%d, Current:%d\n",temperature[index],current[index]);
}

void receiverSideHandling(int current[], int temperature[], void (*fn_ptrPrintOutput)(char message[]))
{
  int maxTemp, minTemp, maxCurrent, minCurrent;
  float averageCurrentof5Samples, averagTemperatureof5Samples;
  char message[200];
  for(int i=0; i<NoOfSamples; i++)
  {
        ReadDataFromConsole(current,temperature,i);
        maxTemp = findMaximum(temperature,i);
        minTemp = findMinimum(temperature,i);
        maxCurrent = findMaximum(current,i);
        minCurrent = findMinimum(current,i);
        averageCurrentof5Samples = findAverage(current,i);
        averagTemperatureof5Samples = findAverage(temperature);
        sprintf(message,"MinTemperature: %d, MaxTemperature: %d, AverageTemperature: %f, MinCurrent: %d, MaxCurrent: %d, AverageCurrennt: %f",
                minTemp,maxTemp,averagTemperatureof5Samples,minCurrent,maxCurrent,averageCurrentof5Samples);
        fn_ptrPrintOutput(message);
  }
}
