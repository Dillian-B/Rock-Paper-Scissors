//  =========================================================
//  Rock, Paper, Scissors.cpp: This file contains the 'main' 
//  function. Program execution begins and ends there.
// 
//  Version: 1.0.0
//  ==============

//  ===================
    #include <iostream>
    #include <ctime>
    using namespace std;
//  ====================

//  ===================
//  Operating Functions
//  ===================

    bool   GoAgain();
    string InnerWorkings(string, int&, int&);
    int    Score(int&, int&);
    bool   StartGame();
    string UsersChoice();
    void   WelcomeBanner();
//  =======================

//  ==========
    int main()
    {
       
        srand(time(0));

        string Choice;
        int PScore = 0;
        int CScore= 0;

        WelcomeBanner();

        if (StartGame() == false)
            return 0;

        do {

            Choice = UsersChoice();

            InnerWorkings(Choice, PScore, CScore);

        } while (GoAgain() == true);

        Score(PScore, CScore);

        return 0;
        
    } // Main()
//  ===========

//  ==============
    bool GoAgain()
    {
        char choice;

        cout << "Would you like to go again? (Y/N)? ";
        cin >> choice;
        cout << endl;

        if (choice == 'y' || choice == 'Y') {
            return true;
        }
        else {
            cout << "Too Bad... Goodbye!" << endl;
            return false;
        }
        
    } // GoAgain()
//  ==============

//  =============================================================
    string InnerWorkings(string Choice, int& PScore, int& CScore)
    {
        string Random[3] = { "Rock", "Paper", "Scissors" };

        string RandomChoice = Random[rand() % 3];

        cout << "The computer chose " << RandomChoice << endl;

        if (RandomChoice == "Rock" && Choice == "Paper") {
            cout << Choice << " beats Rock" << "." << endl << "You win!" << endl;
            PScore++;
        }
        else if (RandomChoice == "Rock" && Choice == "Scissors") {
            cout << "Rock beats " << Choice << "." << endl << "You lose!" << endl;
            CScore++;
        }
        else if (RandomChoice == "Paper" && Choice == "Scissors") {
            cout << Choice << " beats Paper" << "." << endl << "You win!" << endl;
            PScore++;
        }
        else if (RandomChoice == "Paper" && Choice == "Rock") {
            cout << "Paper beats " << Choice << "." << endl << "You lose!" << endl;
            CScore++;
        }
        else if (RandomChoice == "Scissors" && Choice == "Rock") {
            cout << Choice << " beats Scissors" << "." << endl << "You win!" << endl;
            PScore++;
        }
        else if (RandomChoice == "Scissors" && Choice == "Paper") {
            cout << "Scissors beats " << Choice << "." << endl << "You lose!" << endl;
            CScore++;
        }
        else if (RandomChoice == Choice)
            cout << Choice << " ties " << RandomChoice << endl << "You tie" << endl;

        return RandomChoice;
            
    } // InnerWorkings()
//  ====================

//  ===================================
    int Score(int& PScore, int& CScore) 
    {
        cout << "Overall Player Score = " << PScore << endl;
        cout << "Overall Computer Score = " << CScore << endl;
    
        return 0;
    
    } // Score()
//  ============

//  ================
    bool StartGame()
    {
        char choice;

        cout << endl;
        cout << "Would you like to start the game? (Y/N)? ";
        cin >> choice;
        cout << endl;

        if (choice == 'y' || choice == 'Y') {
            return true;
        }
        else {
            cout << "Too Bad... Goodbye!" << endl;
            return false;
        }

    } // StartGame()
//  ================

//  ====================
    string UsersChoice() 
    {
        string choice;

        do 
        {
            cout << "Please type a choice (Rock, Paper, or Scissors) -> ";
            cin >> choice;
            cout << endl;

            if (choice == "Rock" || choice == "Paper" || choice == "Scissors") {
                return choice;
            }
            else {
                cout << "ERROR: Please type the word 'Rock, Paper, or Scissors'." << endl;
            }

        } while (choice != "Rock" || choice != "Paper" || choice != "Scissors");
            
    } // UsersChoice()
//  ==================

//  ====================
    void WelcomeBanner() 
    {
        cout << "================================" << endl;
        cout << "Welcome to Rock, Paper, Scissors" << endl;
        cout << "================================" << endl;

    } // WelcomeBanner()
//  ====================