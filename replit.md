# C Dynamic Memory Allocation Project

## Overview
This project demonstrates dynamic memory allocation with pointers in C. It creates an array of random integers, performs calculations on them (average), and displays the results.

## Recent Changes
- **2025-09-19**: Imported from GitHub and set up in Replit environment
- **2025-09-19**: Configured C compiler toolchain (clang14)
- **2025-09-19**: Set up workflow for building and running the program

## Project Architecture
- **Language**: C
- **Compiler**: Clang 14
- **Build System**: Makefile
- **Main File**: `main.c` - Contains all the core functions for memory allocation, number processing, and display
- **Test Directory**: `testes/` - Contains shell script for testing program execution
- **Build Target**: `main.out` - The compiled executable

### Core Functions
- `numbers_create()` - Allocates memory for integer array
- `numbers_read()` - Fills array with random numbers (0-49)
- `numbers_average()` - Calculates average of array elements
- `numbers_show()` - Displays array in formatted output
- `numbers_destroy()` - Frees allocated memory

## Running the Project
1. Use the "C Program" workflow which automatically builds and runs the program
2. Or manually run: `make && ./main.out`
3. To run tests: `make test`
4. To clean build artifacts: `make clean`

## Current State
✅ **Fully functional** - The project builds successfully and runs without errors. The workflow is configured to compile and execute the program, displaying random numbers and their calculated average.

## User Preferences
- Project follows existing C coding conventions
- Maintains original Portuguese comments and function structure
- Uses standard Makefile build system as originally designed