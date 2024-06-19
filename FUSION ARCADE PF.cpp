#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Function to set the cursor position on the console window
void gotoxy(int x, int y) {
    COORD coord={x , y};
//    coord.X = x;
//    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Here i used fuction to draw a  gameboard ,paddle, ball, score, and lives
void drawBoard(int paddleX, int ballX, int ballY, int score, int lives) {
    system("cls");

    // Draw the paddle
    gotoxy(paddleX, 22); 
    cout << "======";

    // Draw the ball
    gotoxy(ballX, ballY);
    cout << "O";

    // Draw the boundaries of the gameboard
    for (int i = 0; i < 42; i++) {
        gotoxy(i, 0);
        cout << "#";
        gotoxy(i, 24);
        cout << "#";
    }

    for (int i = 0; i < 25; i++) {
        gotoxy(0, i);
        cout << "#";
        gotoxy(41, i);
        cout << "#";
    }

    // Display score and lives
    gotoxy(45, 5);
    cout << "Score: " << score;
    gotoxy(45, 7);
    cout << "Lives: " << lives;
}

//  Ball Blitz Game ki logic
void BallBlitz() {
    system("mode con: lines=30 cols=60");
    int paddleX = 4;
    int ballX = 32;
    int ballY = 19;
    int ballDirX = 1;
    int ballDirY = -1;
    int score = 0;
    int lives = 3;

    cout << "Instructions: " << endl;
    cout << "*************" << endl;
    cout << "1. Press right and left arrow keys to move the paddle." << endl;
//    cout<< " \t \t \t \t \t \t \t  *You Have 3 Lives*                  "<<endl; 
    cout << "2. Press Esc key to quit the game. " ;
 	cout<< "\t \t \t \t  *You Have 3 Lives*                  "<<endl; 
    system("pause");

    while (lives > 0) {
        if (_kbhit()) {
            char key = _getch();

            if (key == 75 && paddleX > 1) {
                paddleX--;
            } else if (key == 77 && paddleX < 34) {
                paddleX++;
            } else if (key == 27) {
                break;
            }
        }

        ballX += ballDirX;
        ballY += ballDirY;

        // Check if the ball hits the paddle
        if (ballY == 20 && ballX >= paddleX && ballX <= paddleX + 5) {
            ballDirY = -ballDirY;
            score++;
        }

        // Check if the ball hits the left or right wall
        if (ballX == 1 || ballX == 40)
            ballDirX = -ballDirX;

        // Check if the ball hits the top wall
        if (ballY == 1)
            ballDirY = -ballDirY;

        // Check if the ball goes beyond the bottom wall
        if (ballY == 23) {
            lives--;
            ballX = 20;
            ballY = 19;
            ballDirY = -ballDirY;
        }

        // Draw the updated game board
        drawBoard(paddleX, ballX, ballY, score, lives);
        Sleep(10);
    }

    system("cls");

    // Display game over message and final score
    gotoxy(15, 8);
    cout << "Game Over!" << endl;

    gotoxy(15, 9);
    cout << "Final Score: " << score << endl;

    gotoxy(15, 10);
    cout << "Press any key to exit..." << endl;
    _getch();
}

// Function to display the result of the math quiz
void displayResult(int correctAns, int skipCount) {
    cout << "---------------------- Quiz Result ----------------------" << endl;
    cout << "You have answered " << correctAns << " correctly!" << endl;
    cout << "You have given " << (5 - correctAns - skipCount) << " wrong answers." << endl;
    cout << "You have skipped " << skipCount << " questions." << endl;
    cout << "----------------------------------------------------------" << endl;
}

// For easy level math quiz
void easyMath() {
    int ansCount = 0, correctAns = 0, skipCount = 0;
    char answer[5] = {'a', 'b', 'c', 'a', 'b'};
    string ques[5] = {
        "Q1) 40x40=___?\n a) 1600 \n b) 1400 \n c) 1200 \n d) 1000",
        "Q2) 999-33-87-100=___?\n a) 789 \n b) 779 \n c) 769 \n d) 759",
        "Q3) What is 22+47?\n a) 68 \n b) 69 \n c) 70 \n d) 71",
        "Q4) To stay in a hotel costs $40 per night. You stay for three nights and check out on the fourth morning. How much will you pay?\n a) $120 \n b) $140 \n c) $100 \n d) $160",
        "Q5) 120+240+400-240-400+1=___?\n a) 120 \n b) 121 \n c) 119 \n d) 118"};

    cout << "\n**************** Welcome To Easy level ****************" << endl;
    cout << ":::::: Instructions ::::::" << endl;
    cout << "Enter your answers by typing the option (a, b, c, or d).\nYou may skip questions by entering 0." << endl;

    for (int i = 0; i < 5; i++) {
               cout << ques[i] << endl;
        char userAnswer;
        cin >> userAnswer;
        if (userAnswer != '0') {
            ansCount++;
            if (userAnswer == answer[i]) {
                correctAns++;
                cout << "Correct Answer!" << endl;
            } else {
                cout << "Wrong Answer!" << endl;
                cout << "Correct Answer: " << answer[i] << endl;
            }
        } else {
            skipCount++;
            cout << "Correct Answer: " << answer[i] << endl;
        }
    }

    // Display the final quiz result
    displayResult(correctAns, skipCount);
}

// For medium level math quiz
void mediumMath() {
    int ansCount = 0, correctAns = 0, skipCount = 0;
    char answer[5] = {'a','b','c','a','b'};
    string ques[5] = {
        "Q1) What is 10% of 100?\n a) 10 \n b) 20 \n c) 30 \n d) 40",
        "Q2) If a train leaves a station at 10 p.m., travels at 30 miles per hour and covers 120 miles, what would the time(in a.m.) be?\n a) 2 \n b) 3 \n c) 4 \n d) 5",
        "Q3) What is 180/9?\n a) 18 \n b) 19 \n c) 20 \n d) 21",
        "Q4) Subtract 999 from 10. What do you have?\n a) 1009 \n b) 989 \n c) 979 \n d) 969",
        "Q5) If I have a liter bottle of cola and I drink 255 ml's, how much is left?\n a) 500 \n b) 600 \n c) 745 \n d) 800"};

    cout << "\n**************** Welcome To Level Medium ****************" << endl;
    cout << ":::::: Instructions ::::::" << endl;
    cout << "Enter your answers by typing the option (a, b, c, or d).\nYou may skip questions by entering 0." << endl;

    for (int i = 0; i < 5; i++) {
        cout << ques[i] << endl;
        char userAnswer;
        cin >> userAnswer;
        if (userAnswer != '0') {
            ansCount++;
            if (userAnswer == answer[i]) {
                correctAns++;
                cout << "Correct Answer!" << endl;
            } else {
                cout << "Wrong Answer!" << endl;
                cout << "Correct Answer: " << answer[i] << endl;
            }
        } else {
            skipCount++;
            cout << "Correct Answer: " << answer[i] << endl;
        }
    }

    // Display the final quiz result
    displayResult(correctAns, skipCount);
}

//For hard level math quiz
void hardMath() {
    int ansCount = 0, correctAns = 0, skipCount = 0;
    char answer[5] = {'c', 'b', 'c', 'a', 'b'};
    string ques[5] = {
        "Q1) How many right angles does a cube have?\n a) 12 \n b) 6 \n c) 24 \n d) 4",
        "Q2) 3,000-800+400-1200+600=___?\n a) 1000 \n b) 2000 \n c) 3000 \n d) 4000",
        "Q3) If a skipping rope is 2 meters long, how many 100-cm pieces could I cut it into?\n a) 10 \n b) 15 \n c) 20 \n d) 25",
        "Q4) Add the following, please: 90+33+0.01+100+241=___?\n a) 464.01 \n b) 534.01 \n c) 564.01 \n d) 594.01",
        "Q5) A man must take a pill every half an hour. He starts at 10 a.m. How many pills will he have taken by 12:01 p.m.?\n a) 50 \n b) 51 \n c) 52 \n d) 53"};

    cout << "\n**************** Welcome To Level Hard ****************" << endl;
    cout << ":::::: Instructions ::::::" << endl;
    cout << "Enter your answers by typing the option (a, b, c, or d).\nYou may skip questions by entering 0." << endl;

    for (int i = 0; i < 5; i++) {
        cout << ques[i] << endl;
        char userAnswer;
        cin >> userAnswer;
        if (userAnswer != '0') {
            ansCount++;
            if (userAnswer == answer[i]) {
                correctAns++;
                cout << "Correct Answer!" << endl;
            } else {
                cout << "Wrong Answer!" << endl;
                cout << "Correct Answer: " << answer[i] << endl;
            }
        } else {
            skipCount++;
            cout << "Correct Answer: " << answer[i] << endl;
        }
    }

    // Display the final quiz result
    displayResult(correctAns, skipCount);
}

// manage the math quiz game
void mathQuizGame() {
    system("cls");

    int level;
    char ch;
lvl:
    cout << "---------------------- Welcome To Math Quiz Game ----------------------" << endl;
    cout << "Choose your level of playing the game!!" << endl;
    cout << "1) Easy \n 2) Medium \n 3) Hard" << endl;
    cin >> level;

    switch (level) {
    case 1:
        cout << "---------------------- Easy Level Quiz ----------------------" << endl;
        easyMath();
        break;

    case 2:
        cout << "---------------------- Medium Level Quiz ----------------------" << endl;
        mediumMath();
        break;

    case 3:
        cout << "---------------------- Hard Level Quiz ----------------------" << endl;
        hardMath();
        break;

    default:
        cout << "You have entered an invalid input. Please choose again!!" << endl;
        goto lvl;
        break;
    }

    cout << "Do you want to play again?\nInput (Y) for Yes and (N) for No." << endl;
    cin >> ch;
    if (ch == 'y' || ch == 'Y') {
        goto lvl;
    } else {
        cout << "\n\n-----------!!Come later again to play!!-----------\n\n";
    }
}

int main() {
//	i used this to fit the game in console acyally it is a ensure that the game display fits well within the console window.
    system("mode con: lines=30 cols=60");

    char choice;
    do {
        system("cls");
        cout << "---------------------------------------------" << endl << endl;
        cout << "          WELCOME TO FUSION ARCADE            " << endl << endl;
        cout << "---------------------------------------------" << endl << endl;
        cout << "Project Made By : Areeb Ahmed ,Abdul Hadi , Abdul Wahab " << endl << endl;
        cout << "---------------------- Game Menu ----------------------" << endl;
        cout << "Choose a game to play:" << endl;
        cout << "1) Ball Blitz" << endl;
        cout << "2) Math Quiz" << endl;
        cout << "3) Quit" << endl;
        cin >> choice;

        switch (choice) {
        case '1':
            BallBlitz();
            break;
        case '2':
            mathQuizGame();
            break;
        case '3':
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }

        if (choice != '3') {
            cout << "Do you want to play Another Game ? (y/n): ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}


