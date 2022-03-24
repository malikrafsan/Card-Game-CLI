## How to run:
- use WSL or Linux to run
- open terminal and execute commands as follow:
  ```
  g++ -std=c++17 main.cpp Recipe.cpp ../FileManager/FileManager.cpp -o main
  ./main
  ```

## Check Unit Testing
- Make sure you have compile the program as described above
- Run again the program but save the output on file
  ```
  ./main > tests/output/recipe.out
  ```
- Run the checker program
  ```
  g++ check.cpp -o check
  ./check
  ```