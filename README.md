## Project Explanation: Concepts & Execution

This project is built to demonstrate core computer science fundamentals in C, bridging the gap between temporary console input and persistent data storage. Here is a breakdown of the technical concepts used and how the code executes them.

### Core Concepts Demonstrated
* **File Handling (I/O):** Utilizing standard library functions (`fopen`, `fprintf`, `fscanf`) to safely open files in varying modes (write, append, read). This ensures that session data is written to the disk and survives after the program is closed.
* **Data Structures (`struct`):** A custom `struct app` is used to bundle disparate data types—a `char` array for the app name and an `int` for the time spent—keeping the data tightly coupled in memory.
* **String Parsing & Sanitization:** Using `<string.h>` functions like `strcspn` to strip hidden newline characters from user input, ensuring clean file formatting. 
* **Buffer Management:** Utilizing `strcat` to dynamically build large strings in memory while categorizing file data, which requires careful sizing of character arrays to prevent buffer overflows or segmentation faults.

### How the Code Works
1. **Initialization & Control Flow:** The program's lifecycle is controlled by a `do-while` loop and a `switch` statement. This keeps the command-line interface active, re-rendering the menu after every action until the user explicitly selects the exit option (`3`).
2. **Storing Data (Option 1):** 
   * The program prompts the user for the application name using `fgets` (which safely allows spaces in the input). 
   * It immediately sanitizes the string by replacing the trailing newline character `\n` with a null terminator `\0`. 
   * It then opens `Track.txt` in `"a"` (append) mode and safely logs the struct's variables to the file separated by formatting tabs.
3. **Reading & Analyzing Data (Option 2):** 
   * The program opens `Track.txt` in `"r"` (read) mode. It uses a specific format specifier `fscanf(fptr,"%*[^\n]\n");` to intentionally skip the header row.
   * It then enters a `while` loop that parses the file line-by-line until it reaches `EOF` (End of File). 
   * **The Sorting Logic:** As the file is read, an `if/else` block checks the extracted time variable. If the time is `<= 3`, `strcat` appends the app name to a predefined "Productive" buffer in memory. If `> 3`, it goes to an "Unproductive" buffer.
   * Once parsing is complete, the file is closed and both formatted buffers are printed to the console as a final report.
