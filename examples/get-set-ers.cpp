
#include <iostream>


using namespace std;

// constrict the rating inputs. 
class Movie
{
    private:
    string rating;
    public:
        string title;
        string director;
        Movie(string aTitle, string aDirector, string aRating){
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        };

        void setRating(string aRating)
        {
            if(aRating == "PG" || aRating== "M-15"){

                rating = aRating;
            }
            else {
                rating = "nr";
            }
        }
        string getRating (){
            return rating;
        }
};


int main()
{

    Movie primer("Primer", "Shane Carruth", "");
    // primer.setRating("PG");
    cout << primer.getRating() << endl;

    return 0;
}