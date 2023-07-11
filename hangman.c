#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

int draw(int *state, int numb, char* input, char letter, char* word);

int main(void)
{
    char *input = malloc(100);
    if(input == NULL)
    {
        return 0;
    }
    printf("Word/Pharse(use '_' as spacing):");
    scanf("%s", input);
    for(int i = 0; i < 50; i++)
    {
        printf("\n");
    }
    int state = 0;
    char *guess = malloc(100);
    char word[100] = {[0 ... 99] = '_'};
    int check;
    for(int i = 0; i < strlen(input); i++)
    {
        input[i] = tolower(input[i]);
        if(input[i] < 97 || input[i] > 122)
        {
            if(input[i] == 95)
            {
                input[i] = ' ';
                word[i] = ' ';
            }
            else
            {
                word[i] = input[i];
            }
        }
            printf(" %c", word[i]);
    }
    printf("\n\n");
    while(1)
    {
        do {printf("letter:");
        scanf("%s",guess);} while ( guess[0] == '\n' );
      //  printf("letter:");  simliar to the top one
     //   do {scanf("%c",guess);} while ( getchar() != '\n' );
        printf("\n\n\n");
        if(!strcasecmp(guess, input))
        {
            check = draw(&state, 2, input, '1', word);
        }
        else if(strlen(guess) == 1)
        {
        guess[0] = tolower(guess[0]);
        for(int i = 0; i < strlen(input); i++)
        {
        if(guess[0] == input[i])
        {
            check = draw(&state, 1, input, guess[0], word);
            break;
        }
            if(i == strlen(input) - 1)
            {
            check = draw(&state, 0, input, '1', word);
            }
        }
        }
        else
        {
        check = draw(&state, 0, input, '1', word);
        }
        if(state == 8)
        {
            printf("lost\n");
            printf("The word is '%s'\n", input);
            break;
        }
        if(check == 1)
        {
            printf("win\n");
            break;
        }
    }
    free(guess);
    free(input);
}

int draw(int* state, int numb, char* input, char letter, char* word)
{
    if(numb == 1)
    {
        for(int i = 0; i < strlen(input); i++)
        {
            if(letter == input[i])
            {
                word[i] = letter;
            }
        }
    }
    else if(numb == 2)
    {
        strcpy(word, input);
    }
    else
    {
        *state = *state + 1;
    }
    char* image[8] = {"", "-------\n|      |\n|", "O", "|", "/", "\\", "/", "\\"};
    for(int i = 7; i >= *state; i--)
    {
        image[i] = "";
    }
    if(*state >= 1)
    {
    printf("|%s"
           "      %s\n"
           "|     %s%s%c\n"
           "|     %s %c\n"
           "|\n"
           "|\n\n", image[1], image[2], image[4], image[3], image[5][0], image[6], image[7][0]);
    }
    int t = 0;
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            printf(" ");
        }
        else
        {
            printf(" %c", word[i]);
            if(word[i] == '_')
            {
                t = 1;
            }
        }
    }
    printf("\n");
    if(t == 0)
    {
        return 1;
    }
    return 0;
}