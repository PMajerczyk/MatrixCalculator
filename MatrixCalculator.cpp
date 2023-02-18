#include <iostream>
#include "Matrix.h"

using namespace std;

matrix mx1;
matrix mx2;

int det(int **A,int ROW,int COL)
{
    int result=0, x=1;
    if(ROW == 1)
        result = A[0][0];
    else if(ROW == 2)
        result = A[0][0]*A[1][1] - A[0][1]*A[1][0];
    else{
        for(int i=0; i<COL; i++){
            for(int j=0; j<ROW; j++){
                int k=j+i;
                while(k >= COL)
                    k-=COL;
                x*= A[j][k];
            }
            result += x;
            x=1;
        }
        for(int i=COL-1; i>=0; i--){
            for(int j=0; j<ROW; j++){
                int k=i-j;
                while(k < 0)
                    k+=COL;
                x *= A[j][k];
            }
            result -= x;
            x=1;
        }
    }
    return result;
}

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
            for (int j=0; j < mx1.ROW; j++){
                for (int i=0; i < mx1.COL; i++){
                    tabx[j][i] = mx1.value_tab[j][i] + mx2.value_tab[j][i];
                    std::cout << tabx[j][i] << " ";
                }
                std::cout << "\n";
            }
            mx1.delete_tab();
            mx2.delete_tab();
        }
        else if(select==2)
        {
            mx1.questions();
            std::cout << "Load the matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            int scalar;
            std::cout << "Give scalar: ";
            std::cin >> scalar;
            while(std::cin.fail()==true){
                std::cin.clear();
                std::cin.sync();
                std::cout << "Error! Invalid value. \n";
                std::cout << "Give scalar: ";
                std::cin >> scalar;
            }
            std::cout << "Result:\n";
            for (int j=0; j < mx1.ROW; j++){
                for (int i=0; i < mx1.COL; i++){
                    mx1.value_tab[j][i] *= scalar;
                    std::cout << mx1.value_tab[j][i] << " ";
                }
                std::cout << "\n";
            }
            mx1.delete_tab();
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
            while(mx2.COL<=0 || mx2.COL>99 || isdigit(mx2.COL)){
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
            for(int k=0;k<mx1.ROW;k++){
                for(int i=0;i<mx2.COL;i++){
                    for(int j=0;j<mx1.COL;j++)
                        tabx[k][i] += mx1.value_tab[k][j] * mx2.value_tab[j][i];
                    std::cout << tabx[k][i] << " ";
                }
                std::cout << "\n";
            }
            mx1.delete_tab();
            mx2.delete_tab();
        }
        else if(select==4)
        {
            std::cout << "(The determinant is only calculated from the square matrix, max size: 3x3)\n";
            std::cout << "Number of rows and columns: ";
            std::cin >> mx1.COL;
            while(mx1.COL<=0 || mx1.COL>3 || isdigit(mx1.COL)){
                std::cin.clear();
                std::cin.sync();
                std::cout << "Error! Invalid value. Try again. (max size: 3x3) \n";
                std::cout << "Number of rows and columns: ";
                std::cin >> mx1.COL;
            }
            mx1.ROW = mx1.COL;
            std::cout << "Load the matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            std::cout << "Result:\n";
            int value = det(mx1.value_tab, mx1.ROW, mx1.COL);
            std::cout << "det = " << value;
            mx1.delete_tab();
        }
        else if(select==5)
        {
            mx1.questions();
            std::cout << "Load the matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            std::cout << "Result:\n";
            int tabx[mx1.COL][mx1.ROW];
            for(int i=0;i<mx1.COL;i++){
                for(int j=0;j<mx1.ROW;j++){
                    tabx[i][j]=mx1.value_tab[j][i];
                    std::cout << tabx[i][j] << " ";
                }
                std::cout << "\n";
            }
            mx1.delete_tab();
        }
        else if(select==6)
        {
            std::cout << "(The inverse matrix is only calculated from the square matrix, max size: 3x3)\n";
            std::cout << "Number of rows and columns: ";
            std::cin >> mx1.COL;
            while(mx1.COL<=0 || mx1.COL>3 || isdigit(mx1.COL)){
                std::cin.clear();
                std::cin.sync();
                std::cout << "Error! Invalid value. Try again. (max size: 3x3) \n";
                std::cout << "Number of rows and columns: ";
                std::cin >> mx1.COL;
            }
            mx1.ROW = mx1.COL;
            std::cout << "Load the matrix in rows. Give " << mx1.ROW*mx1.COL << " values separated by commas. (total values only): ";
            mx1.download();
            float value = det(mx1.value_tab, mx1.ROW, mx1.COL);
            std::cout << "Result:\n";
            if(value==0)
                std::cout << "Inverse matrix doesn't exist";
            else if(mx1.ROW == 1)
                std::cout << 1/value;
            else
            {
                int tabx[mx1.ROW][mx1.COL];
                mx2.value_tab = new int * [mx1.ROW-1];
                for (int i = 0; i < mx1.ROW-1; i++)
                    mx2.value_tab[i] = new int[mx1.COL-1];
                for(int i=0,n=0; i<mx1.ROW; i++)
                    for(int j=0; j<mx1.COL; j++){
                        for(int k=0,m=0; k<mx1.ROW; k++)
                            for(int l=0; l<mx1.COL; l++)
                                if(k!=i && l!=j)
                                {
                                    mx2.value_tab[m][n]=mx1.value_tab[k][l];
                                    n++;
                                    if(n==mx1.COL-1)
                                    {
                                        n=0;
                                        m++;
                                    }
                                }
                        tabx[i][j] = det(mx2.value_tab, mx1.ROW-1, mx1.COL-1);
                        if((i+j)%2==1)
                            tabx[i][j] *= -1;
                    }
                mx2.delete_tab();
                for(int i=0;i<mx1.COL;i++)
                    for(int j=0;j<mx1.ROW;j++)
                        mx1.value_tab[i][j]=tabx[j][i];
                float tab[mx1.ROW][mx1.COL];
                for (int j=0; j < mx1.ROW; j++){
                    for (int i=0; i < mx1.COL; i++){
                        tab[j][i] = 1/value*mx1.value_tab[j][i];
                        cout.precision(3);
                        cout.width(6);
                        std::cout << tab[j][i] << " ";
                    }
                    std::cout << "\n";
                }
            }
            mx1.delete_tab();
        }
        std::cout << "\n\n";
    }
    return 0;
}
