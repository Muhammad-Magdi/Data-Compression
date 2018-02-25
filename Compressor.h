#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Compressor{
	private:
		vector<string> data;						//The output of the Compression process
		string outputFile;							//The output file name.
		string inputFile;								//The target file -Compressed||Decompressed-
		enum Opreation {COMPRESSED, DECOMPRESSED};
		bool printOutput(Opreation);		//Creates and prints either an -Compressed 
		 																//or Decompressed file-
		void deleteSpaces();						//Deletes all the spaces out of the double
																		//qoutes and the <pre> tag
		void compressTags();						//Deletes the closing of the tag
	public:
		Compressor();										//an empty Constructor
		Compressor(string);							//takes the name of the input file
		bool compress(string = "");			//Compresses given inputFile
		bool deCompress(string = "");		//Decompresses given inputFile
};

#include "Compressor.cpp"

#endif
