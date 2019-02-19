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
#include <cmath>
#include <fstream>

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

void BubbleSort(std::vector<int>& theVect);

int Factorial(int number);
int SigmaNumber(int number);
int Fib(int index);
std::vector<int> GenerateFibList(int maxNums);

void PrintHorzVector(std::vector<int>& theVect);

double Area(double radius);
double Area(double height, double width);

// cannot edit in read only editor
// code-runner.runInTerminal to true from your File -> Preferences -> Settings





// ------------------------------------------------------------------------------------


class Animal{
private:
    // which shoulld be change by methods
    std::string name;
    int height;
    int weight;
    

    // this is shared by any object of animal that is ever created
    static int numOfAnimals;


public:

    std::string GetName(){return name;}
    void SetName(std::string animalName){ name = animalName; }

    int GetHeight(){return height;}
    void SetHeight(int cm){ height = cm; }

    int GetWeight(){return weight;}
    void SetWeight(int km){ weight = km; }
    
    void SetAll(std::string, double, double);
    Animal( std::string , double, double);
    Animal();
    ~Animal();
    static int GetNumOfAnimals(){
        return numOfAnimals;
    }
    void ToString();
    

    void GetFamily(){ std::cout << "We are animals" << std::endl; }
    virtual void GetClass(){ std::cout << "I'm an Animal " << std::endl; }


    // void setAll(int, int , string );

    
};

int Animal::numOfAnimals = 0;
void Animal::SetAll(std::string name, double height, double weight){
    this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}
Animal::Animal(std::string name, double height, double weight){
	this->height = height;
	this->weight = weight;
	this->name = name;
	Animal::numOfAnimals++;
}
Animal::Animal(){
    this->height = 0;
	this->weight = 0;
	this->name = "";
	Animal::numOfAnimals++;
}
Animal::~Animal(){
	std::cout << "Animal " << this->name << " destoried" << '\n';
}
void Animal::ToString(){
	std::cout << this->name << " is " << this->height
	<< "cms tall and " << this->weight << "kgs in weight" <<  '\n';
}


class Dog : public Animal{
private:
	std::string sound = "Woof";

public:
    void MakeSound(){
        std::cout << "The dog " << this->GetName() << " says " << this->sound << std::endl;
    }
	void GetSound() {std::cout << sound << '\n';}
	void GetClass(){ std::cout << "I'm a dog" << std::endl; }

	Dog(std::string, int, int,  std::string);
	Dog() : Animal(){};
	void ToString();
};

Dog::Dog(std::string name, int height, int weight,  std::string bark) : Animal( name,height, weight){
	this->sound = bark;
}
void Dog::ToString(){
	std::cout << this->GetName() << " is " << this->GetHeight()
	<< "cms tall and " << this->GetWeight() << "kgs in weight and says "
	<< this->sound <<  '\n';
}


class GermanShepard : public Dog{
public:
		void getClass(){ std::cout << "I'm a German Shepard" << '\n';}
		void getDerived(){ std::cout << "I'm a Animal and Dog" << '\n';}
};



// ------------------------------------------------------------------------------------
class Warrior{
private:
    int attkMax;
    int blockMax;

public:
    std::string name;
    int health;

    Warrior(std::string name, int health, int attkMax, int blockMax){
        this->name = name;
        this->health = health;
        this->attkMax = attkMax;
        this->blockMax = blockMax;
    }

    int Attack(){
        return std::rand() % this->attkMax;
    }
    int Block(){
        return std::rand() % this->blockMax;
    }
};

class Battle{
public:
    static void StartFight(Warrior& warrior1, Warrior& warrior2){
        while(true){
            if(Battle::GetAttackResult(warrior1, warrior2).compare("Game Over")==0){
                std::cout << "Gamve OVer\n";
                break;
            }

            if(Battle::GetAttackResult(warrior2, warrior1).compare("Game Over")==0){
                std::cout << "Gamve OVer\n";
                break;
            }
        }

    }

    std::string static GetAttackResult(Warrior& warriorA, Warrior& warriorB){
        int warriorAAttkAmt = warriorA.Attack();
        int warriorBBlockAmt = warriorA.Block();
        
        int damage2WarriorB = ceil(warriorAAttkAmt - warriorBBlockAmt);
        damage2WarriorB = (damage2WarriorB <= 0) ? 0 : damage2WarriorB;

        warriorB.health = warriorB.health - damage2WarriorB;

        printf("%s attacks %s and deals %d damage \n", 
                    warriorA.name.c_str(), 
                    warriorB.name.c_str(),
                    damage2WarriorB);
        printf("%s is down to %d health \n", 
                    warriorB.name.c_str(),
                    warriorB.health);
        if(warriorB.health <= 0 ){
            printf("%s has Die and %s is Victorius \n", 
                    warriorB.name.c_str(),
                    warriorA.name.c_str());
            return "Game Over";
        }else{
            return "Fight Again";
        }
    }

};


// ------------------------------------------------------------------------------------

// struct Shape{
//     double length, width;
//     Shape(double l = 1, double w = 1){
//         length = l;
//         width = w;
//     }

//     double Area(){
//         return length * width;
//     }

// private:
//     int id;

// };

// struct Circle : Shape{
//     Circle(double width){
//         this->width = width;
//     }
//     double Area(){
//         return 3.14159 * std::pow((width /2), 2);
//     }
// };

// ------------------------------------------------------------------------------------

class Customer{
private:
    friend class GetCustomerData;
    std::string name;

public:
    Customer(std::string name){
        this->name = name;
    }
};

class GetCustomerData{
public:
    static std::string GetName(Customer& customer){
        return customer.name;
    }
};

// ------------------------------------------------------------------------------------
// 多态性
class Shape{
public:
    virtual double Area() = 0;

};

class Circle : public Shape{
protected:
    double width;
public:
    Circle(double w){
        width = w;
    }
    double Area() override{
        return 3.14159 * std::pow((width /2), 2);
    }
};

class Rectangle : public Shape{
protected:
    double height, width;
public:
    Rectangle(double h, double w){
        height = h;
        width = w;
    }
    double Area() override final{
        return height * width;
    }
};

// class Square : public Rectangle{
// public:
//     Square(double h, double w) : Rectangle(h, w){

//     }
//     double Area() override{
//         return height * 2;
//     }
// };

void ShowArea(Shape& shape){
    std::cout << "Area : " << shape.Area() << "\n";
};

// ------------------------------------------------------------------------------------

class Box {
public:
    double length, width, breadth;
    std::string boxString;

    Box(){
        length = 1, width = 1, breadth = 0;
    }
    Box(double l, double w, double b){
        length = l, width = w, breadth = b;
    }
    Box& operator ++ (){
        length++;
        width++;
        breadth++;

        return *this;
    }

    operator const char*(){
        std::ostringstream boxStream;
        boxStream << "Box : " << 
                length << ", " <<
                width << ", " <<
                breadth;
        boxString = boxStream.str();
        return boxString.c_str();
    }

    Box operator + (const Box& box2){
        Box boxSum;
        boxSum.length = length + box2.length;
        boxSum.width = width + box2.width;
        boxSum.breadth = breadth + box2.breadth;

        return boxSum;
    }

    double operator [] (int x){
        if(x==0){
            return length;
        }else if(x==1){
            return width;
        }else if(x==2){
            return breadth;
        }else{
            return 0;
        }
    }

    bool operator == (const Box& box2){
        return ((length == box2.length) && 
                (width == box2.width) &&
                (breadth == box2.breadth));
    }

    bool operator < (const Box& box2){
        double thisSize = length + width + breadth;
        double box2Size = box2.length + box2.width + box2.breadth;
        if(thisSize < box2Size){
            return true;
        }else{
            return false;
        }
    }

    bool operator > (const Box& box2){
        double thisSize = length + width + breadth;
        double box2Size = box2.length + box2.width + box2.breadth;
        if(thisSize > box2Size){
            return true;
        }else{
            return false;
        }
    }

    void operator = (const Box& boxToCopy){
        length = boxToCopy.length;
        width = boxToCopy.width;
        breadth = boxToCopy.breadth;

    }

};


// ------------------------------------------------------------------------------------

double MultyBy2(double num){
    return num * 2;
}

double MultyBy3(double num){
    return num * 3;
}


double DoMath(std::function<double(double)> func, double num){
    return func(num);
}

// ------------------------------------------------------------------------------------

bool IsItOdd(int num){
    return num%2 ==0 ? false : true;
}

std::vector<int> ChangeList(std::vector<int> list, std::function<bool(int)> func){
    std::vector<int> oddList;
    for(auto i: list){
        if(func(i)){
            oddList.push_back(i);
        }
    }
    return oddList;
}


std::vector<char> GetHAndTList(std::vector<char> possibleValues, int numberValuesToGenerate){
    srand(time(NULL));
    std::vector<char> hAndTList;

    for(int x =0; x < numberValuesToGenerate; ++x){
        int randIndex = rand()%2;
        hAndTList.push_back(possibleValues[randIndex]);

    }
    return hAndTList;
}


int GetNumberOfMatches(std::vector<char> list, char valueToFind){
    int numOfMatches = 0;
    for(char c: list){
        if(c==valueToFind){
            numOfMatches++;
        }
    }
    return numOfMatches;
}

// ------------------------------------------------------------------------------------

/*
 * args : arguments count
 * argv : point to whole bunch of arguments value
 */
int main(int argc, char** argv) {
//    -------------------------------------------------------


//    -------------------------------------------------------
    std::vector<char> possibleValues{'H', 'T'};
    std::vector<char> hAndTList = GetHAndTList(possibleValues, 100);
    std::cout << "Number of heads : " << GetNumberOfMatches(hAndTList, 'H') << std::endl;
    std::cout << "Number of heads : " << GetNumberOfMatches(hAndTList, 'T') << std::endl;

//    -------------------------------------------------------
    // std::vector<int> listOfNums {1,2,3,4,5};
    // std::vector<int> oddList = ChangeList(listOfNums, IsItOdd);
    // std::cout << "List of Odds \n";
    // for(auto i: oddList){
    //     std::cout << i << std::endl;
    // }

//    -------------------------------------------------------
    // auto times2 = MultyBy2;
    // std::cout << "5 * 2 = " <<
    //     times2(5) << std::endl;
    // std::cout << "6 * 2 = " <<
    //     DoMath(times2, 6) << std::endl;
    // std::vector<std::function<double(double)>> funcs(2);
    // funcs[0] = MultyBy2;
    // funcs[1] = MultyBy3;
    // std::cout << "2 * 10 = " << funcs[0](10) << std::endl;
    // std::cout << "3 * 10 = " << funcs[1](10) << std::endl;

//    -------------------------------------------------------
    // std::ofstream writeToFile;
    // std::ifstream readFromFile;
    // std::string txtToWrite = "";
    // std::string txtFromFile = "";

    // writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
    // if(writeToFile.is_open()){
    //     writeToFile << "Beginning of File \n";
    //     std::cout << "Enter data to write : ";
    //     getline(std::cin, txtToWrite);
    //     writeToFile << txtToWrite;
    //     writeToFile.close();
    // }

    // readFromFile.open("test.txt", std::ios_base::in);
    // if(readFromFile.is_open()){
    //     while(readFromFile.good()){
    //         getline(readFromFile, txtFromFile);
    //         std::cout << txtFromFile << std::endl;

    //         std::vector<std::string> vect = StringToVector(txtFromFile, ' ');
    //         int wordsInLine = vect.size();
    //         std::cout << "Words in line : " << wordsInLine << "\n";
    //         int charCount = 0;
    //         for(auto word: vect){
    //             for(auto letter: word){
    //                 charCount++;
    //             }
    //         }
    //         int avgNumChars = charCount/wordsInLine;
    //         std::cout<< "Avg Word length : " <<
    //                 avgNumChars << std::endl;


    //     }
    //     readFromFile.close();
    // }


//    -------------------------------------------------------

    // Box box(10,10,10);
    // ++box;
    // std::cout << box << "\n";
    // Box box2(5,5,5);
    // std::cout << "Box1 + Box2 = " << box + box2 << "\n";
    // std::cout << "Box length : " << box[0] << "\n";
    // std::cout << std::boolalpha;
    // std::cout << "Are boxes equal :" << 
    //             (box == box2 ) << "\n";
    // std::cout << "Is box < box2 : " << (box < box2) << "\n";
    // std::cout << "Is box > box2 : " << (box > box2) << "\n";
    
    // box = box2;
    // std::cout << "Is box == box2 : " << (box == box2) << "\n";

//    -------------------------------------------------------

    // Rectangle rectangle(10,5);
    // Circle circle(10);
    // ShowArea(rectangle);
    // ShowArea(circle);

    // Shape square(10, 5);
    // Circle circle(10);
    // ShowArea(square);
    // ShowArea(circle);


//    -------------------------------------------------------

    // Customer tom("tom");
    // GetCustomerData getName;
    // std::cout << "Name : " << getName.GetName(tom) << std::endl;

//    -------------------------------------------------------
    // Shape shape(10, 10);
    // std::cout << "Square Area : " << shape.Area() << std::endl;

    // Circle circle(10);
    // std::cout << "Circle Area : " << circle.Area() << std::endl;
    
    // Shape rectangle(10, 15);
    // std::cout << "Rectangle Area : " << rectangle.Area() << std::endl;


//    -------------------------------------------------------



    // srand(time(NULL));
    // Warrior thor("thor", 100, 30, 15);
    // Warrior hulk("Hulk", 135, 25, 10);

    // Battle::StartFight(thor, hulk);



    // Animal fred;
    // fred.ToString();
    // fred.SetHeight(33);
    // fred.SetWeight(10);
    // fred.SetName("Fred");
    // fred.ToString();
    // Animal tom("tom", 36, 15);
    // tom.ToString();
    // Dog spot("spot", 38, 16, "Wooooof");
    // spot.ToString();

    // std::cout << "Number of Animals " << Animal::GetNumOfAnimals() << std::endl;






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

    
    // std::vector<int> vecVals = GenerateRandVect(10, 5, 50);
    // for(auto x: vecVals){
    //     std::cout << x << "\n";
    // }



//    -------------------------------------------------------   

    // // Bubble sort
    // std::vector<int> vecVals = GenerateRandVect(10, 1, 50);
    // BubbleSort(vecVals);
    // for(auto x: vecVals){
    //     std::cout << x << std::endl;
    // }

//    -------------------------------------------------------   

    // int number = 10000;
    // int sigTotal = SigmaNumber(number);
    // printf("number:%d 's sigma number is : %d \n", number, sigTotal );

    // std::cout << "Factorial 3 = " << Factorial(6) << std::endl;

    // std::vector<int> theVect = {10,8,2,5,9,11,6,14};
    // PrintHorzVector(theVect);

    // int index;
    // std::cout << "Get Fibonacci Index : ";
    // std::cin >> index;

    // printf("Fib(%d) = %d \n", index, Fib(index));


//    -------------------------------------------------------   
    // std::cout << "Area Cicle (c) or Rectangle (r) : ";
    // char areaType;
    // std::cin >> areaType;

    // switch (areaType)
    // {
    //     case 'c':
    //         /* code */
    //         std::cout << "Enter Radius : ";
    //         double radius;

    //         std::cin >> radius;
    //         std::cout << "Area = " << Area(radius) << std::endl;

    //         break;

    //     case 'r':
    //         /* code */
    //         std::cout << "Enter Height : ";
    //         double height, width;
    //         std::cin >> height;
    //         std::cout << "Enter Witdh : ";
    //         std::cin >> width;
    //         std::cout << "Area = " << Area(height, width) << std::endl;

    //         break;
    
    //     default:
    //     /* code */
    //         std::cout << "Please Enter c or r \n : ";
        
    // }

//    -------------------------------------------------------   
    // std::vector<int> vectVals = GenerateRandVect(10, 1, 50);

    // for(auto val: vectVals)
    //         std::cout << val << "\n";
    // std::cout << "after sort:" << "\n";

    // // std::sort(vectVals.begin(), vectVals.end(), [](int x, int y){return x < y;});

    // std::vector<int> evenVectVals;
    // std::copy_if(vectVals.begin(), vectVals.end(), 
    //             std::back_inserter(evenVectVals), 
    //             [](int x){return x%2;});

    // // for(auto val: vectVals)
    // //     std::cout << val << "\n";
    // for(auto val: evenVectVals)
    //     std::cout << val << "\n";

    
    // int sum = 0;
    // std::for_each(vectVals.begin(), vectVals.end(), [&](int x){sum += x;});
    // std::cout << "Sum " << sum << std::endl;

    // int divisor;
    // std::vector<int> vecVals2;
    // std::cout << "List of Values Divisable by : ";
    // std::cin >> divisor;
    // std::copy_if(vectVals.begin(), vectVals.end(), 
    //             std::back_inserter(vecVals2), 
    //             [divisor](int x){return x%divisor==0;});
    // for(auto val: vecVals2)
    //         std::cout << val << "\n";



    // std::vector<double> doubleVec;
    // std::for_each(vectVals.begin(), vectVals.end(), [&](int x){doubleVec.push_back(x*2);});
    // for(auto val: doubleVec)
    //     std::cout << val << "\n";

    // std::vector<int> vec1 = {1,2,3,4,5};
    // std::vector<int> vec2 = {1,2,3,4,5};
    // std::vector<int> vec3(5);
    // transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y){return x + y;});
    // for(auto val: vec3)
    //     std::cout << val << "\n";

    // int age  = 43;
    // bool canIVote = (age  >= 18 ) ? true : false;
    // std::cout.setf(std::ios::boolalpha);
    // std::cout << "Can Derek Vote: " << canIVote << std::endl;

    // std::function<int(int)> Fib = [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    // std::cout << "Fib 4 : " << Fib(4) << std::endl;

    // std::vector<int> listOfFibs = GenerateFibList(10);
    // for(auto val: listOfFibs)
    //     std::cout << val << std::endl;



//    -------------------------------------------------------   




//    -------------------------------------------------------   

//    -------------------------------------------------------   

//    -------------------------------------------------------   

//    -------------------------------------------------------  

//    -------------------------------------------------------   



    return 0;
}



// FUNCTIONS

std::vector<int> GenerateFibList(int maxNums){
    std::vector<int> listOfFibs;

    int i  = 0;

    std::function<int(int)> Fib = [&Fib](int n) {return n < 2 ? n : Fib(n-1) + Fib(n-2);};
    while(i < maxNums){
        listOfFibs.push_back(Fib(i));
        i++;
    }
    return listOfFibs;
    
}

double Area(double radius){
    return 3.14159 * std::pow(radius, 2);
}
double Area(double height, double width){
    return width * height;
}



// Fibonacci 波那契数列 这个数列从第3项开始，每一项都等于前两项之和。
int Fib(int index){
    if(index < 2){
        return index;
    }else{
        return Fib(index -1) + Fib(index-2);
    }
}


void PrintHorzVector(std::vector<int>& theVect){
    int dashes = std::ceil(theVect.size() * 6);
    printf("dashes count:%d", dashes);

    for(int n = 0; n<dashes; n++){
        std::cout << "-";
    }
    std::cout << "\n";

    for(int n = 0; n<theVect.size(); n++){
        printf("| %2d", n);
    }
    std::cout << "|\n";

    for(int n = 0; n<dashes; n++){
        std::cout << "-";
    }
    std::cout << "\n";

    for(int n = 0; n<theVect.size(); n++){
        printf("| %2d", theVect[n]);
    }
    std::cout << "|\n";

    for(int n = 0; n<dashes; n++){
        std::cout << "-";
    }
    std::cout << "\n";




}

// 阶乘 n!
int Factorial(int number){
    if(number == 1){
        return 1;
    }else{
        int result = number *  Factorial(number - 1);
        return result;
    }
}

// 累加公式
int SigmaNumber(int number){
    return number * (number +1) / 2;
}

void BubbleSort(std::vector<int>& theVect){
    int i = theVect.size() - 1;

    while(i >= 1){
        int j = 0;
        while(j<i){
            printf("\nIS %d:%d > %d:%d\n", j, theVect[j], j+1, theVect[j+1]);

            if(theVect[j] >= theVect[j+1]){
                std::cout << "Switch\n";

                int temp = theVect[j];
                theVect[j] = theVect[j+1];
                theVect[j+1] = temp;
            }else{
                std::cout << "Don't Switch\n";
            }
            j += 1;

            for(auto k: theVect){
                std::cout << k << ", ";
            }
        }
        std::cout << "\nEnd of round\n";
        i -= 1;
    }
}


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
