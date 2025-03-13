/*
    Slavomir Svorada
    xsvora02
    14.11.2019
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100 + 1  // +1 because of '\0' character
#define ERROR -1

int read_contact(char name[], char number[]);
int compare_number(char number[]);
int compare_name(char name[], char *a, int length);

int main(int argc, char *argv[])
{
    char number[SIZE];  // String for numbers
    char name[SIZE];    // String for names

    if (argc > 2)   // More than 2 arguments
        printf("Too many arguments.\n");

    else if (argc == 1) // When use only one argument
    {
        for (int j = 0; j < 43; j++)    // 43 because we have 42 contacts
        {
            int result = read_contact(name, number);
            if (result == 1)    // Undefined name or number
            {
                break;
            }
            else if (result == ERROR)   // More than 100 characters OR incorrect defined name or number
            {
                return ERROR;
            }
            else if (result == 0)   // When everything is good
            {
                printf("%s, %s\n", name, number);
            }
        }
    }
    else if (argc == 2) // Use just 2 arguments
    {
        int poc = 0;
        for (int j = 0; j < 43; j++)
        {
            int result = read_contact(name, number);
            if (result == 1)
            {
                break;
            }
            else if (result == ERROR)
            {
                return ERROR;
            }
            else if (result == 0)
            {
                char *a = argv[1];
                int length_name = strlen(name);
                int count_blank_space = 0;
                for (int i = 0; i < length_name; i++) {
                    if(name[i] == ' ')
                    {
                        count_blank_space++;
                    }
                }
                int length = length_name-count_blank_space;
                if (strstr(number, a) != 0)
                {
                    poc++;
                    printf("%s, %s\n", name, number);
                }
                else if (compare_name(name, a, length) == 0)
                {
                    poc++;
                    printf("%s, %s\n", name, number);
                }
            }
        }
        if (poc == 0)   // When the strings of numbers do not contain searched numbers
        {
            printf("NOT FOUND.\n");
        }
    }
    return 0;
}

int compare_name(char *name, char *a, int length)
{
    int length_name = strlen(name);
    char name_without_space[length];
    int l = 0;
    for(int i = 0; i < length_name; i++)
    {
        if(name[i] != ' ')
        {
            name_without_space[l] = name[i];
            l++;
        }
    }

    name_without_space[l] = '\0'; // Last character is '\0'
    char result_number[length];

    for(int j = 0; j < length; j++)
    {
        char name_lower = tolower(name_without_space[j]);

        if((name_lower == 'a') || (name_lower == 'b') || (name_lower == 'c'))
        {
            result_number[j] = '2';
        }
        else if((name_lower == 'd') || (name_lower == 'e') || (name_lower == 'f'))
        {
            result_number[j] = '3';
        }
        else if((name_lower == 'g') || (name_lower == 'h') || (name_lower == 'i'))
        {
            result_number[j] = '4';
        }
        else if((name_lower == 'j') || (name_lower == 'k') || (name_lower == 'l'))
        {
            result_number[j] = '5';
        }
        else if((name_lower == 'm') || (name_lower == 'n') || (name_lower == 'o'))
        {
            result_number[j] = '6';
        }
        else if((name_lower == 'p') || (name_lower == 'q') || (name_lower == 'r') || (name_lower == 's'))
        {
            result_number[j] = '7';
        }
        else if((name_lower == 't') || (name_lower == 'u') || (name_lower == 'v'))
        {
            result_number[j] = '8';
        }
        else if((name_lower == 'w') || (name_lower == 'x') || (name_lower == 'y') || (name_lower == 'z'))
        {
            result_number[j] = '9';
        }
       // else
            //result_number[j] = name_lower; //
    }
    result_number[length] = '\0';   // Last character is '\0'
    if (strstr(result_number,a) != 0)   // Compare string with argument
        return 0;
    else
        return 1;
}

int read_contact(char name[], char number[])
{
    char c = 0;
    int i = 0;
    while ((c = getchar()) != '\n')
    {
        if (i > (SIZE - 2))   // -2 because index starts at 0 and last character is '\0'
        {
            printf("Name input has more than 100 characters.\n");
            return ERROR;
        }
        if (isalpha(c) || (c == ' ') || (c == '.'))
        {
            if (isalpha(c))
            {
                c = tolower(c);
            }
            name[i] = c;
        } else if (c == EOF) {
            break;
        } else {
            printf("Not allowed character in name.\n");
            return ERROR;
        }
        i++;
    }
    name[i] = '\0'; // Last character is '\0'
    if (i == 0)
    {
        return 1;
    }

    i = 0;
    while ((c = getchar()) != '\n')
    {
        if (i > (SIZE- 2))   // -2 because index starts at 0 and last character is '\0'
        {
            printf("Number input has more than 100 characters.\n");
            return ERROR;
        }
        if (isdigit(c) || (c == '+'))
        {
            number[i] = c;
            if ((strstr(number, "+") != 0) && (number[0] != '+'))
            {
                printf("Incorrect format of number.\n");
                return ERROR;
            }
        } else if (c == EOF)
        {
            break;
        } else {
            printf("Not allowed digit in number.\n");
            return ERROR;
        }
        i++;
    }
    number[i] = '\0';
    if (i == 0)
    {
        return 1;
    }

    return 0;
}