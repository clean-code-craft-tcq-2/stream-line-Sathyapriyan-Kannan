#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMSDataReceiver.h"

TEST_CASE("Verify Read parameters from file - Valid Case") {
  int current[NoOfSamples], temperature[NoOfSamples];
  void (*fn_ptrPrintOutput)(char*);
  fn_ptrPrintOutput = &printOnConsole;
  receiverSideHandling(current,temperature,fn_ptrPrintOutput);
}
