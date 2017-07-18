#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <point.h>
#include <cell.h>
#include <board.h>

int main(int argc, char *argv[])
{
      // global setup...

      int result = Catch::Session().run( argc, argv );

      // global clean-up...

      return ( result < 0xff ? result : 0xff );
}
