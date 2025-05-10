#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>

class Logger {
public:
    static void logError(const std::string& message);
    static void logInfo(const std::string& message);
};

class FileHandler {
public:
    static void saveConversion(const std::string& result);
    static void displayHistory();
};

class Converter {
private:
    float meters;
    void displayHeader();
    void displayMenu();
    void setConsoleColor(int color);

public:
    Converter();
    void run();
    float convertToInches();
    float convertToYards();
    float convertToMiles();
    void processChoice(int choice);
    void waitForKeyPress();
};
