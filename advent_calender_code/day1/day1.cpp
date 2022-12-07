#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// has both parts day 1 

int main()
{
    int top3[3] = {0,0,0};
    int largest = 0;
    int currentElf = 0;
    int num = 0;
    std::string myText;
    std::ifstream myFile ("numbers.txt");
     
    if (myFile.is_open())
    {
        while (getline (myFile, myText))
        {
            std::stringstream ss;
            ss << myText;
            ss >> num;
            if (myText == ""){
                for (int i=0; i<3; i++){
                    if (top3[i] < currentElf) {
                        top3[i] = currentElf;
                        std::sort(top3,top3+3);
                        break;
                    }
                }
                currentElf = 0;
                num = 0;
            } else{
                currentElf = currentElf + num;
            }
            
        }
    myFile.close();
  }

    int sum = 0;    
    for (int i=0; i<3; i++) {
        sum = sum + top3[i];
  }
    
    std::cout << sum << std::endl;
}