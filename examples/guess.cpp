
#include <iostream>


using namespace std;


int main()
{

    int secretNum = 7;
    int guess;
    int guessCnt = 0;
    int guessLmt = 2;
    bool limit = false;



    while(secretNum != guess && !limit){
        
        if(guessCnt < guessLmt){
            cout<< "Guess: " << endl;
            cin >> guess;
            
            guessCnt++;
        }
        else{
            limit = true;
        }
        

    }


    // do{

    //     cout << "Guess:" << endl;
    //     cin >> guess;
    //     guessCnt++;
    // }while(secretNum != guess);

    if(!limit){
        cout << "YOU win!!! + your guess count is: "<< endl;
        cout << guessCnt << endl;
    }
    else{
        cout << "out of guesses"<< endl;

    }
    
    return 0;
}