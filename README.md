Set-Up:
  1. In order to run this system, an integrated development environment (IDE) is required, which can include 
  applications such as Visual Studio Code or ATOM.
  2. The source code file that the user intends to use must be located in the same working directory as PPALMS (which
  includes files named main.cpp, group.cpp, group.h, modify.cpp, modify.h, question.h, multichoice.cpp, multichoice.h, fib.cpp, and fib.h).
  3. To create an executable, open a terminal in the working directory of the PPALMS. Type “g++ main.cpp modify.cpp
  group.cpp fib.cpp multichoice.cpp” into the terminal and press enter to create an executable file named “a.out”. If a different name is
  desired for the executable file, then type “g++ -o <desired executable filename> main.cpp modify.cpp group.cpp fib.cpp multichoice.cpp”. 
  4. To run the executable, type “./<executable filename>” in terminal and press enter. If the program is successfully
  running, you should see “Enter a filename:” in the terminal window.

Running the Program:
  1. The user will be prompted to enter the name of the file containing the source code.
  2. Once a valid filename has been entered, the user will see the message "File opened successfully!" in the terminal.
  3. The user will then have the option to select one of three commands by typing in the number associated with command and pressing enter.
  4. The first command will be associated with modifying lines from the source code.
      1. The user will then have the option to select one of six commands by typing in the number associated with command and pressing enter.
      2. The first command handles creating groups. After entering this option, the user will be prompted to enter a start and end line for the group. If all of the inputs are valid, the user will see a message stating the creation was successful.
      3. The second command handles deleting groups. After entering the option, the user will be prompted to enter a start and end line for the group. If all of the inputs are valid, the user will see a message stating the deletion was successful.
      4. The third command handles adding comment. After entering this option, the user will be prompted to enter a comment followed by the start and end line for the group. If all of the inputs are valid, the user will see a message stating that the comment was sucessfully added.
      5. The fourth command handles removing a comment. After entering this option, the user will be prompted to enter a valid start and end line for the group.  If everything is valid, the user will be shown a message stating that the comment has been successfully removed.
      6. The fifth command handles editing a comment. After entering this option, the user will be prompted to enter a comment followed by the start and end line for the group. If there is no comment associated with the given group, the user will be brought back to the command selection prompt and given an error message.
      7. The sixth command handles removing lines from the source code. After entering this option, the user will be prompted to enter lines of code they want to omit separated by a space (ie: 1 3 7). If the user enters an invalid line number, that value will be ignored.
      8. The seventh command handles exiting the system. Entering this option causes the program to stop running.
  5. The second command will be associated with generating questions.
      1. The user will be first prompted to enter the desired number of questions that they would like to be generated, ranging from 1-500 questions. Then they will choose from one of three choices.
      2. The first command handles generating multiple choice questions.
      3. The second command handles generating fill in the blank questions.
      4. The third command handles exiting the question generation section of the PPALMS.

Setting up the tests and generating the reports:
1. Type g++ test_main.cpp test.cpp modify.cpp group.cpp fib.cpp multichoice.cpp
2. Then type ./a.out
3. You will see the 4 generated reports called Group_report.txt, Modify_report.txt, MultiChoice_report.txt and FIB_report.txt