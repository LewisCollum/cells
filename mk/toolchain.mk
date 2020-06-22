CROSS_COMPILE = 
CXX = $(CROSS_COMPILE)g++
OBJCOPY = $(CROSS_COMPILE)objcopy
CXXFLAGS += -O3 -std=c++2a -fconcepts -Wall -Wextra
