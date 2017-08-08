#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/functions.c"

kmain()
{	
	clearScreen();
	print("PDOS MADE BY PIXEL DEVELOPERS\n");
	print("\nPDOS: Type: lis for a list of commands in PDOS\n");
	while(1)
	{
         	print("\nPDOS> ");
                
                string ch = readStr();
                if(strEql(ch,"cmd"))
                {
                        print("\nYou are allready in cmd\n");
                }
                else if(strEql(ch,"clear"))
                {
                        clearScreen();
                }
		else if(strEql(ch,"lis"))
                {
                        list();
                }
		else if(strEql(ch,"calculator"))
                {
                        calc();
                }
		else if(strEql(ch,"ver"))
                {
                        ver();
                }
                else
                {
                        print("\nBad command!\n");
                }
                
                print("\n");        
       }
}
