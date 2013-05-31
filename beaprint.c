#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BEA_ENGINE_STATIC  /* specify the usage of a static version of BeaEngine */
#define BEA_USE_STDCALL    /* specify the usage of a stdcall version of BeaEngine */
#include "BeaEngine.h"


#define START_ADDR      0x1000
#define LEN             0x11000          

int main(char *argv[], int argc) {
	/* ============================= Init datas */
    DISASM MyDisasm;
    int len, i = 0;
    int Error = 0;
     
    FILE *f;
    char * buffer = (char *) malloc((sizeof(char) * 1024 * 1024));
    int n;

    f = fopen("input.bin", "rb");
    if(f) {
        n = fread(buffer, 1024*1025, 1, f);
    } else {
        printf("[*] ERROR");
    }

    for(i = START_ADDR; i < LEN; i++) {
            //if(i > 00001000 && i < 00001100) {
                printf("[%d] %#x \n", i, buffer[i]);
            //}

    }
    i = 0;
    //return 0;

    /* ===================== display the version and revision used */
        (void) printf("Version : %s\n", BeaEngineVersion());
        (void) printf("Revision : %s\n", BeaEngineRevision());
    /* ============================= Init the Disasm structure (important !)*/
    (void) memset (&MyDisasm, 0, sizeof(DISASM));
 
    /* ============================= Init EIP */
    MyDisasm.EIP = (UIntPtr) &buffer[START_ADDR];//&main;
 
    /* ============================= Loop for Disasm */
    while ((!Error) && (i<LEN)){
        len = Disasm(&MyDisasm);
        //printf("ASd");
        if (len != UNKNOWN_OPCODE) {
            (void) puts(MyDisasm.CompleteInstr);
            MyDisasm.EIP = MyDisasm.EIP + (UIntPtr)len;
            i++;
        } else {
            MyDisasm.EIP = MyDisasm.EIP + 1;
        }
        //else {
            //printf("ERROR");
            //Error = 1;
        //}
    };

	return 0;
}
