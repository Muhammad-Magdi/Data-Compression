Compressor :: Compressor(){
	inputFile = "";
}

Compressor :: Compressor(string IF){
	inputFile = IF;
}

bool Compressor :: compress(string IF){
	if(IF.empty() && inputFile.empty())	return false;
	if(!IF.empty())	inputFile = IF;
	getInput(COMPRESS);
	deleteSpaces();
	compressTags();
	compressRLE();
	printOutput(COMPRESS);
	return true;
}

bool Compressor :: getInput(Operation op){
	if(op == DECOMPRESS && inputFile.substr(0, 4) !="COM_")	return false;
	instream  = ifstream(inputFile, ios::in);
	string s;
	while(getline(instream, s))
		data += s;
	return 1;
}

void Compressor :: deleteSpaces(){
	string outputFile = "";
	for(int i=0; i<data.size(); i++){
    if(data[i]=='<'){
      while(data[i]!='>'){
        outputFile.push_back(data[i++]);
      }
    }
    else if(data[i]=='\"'){
    	outputFile.push_back(data[i++]);
      while(data[i]!='\"')
        outputFile.push_back(data[i++]);
      outputFile.push_back(data[i]);
    }
    else if(data[i]=='\''){
    	outputFile.push_back(data[i++]);
      while(data[i]!='\'')
        outputFile.push_back(data[i++]);
      outputFile.push_back(data[i]);
    }
    else if(data[i] == ' ' || data[i]=='\t') continue;
  	outputFile.push_back(data[i]);
  }
	data = outputFile;
}

void Compressor :: compressTags(){
	
}

void Compressor :: compressRLE(){
	/* using numbers in ASCII starting from 210 -not represented on keyboard- */
	string ret = "";
	for(int i = 0 ; i < (int)data.length() ; ){
		int cnt = 1, j = i+1;
		while(j < data.length() && data[i]==data[j] && cnt < 15)	++cnt, ++j;
		if(cnt>2){
			ret.push_back((char)(ASCIIbase + cnt - 3));
		}else{
			j = i+1;
		}
			ret.push_back(data[i]);
		i = j;
	}
	data = ret;
}

bool Compressor :: deCompress(string IF){
	if(IF.empty() && inputFile.empty())	return false;
	if(!IF.empty())	inputFile = IF;
	getInput(DECOMPRESS);
	deCompressTags();
	deCompressRLE();
	printOutput(DECOMPRESS);
	return true;
}

bool Compressor :: printOutput(Operation op){
	string o = "";
	if(op == COMPRESS)	o = "COM_"+inputFile;
	else	o = inputFile.substr(3, inputFile.size()-3);
	outstream = ofstream(o, ios::out);
	outstream << data;
}

void Compressor :: deCompressTags(){
	
}

void Compressor :: deCompressRLE(){
	string ret = "";
	for(int i = 0 ; i < (int)data.length() ; ++i){
		int cnt = 0;
		if((unsigned char)data[i] >= ASCIIbase)	cnt = (unsigned char)data[i++]-ASCIIbase+2;
		while(cnt--){
			ret.push_back(data[i]);
		}
		ret.push_back(data[i]);
	}
	data = ret;
}


