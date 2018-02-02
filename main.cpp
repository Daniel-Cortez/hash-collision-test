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
#include <cstdio>
#include <unordered_map>

#include "tester.h"
#include "functions/MurmurHash2.h"
#include "functions/MurmurHash3.h"
#include "functions/lookup3.h"
#include "functions/JenkinsOAAT.h"
#include "functions/fnv1a_32.h"
#include "functions/AnveCMD_Hash.h"
#include "functions/AnveHashMap_Hash.h"


uint32_t wrap_unordered_map_hash(const char *str)
{
	static std::unordered_map<std::string, int> sm;
	return sm.hash_function()(str);
}

uint32_t wrap_murmur2a(const char *str)
{
	return MurmurHash2A(str, strlen(str), (uint32_t)0);
}

uint32_t wrap_murmur3_32(const char *str)
{
	uint32_t hash;
	MurmurHash3_x86_32(str, strlen(str), (uint32_t)0, &hash);
	return hash;
}

uint32_t wrap_lookup3(const char *str)
{
#if defined HASH_BIG_ENDIAN
	return hashbig(str, strlen(str), (uint32_t)0);
#else
	return hashlittle(str, strlen(str), (uint32_t)0);
#endif
}

uint32_t wrap_FNV1a_32(const char *str)
{
	return (uint32_t)fnv_32a_str((char *)str, (Fnv32_t)0);
}

uint32_t wrap_AnveCMD_Hash(const char *str)
{
	return AnveCMD_Hash(str);
}


static const Tester::hash_function_info_t hash_functions[] =
{
	{ "std::unordered_map hash function",	wrap_unordered_map_hash },
	{ "MurmurHash2A",						wrap_murmur2a },
	{ "MurmurHash3_x86_32",					wrap_murmur3_32 },
	{ "lookup3",							wrap_lookup3 },
	{ "one-at-a-time",						JenkinsOAAT },
	{ "FNV1a_32",							wrap_FNV1a_32 },
	{ "AnveCMD_Hash",						wrap_AnveCMD_Hash },
	{ "AnveHashMap_Hash",					AnveHashMap_Hash }
};


int main(int *argc, char *argv[])
{
	bool success = true;
	if (!(success = Tester::LoadDictionary("../words_alpha.txt", (size_t)31)))
		goto ret;

	for (size_t i = 0; i < sizeof(hash_functions) / sizeof(hash_functions[0]); ++i)
		Tester::DoTest(hash_functions[i]);

ret:
	printf("\nPress any key to quit...\n");
	getchar();
	return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
