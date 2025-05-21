#include <iostream>
#include <cmath>


int PlayerWins = 0;
int ComputerWins =0;

char computechoice(){

    
srand(time(NULL));
int compnum = rand () %3+1;

if (compnum == 1){
    return 'r';
}
if (compnum == 2)
{
    return 'p';
}
if (compnum == 3)
{
    return 's';
}
return 'x';
}


void computeWinner(char choice, char compchoice)
{
    std:: cout << "Player : " << choice << " Computer : " << compchoice << "\n"; 
    if (choice == 'r')
    {
        if (compchoice == 'p')
        {
            std:: cout << "Computer wins";
            ComputerWins += 1;
   
        }

        if (compchoice == 's')
        {
            std :: cout << "Player wins";
            PlayerWins +=1;
           
        }

        else {
            std :: cout << "Ties";
            
        }
    }

    else if (choice == 's')
    {
        if (compchoice == 'p')
        {
            std:: cout << "Player wins";
            PlayerWins += 1;
           
        }

        if (compchoice == 's')
        {
            std :: cout << "Ties";
           
        }

        if (compchoice == 'r')
        {
            std :: cout << "Computer wins";

            ComputerWins += 1;
          
        }

    }

    else if (choice == 'p')
    {
        if (compchoice == 'p')
        {
            std:: cout << "Ties";
            
            
        }

        if (compchoice == 's')
        {
            std :: cout << "Computer Wins";
            ComputerWins +=1 ;
            
        }

        if (compchoice == 'r')
        {
            std :: cout << "Player wins";

            PlayerWins += 1;
           
        }

    }



}


int main()
{


  
    char choice ;
    char compchoice;

    while(true)
    {

        std:: cout << "\nEnter the choice : r - rock, p -paper , s- scissors , x - exit and t = scores  :: ";
        std :: cin >> choice;

        switch (choice)
        {
        case 'r':
        {
            compchoice =computechoice();
            computeWinner(choice, compchoice);

            break;
        }

        case 's':
        {
            compchoice =computechoice();
            computeWinner(choice, compchoice);

            break;
        }

        case 'p':
        {
            compchoice =computechoice();
            computeWinner(choice, compchoice);

            break;
        }

        case 'x':
        {
            std:: cout << "System is quiting";
            return false;
        }

        case 't':
        {
            std:: cout << "SCORE :: Player : " << PlayerWins <<" | Computer : " <<ComputerWins;
            break;
        }


        default:
        std :: cout << "Enter the valid input";
            break;
        }
    }
    
}
