#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "16";
	static const char MONTH[] = "08";
	static const char YEAR[] = "2020";
	static const char UBUNTU_VERSION_STYLE[] =  "20.08";
	
	//Software Status
	static const char STATUS[] =  "Alpha";
	static const char STATUS_SHORT[] =  "a";
	
	//Standard Version Type
	static const long MAJOR  = 1;
	static const long MINOR  = 1;
	static const long BUILD  = 121;
	static const long REVISION  = 633;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT  = 145;
	#define RC_FILEVERSION 1,1,121,633
	#define RC_FILEVERSION_STRING "1, 1, 121, 633\0"
	static const char FULLVERSION_STRING [] = "1.1.121.633";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY  = 21;
	

}
#endif //VERSION_H
