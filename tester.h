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

#include <cstddef>

class Tester
{
public:
	struct hash_function_info_t
	{
		const char *name;
		uint32_t (*func)(const char *str);
	};

public:
	static bool LoadDictionary(const char *filename, size_t word_length);

	static void DoTest(hash_function_info_t func_info);
};
