#define BOOST_TEST_MODULE My first test module
#include <boost/test/included/unit_test.hpp>
#include "../Calculator.hpp"
    
BOOST_AUTO_TEST_CASE(first_test_function)
{
  int a = 42;
  int b = 3;
  Calculator calc_test;
  BOOST_CHECK_EQUAL(calc_test.addition(a, b), 45);
  //BOOST_TEST(a > 0);
}