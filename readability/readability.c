#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>

int count_letters(char *string);
int count_sentences(char *string);
int count_words(char *string);

int main(void)
{
    char writing[100000];
    printf("Text: ");
    scanf("%[^\n]s", writing);

    float letters = count_letters(writing);
    float sentences = count_sentences(writing);
    float words = count_words(writing);

    float lettersperhund = (letters/words) * 100.00;
    float sentencesperhund = (sentences/words) * 100.00;

    int index = round((0.0588 * lettersperhund) - (0.296 * sentencesperhund) - 15.8);

    if(index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if(index >= 1)
    {
        if(index >= 16)
        {
            printf("Grade 16+\n");
            return 0;
        }
        printf("Grade %d\n", index);
        return 0;
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
}

int count_letters(char *string)
{
    int numb = 0;
    char enders[8] = {'!', ',', '.', '?', ' ', '\'', ';','"'};
    for(int i = 0; i < strlen(string); i++)
    {
        for(int j = 0; j < sizeof(enders)/sizeof(enders[0]); j++)
        {
            if(string[i] == enders[j])
            {
                numb--;
                break;
            }
        }
        numb++;
    }
    return numb;
}
int count_sentences(char *string)
{
    int numb = 0;
    char enders[3] = {'!', '.', '?'};
    for(int i = 0; i <= strlen(string); i++)
    {
        for(int j = 0; j < sizeof(enders)/sizeof(enders[0]); j++)
        {
            if(string[i] == enders[j])
            {
                numb++;
                break;
            }
        }
    }
    return numb;
}
int count_words(char *string)
{
    int numb = 0;
    char enders[8] = {'!', ',', '.', '?', ' ', ';', '"'};
    for(int i = 0; i < strlen(string); i++)
    {
        for(int j = 0; j < sizeof(enders)/sizeof(enders[0]); j++)
        {
            if(string[i] == enders[j])
            {
                numb++;
                for(int k = 0; k < sizeof(enders)/sizeof(enders[0]); k++)
                {
                    if(string[i+1] == enders[k])
                    {
                        numb--;
                    }
                }
                break;
            }
        }
    }
    return numb + 1;
}