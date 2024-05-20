#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 30
#define MAX_ATTEMPS 5

int ChooseCategory();
char *PickRandomSelectedWord(char SelectedCategoryWords[MAX_WORDS][MAX_WORD_LENGTH]);
void InitializeRandomlySelectedWord(char* SelectedCategoryWords, char HiddenWord[MAX_WORDS]);
int EvaluatePlayerGuess(char PlayerGuess, char* SelectedCategoryWords, char HiddenWord[]);

int main()
{
    int WrongGuessesByPlayer = 0;
    char LetterGuessedByPlayer;

    char AsianCountries[MAX_WORDS][MAX_WORD_LENGTH] = {"INDIA","NEPAL","BHUTAN","CHINA","BANGLADESH",
                                                       "SRILANKA","KOREA","JAPAN","INDONESIA","AFGANISTAN"};
    char IndiaCities[MAX_WORDS][MAX_WORD_LENGTH] = {"MUMBAI","CHENNAI","KOLKATA","DELHI","BANGALORE",
                                                    "HYDERABAD","KERALA","TAMILNADU"};
    char Animals[MAX_WORDS][MAX_WORD_LENGTH] = {"LIONS","TIGET","CHEETAH","LEOPARD","BEAR",
                                                "CAMEL","COW","DEER","ZEBRA","ELEPHANT"};
    char SelectedCategoryWords[MAX_WORDS][MAX_WORD_LENGTH] = {""};

    char* RandomlySelectedWord;
    char HiddenWord[MAX_WORDS];

    int SeletedCategoryIndex = -1;
    do
    {
        SeletedCategoryIndex = ChooseCategory();
    } while (SeletedCategoryIndex == -1);
    
    switch (SeletedCategoryIndex)
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
    while(WrongGuessesByPlayer < MAX_ATTEMPS)
    {
        printf("\n%s",HiddenWord);
        printf("\n Guess a letter for hidden word : ");

        scanf("%c",&LetterGuessedByPlayer);
        getc(stdin); // To not allow enter as an input

        LetterGuessedByPlayer = toupper(LetterGuessedByPlayer);
        fflush(stdin);

        if(EvaluatePlayerGuess(LetterGuessedByPlayer,RandomlySelectedWord,HiddenWord) == 0)
        {
            printf("\n Nope! %c is not part of this word, Please try again\n",LetterGuessedByPlayer);
            WrongGuessesByPlayer++;
        }
        else 
        {
            printf("You have guessed it corretly\n");
        }
        printf("Attemps left is %d \n",MAX_ATTEMPS - WrongGuessesByPlayer);
        if(strcmp(RandomlySelectedWord,HiddenWord) == 0)
        {
            printf("You have guessed the correct word, well done!");
            printf("The word is %s",RandomlySelectedWord);

            break;
        }
    }
    if(MAX_ATTEMPS == WrongGuessesByPlayer)
    {
        printf("Retry exhausted better luck nextime\n");
        printf("The actual word is %s \n",RandomlySelectedWord);
    }
    return 0;
}

int ChooseCategory()
{
    int UserInput;
    printf("Select category of words to play with \n");
    printf("Press 1 for Asian Countries\n");
    printf("Press 2 for Indian Cities\n");
    printf("Press 3 for Animals\n");
    scanf("%d",&UserInput);
    getc(stdin);
    fflush(stdin);
    
    if(UserInput > 0 && UserInput < 4)
    {
        return UserInput;
    }
    else
    {
        printf("\nINVALID INPUT, PLEASE TRY AGAIN\n\n");
        return -1;
    }

}

char *PickRandomSelectedWord(char SelectedCategoryWords[MAX_WORDS][MAX_WORD_LENGTH])
{
    srand(time(NULL));
    int RandomlySelectedWordIndex = rand() % MAX_WORDS;
    //int RandomlySelectedWordIndex = 0; //hack remove later
    return((char*)SelectedCategoryWords[RandomlySelectedWordIndex]);
}

void InitializeRandomlySelectedWord(char* SelectedCategoryWords, char HiddenWord[MAX_WORDS])
{
    int index = 0;
    int WordLength = strlen(SelectedCategoryWords);
    if(WordLength > 3)
    {
        for(index = 0;index<WordLength;index++)
        {
            HiddenWord[index] = '-';
        }
        HiddenWord[index] = '\0';
    }
    
}

int EvaluatePlayerGuess(char PlayerGuess, char* SelectedCategoryWords, char HiddenWord[])
{
    int index = 0;
    int outcome = 0;
    for(index = 0; SelectedCategoryWords[index] != '\0';index++)
    {
        // check whether word has already been guessed or its a wrong guess
        if(PlayerGuess == HiddenWord[index])
        {
            return 0;
        }
        // player has gussed in correctly
        if(PlayerGuess == SelectedCategoryWords[index])
        {
            HiddenWord[index] = PlayerGuess;
            outcome++;
        }
    }
    return outcome;
}
