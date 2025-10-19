# MOBITANGGA – Final Project Report

### IF2111 – Group 19 (Academic Year 2021/2022)

## 1. Introduction

MOBITANGGA is a Command-Line Interface (CLI) based game developed as part of the final project for the IF2111 course on Abstract Data Types (ADT). The game is inspired by the classic Snakes and Ladders concept, reimagined with elements from the popular Doraemon universe. It was fully implemented using the C programming language to showcase the application of ADT, modular programming, and file handling.

## 2. Game Concept

The game accommodates 2 to 4 players who compete on a board consisting of **N tiles**. All players start at tile 1, and the objective is to reach tile **N** before others. The board includes unique mechanics such as teleporters, adding strategic variation to the gameplay.

## 3. Features and Mechanics

* **Platform:** Command-Line Interface (CLI)
* **Programming Language:** C
* **Players:** 2–4 players
* **Objective:** Be the first to reach the final tile (N)
* **Teleporter System:** Certain tiles transport players forward or backward
* **External Configuration:** Game settings loaded via `.txt` files

## 4. Configuration File Structure

The gameplay environment is defined using external text configuration files containing:

* Total number of tiles
* Board layout (string representation)
* `maxRoll` value (maximum dice outcome)
* Number and position of teleporters (entry and exit tiles)

### Available Levels

* **Level 1:** `test1.txt`
* **Level 2:** `test2.txt`

## 5. Installation & Setup

Before running the game, compilation is required using a C compiler. Recommended compiler:

* **Code::Blocks:** [http://www.codeblocks.org/downloads](http://www.codeblocks.org/downloads)

### Steps:

1. Install a C compiler (e.g., Code::Blocks)
2. Clone the repository **or** download the `.zip` file and extract it
3. Compile the program using the chosen C IDE or terminal

## 6. Purpose of the Project

This project aims to:

* Apply concepts of Abstract Data Types (ADT)
* Implement modular programming in C
* Utilize file processing for dynamic game setup
* Enhance logical and structured problem-solving skills

---

*Further sections such as Gameplay Flow, ADT Design, Testing, and Conclusion can be added upon request.*
