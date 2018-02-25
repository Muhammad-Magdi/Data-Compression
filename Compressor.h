#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum Operation {COMPRESS, DECOMPRESS};

class Compressor{
	private:
		const int ASCIIbase = 210;
		string data;										//The output of the Compression process
		string outputFile;							//The output file name.
		string inputFile;								//The target file -Compressed||Decompressed-
		ifstream instream;							//input file stream
		ofstream outstream;							//output file stream
		
		bool printOutput(Operation);		//Creates and prints either an -Compressed 
		 																//or Decompressed file-
		void deleteSpaces();						//Deletes all the spaces out of the double
																		//qoutes and the <pre> tag
		void compressTags();						//Deletes the closing of the tag
		void deCompressTags();					//reConstructs the tags
		void compressRLE();											//Runs RLE
		void deCompressRLE();						//decompresses the RLE
		bool getInput(Operation);								//gets Input from file using input stream
		
	public:
		Compressor();										//an empty Constructor
		Compressor(string);							//takes the name of the input file
		bool compress(string = "");			//Compresses given inputFile
		bool deCompress(string = "");		//Decompresses given inputFile
};

#include "Compressor.cpp"

#endif
