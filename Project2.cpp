#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <deque>
#include<map>

using namespace std;

void parse_args(string line, vector<string> &cmds){
    stringstream liness(line);
 
    string token;
    while (getline(liness, token, ' ')) {
        cmds.push_back(token);
    }
}

deque<string> history;
void history_function()
{
    int count=0;
            for(auto it= history.begin(); it!= history.end() && count <=10 ; it++)
            {
                count++;
                cout << count << "." <<  *it << endl;
            }
}
void runcommand(vector<string> cmd_args, string cmd){
int pid = fork();
        int status;

        if (pid == 0)
        {
            char * cmd_f = const_cast<char*> ((cmd_args[0]).c_str());
            char * cmd_f1 = const_cast<char*> ((cmd_args[1]).c_str());
            char * cmd_f2 = const_cast<char*> ((cmd_args[2]).c_str());

            char * argv[4] = {cmd_f , cmd_f1 , cmd_f2, NULL};
            execvp(argv[0], argv);

            
            if(errno != 0)
            {
                cout << "The program seems missing. Erro code is: " << errno << endl;
            }
        }
        else
        {
            // wait for program to finish and print exit status
            waitpid(pid, &status, 0);
            if(WEXITSTATUS(status) != 0)
            {
            cout << "The program existed with error: " << status << endl;
            }
        }
}

int main(void)
{
    int c_ount =1;
    map<int, string> myMap;

    int argc = 0;
    while (1)
    {
        // prompt
        cout << "ag736s$ ";

        string cmd;
        getline(cin, cmd);


        // ignore empty input
        if (cmd == "" || cmd.size() == 0) 
            continue;


        // built-in: exit
        if (cmd == "help"){
            cout << "Please print your help message of this program.\n";
            continue;
        }else if(cmd == "exit"){
            cout << SA_INTERRUPT;
            exit(0);
        }

        //FOR HISTORY COMMAND 
        history.push_back(cmd);
        myMap[c_ount] = cmd;
        c_ount++;

        if(history.size() > 10)
        {
        history.pop_front();
        }
        
        vector<string> cmd_args;
        parse_args(cmd, cmd_args);
         if(cmd == "hist")
            {
                history_function();
            }  

            else if (cmd_args[0]== "r")
            {
                int index= stoi(cmd_args[1]);

                if(myMap[index]== "hist")
                {
                    history_function();
                    continue;
                }else{
                    vector<string> r_cmd_args;
                    parse_args(myMap[index], r_cmd_args);
                    runcommand(r_cmd_args,myMap[index]);
                }
                
                    
                    
            }
            else

        // fork child and execute program
        runcommand(cmd_args,cmd);
        
}
}   