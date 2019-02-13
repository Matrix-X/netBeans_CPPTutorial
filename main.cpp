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
#include <numeric>

//using namespace std;
// using std::cout;

// global Vars
int g_iRandNum = 0;
const double PI = 3.14159;

double AddNumbers(double num1, double num2);
void AssignAge(int age);
int AssignAge2();
void AssignAge3(int* pAge);
void DoubleArray(int* arr, int size);
std::vector<int> Range(int start, int max, int step);

// cannot edit in read only editor
// code-runner.runInTerminal to true from your File -> Preferences -> Settings

/*
 * args : arguments count
 * argv : point to whole bunch of arguments value
 */
int main(int argc, char** argv) {

    


//    -------------------------------------------------------

    // std::vector<int> myVec2(10);
    // std::iota(std::begin(myVec2), std::end(myVec2), 1);

    // for(auto y:myVec2) {
    //     if(y%2==0){
    //         std::cout << y << std::endl;
    //     }    
    // }

//    -------------------------------------------------------

    // std::vector<int> myVec(10);
    // std::iota(std::begin(myVec), std::end(myVec), 0);

    // for(int i=0; i < myVec.size(); ++i){
    //     std::cout << myVec[i] << "\n";
    // }

    // for(auto y:myVec) std::cout << y << std::endl;

    // int val = 8;
    // if((val % 2) == 0){
    //     std::cout << val << " is even\n";
    // }else{
    //     std::cout << val << " is odd\n";
    // }



//    -------------------------------------------------------

    // double dbNum1 = 0, dbNum2 = 0;
    // std::string sCalc = "";
    // std::vector<std::string> vectCalc;
    
    // std::cout << "Enter calculation (ex. 5 + 6) : ";
    // getline(std::cin, sCalc);
    // std::stringstream ss(sCalc);
    // std::string sIndivStr;
    // char cSpace = ' ';

    // while(getline(ss, sIndivStr, cSpace)){
    //     vectCalc.push_back(sIndivStr);
    // }

    // dbNum1 = std::stoi(vectCalc[0]);
    // dbNum2 = std::stoi(vectCalc[2]);

    // std::string operation = vectCalc[1];

    // if(operation == "+"){
    //     printf("%.1f + %.1f = %.1f \n", dbNum1, dbNum2, dbNum1+dbNum2);
    // }else if(operation == "-"){
    //     printf("%.1f - %.1f = %.1f \n", dbNum1, dbNum2, dbNum1-dbNum2);
    // }else if(operation == "*"){
    //     printf("%.1f * %.1f = %.1f \n", dbNum1, dbNum2, dbNum1*dbNum2);
    // }else if(operation == "/"){
    //     printf("%.1f / %.1f = %.1f \n", dbNum1, dbNum2, dbNum1/dbNum2);
    // }else{
    //     std::cout << "Please enter only +. -, *, /\n";
    // }

//    -------------------------------------------------------


    // std::string sSentence = "this is a random string";
    // std::vector<std::string> vectWords;
    // std::stringstream ss(sSentence);

    // std::string sIndivStr;
    // char cSpace = ' ';

    // while(getline(ss, sIndivStr, cSpace)){
    //     vectWords.push_back(sIndivStr);
    // }

    // for(int i=0; i< vectWords.size(); ++i){
    //     std::cout << vectWords[i] << std::endl;

    // }


//    -------------------------------------------------------

    // std::vector<int> vectRandNums(2);
    // vectRandNums[0] = 10;
    // vectRandNums[1] = 20;
    // vectRandNums.push_back(30);
    
    // std::cout   << "last Index at "<< vectRandNums.size()-1 
    //             << ":  " 
    //             << vectRandNums[vectRandNums.size()-1] 
    //             << std::endl;


//    -------------------------------------------------------
    
    // int arrayNums[10] = {1};
    // int arrayNums2[] = {1,2,3};

    // int arrayNums3[5] = {8,9};

    // // std::cout << "1st Value : " << arrayNums[0] << std::endl;
    // std::cout << "1st Value : " << arrayNums3[0] << std::endl;
    // arrayNums3[0] = 7;
    // std::cout << "1st Value : " << arrayNums3[0] << std::endl;
    // std::cout << "Array size : " << sizeof(arrayNums3)/ sizeof(*arrayNums3) << std::endl;

    // int arrayNums4[2][2][2] = {{{1,2}, {3,4}}, {{5,6}, {7,8}}};
    // std::cout << arrayNums4[1][1][1] << std::endl;

//    -------------------------------------------------------

    // std::string sMiles;
    // double dMiles, dKilometers;
    // std::cout << "Enter Miles : ";
    // getline(std::cin, sMiles);
    // dMiles = std::stod(sMiles);
    // dKilometers = dMiles * 1.60934;
    // printf("%.1f miles equals %.4f kilometers \n",dMiles, dKilometers);
    
    
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
    



    // double num1, num2;
    // std::cout << "Enter Num 1 : ";
    // std::cin >> num1;
    // std::cout << "Enter Num 2 : ";
    // std::cin >> num2;

    // printf("%.1f + %.1f = %.1f \n", num1, num2, AddNumbers(num1, num2));

//    -------------------------------------------------------    
    // int age = 43;
    // AssignAge(age);
    // std::cout << "new age " << age << std::endl;

    // age = AssignAge2();
    // std::cout << "returned age " << age << std::endl;
    
 //    -------------------------------------------------------    

    // int age = 43;
    // int* pAge = NULL;

    // pAge = &age;

    // std::cout << "Address : " << pAge << std::endl;
    // std::cout << "Value at Address : " << *pAge << std::endl;

    // int intArray[] = {1,2,3,4};
    // int* pIntArray = intArray;

    // std::cout << "1st " << *pIntArray << "Address " << pIntArray << std::endl;
    // pIntArray++;

    // std::cout << "2nd " << *pIntArray << "Address " << pIntArray << std::endl;
    // pIntArray--;

    // std::cout << "1st " << *pIntArray << "Address " << pIntArray << std::endl;

//    -------------------------------------------------------    
    // int age = 43;
    // AssignAge3(&age);
    // std::cout << "Pointer Age "  << age << std::endl;

//    -------------------------------------------------------    
    // int arrayInt[] = {1,2,3,4};
    // DoubleArray(arrayInt, 4);
    // for(int i=0; i<4; i++){
    //     std::cout << "Array " << arrayInt[i] << std::endl;
    // }

//    -------------------------------------------------------    

    // std::vector<int> range = Range(1, 10, 2);
    // for(auto y: range) {
    //     std::cout << y << std::endl;
    // }

//    -------------------------------------------------------    

    // double investment = 0.0, interestRate = 0.0;
    // std::cout << "How much to invest : ";
    // std::cin >> investment;

    // std::cout << "Interest Rate: ";
    // std::cin >> interestRate;

    // interestRate *= .01;
    // for(auto y: Range(1, 10, 1)){
    //     investment += (investment * interestRate);
    // }
    // std::cout << "Value after 10 years : " << investment << "\n";


//    -------------------------------------------------------    



//    -------------------------------------------------------    
    return 0;
}



// FUNCTIONS



double AddNumbers(double num1,  double num2){
    return num1 + num2;
}


void AssignName(){
    std::string name = "Derek";
}


void AssignAge(int age){
    age = 24;
}

int AssignAge2(){
    int age = 24;
    return age;
}

void AssignAge3(int* pAge){
    
    *pAge = 22;

}

void DoubleArray(int* arr, int size){
    for(int i=0; i< size; i++){
        arr[i] = arr[i]*2;
    }
}

std::vector<int> Range(int start, int max, int step){
    int i = start;


    std::vector<int> range;

    while(i<max){
        range.push_back(i);
        i += step;
    }
    return range;
}


// END FUNCTIONS
