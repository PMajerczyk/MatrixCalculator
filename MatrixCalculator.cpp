#include <iostream>
#include "Matrix.h"

using namespace std;

matrix mx1;
matrix mx2;

int main()
{
    while(true)
    {
        int select = mx1.select();
        if (select==1)
        {
            mx1.questions();
            std::cout << "Load the first matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            std::cout << "Number of rows: " << mx1.ROW << " (must be the same as in the first matrix)\n";
            std::cout << "Number of columns: " << mx1.COL << " (must be the same as in the first matrix)\n";
            mx2.ROW=mx1.ROW;
            mx2.COL=mx1.COL;
            std::cout << "Load the second matrix. Give " << mx2.ROW*mx2.COL << " values: ";
            mx2.download();
            std::cout << "Result:\n";
            int tabx[mx1.ROW][mx2.COL];
            for (int j=0; j < mx1.ROW; j++)
            {
                for (int i=0; i < mx1.COL; i++)
                {
                    tabx[j][i] = mx1.value_tab[j][i] + mx2.value_tab[j][i];
                    std::cout << tabx[j][i] << " ";
                }
                std::cout << "\n";
            }
            for (int i=0; i < mx1.ROW; i++)
                delete [] mx1.value_tab[i];
            delete [] mx1.value_tab;
            for (int i=0; i < mx2.ROW; i++)
                delete [] mx2.value_tab[i];
            delete [] mx2.value_tab;
        }
        else if(select==2)
        {
            mx1.questions();
            std::cout << "Load the matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            int scalar;
            std::cout << "Give scalar: ";
            std::cin >> scalar;
            while(std::cin.fail()==true)
            {
                std::cin.clear();
                std::cin.sync();
                std::cout << "Error! Invalid value. \n";
                std::cout << "Give scalar: ";
                std::cin >> scalar;
                if (std::cin.fail()==false) break;
            }
            std::cout << "Result:\n";
            for (int j=0; j < mx1.ROW; j++)
            {
                for (int i=0; i < mx1.COL; i++)
                {
                    mx1.value_tab[j][i] *= scalar;
                    std::cout << mx1.value_tab[j][i] << " ";
                }
                std::cout << "\n";
            }
            for (int i=0; i < mx1.ROW; i++)
                delete [] mx1.value_tab[i];
            delete [] mx1.value_tab;
        }
        else if(select==3)
        {
            mx1.questions();
            std::cout << "Load the first matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            std::cout << "Number of rows: " << mx1.COL << " (must be the same as the columns of the first matrix)\n";
            mx2.ROW=mx1.COL;
            std::cout << "Number of columns: ";
            std::cin >> mx2.COL;
            while(mx2.COL<=0 || mx2.COL>99 || isdigit(mx2.COL))
            {
                std::cin.clear();
                std::cin.sync();
                std::cout << "Error! Invalid value. Try again. \n";
                std::cout << "Number of columns: ";
                std::cin >> mx2.COL;
            }
            std::cout << "Load the second matrix. Give " << mx2.ROW*mx2.COL << " values: ";
            mx2.download();
            std::cout << "Result:\n";
            int tabx[mx1.ROW][mx2.COL];
            for(int i=0;i<mx1.ROW;i++)
                for(int j=0;j<mx2.COL;j++)
                    tabx[i][j]=0;
            for(int k=0;k<mx1.ROW;k++)
            {
                for(int i=0;i<mx2.COL;i++)
                {
                    for(int j=0;j<mx1.COL;j++)
                        tabx[k][i] += mx1.value_tab[k][j] * mx2.value_tab[j][i];
                    std::cout << tabx[k][i] << " ";
                }
                std::cout << "\n";
            }
            for (int i=0; i < mx1.ROW; i++)
                delete [] mx1.value_tab[i];
            delete [] mx1.value_tab;
            for (int i=0; i < mx2.ROW; i++)
                delete [] mx2.value_tab[i];
            delete [] mx2.value_tab;
        }
        std::cout << "\n\n";
    }
    return 0;
}
