/* See the corresponding *.cpp file for a description. */

#ifndef _INC_FNV1A_32_H
#define _INC_FNV1A_32_H

#include <stdint.h>

typedef uint32_t Fnv32_t;
Fnv32_t fnv_32a_buf(void *buf, size_t len, Fnv32_t hashval);
Fnv32_t fnv_32a_str(char *buf, Fnv32_t hashval);

#endif // _INC_FNV1A_32_H

