#ifndef PARSE_COMMANDS_H
#define PARSE_COMMANDS_H

class ParseCommands
{
	const static int words_max_count = 32;
	const char *delimiter_ = " ";

	void remove_last_r_or_n(char *word);
	void remove_last_rn(char *word);
	bool parse_parameters(char *words[], int words_count);

public:
	char *words[words_max_count];
	int words_count = 0;
	int parameters[words_max_count];
	int parameters_count = 0;

	ParseCommands();
	bool parse_line(char *line, char *result);
	void free_memory(void);
};

#endif // PARSE_COMMANDS_H
