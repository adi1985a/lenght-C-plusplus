#include "Converter.h"

Converter::Converter() : meters(0.0) {}

void Converter::setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Converter::displayHeader() {
    system("cls");
    setConsoleColor(11);
    std::cout << "****************************************************\n";
    std::cout << "*        Length Unit Converter - Version 2.0        *\n";
    std::cout << "*            Created by: Adrian Lesniak            *\n";
    std::cout << "****************************************************\n\n";
    
    setConsoleColor(14);
    std::cout << "Program Description:\n";
    std::cout << "This tool converts meters to inches, yards, and miles.\n";
    std::cout << "Results are saved automatically for future reference.\n\n";
}

void Converter::displayMenu() {
    setConsoleColor(15);
    std::cout << "------------------------\n";
    std::cout << "        MENU           \n";
    std::cout << "------------------------\n";
    std::cout << "1. Convert to inches\n";
    std::cout << "2. Convert to yards\n";
    std::cout << "3. Convert to miles\n";
    std::cout << "4. View conversion history\n";
    std::cout << "5. Exit\n";
    std::cout << "------------------------\n";
}

float Converter::convertToInches() {
    return meters * 39.37;
}

float Converter::convertToYards() {
    return meters * 1.0936;
}

float Converter::convertToMiles() {
    return meters * 0.0006213;
}

void Converter::waitForKeyPress() {
    std::cout << "\nPress any key to return to menu...";
    _getch();
}

void Converter::processChoice(int choice) {
    if (choice >= 1 && choice <= 3) {
        std::cout << "\nEnter length in meters: ";
        if (!(std::cin >> meters)) {
            Logger::logError("Invalid input");
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            return;
        }
    }

    std::string result;
    setConsoleColor(10);
    switch (choice) {
        case 1:
            result = "Meters: " + std::to_string(meters) + " = " + std::to_string(convertToInches()) + " inches";
            std::cout << result << std::endl;
            break;
        case 2:
            result = "Meters: " + std::to_string(meters) + " = " + std::to_string(convertToYards()) + " yards";
            std::cout << result << std::endl;
            break;
        case 3:
            result = "Meters: " + std::to_string(meters) + " = " + std::to_string(convertToMiles()) + " miles";
            std::cout << result << std::endl;
            break;
        case 4:
            FileHandler::displayHistory();
            return;
        case 5:
            std::cout << "Thank you for using the converter!\n";
            return;
        default:
            Logger::logError("Invalid menu choice");
            std::cout << "Invalid choice! Please try again.\n";
            return;
    }
    FileHandler::saveConversion(result);
}

void Converter::run() {
    int choice;
    do {
        displayHeader();
        displayMenu();
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        processChoice(choice);
        if (choice != 5) waitForKeyPress();
    } while (choice != 5);
}

int main() {
    Converter converter;
    converter.run();
    return 0;
}


