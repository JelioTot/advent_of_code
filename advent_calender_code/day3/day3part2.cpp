#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>

int main()
{

    std::vector<char> bag;
    std::string myText;
    std::ifstream myFile ("rucksack.txt");
    int totalScore = 0;
    char value;
    char value2ndHalf;
    int adder = 0;
    bool checkSame[26*2][3] = {false};
    int count = 0;
     
    if (myFile.is_open())
    {
        while ( getline (myFile, myText) )
        {
            
            char *rucksack;
            rucksack = &myText[0];
            char check;
            int length_rucksack = myText.size();
            for (int i = 0; i < length_rucksack; i++){
                if (65 <= rucksack[i] && rucksack[i] <= 90){
                    value = rucksack[i] - 39;
                    check = rucksack[i];
                    checkSame[value][count] = true;
                    if (checkSame[value][0] && checkSame[value][1] && checkSame[value][2] == true){
                        adder = value + 1;
                        break;
                    }
                } else {
                    value = rucksack[i] - 97;
                    checkSame[value][count] = true;
                    check = rucksack[i];
                    if (checkSame[value][0] && checkSame[value][1] && checkSame[value][2] == true){
                        adder = value + 1;
                        break;
                    }
                }
                
            }
            count++;
            if (count == 3){
                for (int i = 0; i<26*2; i++){
                    for (int j = 0; j<3; j++){
                        checkSame[i][j] = false;
                    }   
                }
                count = 0;
                totalScore = totalScore + adder;
            }
            
        }
        myFile.close();
    }
    std::cout << totalScore << std::endl;
}