#include <iostream>
#include <unistd.h>
#include "get_next_line.hpp"
using namespace std;

static std::string next_lining(std::string stash)
{
	int		i;
	int		j;
	std::string line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static std::string read_as_buffer(int fd, std::string stash)
{
	int		bytes_to_read;

	char buf[BUFFER_SIZE + 1];
	bytes_to_read = 1;
	while (stash.find('\n') == std::string::npos && bytes_to_read != 0)
	{
		bytes_to_read = read(fd, buf, BUFFER_SIZE);
		stash += std::string(buf, bytes_to_read);
	}
	return (stash);
}

static std::string clean_stash(std::string stash)
{
	int			i;
	int			j;
	std::string _new;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	i += (stash[i] == '\n');
	if (!stash[i])
	{
		_new = malloc(1);
		if (!_new)
			return (NULL);
		_new[0] = '\0';
		free(stash);
		return (_new);
	}
	_new = malloc(ft_strlen(stash) - i + 1);
	if (!_new)
		return (NULL);
	while (stash[i])
		_new[j++] = stash[i++];
	_new[j] = '\0';
	return (free(stash), _new);
}

std::string get_next_line(int fd)
{
	static std::string stash;
	std::string	chosen_one;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	stash = read_as_buffer(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	chosen_one = next_lining(stash);
	stash = clean_stash(stash);
	return (chosen_one);
}
