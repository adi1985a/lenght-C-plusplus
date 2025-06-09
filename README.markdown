# 📏🔄 UnitMaster: Length Converter Pro v2.0 📐
_A C++ console application for converting lengths from meters to various imperial units, featuring history, logging, and a colorful UI._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Core Components & `Converter.h`](#-core-components--converterh)
6.  [Installation and Setup](#️-installation-and-setup)
7.  [Usage Guide](#️-usage-guide)
8.  [File Structure & Data Persistence](#-file-structure--data-persistence)
9.  [Technical Notes](#-technical-notes)
10. [Contributing](#-contributing)
11. [License](#-license)
12. [Contact](#-contact)

## 📄 Overview

**UnitMaster: Length Converter Pro (Version 2.0)**, developed by Adrian Lesniak, is a practical C++ console application designed for converting length measurements from meters into common imperial units: inches, yards, and miles. The program boasts a user-friendly, menu-driven interface with colorful output (enhanced on Windows). It diligently logs all conversion operations to `conversion_history.txt` and any errors to `error_log.txt`, both with timestamps. Built with an object-oriented approach using `Converter`, `Logger`, and `FileHandler` classes (defined in the user-provided `Converter.h`), it offers a robust and organized solution for quick length conversions.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

*   📏 **Length Conversions**:
    *   `convertToInches`: Converts meters to inches (1 meter = 39.37 inches).
    *   `convertToYards`: Converts meters to yards (1 meter = 1.0936 yards).
    *   `convertToMiles`: Converts meters to miles (1 meter = 0.0006213 miles).
*   🖥️ **Interactive Console Interface**:
    *   `displayHeader`: Shows a clear program title, author information, and a brief description.
    *   `displayMenu`: Provides a simple menu with options for converting to inches, yards, miles, viewing history, and exiting.
    *   **Colorful Output**: Utilizes Windows console API for distinct colors (cyan, yellow, white, green) to improve UI readability and user engagement.
*   🗃️ **File Handling & History**:
    *   `FileHandler::saveConversion`: Saves each successful conversion result along with a timestamp to `conversion_history.txt`.
    *   `FileHandler::displayHistory`: Allows users to view all previously saved conversion records.
*   ✍️ **Event Logging**:
    *   `Logger::logError`: Records any operational errors (e.g., invalid input) with timestamps to `error_log.txt`.
    *   `Logger::logInfo`: (Defined but noted as unused in the provided code) Could be used to log successful operations or other informational messages to `info_log.txt`.
*   ⚙️ **Robust Operation**:
    *   The main program loop (`Converter::run`) manages user interaction, input validation, and dispatches conversion tasks.
    *   `processChoice` method handles user menu selections and the logic for each conversion.
*   🛠️ **Utility Functions**:
    *   `setConsoleColor`: A dedicated function to set the console text color.
    *   `waitForKeyPress`: Pauses execution and waits for a user keypress before returning to the menu.

## 🖼️ Screenshots


_Screenshots showcasing the main menu, input for meter values, conversion results, the history display, and examples of the log/history files._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
  <img src="screenshots\9.jpg" width="300"/>
  <img src="screenshots\10jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<windows.h>` for `SetConsoleTextAttribute` and `<conio.h>` for `_getch`).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<fstream>`, `<string>`, `<vector>`, `<iomanip>` (for output formatting), `<ctime>` (for timestamps).
*   📄 **`Converter.h` Header File (User-Provided)**: This project **critically requires** a header file named `Converter.h`. **This file is not included in the repository and must be created by the user.** It must define the `Converter`, `Logger`, and `FileHandler` classes and their respective members. See "Core Components & `Converter.h`" and "Installation and Setup" for details.
*   **Write Permissions**: The application needs write permissions in its execution directory to create/modify `error_log.txt`, `info_log.txt` (if used), and `conversion_history.txt`.

## 🧩 Core Components & `Converter.h`

The `Converter.h` file is central to this project and must be provided by the user. It should declare:

*   **`Logger` Class**:
    *   Methods like `logError(const std::string& message)` and `logInfo(const std::string& message)`.
    *   Manages writing timestamped entries to `error_log.txt` and `info_log.txt`.
*   **`FileHandler` Class**:
    *   Methods like `saveConversion(const std::string& conversionDetails)` and `displayHistory(const std::string& filePath)`.
    *   Handles reading from and writing to `conversion_history.txt`.
*   **`Converter` Class**:
    *   The main application class.
    *   Contains instances of `Logger` and `FileHandler`.
    *   Methods for each conversion: `convertToInches(double meters)`, `convertToYards(double meters)`, `convertToMiles(double meters)`.
    *   UI methods: `displayHeader()`, `displayMenu()`.
    *   Core logic: `run()` (main loop), `processChoice(int choice)`.
    *   Utility methods like `setConsoleColor(int color)` and `waitForKeyPress()`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Create `Converter.h`**:
    Place your `Converter.h` file (containing the declarations for `Converter`, `Logger`, and `FileHandler` classes) in the project directory.

3.  **Prepare Source Files**:
    *   Ensure your main application logic (likely including the `main()` function and `Converter` class method implementations if not inlined) is saved as `main.cpp`.
    *   The implementations for `Logger` and `FileHandler` methods should be in `Converter.cpp` (as per the description) or separate `.cpp` files.

4.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp Converter.cpp -o length_converter.exe -std=c++11 -static-libgcc -static-libstdc++
    ```
    *(This assumes `Converter.cpp` contains implementations for classes declared in `Converter.h`. Adjust if your file structure or class implementation locations differ).*

5.  **Run the Program**:
    ```bash
    .\length_converter.exe
    ```
    (or `length_converter.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `length_converter.exe` as detailed above.
2.  **Interface**:
    *   The program will display a header and a main menu with the following options:
        1.  Convert meters to inches
        2.  Convert meters to yards
        3.  Convert meters to miles
        4.  View conversion history
        5.  Exit
3.  **Input**:
    *   Select a menu option (1–5) by typing the number and pressing Enter.
    *   **For conversions (Options 1–3)**: You will be prompted to enter the length in meters.
    *   The program validates input; non-numeric or invalid entries will trigger an error (logged to `error_log.txt`) and prompt for re-entry.
4.  **Output**:
    *   **Conversions**: The result of the conversion (e.g., "Meters: 1.00 = 39.37 inches") will be displayed on the console and saved with a timestamp to `conversion_history.txt`.
    *   **View History (Option 4)**: Displays all past conversion records stored in `conversion_history.txt`, including their timestamps.
    *   **Errors**: Any operational errors are logged to `error_log.txt`.
5.  **Actions**:
    *   After each operation (conversion or history view), you will be prompted to press any key to return to the main menu.
    *   Select option `5` to exit the application.

## 🗂️ File Structure & Data Persistence

*   `main.cpp`: Typically contains the `main()` function and might include implementations for the `Converter` class methods if not in a separate file.
*   `Converter.cpp`: As per description, implements `Logger` and `FileHandler` functions. May also contain `Converter` method implementations.
*   `Converter.h`: (User-provided) Header file with class declarations for `Converter`, `Logger`, and `FileHandler`.
*   `error_log.txt`: A plain text file where error messages are logged with timestamps. Created or appended to.
*   `info_log.txt`: (If `Logger::logInfo` is implemented and used) A plain text file for informational logs.
*   `conversion_history.txt`: A plain text file that stores a record of all successful conversions, including the input, output, and timestamp. Created or appended to.

## 📝 Technical Notes

*   **Windows Specifics**: The project leverages Windows-specific headers (`<windows.h>`, `<conio.h>`) for functionalities like colored console output (`SetConsoleTextAttribute`) and direct keypress input (`_getch()`). Adapting for true cross-platform use would require alternative libraries or conditional compilation.
*   **Object-Oriented Design**: The use of `Converter`, `Logger`, and `FileHandler` classes promotes a modular, organized, and maintainable codebase.
*   **Input Validation**: The `Converter::run` or `processChoice` method handles non-numeric input using `std::cin.clear()` and `std::cin.ignore()` to prevent program crashes and ensure data integrity.
*   **Timestamping**: Uses C++ `<ctime>` functionalities to generate timestamps for log entries and conversion history records.
*   **`Logger::logInfo`**: While defined, its actual use for logging successful conversions or other info events is noted as unimplemented in the provided code description. This offers an area for future enhancement.

## 🤝 Contributing

Contributions to **UnitMaster: Length Converter Pro** are highly encouraged! If you have ideas for adding more unit conversions (e.g., metric to metric, other imperial units), improving cross-platform support, enhancing the UI, or implementing features like user-configurable conversion factors:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourConversionIdea`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourConversionIdea'`).
4.  Push to the branch (`git push origin feature/YourConversionIdea`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🌐 _Bridging metric and imperial, one conversion at a time!_
