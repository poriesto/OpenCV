CC=g++
CFLAGS = -std=c++11 -Wall
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_flann
INC_PATH = /usr/include/opencv2
SOURCE=main.cpp

all:
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $(SOURCE) -I obj/ -o obj/main.o
	$(CC) -o bin/main obj/main.o $(LIBS)
clean:
	rm -f obj/*.* bin/*.*
