/* This code is derived from AnveCMD plugin for SA-MP */

#include <string.h>

#include "AnveCMD_Hash.h"


int AnveCMD_Hash(const char *cmd) {
	int i = 0,
		result = 0;
	while (i < strlen(cmd)) {
		result += result - (cmd[i] * 2) - i;
		i++;
	}
	return result;
}
