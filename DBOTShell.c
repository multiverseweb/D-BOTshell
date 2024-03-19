#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"
#define block u"U+2588"

int main()
{
    sleep(2);
    int z;
    int width = 50;

    for (z = 0; z <= width; z++) {
        printf("\r");
        printf(YELLOW);
        printf("[");
        for (int j = 0; j < width; j++) {
            if (j < z) {
                printf("|||");
            } else {
                printf("   ");
            }
        }
        printf("]%d%%", z * 2);
        fflush(stdout);
        usleep(2300);
    }

    
    char command[100];
    int i;
    printf(RESET "\n");
    for (i = 0; i < 72; i++)
    {
        printf("=");
    }
    printf("D'BOT Shell");
    for (i = 0; i < 73; i++)
    {
        printf("=");
    }
    //===============================================================displaying top introduction
    printf(CYAN "\n\nThe D'BOT Shell is a command-line interpreter that provides a user interface to interact with the operating system. It is a program that takes commands from the user and executes them. The shell also provides a variety of features to help users interact with the operating system, such as file and directory management, data manipulation, etc. .\nThe commands that can be executed are listed below:\n\n- mkdir dir_name\n- touch file_name\n- cat file_name\n- echo 'text_to_write' > file_name\n- ls\n- pwd\n- exit\n\n");
    printf(RESET);
    for (i = 0; i < 156; i++)
    {
        printf("=");
    }

    while (1)
    {
        printf(GREEN "\n$");
        printf(RESET "_ " RESET);
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "exit") == 0)
        {
            printf(MAGENTA"\nMade by Dev, Bhavya, Ojas & Tejas :)");
            sleep(2);
            printf(".");
            sleep(1);
            printf(".");
            sleep(1);
            printf(".");
            sleep(3);
            break;
        }
        else if (strncmp(command, "mkdir", 5) == 0)
        {
            char dirname[50];
            sscanf(command, "mkdir %[^\n]", dirname);
            if (mkdir(dirname) == 0)
            {
                printf(GREEN "Directory created successfully.\n" RESET);
            }
            else
            {
                printf(RED "Failed to create directory.\n" RESET);
            }
        }
        else if (strncmp(command, "touch", 5) == 0)
        {
            char filename[50];
            sscanf(command, "touch %[^\n]", filename);
            FILE *file = fopen(filename, "w");
            if (file != NULL)
            {
                fclose(file);
                printf(GREEN "File created successfully.\n" RESET);
            }
            else
            {
                printf(RED "Failed to create file.\n" RESET);
            }
        }
        else if (strncmp(command, "cat", 3) == 0)
        {
            char filename[50];
            sscanf(command, "cat %[^\n]", filename);
            FILE *file = fopen(filename, "r");
            if (file != NULL)
            {
                char ch;
                while ((ch = fgetc(file)) != EOF)
                {
                    printf("%c", ch);
                }
                fclose(file);
            }
            else
            {
                printf(RED "Failed to open file.\n" RESET);
            }
        }
        else if (strncmp(command, "echo", 4) == 0) {
            char text[100];
            char filename[50];
            sscanf(command, "echo '%[^\n]' > %[^\n]", text, filename);
            FILE *file = fopen(filename, "a");
            if (file != NULL) {
                fprintf(file, "%s\n", text);
                fclose(file);
                printf(GREEN "Text written to file.\n" RESET);
            } else {
                printf(RED "Failed to open file.\n" RESET);
            }
        }
        else if (strncmp(command, "ls", 2) == 0)
        {
            system("ls");
        }
        else if (strncmp(command, "pwd", 3) == 0)
        {
            system("pwd");
        }
        else
        {
            printf(YELLOW "Command not supported.\n" RESET);
        }
        /*else{
            system(command);
        }*/
    }

    return 0;
}
