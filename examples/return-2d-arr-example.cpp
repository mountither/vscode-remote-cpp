
#include <iostream>

using namespace std;



int** readFile(unsigned height, unsigned width)
{
    int** array2d = 0;
    array2d = new int*[height];

    for(int i =0; i < height; i++){

        array2d[i] = new int[width];

        for (int j = 0; j < width; j++){

            array2d[i][j]= i + width * j;

        }
    }
    return array2d;

}

int main(){

    
    int height = 2;
    int width = 2;

    int** myArr = readFile(height, width);

    for (int h = 0; h < height; h++)
      {
            for (int w = 0; w < width; w++)
            {
                  printf("%i,", myArr[h][w]);
            }
            printf("\n");
      }
      
    // important: clean up memory
    printf("\n");
    printf("Cleaning up memory...\n");
    for (int h = 0; h < height; h++)
    {
        delete [] myArr[h];
    }
    
    delete [] myArr;
    myArr = 0;

    return 0;
}