#include <stdio.h>
#include <stdlib.h>

#include "run.h"
#include "filefunc.h"
#include "timer.h"

#include "opencv2/opencv.hpp"
using namespace cv;

#include <fstream>
using namespace std;

#include "imio.h"


int main(int argc, char *argv[])
{
	// get monitor size
	char name_video[256];
	char name_cascade[256];
	sprintf(name_video, "camera");
#if 0
	sprintf(name_video, "..\\bin\\list.txt");
	sprintf(name_cascade, "..\\bin\\face_24x24_14.xml");
	loadDetector(name_cascade);
	runFace(name_video, 1080, 1920);
		
#else 
	sprintf(name_cascade, "..\\bin\\opencv_dll.dll");
	if(argc==1) {
		sprintf(name_video, "camera");
		loadDetector(name_cascade);
		runFace(name_video);
	}
 	else if(argc==2) {
		int flag_io = get_type_IO(argv[1]);
		if(IO_ERROR == flag_io) {
			sprintf(name_video, "camera");
			sprintf(name_cascade, argv[1]);
		}
		loadDetector(name_cascade);
		runFace(name_video);
	}
	else if(argc==3) {
		sprintf(name_cascade,argv[1]);
		sprintf(name_video,argv[2]);
		loadDetector(name_cascade);
		runFace(name_video);
	}
#endif

	return 1;
}
