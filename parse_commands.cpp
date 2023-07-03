#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include "procfs_thread.h"
#include "parse_commands.h"

ParseCommands::ParseCommands() { }

void ParseCommands::remove_last_r_or_n(char *word)
{
	int length = strlen(word);
	if (length > 0 && (word[length - 1] == '\r' || word[length - 1] == '\n'))
	{
		word[length - 1] = 0;
	}
}

void ParseCommands::remove_last_rn(char *word)
{
	remove_last_r_or_n(word);
	remove_last_r_or_n(word);
}

bool ParseCommands::parse_parameters(char *words[], int words_count)
{
	for (int i = 1; i < words_count; i++)
	{
		char *end;
		long l = strtol(words[i], &end, 10);
		if (end == words[i])
		{
			return false;
		}
		if (!(l >= INT_MIN && l <= INT_MAX))
		{
			return false;
		}
		parameters[parameters_count++] = (int)l;
	}

	return true;
}

void ParseCommands::free_memory(void)
{
	for (int i = 0; i < words_count; i++)
	{
		free(words[i]);
	}
}

bool ParseCommands::parse_line(char *line, char *result)
{
	words_count = 0;
	parameters_count = 0;

	char *word = strtok(line, delimiter_);
	while (word != NULL)
	{
		remove_last_rn(word);
		// debug_string(word, 100);
		if (words_count + 1 >= words_max_count)
		{
			free_memory();
			strcpy(result, "error");
			return false;
		}

		char *words_ = (char*)calloc(1, strlen(word) + 1);
		if (words_ == NULL)
		{
			free_memory();
			strcpy(result, "error");
			return false;
		}

		int word_length = strlen(word);
		strncpy(words_, word, word_length);
		words[words_count++] = words_;

		word = strtok(NULL, delimiter_);
	}

	if (words_count == 0 || !parse_parameters(words, words_count))
	{
		free_memory();
		strcpy(result, "error");
		return false;
	}

	// for (int i = 0; i < parameters_count; i++)
	// 	printf("%d\r\n", parameters[i]);

	return true;
}
