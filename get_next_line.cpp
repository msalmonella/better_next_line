#include <iostream>
#include <unistd.h>
#include "get_next_line.hpp"
using namespace std;

static std::string next_lining(std::string stash)
{
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (stash.substr(0, i + 1));
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
	while (stash[i] && stash[i] != '\n')
		i++;
	i += (stash[i] == '\n');
	if (!stash[i])
		return ("");
	return (stash.substr(i));
}

std::string get_next_line(int fd)
{
	static std::string stash;
	std::string	chosen_one;

	stash = read_as_buffer(fd, stash);
	if (stash.empty())
		return ("");
	chosen_one = next_lining(stash);
	stash = clean_stash(stash);
	return (chosen_one);
}
