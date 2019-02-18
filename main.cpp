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
#include <ctime>

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
std::vector<std::string> StringToVector(std::string theString, char separator);
std::string VectorToString(std::vector<std::string> & vect, char separator);

std::string CaesarCipher(std::string theString, int key, bool encrypt);

bool IsPrime(int num);
std::vector<int> GetPrimes(int maxNum);

void SolveForX(std::string equation);

std::vector<int> GenerateRandVect(int numOfNums, int min, int max);


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

    // int i = 1;
    // while(i <= 20){
    //     if((i%2)==0){
    //         i += 1;
    //         continue;
    //     }

    //     if(i==15){
    //         break;
    //     }
    //     std::cout << i << "\n";

        
    //     i +=1;
    // }

//    -------------------------------------------------------    

    // int treeHeight = 0, spaces = 0, hashes = 1, stumpSpaces = 0;
    // std::cout << "How tall is the tree: ";
    // std::cin >> treeHeight;

    // spaces = treeHeight - 1;
    // stumpSpaces = treeHeight - 1;

    // while(treeHeight!=0){
    //     for(auto x: Range(1, spaces, 1))
    //         std::cout << " ";
        
    //     for(auto x: Range(1, hashes, 1))
    //         std::cout << "#";
        
    //     std::cout << "\n";
        
    //     spaces-=1;
    //     hashes+=2;
    //     treeHeight--;
    // }
    // for(auto x: Range(1, stumpSpaces, 1))
    //         std::cout << " ";
    // std::cout << "#" << std::endl;

//    -------------------------------------------------------    

    // double num1 = 0, num2 = 0;
    // std::cout << "Enter number 1: ";
    // std::cin >> num1;
    // std::cout << "Enter number 2: ";
    // std::cin >> num2;

    // try{
    //     if(num2 == 0){
    //         throw "Division by zero is not possible";
    //     }else{
    //         printf("%.1f / %.1f = %.2f", num1, num2, (num1 / num2));
    //     }
    // }
    // catch(const char* exp){
    //     std::cout << "Error : " << exp << "\n";
    // }
    

//    -------------------------------------------------------   
    // try{
    //     std::cout << "Throwing exception \n";
    //     throw std::runtime_error("error occurred");
    //     std::cout << "Can you print me? \n";
    // }
    // catch(std::exception &exp){
    //     std::cout << "Handle Exception : " << exp.what() << std::endl;
    // }
    // catch(...){
    //     std::cout << "Default Exception\n";
    // }


//    -------------------------------------------------------   
// srand(time(NULL));
// int secreteNum = std::rand() % 11;
// int guess = 0;

// do{
//     std::cout << "Guess the number : ";
//     std::cin >> guess;
//     if(guess > secreteNum) std::cout << "To Big\n";
//     if(guess < secreteNum) std::cout << "To Small\n";
// }while(secreteNum != guess);

// std::cout << "you guessed it \n ";


//    ------------------------------------------------------- 
// char cSting[] = {'A', ' ', 'S', 't', 'r', 'i', 'n', 'g', '\0'};

// std::cout << "Array String: " << cSting << std::endl;
// std::cout << "Array Size: " << sizeof(cSting) << std::endl;

    // std::vector<std::string> strVect(10);
    // std::string str("I'm a string");
    // strVect[0] = str;

    // std::cout << str[0] << str.at(0) << str.front() << str.back() << std::endl;
    // std::cout << str.length() << std::endl;
    // std::string str2(str);
    // strVect[1] = str2;
    // std::string str3(str, 4);
    // strVect[2] = str3;
    // std::string str4(5, 'x');
    // strVect[3] = str4;
    // strVect[4] = str.append(" and your not");
    // str += " and your not";
    // str.append(str, 34, 37);
    // strVect[5] = str;
    // str.erase(13, str.length()-1);
    // strVect[6] = str;

    // std::cout << &str << ": " << str << "\n" << std::endl;

    // if(str.find("string") != std::string::npos){
    //     std::cout << "1st index " << str.find("string") << std::endl;
    // }
    // std::cout << "Substr " << str.substr(6,6) << std::endl;

    // for(int i=0; i<10; i++)
    //     std::cout << &strVect[i] << ": " << strVect[i] << std::endl;
    // std::cout << "\n";
    // for(auto y: strVect){
    //     std::cout << &y << ": " << y << std::endl;
        
    // }

    // reverse(str.begin(), str.end());
    // std::cout << "Reverse " << str << "\n";
    // transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    // std::cout << "Upper " << str2 << "\n";
    // transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    // std::cout << "Lower " << str2 << "\n";

//    -------------------------------------------------------   

    // // a - z : 97 - 122
    // // A - Z : 65 - 90
    // std::string normalStr, secretStr = "";
    // std::cout << "Enter your string in uppercase : ";
    // std::cin >> normalStr;

    // for(char c: normalStr){
    //     secretStr += std::to_string( (int)c - 23 );
    // }

    // std::cout << "Secret: " << secretStr << std::endl;

    // normalStr  = "";
    // for(int i = 0; i < secretStr.length(); i+=2){
    //     std::string sCharCode = "";
    //     sCharCode += secretStr[i];
    //     sCharCode += secretStr[i+1];
        
    //     int nCharCode = std::stoi(sCharCode);
    //     char chCharCode = nCharCode + 23;
    //     normalStr += chCharCode;
    // }
    // std::cout << "Original: " << normalStr << std::endl;



//    -------------------------------------------------------   

    // std::vector<std::string> vec = StringToVector("This is a random string", ' ');
    // for(int i =0 ;i < vec.size(); i++){
    //     std::cout << vec[i] << std::endl;
    // }

    // std::vector<std::string> vCusts(3);
    // vCusts[0] = "Bob";
    // vCusts[1] = "Sue";
    // vCusts[2] = "Tom";

    // std::string sCusts = VectorToString(vCusts, ' ');
    // std::cout << sCusts << std::endl;


//    -------------------------------------------------------   

    // std::string theString = "Make me secret";
    // std::string encryptedStr = CaesarCipher(theString, 5, true);
    // std::string decryptedString = CaesarCipher(encryptedStr, 5, false);
    // std::cout << "Encrypted " << encryptedStr << std::endl;
    // std::cout << "Decrypted " << decryptedString << std::endl;

//    -------------------------------------------------------   
    // std::cout << "Enter an equation to solve ";
    // std::string equation = "";
    // getline(std::cin, equation);
    // SolveForX(equation);

//    -------------------------------------------------------   

    // int num = 0;
    // std::cout << "Number to Check : ";
    // std::cin >> num;

    // std::cout.setf(std::ios::boolalpha);
    // std::cout << "Is " << num << " Prime " << IsPrime(num) << std::endl;
    // std::cout << "Generate Primes up to ";
    // int maxPrime;
    // std::cin >> maxPrime;
    // std::vector<int> primeList = GetPrimes(maxPrime);
    // for(auto x: primeList)
    //     std::cout << x << "\n";

    
    std::vector<int> vecVals = GenerateRandVect(10, 5, 50);
    for(auto x: vecVals){
        std::cout << x << "\n";
    }



//    -------------------------------------------------------   

//    -------------------------------------------------------   

//    -------------------------------------------------------   

//    -------------------------------------------------------   

//    -------------------------------------------------------   

//    -------------------------------------------------------   


    return 0;
}



// FUNCTIONS


std::vector<int> GenerateRandVect(int numOfNums, int min, int max){
    std::vector<int> vecValues;
    srand(time(NULL));

    int i = 0, randVal =0;
    while(i<numOfNums){
        randVal = min + std::rand() %  ((max + 1) - min);
        vecValues.push_back(randVal);
        
        i++;
    }

    return vecValues;

}

bool IsPrime(int num){
    for(auto n:Range(2, num-1, 1)){
        if(num%n==0){
            return false;
        }
    }

    return true;
}

std::vector<int> GetPrimes(int maxNum){
    std::vector<int> vectPrimes;
    for(auto x: Range(2, maxNum, 1)){
        if(IsPrime(x)){
            vectPrimes.push_back(x);
        }
    }
    return vectPrimes;
}


void SolveForX(std::string equation){
    std::vector<std::string> vectEquation = StringToVector(equation, ' ');
    int num1 = std::stoi(vectEquation[2]);
    int num2 = std::stoi(vectEquation[4]);
    int xVal = num2 - num1;
    std::cout << "x = " << xVal << "\n";
}

std::string CaesarCipher(std::string theString, int key, bool encrypt)
{
    std::string returnString = "";

    int charCode = 0;

    char letter;
    if(encrypt){
        key = key * -1;
    }

    
    for(char& c: theString){
        
        if(isalpha(c)){
            // std::cout << "input " << c << std::endl;
            charCode = (int)c;
            charCode += key;

            if(isupper(c)){
                
                if(charCode > (int)'Z'){
                    charCode -= 26;
                }else if(charCode < (int)'A'){
                    charCode += 26;
                }
            }else{
                if(charCode > (int)'z'){
                    charCode -= 26;
                }else if(charCode < (int)'a'){
                    charCode += 26;
                }
            }
            letter = charCode;
            returnString += letter;

            // std::cout << "output " << charCode << std::endl;
        }else{
            // std::cout << "not alpha " << charCode << std::endl;
            letter = c;
            returnString += c;
        }
    }

    return returnString;

}

std::vector<std::string> StringToVector(std::string theString, char separator){
    std::vector<std::string> vectWords;

    std::stringstream ss(theString);
    std::string sIndivStr;
    while(getline(ss, sIndivStr, separator)){
        vectWords.push_back(sIndivStr);
    }

    return vectWords;
}

 std::string VectorToString(std::vector<std::string> & vect, char separator){
     std::string theString = "";
     for(auto cust: vect){
         theString += cust + separator;
     }
    return theString;
 }



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

    while(i<=max){
        range.push_back(i);
        i += step;
    }
    return range;
}




// END FUNCTIONS
