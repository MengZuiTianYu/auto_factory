CXX=g++
LDFLAGS=-std=c++11 -O1 -g -w -fopenmp

TARGET=main.app


INCLUDE_BASE = ./

INCLUDE_DIR = -I"$(INCLUDE_BASE)" 

SRC_BASE = ./

SRCS := $(wildcard $(SRC_BASE)/*.cpp) 

OBJS := $(SRCS:%.cpp=%.o)




#　编译工程，生成可执行文件
all:$(OBJS) 
	@echo "Compilling......"
	$(CXX)  $(LDFLAGS) -o $(TARGET) $^ $(CFLAGS) $(LIBS)

%.o:%.cpp
	$(CXX) $(LDFLAGS) -c $< -o $@ $(LIBS) $(CFLAGS) $(INCLUDE_DIR)
	@echo " "

	
.PHONY:clean
clean:
	rm -rf $(TARGET) $(OBJS) *.gch


