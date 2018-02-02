/*==============================================================================
	Copyright (c) 2016-2018 Stanislav Gromov

	This program is free software : you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.If not, see <https://www.gnu.org/licenses/>.
==============================================================================*/

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#include "tester.h"


static std::vector<std::string> dictionary;
static std::map<uint32_t, std::string> dict_map;


bool Tester::LoadDictionary(const char *filename, size_t word_length)
{
	std::string line;
	std::ifstream f;

	printf("Loading the dictionary from file \"%s\"...\n", filename);
	f.open(filename);
	if (f.bad())
	{
		printf("Couldn't open file \"%s\"!\n", filename);
		return false;
	}
	while (std::getline(f, line))
		if (line.length() <= word_length)
			dictionary.push_back(std::string(line));
	f.close();

	printf("Loaded %d words\n", dictionary.size());
	return true;
}

void Tester::DoTest(hash_function_info_t func_info)
{
	size_t num_collisions = 0;
	printf("\nTesting: %s...\n", func_info.name);
	for (size_t i = 0; i < dictionary.size(); ++i)
	{
		const char *word = dictionary.at(i).c_str();
		const uint32_t hash = func_info.func(word);
		std::map<uint32_t, std::string>::iterator it = dict_map.find(hash);
		if (it == dict_map.end())
		{
			dict_map.insert(std::pair<uint32_t, std::string>(hash, word));
			continue;
		}
		//printf("Found collision: %s and %s (%08lx)\n", it->second.c_str(), word, (long)hash);
		++num_collisions;
	}
	dict_map.clear();
	if (num_collisions == 0)
		printf("No collisions found\n");
	else
		printf("Found %ld collisions\n", num_collisions);
}
