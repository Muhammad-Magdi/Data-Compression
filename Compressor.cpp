Compressor :: Compressor(){
	inputFile = "";
}

Compressor :: Compressor(string IF){
	inputFile = IF;
}

void Compressor :: deleteSpaces(string IF){
	vector<string> tree;
	string outputFile = "";
	for(int i=0; i<inputFile.size(); i++){
    if(inf[i]=='<'){
      while(inf[i]!='>'){
        outputFile.push_back(inf[i++]);
      }
      outputFile.push_back()
      continue;
    }
    if(inf[i]=='"'){
      while(inf[i]!='"'){
        outputFile.push_back(inf[i++]);
      }
      outputFile.push_back()
      continue;
    }
    if(inf[i]=='\''){
      while(inf[i]!='\''){
        outputFile.push_back(inf[i++]);
      }
      outputFile.push_back()
      continue;
    }
    if(inf[i] == ' ') continue;
    outputFile.push_back(inf[i]);
    }
}

bool Compressor :: compress(string IF){
	if(IF.empty() && inputFile.empty())	return 0;
}

bool Compressor :: deCompress(string IF){
	if(IF.empty() && inputFile.empty())	return 0;
}

bool Compressor :: printOutput(Operation op){
	string o = "";
	o = (op == DECOMPRESSED ? "" : "COM_") + inputFile;
	outstream = ofstream(o, "ios::out");
	outstream << data;
}

void Compressor :: compressTags(){
	
}

void Compressor :: deCompressTags(){
	
}

void Compressor :: RLE(){
	/* using numbers in ASCII starting from 210 -not represented on keyboard- */
	int baseASCII = 210;
	string ret = "";
	for(int i = 0 ; i < (int)data.length() ; ){
		int cnt = 1, j = i+1;
		while(j < data.length() && data[i]==data[j] && cnt < 15)	++cnt, ++j;
		if(cnt>2){
			ret += (baseASCII + cnt);
		}else{
			j = i+1;
		}
			ret += data[i];
		i = j;
	}
}

void Compressor :: decompressRLE(){

}

void Compressor :: getInput(){
	instream  = ifstream(inputFile, "ios::in");
	string s;
	while(getline(instream, s))
		data += s;
}


