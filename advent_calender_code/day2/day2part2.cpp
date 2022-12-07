#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

int grid[3][3] = {{3, 6, 0}, {0, 3, 6}, {6, 0, 3}};

int find_score(int score, int place){
    for (int i = 0; i<3; i++){
        if (grid[place][i] == score){
            return i+1;
            break;
        }
    }

}

int main()
{

    std::string myText;
    std::ifstream myFile ("rockpapersissors.txt");
    int totalScore = 0;
    int x = 0;
    int y = 3;
    int z = 6;
    int p, q;
    int item;
     
    if (myFile.is_open())
    {
        while ( getline (myFile, myText) )
        {
            int adder = 0;
            const char* played = myText.c_str();
            for(int i = 0; i < 3; i++) {
                switch (played[i]){
                    case 'A':
                        p = 0;
                        break;
                    case 'B':
                        p = 1;
                        break;
                    case 'C':
                        p = 2;
                        break;
                    case 'X':
                        item = find_score(x, p);
                        adder = item + x;
                        break;
                    case 'Y':
                       item = find_score(y, p);
                       adder = item + y;
                        break;
                    case 'Z':
                        item = find_score(z, p);
                        adder = item + z;
                        break;
                    default:
                        break;

                }

            }
            totalScore = totalScore + adder;
        }
        myFile.close();
    }
    std::cout << totalScore << std::endl;
}
