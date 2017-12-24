# Mastermind

A C++ program that generates three randomly generated numbers from 1 through 7. The user guesses the numbers in a proper sequence. If the number is in the sequence but in the wrong location, it is called a ***match***. If the number is in the sequence and in the right location, it is called a ***hit***.

## Sample output

```
 ̃ ̃ ̃ ̃ ̃  Welcome to the game! ̃ ̃ ̃ ̃ ̃ ̃
Numbers selected. You’ll never guess them!
Round 1:
Please input your guesses in order: 123
--------------------------------------------------
0 hits
1 matches.
Too bad. You guessed wrong.
--------------------------------------------------

Round 2:
Please input your guesses in order: 145
--------------------------------------------------
0 hits
3 matches.
Too bad. You guessed wrong.
--------------------------------------------------
Round 3:
Please input your guesses in order: 415
--------------------------------------------------
1 hits
2 matches.
Too bad. You guessed wrong.
--------------------------------------------------
Round 4:
Please input your guesses in order: 451
--------------------------------------------------
0 hits
3 matches.
Too bad. You guessed wrong.
--------------------------------------------------
Round 5:
Please input your guesses in order: 514
--------------------------------------------------
3 hits
0 matches.
*****
Congratulations! You won the game! It only took you 5 rounds!
*****
Do you want to play again? n

See you next time!
--------------------------------------------------
```