/* This code is part of Unreal Engine C++ Developer course: 
https://www.udemy.com/course/unrealcourse/  
*/

#include <iostream>
#include <ctime>

bool PlayGameWithDifficulty(int Difficulty){
    srand (time(NULL));
    // Generate numbers to be guessed
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Instructions
    std::cout << "You are a secret agent trying to break into a Lever " << Difficulty << " Server Room." << std::endl;
    std::cout << "In order to do this, you have to crack the code following the intructions below." << std::endl;
    std::cout << " - Enter three numbers with a spece between them." << std::endl;
    std::cout << " - The sum of the three numers is equal to " << CodeSum << "." << std::endl;
    std::cout << " - The product of the three numbers is equal to " << CodeProduct << "." << std::endl;


    // User input
    int GuessA, GuessB, GuessC;

    std::cout << "Enter the code: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    // Return result, are the guessed number correct?
    if(CodeSum == GuessSum && CodeProduct == GuessProduct)
        return true;
    return false;
}

int main(){
    int LevelDifficulty = 1;
    int MaxLevel = 10;
    while(LevelDifficulty <= MaxLevel){
        bool bLevelComplete = PlayGameWithDifficulty(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            std::cout << std::endl << "You entered the room!" << std::endl ;
            ++LevelDifficulty;
        }else
        {
            std::cout << std::endl << "Wrong code! You're at the beginning again!" << std::endl;
            LevelDifficulty = 1;
        }
    }
    std::cout << "CONGRATULATIONS! You cleared all rooms! You're a master cracker!" << std::endl;
    return 0;
}