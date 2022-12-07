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
    char value1stHalf;
    char value2ndHalf;
    //const char* rucksack;
    int adder = 0;
     
    if (myFile.is_open())
    {
        while ( getline (myFile, myText) )
        {
            bool checkSame[26*2][2] = {false};
            char *rucksack;
            rucksack = &myText[0];
            char check;
            //rucksack = myText.c_str();
            int length_rucksack = (myText.size() / 2);
            for (int i = 0; i < length_rucksack; i++){
                if (65 <= rucksack[i] && rucksack[i] <= 90){
                    value1stHalf = rucksack[i] - 39;
                    check = rucksack[i];
                    checkSame[value1stHalf][0] = true;
                    if (checkSame[value1stHalf][0] && checkSame[value1stHalf][1] == true){
                        adder = value1stHalf + 1;
                        break;
                    }
                } else {
                    value1stHalf = rucksack[i] - 97;
                    checkSame[value1stHalf][0] = true;
                    check = rucksack[i];
                    if (checkSame[value1stHalf][0] && checkSame[value1stHalf][1] == true){
                        adder = value1stHalf + 1;
                        break;
                    }
                }
                if (65 <= rucksack[i+length_rucksack] && rucksack[i+length_rucksack] <= 90){
                    value2ndHalf = rucksack[i+length_rucksack] - 39;
                    checkSame[value2ndHalf][1] = true;
                    check = rucksack[i+length_rucksack];
                    if (checkSame[value2ndHalf][0] && checkSame[value2ndHalf][1] == true){
                        adder = value2ndHalf + 1;
                        break;
                    }
                } else {
                    value2ndHalf = rucksack[i+length_rucksack] - 97;
                    checkSame[value2ndHalf][1] = true;
                    check = rucksack[i+length_rucksack];
                    if (checkSame[value2ndHalf][0] && checkSame[value2ndHalf][1] == true){
                        adder = value2ndHalf + 1;
                        break;
                    }
                }
                //std::cout << length_rucksack << std::endl;
            }
            totalScore = totalScore + adder;
            // for (int i = 0; i<26*2; i++){
            //     std::cout << checkSame[i][0] << checkSame[i][1] << std::endl;
            // }
            //int sizesack = sizeof(rucksack);
            //std::cout << length_rucksack << std::endl;
        }
        myFile.close();
    }
    std::cout << totalScore << std::endl;
}
