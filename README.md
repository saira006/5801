Set-Up:
  1. In order to run this system, an integrated development environment (IDE) is required, which can include 
  applications such as Visual Studio Code or ATOM.
  2. The source code file that the user intends to use must be located in the same working directory as PPALMS (which
  includes files named main.cpp, group.cpp, group.h, modify.cpp, and modify.h).
  3. To create an executable, open a terminal in the working directory of the PPALMS. Type “g++ main.cpp modify.cpp
  group.cpp” into the terminal and press enter to create an executable file named “a.out”. If a different name is
  desired for the executable file, then type “g++ -o <desired executable filename> main.cpp modify.cpp group.cpp”. 
  4. To run the executable, type “./<executable filename>” in terminal and press enter. If the program is successfully
  running, you should see “Enter a filename:” in the terminal window.

Running the Program:
  1. The user will be prompted to enter the name of the file containing the source code.
  2. Once a valid filename has been entered, the user will have the option to select one of six commands by typing in the number associated with command and pressing enter.
  3. The first command handles creating groups. After entering this option, the user will be prompted to enter a start and end line for the group. If all of the inputs are valid, the user will see a message stating the creation was successful.
  4. The second command handles deleting groups. After entering the option, the user will be prompted to enter a start and end line for the group. If all of the inputs are valid, the user will see a message stating the deletion was successful.
  5. The third command handles adding comment. After entering this option, the user will be prompted to enter a comment followed by the start and end line for the group. If all of the inputs are valid, the user will see a message stating that the comment was sucessfully added.
  6. The fourth command handles removing a comment. After entering this option, the user will be prompted to enter a valid start and end line for the group.  If everything is valid, the user will be shown a message stating that the comment has been successfully removed.
  7. The fifth command handles editing a comment. After entering this option, the user will be prompted to enter a comment followed by the start and end line for the group. If there is no comment associated with the given group, the user will be brought back to the command selection prompt and given an error message.
  8. The sixth command handles exiting the system. Entering this option causes the program to stop running.

Setting up the tests and generating the reports:
1. Type g++ test_main.cpp test.cpp modify.cpp group.cpp
2. Then type ./a.out
3. You will see the 2 generated reports called Group-report.txt and Modify-report.txt