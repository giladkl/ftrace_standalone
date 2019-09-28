#define _GNU_SOURCE

#include <sys/syscall.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helper.h"

extern char _binary_standalone_ftrace_ko_start;
extern char _binary_standalone_ftrace_ko_size;

uint32_t * module_layout_magic_ptr = NULL;
char * ver_magic_ptr = NULL;

#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)

int main(int argc, char ** argv)
{
    
    module_layout_magic_ptr = memmem(&_binary_standalone_ftrace_ko_start, (int) &_binary_standalone_ftrace_ko_size, "\x13\x37\x13\x37module_layout", 4);
    *module_layout_magic_ptr = atoi(argv[1]);

    ver_magic_ptr = memmem(&_binary_standalone_ftrace_ko_start, (int) &_binary_standalone_ftrace_ko_size, "VERMAGICHEREPLEASE", 4);
    strcpy(ver_magic_ptr, argv[2]);

    if (0 != init_module(&_binary_standalone_ftrace_ko_start, &_binary_standalone_ftrace_ko_size, ""))
    {
        perror("Error while loading module: ");
    }
    return 0;
}