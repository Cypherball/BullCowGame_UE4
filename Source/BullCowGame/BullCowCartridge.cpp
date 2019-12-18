// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cow Game!\nYou have to guess the correct word.\nGood luck!\n"));  
    InitGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    
    if(bGameOver)
    {
        InitGame();
        return;
    } 

    if(Input.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i characters long. Try again. You have %i chances remaining."),WordLength,Lives);
        return;
    }
    if(Input == HiddenWord){
        PrintLine(TEXT("You've won!"));
        EndGame();
    } else
    {
        if(--Lives)
        {
            PrintLine(TEXT("Nope, try again! You have %i guesses remaining."),Lives);
        } else
        {
            PrintLine(TEXT("You are out of lives. Game Over!"));
            EndGame();
        }
    }
}

void UBullCowCartridge::InitGame()
{
    bGameOver = false;
    HiddenWord = "cake";
    Lives = 4;
    WordLength = HiddenWord.Len();
    SetInstructions();
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nGame has ended. Press enter to continue."));
}

void UBullCowCartridge::SetInstructions()
{
    PrintLine(TEXT("The word is %i characters long. You will have %i guesses.\nGood luck!\n"), WordLength,Lives);
}