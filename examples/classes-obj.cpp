
#include <iostream>

using namespace std;


class Book {
    // is accessed publicly (blueprint)
    public:
        string title;
        string author;
        int pages;
    
        // constructor init. 
        Book(string Atitle, string Aauthor, int Apages){
            title = Atitle;
            author = Aauthor;
            pages = Apages;
        }

};

int main()
{

    // create an book obj 
    Book book01("harry potter", "Jk rowl", 500);
    // give attributes
    // book01.title = "harry potter";
    // book01.author = "jk rowl";
    // book01.pages = 500;

    cout << book01.title << endl;
    
    return 0;
}