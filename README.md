# Hangman Game (Hacman)

A classic word-guessing game implemented in C, featuring multiple categories and interactive gameplay.

## 📋 Description

Hacman is a terminal-based Hangman game where players guess letters to reveal hidden words. The game includes three different word categories:
- **Asian Countries** - Guess names of countries in Asia
- **Indian Cities** - Guess major cities in India
- **Animals** - Guess names of animals

## 🎮 How to Play

1. Run the program
2. Select a category (1-3)
3. Guess letters one at a time
4. You have **5 attempts** to guess wrong letters
5. Reveal all letters in the word before running out of attempts to win
6. The hidden word is displayed with dashes (`-`) for unrevealed letters

## 💻 Requirements

- C compiler (GCC recommended)
- Standard C libraries

## 🚀 Compilation & Execution

### On Windows:
```bash
gcc Hacman.c -o Hacman.exe
Hacman.exe
```

### On Linux/macOS:
```bash
gcc Hacman.c -o Hacman
./Hacman
```

## 🎯 Features

- **Multiple Categories**: Choose from 3 different word categories
- **Input Validation**: Ensures valid category selection
- **Case Insensitive**: Accepts both uppercase and lowercase letter guesses
- **Attempt Tracking**: Shows remaining attempts after each guess
- **Game Win/Loss Detection**: Automatically detects when you win or lose
- **Random Word Selection**: Uses `rand()` for random word selection each game

## 📝 Game Rules

1. Select a category at the start
2. Guess one letter per turn
3. Correct guesses reveal all instances of that letter
4. Incorrect guesses count against your 5 attempts
5. Win by revealing the entire word before attempts run out
6. Lose if you exhaust all 5 attempts

## 🔧 Code Structure

- **ChooseCategory()**: Handles category selection with input validation
- **PickRandomSelectedWord()**: Selects a random word from the chosen category
- **InitializeRandomlySelectedWord()**: Creates the hidden word display
- **EvaluatePlayerGuess()**: Checks the guess and updates the hidden word

## 📊 Word Categories

| Category | Words |
|----------|-------|
| Asian Countries | India, Nepal, Bhutan, China, Bangladesh, Sri Lanka, Korea, Japan, Indonesia, Afghanistan |
| Indian Cities | Mumbai, Chennai, Kolkata, Delhi, Bangalore, Hyderabad, Kerala, Tamil Nadu, Pune, Lucknow |
| Animals | Lions, Tiger, Cheetah, Leopard, Bear, Camel, Cow, Deer, Zebra, Elephant |

## 🐛 Known Limitations

- Only available in English (uppercase words)
- Limited word database (10 words per category)
- Console-based interface only
- No word hints feature
- Cannot replay without rerunning the program

## 🎓 Learning Concepts

This project demonstrates:
- String manipulation in C
- Arrays and pointers
- Function declarations and definitions
- Random number generation
- Input validation and error handling
- Game loop logic

## 📄 License

Feel free to use and modify this code for educational purposes.

## 👨‍💻 Author

Created as a learning project for C programming.

## 🤝 Contributing

eel free to fork this project
