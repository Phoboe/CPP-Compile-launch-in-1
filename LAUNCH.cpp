#include <iostream>
#include <cctype> //Pour tolower()
#include <string>
#include <vector>

using namespace std;

void error(string s) { /* error print */
  cout << " >> ERROR: Invalid arguments entry."               << endl;
  cout << " >> Reason : " << s                                << endl;
  cout << " >> Two argument needed. For help, use /? or help" << endl;
}

void help() { /* help print */
  cout << " >> Program LAUNCH.exe : "                           << endl;
  cout << " >> To directly compile and launch a .cpp program. " << endl << endl;
  cout << " >> Two arguments needed : "                          << endl;
  cout << " >> 1) *file name -> with the extension"             << endl;
  cout << " >> 2) *compile -> 'y'/'yes' or 'n'/no"              << endl << endl;
  cout << " >> Use examples :  "                                << endl;
  cout << " >> LAUNCH prog.cpp"                                 << endl;
  cout << " >> LAUNCH prog.cpp n"                               << endl;
  cout << " >> LAUNCH.exe prog.cpp y"                           << endl;
}


int main(int argc, char**argv) {

  string raise = "OK" ; // if an error occur, it call the error()function
  string program      ;
  char   compile = 'y';
  vector<string> argvs; // real strings
  for (auto& x : argvs) { argvs.push_back(x); }

  if (argc == 1) // oubli du nom
  {
    raise = "You must specify the file to use.";
  }
  else if (argc == 2)
  {
    if (argvs[1] == "/?" || argvs[1] == "help") {
      help();
    }
    else {
      program = argvs[1];
    }
  }
  else if (argc == 3)
  {
    program = argvs[1];
    compile = argvs[2][0];
    if (tolower(compile) != 'y' || tolower(compile) != 'n')
    { raise = ("You must use y, n, yes or no. Not " + argvs[2]); }
    else { compile = argv[2][0]; }
  }
  else if (argc >= 4) // Too much
  {
    raise = "Too much arguments. Type 'LAUNCH /?' for more information";
  }

  if (raise != "OK") { // an error occured
    error(raise);
    return 0;
  }

  system("cls");
  if (compile == 'y')
  {
    cout << " >> compiling test.cpp...  " << endl;
    system( "g++ -o app -Wall test.cpp");
    cout << " >> Compile complete 100%" << endl;
    cout << "--------------- Launching start ---------------" << endl << endl;
    system( "app");
  }

  return 0;
}

/*
          OOOO           OOOO
         O  @ O         O  @ O         __________
          OOOO           OOOO         /  ///____;P
          				 V                 /  /
           \ _-_-_-_-_-_-           /__/
*/
