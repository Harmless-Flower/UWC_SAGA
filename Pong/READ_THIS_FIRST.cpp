/*

If you were following along in class already, skip to Step 9, otherwise follow the steps below.
  1. Make a Student License in JetBrains (simply search it up, and complete as necessary)
  2. Install Clion
  3. If youre brew is installed, skip this step, otherwise copy and paste the line below into your terminal and press enter
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     Input your computer password whenever it asks for one and follow the steps displayed on the terminal if it ever stops for too long
  4. Open Clion and under File, click New, then Project, and you should get a pop up window
  5. In the pop up window, there should be a long line, such as "/User/coolguy123/ClionProjects/untitled"
     Rename the last part (the untitled part only) to whatever name you want the project to be called, for example
     "/User/coolguy123/ClionProjects/untitled" => "/User/coolguy123/ClionProjects/PongGame"
     Also, set the c++ version to 23 and then make the project
  6. Once a new project is made, you can click the play button in the top right to see if its all working, if sucessful,
     click on the CMakeLists.txt file, delete everything in it, and replace with the text below.
     
      cmake_minimum_required(VERSION 3.14)
      project(Title)

      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

      set(SOURCE_FILES main.cpp)
      add_executable(Title ${SOURCE_FILES})

      include_directories(/usr/local/include)

      find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
      include_directories(${SFML_INCLUDE_DIRS})
      target_link_libraries(Title sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
      
      Note that where it says Title, replace it with the name you gave to the project (for eg. PongGame from step 5)
      
      Then on the top a header should pop up asking whether these changes should be reloaded, click yes
   7. Next, under File, New, click C++ Class and name it Bat
   8. Then repeat Step 7, but name it Ball
   9. Finally, copy the contents of each file with that from this github (for example, replace the contents of your main.cpp file with that on this github)
   10. Two important steps to make is that to display text in the game, a font is necessary. To do that, any font can be used, an example being this link
       which has a game over font: https://www.dafont.com/game-over.font
   11. Download the desired font for the game, and in main.cpp, line 28, replace address_to_file_with_chosen_font with the address to where your
       downloaded font is, for example if you downloade the game over font to your desktop, then your address would be 
       /Users/username/Desktop/game_over.tff
   12. That's it! Now if you click the play button, you should see the Pong game pop up and you can control it with the left and right key,
       with the escape key being to close the game.
   
   Disclaimer: This is a very simple Pong Game, so there might be some glitches while playing the game. If any happen, simply close the game and restart.

*/
