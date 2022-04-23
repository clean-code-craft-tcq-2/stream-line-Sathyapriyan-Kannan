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
    int sum;
    float average;
    if(NoOfSamples >= 5)
    {
        for(int i=(NoOfSamples-1); i>(NoOfSamples-6);i--)
        {
            sum += data[i];
        }
        average = sum/5;
    }
    else
    {
        for(int i=0; i<NoOfSamples; i++)
        {
            sum += data[i];
        }
        average = sum/NoOfSamples;
    }
    return average;
}

int findMinimum(int data[])
{
    int Minimum = data[0];
    for(int i=1; i<NoOfSamples; i++)
    {
        if(Minimum > data[i])
        {
            Minimum = data[i];
        }
    }
    return Minimum;
}

int findMaximum(int data[])
{
    int Maximum = data[0];
    for(int i=1; i<NoOfSamples; i++)
    {
        if(Maximum < data[i])
        {
            Maximum = data[i];
        }
    }
    return Maximum;
}

void ReadDataFromConsole(int current[], int temperature[])
{
    char dataFromConsole[100]; 
    for(int i=0; i<NoOfSamples; i++)
    {
        char *singleParameter;
        scanf ("%50s", dataFromConsole);
        singleParameter = strtok(dataFromConsole, ",");
        current[i] = atoi(singleParameter);
        singleParameter = strtok(NULL, ",");
        temperature[i] = atoi(singleParameter);
        printf("Current: %d, Temperature: %d\n",current[i],temperature[i]);
    }
}

void receiverSideHandling(int current[], int temperature[], void (*fn_ptrPrintOutput)(char message[]))
{
  int maxTemp, minTemp, maxCurrent, minCurrent;
  float averageCurrentof5Samples, averagTemperatureof5Samples;
  char message[200];
  ReadDataFromConsole(current,temperature);
  maxTemp = findMaximum(current);
  minTemp = findMinimum(current);
  maxCurrent = findMaximum(temperature);
  minCurrent = findMinimum(temperature);
  averageCurrentof5Samples = findAverage(current);
  averagTemperatureof5Samples = findAverage(temperature);
  sprintf(message,"MinTemperature: %d, MaxTemperature: %d, AverageTemperature: %f, MinCurrent: %d, MaxCurrent: %d, AverageCurrennt: %f",
         minTemp,maxTemp,averagTemperatureof5Samples,minCurrent,maxCurrent,averageCurrentof5Samples);
  fn_ptrPrintOutput(message);
}
