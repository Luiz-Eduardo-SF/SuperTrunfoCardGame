# City Card Game 🏙️

Welcome to the **City Card Game**! This is a fun and interactive C program that simulates a card game where each card represents a city with various attributes such as population, area, GDP, and more. The goal of the game is to compare two city cards based on their attributes and determine which one is "stronger" according to the calculated metrics.

## How It Works 🎮

1. **Create City Cards**: The program allows you to input data for two city cards, including:
   - State abbreviation (e.g., SP, RJ)
   - City name
   - Unique card code
   - Population
   - Number of tourist attractions
   - Area (in km²)
   - GDP

2. **Calculate Metrics**: The program automatically calculates additional metrics for each city, such as:
   - GDP per capita
   - Population density (people per km²)
   - A custom "Super Power" score based on a combination of attributes.

3. **Compare Cards**: Once both cards are created, the program compares them across all attributes and determines the winner for each category. The city with the highest "Super Power" score wins the game!

4. **Interactive Menu**: The program features a user-friendly menu where you can:
   - Start a new game
   - Learn how the game works
   - Exit the program

## Why This Project? 🌟

This project is a great example of how to:
- Use **structs** to organize complex data.
- Implement **user input validation** and **buffer handling** in C.
- Create an interactive console-based application.

Whether you're a beginner learning C or an experienced programmer looking for a fun project, this game is a great way to practice coding while having fun!

## How to Run 🚀

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/city-card-game.git
2. Compile the program using a C compiler (e.g., GCC):
   ```bash
   gcc -o city_card_game main.c
3. Run the executable:
   ```bash
   ./city_card_game

## Contributions 🤝

Feel free to contribute to this project! Whether it's adding new features, improving the code, or fixing bugs, your contributions are welcome. Just fork the repository, make your changes, and submit a pull request.
