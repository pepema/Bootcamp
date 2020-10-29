# Step by step guide to start debugging in vscode
Note that this is the stupid way of doing this and there's probably better ways by also configuring your tasks.json  

1. Create your binary with debug flags.  
If you do this with g++ just add -g when compiling.  
If you are doing this with CMake add the line ´set(CMAKE_BUILD_TYPE Debug)´  
2. In your workspace folder add a launch.json file by choosing Run->Add Configuration... Note, this file should be located in your workspace/.cscode  
3. In the "program" key, add the path to you binary. Easiest way of doing this is right clicking on your binary created in step 1, and choose ´Copy Relative Path´. Paste after the variable workspaceFolder.  
Here's an example: ´"program": "${workspaceFolder}/Lecture9/2nd/build/2nd"´  
4. Change the stopAtEntry flag to ´true´ to not get lost when you start debugging.  
5. Now press ´F5´ and you should be good to go!