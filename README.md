# Tetris
## My take on Tetris written in C++ using SDL3

## WIP, Game is not currently playable
  
## Building from source
### Dependencies
This project uses cmake and therefore depends on cmake 3.16+ to be installed by the user,  
A Cmake generator like Visual Studio, make or ninja is required,  
A C++ Compiler like g++, clang or Visual C++ is required,  
  
Arch Linux:  
```shell
sudo pacman -Sy cmake make g++
```

Debian based Linux:  
```shell
sudo apt install cmake make g++
```

Fedora Linux:  
```shell
sudo dnf install cmake make g++
```

### Build
Clone the Repo:  
```shell
git clone https://github.com/SyntaxError2505/tetris.git && cd tetris
```

Clone SDL3 into the Repo:  
```shell
git clone https://github.com/libsdl-org/SDL.git ./third-party
```

Build with Cmake:  
```shell
mkdir build && cd build
cmake ..
cmake --build .
```

### If errors occur during build please leave an issue or a pull request to update the project
