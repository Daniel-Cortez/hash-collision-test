/* Based on public domain code by Bob Jenkins.
 * http://www.burtleburtle.net/bob/hash/doobs.html
 */

#include "JenkinsOAAT.h"


uint32_t JenkinsOAAT(const char *str)
{
	uint32_t hash = 0;
	while (*str!='\0')
	{
		hash += *str++;
		hash += hash << 10;
		hash ^= hash >> 6;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}
