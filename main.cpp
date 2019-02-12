/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: michaelhu
 *
 * Created on February 12, 2019, 3:13 PM
 */


// this is the c preprocessor directive 
// which is loading files and objects 
// contains pre-made functions
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>   // resizable arrays
#include <sstream>  // manipulate strings
#include <limits>   

//using namespace std;
// using std::cout;

// global Vars
int g_iRandNum = 0;
const double PI = 3.14159;


/*
 * args : arguments count
 * argv : point to whole bunch of arguments value
 */
int main(int argc, char** argv) {
    
    
    std::string sMiles;
    double dMiles, dKilometers;
    std::cout << "Enter Miles : ";
    getline(std::cin, sMiles);
    dMiles = std::stod(sMiles);
    dKilometers = dMiles * 1.60934;
    printf("%.1f miles equals %.4f kilometers \n",dMiles, dKilometers);
    
    
//    -------------------------------------------------------
//    std::string sQuestion ("Enter Number 1: ");
//    std::string sNum1, sNum2;
//    std::cout << sQuestion;
//    getline(std::cin, sNum1);
//    std::cout << "Enter Number 2: ";
//    getline(std::cin, sNum2);
//    
//    int nNum1 = std::stoi(sNum1);
//    int nNum2 = std::stoi(sNum2);
//    
//    printf("%d + %d = %d \n", nNum1, nNum2, (nNum1 + nNum2));
//    printf("%d - %d = %d \n", nNum1, nNum2, (nNum1 - nNum2));
//    printf("%d * %d = %d \n", nNum1, nNum2, (nNum1 * nNum2));
//    printf("%d / %d = %d \n", nNum1, nNum2, (nNum1 / nNum2));
//    printf("%d %% %d = %d \n", nNum1, nNum2, (nNum1 % nNum2));
    
//    -------------------------------------------------------
    
//    double dbBigFloat = 1.11111111111111111111;
//    double dbBigFloat2 = 1.1111111111;
//    double dbDoubleSum = dbBigFloat + dbBigFloat2;
//    printf("dbDoubleSum Precision : %.20f\n", dbDoubleSum);
//    printf("%c %d %5d %.3f %s \n", 'A', 10, 5, 3.1234, "Hi");
    
//    -------------------------------------------------------

//    // this shows only 5 precision
//    float fBigFloat = 1.1111111111;
//    float fBigFloat2 = 1.1111111111;
//    float fFloatSum = fBigFloat + fBigFloat2;
//    printf("fFloatSum Precision : %.10f\n", fFloatSum);
    
    
//    -------------------------------------------------------

//    bool bMarried = true;
//    char chMyGrade = 'A';
//    unsigned short int u16Age = 43;
//    short int siWeight = 180;
//    int nDays = 7;
//    long lBigNum = 1100000;
//    float fPi = 3.15156;
//    double dbBigFloat = 1.1111111111111;
//    long double ldPi = 3.14156;
//    auto whatWIllBe = true;
//    
//    // command + shift + click = multi selections
//    std::cout << "Min bool" << std::numeric_limits<bool>::min() << std::endl;
//    std::cout << "Max bool" << std::numeric_limits<bool>::max() << std::endl;
//    
//    
//    std::cout << "Min unsigned short int " << std::numeric_limits<unsigned short int>::min() << std::endl;
//    std::cout << "Max unsigned short int " << std::numeric_limits<unsigned short int>::max() << std::endl;
//    
//    
//    std::cout << "Min short int " << std::numeric_limits<short int>::min() << std::endl;
//    std::cout << "Max short int " << std::numeric_limits<short int>::max() << std::endl;
//    
//    
//    std::cout << "Min int " << std::numeric_limits<int>::min() << std::endl;
//    std::cout << "Max int " << std::numeric_limits<int>::max() << std::endl;
//    
//    
//    std::cout << "Min long " << std::numeric_limits<long>::min() << std::endl;
//    std::cout << "Max long " << std::numeric_limits<long>::max() << std::endl;
//    
//    
//    std::cout << "Min float " << std::numeric_limits<float>::min() << std::endl;
//    std::cout << "Max float " << std::numeric_limits<float>::max() << std::endl;
//    
//    
//    std::cout << "Min long double " << std::numeric_limits<long double>::min() << std::endl;
//    std::cout << "Max long double " << std::numeric_limits<long double>::max() << std::endl;
//    
//    std::cout << "int size " << sizeof(int) << " bytes" << std::endl;
    
    
//    -------------------------------------------------------
    
//    // std represent your console on your screen
//    std::cout << "Hello world!" << std::endl;
//    
//    if(argc != 1){
//        std::cout << "You entered " << argc << "arguments \n" << std::endl;
//    }
//    
//    for(int i=0; i<argc; ++i){
//        std::cout << "No:" << i << " value is :" << argv[i] << " \n" << std::endl;
//    }
    
//    -------------------------------------------------------
    
    
    return 0;
}

