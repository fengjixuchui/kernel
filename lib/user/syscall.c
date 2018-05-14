#include "syscall.h"

/* 无参数的系统调用 */
#define _syscall0(NUMBER)  \
({                         \
        int retval;        \
        asm volatile(      \
            "int $0x80"    \
            : "=a"(retval) \
            : "a"(NUMBER)  \
            : "memory");   \
        retval;            \
})

/* 一个参数的系统调用 */
#define _syscall1(NUMBER, ARG1)      \
    ({                               \
        int retval;                  \
        asm volatile(                \
            "int $0x80"              \
            : "=a"(retval)           \
            : "a"(NUMBER), "b"(ARG1) \
            : "memory");             \
        retval;                      \
    })

/* 两个参数的系统调用 */
#define _syscall2(NUMBER, ARG1, ARG2) ({    \
    int retval;                             \
    asm volatile(                           \
        "int $0x80"                         \
        : "=a"(retval)                      \
        : "a"(NUMBER), "b"(ARG1), "c"(ARG2) \
        : "memory");                        \
    retval;                                 \
})

/* 三个参数的系统调用 */
#define _syscall3(NUMBER, ARG1, ARG2, ARG3) ({         \
    int retval;                                        \
    asm volatile(                                      \
        "int $0x80"                                    \
        : "=a"(retval)                                 \
        : "a"(NUMBER), "b"(ARG1), "c"(ARG2), "d"(ARG3) \
        : "memory");                                   \
    retval;                                            \
})

/* 返回当前任务pid */
uint32_t getpid()
{
    return _syscall0(SYS_GETPID);
}

uint32_t write(int32_t fd, const void *buf, uint32_t count)
{
    return _syscall3(SYS_WRITE, fd, buf, count);
}

void *malloc(uint32_t size)
{
    return (void*)_syscall1(SYS_MALLOC, size);
}

void free(void *ptr)
{
    _syscall1(SYS_FREE, ptr);
}

int open(const char *pathname, int flags)
{
    return _syscall2(SYS_OPEN, pathname, flags);
}

int close(int fd)
{
    return _syscall1(SYS_CLOSE, fd);
}

int32_t read(int32_t fd, void *buf, uint32_t count)
{
    return _syscall3(SYS_READ, fd, buf, count);
}

int32_t lseek(int32_t fd, int32_t offset, uint8_t whence)
{
     return _syscall3(SYS_LSEEK, fd, offset, whence);
}

int32_t unlink(const char *pathname)
{
    return _syscall1(SYS_UNLINK, pathname);
}