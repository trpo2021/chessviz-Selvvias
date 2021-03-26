CXX = g++
CXXFLAGS = -Wall -Werror -I src
CPPFLAGS = -MMD

A_NAME = chessviz.exe

BIN_D = bin
SRC_D = src
OBJ_D = obj
NAMEDIR = chessviz
NAMEDIRLIB = chessvizlib

APP_PATH = $(BIN_D)/$(A_NAME)

CPP_PATH = $(SRC_D)/$(NAMEDIR)
HPP_PATH = $(SRC_D)/$(NAMEDIRLIB)

ML_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/mainlib.a
MAIN_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/main.o
BI_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/boardinit.o
BP_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/boardprint.o
MV_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/move.o

TO_RM_OBJ = $(shell find $(OBJ_D)/$(SRC_D)/$(NAMEDIR) -name '*.d')
TO_RM_BIN = $(shell find $(BIN_D) -name '*.d')

$(APP_PATH) : $(MAIN_PATH) $(BI_PATH) $(BP_PATH) $(MV_PATH)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ML_PATH) : main.o boardinit.o boardprint.o move.o
	ar rcs $@ $^

$(MAIN_PATH) : $(CPP_PATH)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(BI_PATH) : $(CPP_PATH)/boardinit.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(BP_PATH) : $(CPP_PATH)/boardprint.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(MV_PATH) : $(CPP_PATH)/move.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

-include main.d boardinit.d boardprint.d move.d

clean : 
	rm -rf $(TO_RM_OBJ) $(TO_RM_BIN)
