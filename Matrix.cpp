#include <iostream>
#include "Matrix.h"
#include <string>

using namespace std;

int matrix::select()
{
    std::cout << "Select matrix operation:\n";
    std::cout << "1 - addition of two matrices,\n";
    std::cout << "2 - multiplication by a scalar,\n";
    std::cout << "3 - multiplication of two matrices,\n";
    std::cout << "Enter number: ";
    std::cin >> nr;
    while(nr!=1 && nr!=2 && nr!=3){
        std::cin.clear();
        std::cin.sync();
        std::cout << "Error! Invalid value. Try again. \n";
        std::cout << "Enter number: ";
        std::cin >> nr;
    }
    return nr;
}

void matrix::questions()
{
    std::cout << "Number of rows: ";
    std::cin >> ROW;
    while(ROW<=0 || ROW>99 || isdigit(ROW))
    {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Error! Invalid value. Try again. \n";
        std::cout << "Number of rows: ";
        std::cin >> ROW;
    }
    std::cout << "Number of columns: ";
    std::cin >> COL;
    while(COL<=0 || COL>99 || isdigit(COL))
    {
        std::cin.clear();
        std::cin.sync();
        std::cout << "Error! Invalid value. Try again. \n";
        std::cout << "Number of columns: ";
        std::cin >> COL;
    }
}

void matrix::download()
{
    std::cin >> mx;
    value_tab = new int * [ROW];
    for (int i = 0; i < ROW; i++)
        value_tab[i] = new int[COL];
    std::string val;
    int value[ROW*COL];
    do{
        int j=0;
        val.clear();
        for(int i=0; mx[i] != '\0'; i++)
        {
            if(mx[i] != '-'&&mx[i] != ','&&!isdigit(mx[i]))
            {
                std::cout << "Error! Invalid value. \n";
                val = "error";
                break;
            }
            if(mx[i] != ',')
                val += mx[i];
            if(mx[i] == ',' || mx[i+1] == '\0')
            {
                value[j] = std::stoi(val);
                val.clear();
                j++;
            }
            if(j==ROW*COL && mx[i+1]!='\0')
            {
                std::cout << "Error! Too many values. \n";
                val = "error";
                break;
            }
        }
        if (j < ROW*COL && val!="error")
        {
            std::cout << "Error! Not enough values. \n";
            val = "error";
        }
        if(val == "error")
        {
            std::cout << "Load the matrix again: ";
            std::cin >> mx;
        }
    } while(val == "error");
        for (int k=0, j=0; j < ROW; j++)
        {
            for (int i=0; i < COL; i++)
            {
                value_tab[j][i] = value[k];
                std::cout << value_tab[j][i] << " ";
                k++;
            }
            std::cout << "\n";
        }
}
