#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMSDataReceiver.h"

TEST_CASE("Verify findMinimum function") {
  int dataSet1[] = {19,20,78,100,7,67,3,89};
  int size1 = sizeof(dataSet1)/sizeof(dataSet1[0]);
  int minimum = findMinimum(dataSet1,(size1-1));
  REQUIRE(minimum == 3);
}

TEST_CASE("Verify findMaximum function") {
  int dataSet2[] = {3,19,20,78,7,67,3,89};
  int size2 = sizeof(dataSet2)/sizeof(dataSet2[0]);
  int maximum = findMaximum(dataSet2,(size2-1));
  REQUIRE(maximum == 89);
}

TEST_CASE("Verify calcMovingAverage function - window length greater than data size") {
  int dataSet3[] = {15,20,45};
  int winLength = 5;
  int size3 = sizeof(dataSet3)/sizeof(dataSet3[0]);
  float average = calcMovingAverage(dataSet3,(size3-1),winLength);
  REQUIRE(average == 16.00);
}

TEST_CASE("Verify calcMovingAverage function - window length equal to data size") {
  int dataSet4[] = {15,20,45,19,23};
  int winLength = 5;
  int size4 = sizeof(dataSet4)/sizeof(dataSet4[0]);
  float average = calcMovingAverage(dataSet4,(size4-1),winLength);
  REQUIRE(average == 24.4);
}

TEST_CASE("Verify calcMovingAverage function - window length less than data size") {
  int dataSet5[] = {15,20,45,19,23,24,56,23};
  int winLength = 5;
  int size5 = sizeof(dataSet5)/sizeof(dataSet5[0]);
  float average = calcMovingAverage(dataSet5,(size5-1),winLength);
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
