CXX = g++
CXXFLAGS = -Wall -Werror -I src
CXXFLAGS_2 = -Wall -Werror -I thirdparty
CPPFLAGS = -MMD

A_NAME = chessviz.exe
T_NAME = chesstest.exe

BIN_D = bin
SRC_D = src
OBJ_D = obj
TST_D = test
NAMEDIR = chessviz
NAMEDIRLIB = chessvizlib

APP_PATH = $(BIN_D)/$(A_NAME)
TST_PATH = $(BIN_D)/$(T_NAME)

CPP_PATH = $(SRC_D)/$(NAMEDIR)
HPP_PATH = $(SRC_D)/$(NAMEDIRLIB)

ML_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIRLIB)/mainlib.a

MAIN_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/main.o
BI_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/boardinit.o
BP_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/boardprint.o
MV_PATH = $(OBJ_D)/$(SRC_D)/$(NAMEDIR)/move.o

$(APP_PATH) : $(ML_PATH)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(ML_PATH) : $(MAIN_PATH) $(BI_PATH) $(BP_PATH) $(MV_PATH)
	ar r $@ $^

$(MAIN_PATH) : $(CPP_PATH)/main.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(BI_PATH) : $(CPP_PATH)/boardinit.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(BP_PATH) : $(CPP_PATH)/boardprint.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

$(MV_PATH) : $(CPP_PATH)/move.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

-include main.d boardinit.d boardprint.d move.d

.PHONY : test
test : $(TST_PATH)
$(TST_PATH) : $(TST_D)/board_test.o $(TST_D)/main.o $(ML_PATH)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(TST_D)/%.o : %.cpp
	$(CXX) $(CXXFLAGS_2) -c  $(CPPFLAGS) $@ -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(ML_PATH)
	find $(OBJ_D) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_D) -name '*.d' -exec $(RM) '{}' \;
	find $(TST_D) -name '*.o' -exec $(RM) '{}' \;
	find $(TST_D) -name '*.d' -exec $(RM) '{}' \;
