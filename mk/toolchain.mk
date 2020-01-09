CROSS_COMPILE = 
CXX = $(CROSS_COMPILE)g++
OBJCOPY = $(CROSS_COMPILE)objcopy
BUILD_DIR = build
COMMON = $(ROOT)/common
CXXFLAGS = -O3 -Wall -std=c++2a -I$(COMMON)
CXXTEST = cxxtest

