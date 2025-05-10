# Length Unit Converter

## Overview
This C++ console application (Version 2.0), created by Adrian Lesniak, converts lengths from meters to inches, yards, and miles. It features a menu-driven interface, Windows-specific colored output, error logging, and conversion history storage. The program uses object-oriented design with `Converter`, `Logger`, and `FileHandler` classes.

## Features
- **Conversion Functions**:
  - `convertToInches`: Meters to inches (1 m = 39.37 in).
  - `convertToYards`: Meters to yards (1 m = 1.0936 yd).
  - `convertToMiles`: Meters to miles (1 m = 0.0006213 mi).
- **Interface**:
  - `displayHeader`: Shows program title, author, and description.
  - `displayMenu`: Lists options: convert to inches, yards, miles, view history, exit.
  - Colored output (cyan, yellow, white, green) using Windows console API.
- **File Handling**:
  - `FileHandler::saveConversion`: Saves results to `conversion_history.txt` with timestamps.
  - `FileHandler::displayHistory`: Displays conversion history.
- **Logging**:
  - `Logger::logError`: Logs errors to `error_log.txt` with timestamps.
  - `Logger::logInfo`: Logs info to `info_log.txt` (unused in provided code).
- **Main Program**:
  - `Converter::run`: Loops until exit (5), handles input validation, and processes conversions.
  - `processChoice`: Manages user input and conversion logic.
- **Utilities**:
  - `setConsoleColor`: Sets console text color.
  - `waitForKeyPress`: Pauses for user input to return to menu.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `<windows.h>`, `SetConsoleTextAttribute`, `_getch`)
- Standard C++ libraries: `<iostream>`, `<fstream>`, `<string>`, `<conio.h>`
- Header: `Converter.h` (defines `Converter`, `Logger`, `FileHandler` classes)
- Write permissions for `error_log.txt`, `info_log.txt`, `conversion_history.txt`
- Operating system: Windows (due to console functions)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Create `Converter.h` with class definitions for `Converter`, `Logger`, and `FileHandler`.
3. Save the first provided code as `main.cpp` and the second as `Converter.cpp`.
4. Compile the program:
   ```bash
   g++ main.cpp Converter.cpp -o length_converter
   ```
5. Run the program:
   ```bash
   .\length_converter
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header and menu with options:
     1. Convert to inches
     2. Convert to yards
     3. Convert to miles
     4. View conversion history
     5. Exit
3. **Input**:
   - Select 1–5 to choose an option.
   - For conversions (1–3), enter length in meters.
   - Invalid inputs (e.g., non-numeric) trigger error logging and retry.
4. **Output**:
   - Conversions: Shows result (e.g., "Meters: 1 = 39.37 inches") and saves to `conversion_history.txt`.
   - History (4): Displays all past conversions (e.g., "Meters: 1 = 39.37 inches - May 11 2025 12:00:00").
   - Errors: Logged to `error_log.txt` (e.g., "[ERROR] Invalid input - May 11 2025 12:00:00").
5. **Actions**:
   - Press any key to return to menu after each operation.
   - Select 5 to exit.

## File Structure
- `main.cpp`: Main program file with `Converter` class implementation and `main` function.
- `Converter.cpp`: Implements `Logger` and `FileHandler` functions.
- `Converter.h`: Header file with class declarations.
- `error_log.txt`: Log file for errors (created/appended).
- `info_log.txt`: Log file for info (unused, created if implemented).
- `conversion_history.txt`: Stores conversion results (created/appended).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `<windows.h>` and `_getch`; adapt for cross-platform (e.g., ANSI colors, `system("clear")`).
- Requires `Converter.h` with class definitions for `Converter`, `Logger`, and `FileHandler`.
- Input validation handles non-numeric inputs via `cin.clear()` and `cin.ignore()`.
- `Logger::logInfo` defined but unused; could be used for logging successful conversions.
- Extend by adding more units (e.g., centimeters, kilometers), cross-platform support, or a GUI.
- Ensure write permissions for log and history files.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.