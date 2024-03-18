#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void main()
{
    int i;
    printf("\n\n");
    for (i = 0; i < 72; i++)
    {
        printf("=");
    }
    printf("D'BOT Shell"); 
    for (i = 0; i < 73; i++)
    {
        printf("=");
    }
    //===============================================displaying top introduction
    printf("\n\nThe D'BOT Shell is a command-line interpreter that provides a user interface to interact with the operating system. It is a program that takes commands from the user and executes them. The shell also provides a variety of features to help users interact with the operating system, such as file and directory management, data manipulation, etc. .\n\n");
    for (i = 0; i < 156; i++)
    {
        printf("=");
    }
    Sleep(3000);
    char command[1000];
    while (command != "exit")
    {
        printf("\n\n$");
        printf("\033[0;32m");
        printf("_ ");
        fgets(command, sizeof(command), stdin);

        command[strcspn(command, "\n")] = 0;

        system(command);
    }
}
