chessvizz.exe : src/main.cpp src/move.cpp src/boardinit.cpp src/boardprint.cpp
	 g++ -Wall -Werror -o chessvizz.exe src/main.cpp src/move.cpp src/boardinit.cpp src/boardprint.cpp