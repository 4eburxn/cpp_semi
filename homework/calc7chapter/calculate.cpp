#ifndef TOKEN_TOKENSTREAM
    #define TOKEN_TOKENSTREAM
    #include<token_tokenstream.h>
#endif
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

double statement();
extern Token_stream ts;
void clean_up_mess();

void calculate ()
{
  while (true)
    try
    {
      cout << prompt;
      Token t = ts.get();
      while (t.kind == print)
        t = ts.get();
      if (t.kind == quit)
        return;

      ts.putback(t);
      cout << result << statement() << endl;
    }
    catch (runtime_error& e)
    {
      cerr << e.what() << endl;
      clean_up_mess();
    }
}