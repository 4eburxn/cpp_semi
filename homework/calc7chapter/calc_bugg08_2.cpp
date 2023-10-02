/*
  calculator08buggy.cpp

  Helpful comments removed.

  We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/
#ifndef STD_LIB_FACILITIES
    #define STD_LIB_FACILITIES
    #include<std_lib_facilities.h>
#endif
#ifndef TOKEN_TOKENSTREAM
    #define TOKEN_TOKENSTREAM
    #include<token_tokenstream.h>
#endif
#ifndef VARIABLE
    #define VARIABLE
    #include<variable.h>
#endif
#include<grammar.h>
#include<calculate.h>

#ifndef CONSTANTS
    #define CONSTANTS
    constexpr char quit = 'q';
    constexpr char print = ';';
    constexpr char number = '8';
    constexpr char name = 'a';
    constexpr char let = 'L';

    const string prompt = "> ";
    const string result = "= ";
    const string declkey = "let";
#endif






//Token_stream ts;
int main ()
try
{
  define_name("pi", 3.141592653589793);
  define_name("e", 2.718281828459045);

  calculate();
}
catch (exception& e)
{
  cerr << "exception: " << e.what() << endl;
  return 1;
}
catch (...)
{
  cerr << "Oops, unknown exception" << endl;
  return 2;
}