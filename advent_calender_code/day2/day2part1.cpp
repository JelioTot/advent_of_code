#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

int main()
{

    std::string myText;
    std::ifstream myFile ("rockpapersissors.txt");
    char played[3];
    int totalScore = 0;
    int grid[3][3] = {{3, 6, 0}, {0, 3, 6}, {6, 0, 3}};
     
    if (myFile.is_open())
  {
    while ( getline (myFile, myText) )
    {
        int adder = 0;
        int x, y;
        const char* played = myText.c_str();
        for(int i = 0; i < 3; i++) {
            switch (played[i]){
                case 'A':
                    x = 0;
                    break;
                case 'B':
                    x = 1;
                    break;
                case 'C':
                    x = 2;
                    break;
                case 'X':
                    y = 0;
                    break;
                case 'Y':
                    y = 1;
                    break;
                case 'Z':
                    y = 2;
                    break;
                default:
                    break;
            }
        }
        adder = grid[x][y] + (y+1);
        totalScore = totalScore + adder;
    }
    myFile.close();
  }
  std::cout << totalScore << std::endl;
    
}

