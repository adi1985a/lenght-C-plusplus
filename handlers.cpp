#include "Converter.h"

void Logger::logError(const std::string& message) {
    std::ofstream errorLog("error_log.txt", std::ios::app);
    if (errorLog.is_open()) {
        errorLog << "[ERROR] " << message << " - " << __DATE__ << " " << __TIME__ << std::endl;
        errorLog.close();
    }
}

void Logger::logInfo(const std::string& message) {
    std::ofstream infoLog("info_log.txt", std::ios::app);
    if (infoLog.is_open()) {
        infoLog << "[INFO] " << message << " - " << __DATE__ << " " << __TIME__ << std::endl;
        infoLog.close();
    }
}

void FileHandler::saveConversion(const std::string& result) {
    std::ofstream history("conversion_history.txt", std::ios::app);
    if (history.is_open()) {
        history << result << " - " << __DATE__ << " " << __TIME__ << std::endl;
        history.close();
    }
}

void FileHandler::displayHistory() {
    std::ifstream history("conversion_history.txt");
    if (history.is_open()) {
        std::string line;
        std::cout << "\nConversion History:\n";
        std::cout << "-------------------\n";
        while (getline(history, line)) {
            std::cout << line << std::endl;
        }
        history.close();
    } else {
        std::cout << "No conversion history available.\n";
    }
}
