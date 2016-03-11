#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "parse.h"

using std::cout;
using std::endl;

void print_tokens(std::vector<std::string> tokens)
{
	for(auto t: tokens) { cout << "Token: *" << t << "*" << endl; }
	cout << endl;
}

main()
{
	std::string in;
        //while(std::getline(std::cin, in) ) {
	char *line;
	//initialise_readline();
	bool done = false;
	while(! done)  {
		line = readline("");
		if(line == NULL) {
			done = true;
			continue;
		}

		add_history(line);
		in = std::string(line);
		free(line);

		std::vector<std::string> tokens = tokenize_line(in);
		print_tokens(tokens);
		//std::cout << tokens << std::endl;
	}
}
