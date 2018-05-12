#ifndef _LIB_USER_SYSCALL_H_
#define _LIB_USER_SYSCALL_H_


#include "../stdint.h"

enum SYSCALL_NR 
{
   SYS_GETPID,
   SYS_WRITE,
   SYS_MALLOC,
   SYS_FREE,
   SYS_OPEN,
   SYS_CLOSE
};

uint32_t getpid(void);
uint32_t write(char *str);
void *malloc(uint32_t size);
void free(void *ptr);
int open(const char *pathname, int flags);
int close(int fd);

#endif

