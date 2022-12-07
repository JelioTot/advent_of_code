#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <math.h>

void NumFinder(char *pairs, int symbol_locations[], int nums[], int j) {
    int loc = symbol_locations[j];
    int start = 0;
    if (j-1>=0) {
        start = symbol_locations[j-1] + 1;
    }
    //int start = symbol_locations[-1] + 1;
    for (int i=start; i<loc; i++) {
        int intpairs = pairs[i] - '0';
        nums[j] = nums[j] + intpairs*pow(10, (loc-i-1));
        int hel = nums[j];
    }

}

int main()
{
    std::string myText;
    std::ifstream myFile ("day4_data.txt");
    int totalScore = 0;
    char dash = '-';
    char comma = ',';
     
    if (myFile.is_open())
    {
        while ( getline (myFile, myText) )
        {
            int nums[4] = {0};
            int symbol_locations[4] = {0};
            char *pairs;
            pairs = &myText[0];
            int count = 0;
            std::cout << pairs << std::endl;
            for (int i=0; i<myText.length(); i++) {
                if (pairs[i] == '-') {
                    symbol_locations[count] = i;
                    count++;
                }
                if (pairs[i] == ',') {
                    symbol_locations[count] = i;
                    count++;
                }
            }
            symbol_locations[3] = myText.length();
            for (int j=0; j<=3; j++){
                NumFinder(pairs, symbol_locations, nums, j);
            }

            if (nums[0] >= nums[2] & nums[0] <= nums[3]) {
                totalScore++;
            } else if (nums[1] >= nums[2] & nums[1] <= nums[3]) {
                totalScore++;
            } else if (nums[2] >= nums[0] & nums[2] <= nums[1]) {
                totalScore++;
            } else if (nums[3] >= nums[0] & nums[3] <= nums[1]) {
                totalScore++;
            } 
            //pairs[i];
        }
        myFile.close();
    }
    std::cout << totalScore << std::endl;
}