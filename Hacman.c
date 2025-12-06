#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 30
#define MAX_ATTEMPTS 5

int ChooseCategory();
char *PickRandomSelectedWord(char SelectedCategoryWords[MAX_WORDS][MAX_WORD_LENGTH]);
void InitializeRandomlySelectedWord(char* SelectedCategoryWords, char HiddenWord[MAX_WORD_LENGTH]);
int EvaluatePlayerGuess(char PlayerGuess, char* SelectedCategoryWords, char HiddenWord[]);

int main()
{
    srand(time(NULL)); // Seed the random number generator once at the start

    int WrongGuessesByPlayer = 0;
    char LetterGuessedByPlayer;

    char AsianCountries[MAX_WORDS][MAX_WORD_LENGTH] = {"INDIA","NEPAL","BHUTAN","CHINA","BANGLADESH",
                                                       "SRILANKA","KOREA","JAPAN","INDONESIA","AFGANISTAN"};
    char IndiaCities[MAX_WORDS][MAX_WORD_LENGTH] = {"MUMBAI","CHENNAI","KOLKATA","DELHI","BANGALORE",
                                                    "HYDERABAD","KERALA","TAMILNADU","PUNE","LUCKNOW"};
    char Animals[MAX_WORDS][MAX_WORD_LENGTH] = {"LIONS","TIGER","CHEETAH","LEOPARD","BEAR",
                                                "CAMEL","COW","DEER","ZEBRA","ELEPHANT"};
    char SelectedCategoryWords[MAX_WORDS][MAX_WORD_LENGTH] = {""};

    char* RandomlySelectedWord;
    char HiddenWord[MAX_WORD_LENGTH];

    int SelectedCategoryIndex = -1;
    do
    {
        SelectedCategoryIndex = ChooseCategory();
    } while (SelectedCategoryIndex == -1);
    
    switch (SelectedCategoryIndex)
    {
    case 1:
        memcpy(SelectedCategoryWords,AsianCountries,sizeof(AsianCountries));
        printf("You have selected Asian Countries! Lets Play\n");
        break;
    case 2:
        memcpy(SelectedCategoryWords,IndiaCities,sizeof(IndiaCities));
        printf("You have selected Indian Cities! Lets Play\n");
        break;
    case 3:
        memcpy(SelectedCategoryWords,Animals,sizeof(Animals));
        printf("You have selected Animals! Lets Play\n");
        break; 
    default:
        break;
    }

    RandomlySelectedWord = PickRandomSelectedWord(SelectedCategoryWords);
    InitializeRandomlySelectedWord(RandomlySelectedWord,HiddenWord);
    //Main game loop
    while(WrongGuessesByPlayer < MAX_ATTEMPTS)
    {
        printf("\n%s",HiddenWord);
        printf("\n Guess a letter for hidden word : ");

        scanf("%c",&LetterGuessedByPlayer);
        getc(stdin); // To not allow enter as an input

        LetterGuessedByPlayer = toupper(LetterGuessedByPlayer);

        if(EvaluatePlayerGuess(LetterGuessedByPlayer,RandomlySelectedWord,HiddenWord) == 0)
        {
            printf("\n Nope! %c is not part of this word, Please try again\n",LetterGuessedByPlayer);
            WrongGuessesByPlayer++;
        }
        else 
        {
            printf("You have guessed it correctly\n\n");
        }
        printf("Attempts left is %d \n",MAX_ATTEMPTS - WrongGuessesByPlayer);
        if(strcmp(RandomlySelectedWord,HiddenWord) == 0)
        {
            printf("You have guessed the correct word, well done!");
            printf("The word is %s\n",RandomlySelectedWord);

            break;
        }
    }
    if(MAX_ATTEMPTS == WrongGuessesByPlayer)
    {
        printf("Retry exhausted better luck next time\n");
        printf("The actual word is %s \n",RandomlySelectedWord);
    }
    return 0;
}

int ChooseCategory()
{
    int UserInput;
    printf("Select category of words to play with \n 1. Asia Countries \n 2. India Cities \n 3. Animals \n");
    char inputBuffer[100];
    if (fgets(inputBuffer, sizeof(inputBuffer), stdin) != NULL && sscanf(inputBuffer, "%d", &UserInput) == 1)
    {
        if(UserInput > 0 && UserInput < 4)
        {
            return UserInput;
        }
    }
    printf("\nINVALID INPUT, PLEASE TRY AGAIN\n\n");
    return -1;
}

char *PickRandomSelectedWord(char SelectedCategoryWords[MAX_WORDS][MAX_WORD_LENGTH])
{
    int randomIndex = rand() % MAX_WORDS;
    return SelectedCategoryWords[randomIndex];
}

void InitializeRandomlySelectedWord(char* RandomlySelectedWord, char HiddenWord[MAX_WORD_LENGTH])
{
    int index = 0;
    int WordLength = strlen(RandomlySelectedWord);
    for(index = 0; index < WordLength; index++)
    {
        HiddenWord[index] = '-';
    }
    HiddenWord[index] = '\0';
}

int EvaluatePlayerGuess(char PlayerGuess, char* RandomlySelectedWord, char HiddenWord[])
{
    int index = 0;
    int outcome = 0;
    for(index = 0; RandomlySelectedWord[index] != '\0'; index++)
    {
        // Only update positions where the guess matches and hasn't been revealed yet
        if(PlayerGuess == RandomlySelectedWord[index] && HiddenWord[index] != PlayerGuess)
        {
            HiddenWord[index] = PlayerGuess;
            outcome++;
        }
    }
    return outcome;
}
