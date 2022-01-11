#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    // Set the string answer
    char answer[] = "paul";
    char progressAnswer[] = "____";
    bool found = false;
    int guesses = 10;
    // Prompt the user for a guess
    char guess;
    while (guesses > 0)
    {
        found = false;
        printf("Welcome to hangman, the word has %lu letters\n", strlen(answer));
        printf("Please guess one letter: ");
        scanf(" %c", &guess);
        // If it exists, print out the work with _ for un-guessed and put the correct letter in the spot
        for (int i = 0; i < strlen(answer); i++)
        {
            if (guess == answer[i])
            {
                progressAnswer[i] = guess;
                found = true;
            }
        }
        if (found)
        {
            printf("Great guess, that was in there! \nThe updated word is:\n");
            // _,_,_,e,r
            for (int j = 0; j < strlen(progressAnswer); j++)
            {
                printf("%c,", progressAnswer[j]);
            }
            printf("\n");
        }
        else
        {
            printf("Nice try, but it isn't in there. Try again\n");
            guesses--;
            // _,_,_,e,r
            for (int j = 0; j < strlen(progressAnswer); j++)
            {
                printf("%c,", progressAnswer[j]);
            }
            printf("\n");
            // Also print out the number of guesses they have left
            printf("Also, you only have %d guesses left\n", guesses);
        }
        // Check for winner
        if (strcmp(progressAnswer, answer) == 0)
        {
            printf("\n\nCongrats! You have solved the hangman!\n");
            printf("Winning word is: %s\n", answer);
            return 0;
        }
    }
    printf("\n\nYou LOSE!\n\n");
}
