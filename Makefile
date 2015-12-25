CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++14
OBJ_HIDE=src/hide.o src/process.o src/utils.o
OBJ_FIND=src/find.o src/process.o src/utils.o
EXEC_HIDE=hide
EXEC_FIND=find

OPENCVLIB=-lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml
OPENCVLIB+=-lopencv_video -lopencv_features2d -lopencv_calib3d
OPENCVLIB+=-lopencv_objdetect -lopencv_contrib -lopencv_legacy
OPENCVLIB+=-lopencv_stitching

all: CXXFLAGS+= -O3 -DNDEBUG
all: hide find

debug: CXXFLAGS+= -g
debug: hide find

hide: $(OBJ_HIDE)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_HIDE) $(OPENCVLIB)

find: $(OBJ_FIND)
	$(CXX) $(CXXFLAGS) $^ -o $(EXEC_FIND) $(OPENCVLIB)

clean:
	rm -rf $(EXEC_HIDE) $(EXEC_FIND) $(OBJ_FIND) $(OBJ_HIDE)
	rm -rf output.png

.PHONY: all clean debug hide find
