Compressor :: Compressor(){
	inputFile = "";
}

Compressor :: Compressor(string IF){
	inputFile = IF;
}

void Compressor :: deleteSpaces(){
	string outputFile = "";
	for(int i=0; i<data.size(); i++){
    if(data[i]=='<'){
      while(data[i]!='>'){
        outputFile.push_back(data[i++]);
      }
      outputFile.push_back();
      continue;
    }
    if(data[i]=='"'){
      while(data[i]!='"'){
        outputFile.push_back(data[i++]);
      }
      outputFile.push_back();
      continue;
    }
    if(data[i]=='\''){
      while(data[i]!='\''){
        outputFile.push_back(data[i++]);
      }
      outputFile.push_back();
      continue;
    }
    if(data[i] == ' ' || data[i] == '\n') continue;
    outputFile.push_back(data[i]);
    }
    data = outputFile;
}

bool Compressor :: compress(string IF){
	if(IF.empty() && inputFile.empty())	return 0;
}

bool Compressor :: deCompress(string IF){
	if(IF.empty() && inputFile.empty())	return 0;
}

bool Compressor :: printOutput(Operation op){

}

void Compressor :: compressTags(){
  string outFile = "";
  vector<string> tree;
  
}

void Compressor :: RLE(){
	/* using numbers in ASCII starting from 210 -not represented on keyboard- */
}

void Compressor :: getInput(){

}
