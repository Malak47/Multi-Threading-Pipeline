CXX = g++
CXXFLAGS = -std=c++11 -Wall -lpthread
OBJECT_PATH = objects
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(OBJECT_PATH)/%.o, $(SRCS))

st_pipeline: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECT_PATH)/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: st_pipeline

default: st_pipeline

.PHONY: all

clean:
	rm -rf $(OBJECT_PATH)/* *.o st_pipeline
