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
#include <vector> // resizable arrays
#include <sstream>  // manipulate strings

//using namespace std;
// using std::out;

/*
 * args : arguments count
 * argv : point to whole bunch of arguments value
 */
int main(int argc, char** argv) {

    // std represent your console on your screen
    std::cout << "Hello world!" << std::endl;
    
    if(argc != 1){
        std::cout << "You entered " << argc << "arguments \n" << std::endl;
    }
    
    for(int i=0; i<argc; ++i){
        std::cout << "No:" << i << " value is :" << argv[i] << " \n" << std::endl;
    }
    
    return 0;
}

