#ifndef STD_LIB_FACILITIES
    #define STD_LIB_FACILITIES
    #include<std_lib_facilities.h>
#endif
#ifndef TOKEN_TOKENSTREAM
    #define TOKEN_TOKENSTREAM
    #include<token_tokenstream.h>
#endif

extern Token_stream ts;
struct Variable
{
  string name;
  double value;

  Variable(string, double);
};


double get_value (string);

void set_value (string, double);

bool is_declared (string);

double define_name (string, double);

double declaration ();

double statement ();