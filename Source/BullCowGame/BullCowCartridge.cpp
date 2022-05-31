// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame(); // Set up game
    //PrintLine(TEXT("The hidden word is : %s. It is %i letters long."), *HiddenWord, HiddenWord.Len());
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    // if game is over, reset game
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        // Check player guess
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            --Lives;
            PrintLine(TEXT("Lost a life!"));
            print(TEXT("%i"), Lives);
            
            if (Lives > 0)
            {
              if (HiddenWord.Len() != Input.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing the word again. \nYou have %i lives left."), Lives);
                }  
            } else {
                PrintLine(TEXT("You have lost!"));
                EndGame();
            }
            
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    // Welcoming player
    PrintLine(TEXT("Welcome to Bull Cows!"));
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and\npress enter to continue."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("The hidden word was %s"), *HiddenWord);
    PrintLine(TEXT("Press enter to play again."));
}