#include <iostream>
#include <iomanip>
#include <string.h>

//STRUCT FOR THE PARAMS
struct Param{
  char const  letter;
  char const *text,*description;
};

//STRUCT FOR THE COMMANDS
struct Command{
  char const *command, *description;
};

//Global Strings for having them seperated
char const* ERROR_NO_PARAMS = "NO PARAMETERS; you neet to at least give me a command";
char const* ERROR_WRONG_COMMAND = "COMMAND DOES NOT EXISTS; I Cannot find this command, please check spelling";
char const* HELP_COMMAND = "Usage: andy [OPTIONS] COMMAND";
char const* HELP_DESCRIPTION = "Cool new App doing cool stuff Lorem Ipsu"
  "Tskekr kktekt e tkek wektwke ktw e ktkwe kweor jkqpjrwio rjqwj iqpj rwq"
  "adsjds j Sjkd j jsd j astjheqwiedf spüd üpsdi üsü a iüpas d";
char const* HELP_COMMANDS = "Commands";

//PARAMS
const Param params[] = { {'d',"Debug12345678912","TEST"},
                         {'v',"Verbose","Krasse Sachen werden passieren und noch viel mehr, passieren wenn man dingsbumbs lol"}
                       };

//COMMANDS
const Command coms[] = { {"telco","Telephone-conference tool for cool log generation should be incredible fast"},
                         {"Calc","Calculate Stuff"}
                       };


//PRINT PARAMETERS
void printParams(){
  for (unsigned char i=0; i<sizeof(params)/sizeof(*params); i++){
    std::cout << "  " << "-" << params[i].letter << "  "
              << std::left << "--" << std::setw(23) << params[i].text
              << std::left << std::setw(40) << params[i].description
              << std::endl;
  }
}

//PRINT COMMANDS
void printCommands(){
  for (unsigned char i=0; i<sizeof(coms)/sizeof(*coms); i++){
    std::cout << "  " << std::setw(20) << std::left << coms[i].command << " " 
             << coms[i].description << std::endl;
  }
}

//GET THE HELP OUTPUT
void help(){
  std::cout << std::endl << HELP_COMMAND << std::endl
            << std::endl << HELP_DESCRIPTION << std::endl << std::endl;
  printParams();
  std::cout << std::endl << HELP_COMMANDS << std::endl;
  printCommands();
  std::cout << std::endl;
}

//PRINT SOMME ERROR MESSAGE AND THEN SHOW THE HELPER
void helpAndError(const char* errMsg){
  std::cout << std::endl << "ERROR: " << errMsg << std::endl;
  help();
}

//START APPLICATION HERE
int main(int argc,const char** argv){

  //CHECK THE AMOUNT OF ARGS.
  //less than 2 is not enough -> fails -> show help
  if (argc < 2){
    helpAndError(ERROR_NO_PARAMS);
    return -1;
  }

  //if we are here we know we have 2 or more arguments to deal with
  //take the last argument as command
  const char* command = argv[argc -1];
  bool commandIsValid = false;

  //check that command
  for (unsigned char i=0; i<sizeof(coms)/sizeof(*coms); i++){
    if (strcasecmp(coms[i].command, command)==0){
      commandIsValid = true;
      break;
    }
  }

  if (!commandIsValid){
    helpAndError(ERROR_WRONG_COMMAND);
    return -2;
  }

  //if we are here we know we have a legal command in the end of our
  //input so we can send this out
  std::cout << ">" << command  << "<" << commandIsValid << std::endl;
  return 0;
}
