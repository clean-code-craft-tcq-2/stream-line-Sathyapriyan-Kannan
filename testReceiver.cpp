#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMSDataReceiver.h"

TEST_CASE("Verify findMinimum function") {
  int dataSet[] = {19,20,78,100,7,67,3,89};
  int size = sizeof(dataSet)/sizeof(dataSet[0]);
  int minimum = findMinimum(dataSet,size);
  REQUIRE(minimum == 3);
}

TEST_CASE("Verify findMaximum function") {
  int dataSet[] = {3,19,20,78,7,67,3,89};
  int size = sizeof(dataSet)/sizeof(dataSet[0]);
  int minimum = findMaximum(dataSet,size);
  REQUIRE(minimum == 89);
}

TEST_CASE("Verify calcMovingAverage function - window length greater than data size") {
  int dataSet[] = {15,20,45};
  int winLength = 5;
  int size = sizeof(dataSet)/sizeof(dataSet[0]);
  float average = calcMovingAverage(dataSet,size,winLength);
  REQUIRE(average == 16);
}

TEST_CASE("Verify calcMovingAverage function - window length equal to data size") {
  int dataSet[] = {15,20,45,19,23};
  int winLength = 5;
  int size = sizeof(dataSet)/sizeof(dataSet[0]);
  float average = calcMovingAverage(dataSet,size,winLength);
  REQUIRE(average == 24.40);
}

TEST_CASE("Verify calcMovingAverage function - window length greater than data size") {
  int dataSet[] = {15,20,45,19,23,24,56,23};
  int winLength = 5;
  int size = sizeof(dataSet)/sizeof(dataSet[0]);
  float average = calcMovingAverage(dataSet,size,winLength);
  REQUIRE(average == 29.00);
}

TEST_CASE("Verify Read parameters from file - OverAllFunctionality for coverage") {
  int current[NoOfSamples], temperature[NoOfSamples];
  void (*fn_ptrPrintOutput)(char*);
  fn_ptrPrintOutput = &printOnConsole;
  void (*fn_ptrReadData)(int*, int*, int);
  fn_ptrReadData = &ReadDataFromConsole;
  receiverSideHandling(current,temperature,NoOfSamples,WindowLength,fn_ptrPrintOutput,fn_ptrReadData);
}
