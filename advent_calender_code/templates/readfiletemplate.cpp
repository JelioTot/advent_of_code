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
    std::ifstream myFile ("text.txt");
    int totalScore = 0;
     
    if (myFile.is_open())
    {
        while ( getline (myFile, myText) )
        {

        }
        myFile.close();
    }
    std::cout << totalScore << std::endl;
}