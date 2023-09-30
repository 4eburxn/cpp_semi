#ifndef STD_LIB_FACILITIES
    #define STD_LIB_FACILITIES
    #include<std_lib_facilities.h>
#endif

struct Token
{
  char kind;
  double value;
  string name;

  Token(char);

  Token(char, string);

  Token(char, double);
};

class Token_stream
{
  bool full;
  Token buffer;

public:
  Token_stream();

  Token get ();
  void putback (Token);

  void ignore (char);
};
