Compressor :: Compressor(){
	inputFile = "";
}

Compressor :: Compressor(string IF){
	inputFile = IF;
}

bool Compressor :: compress(string IF){
	if(IF.empty() && inputFile.empty())	return 0;
	if(inputFile.empty())	inputFile = IF;
	cout << inputFile.size() << endl;
	getInput();
	cout << data.size() << endl;
	deleteSpaces();
	cout << data.size() << endl;
//	compressTags();
//	compressRLE();
	printOutput(COMPRESSED);
	return 1;
}

void Compressor :: getInput(){
	instream  = ifstream(inputFile, ios::in);
	string s;
	while(getline(instream, s))
		data += s;
}

void Compressor :: deleteSpaces(){
	string outputFile = "";
	char pr;
	for(int i=0; i<data.size(); i++){
    if(data[i]=='\t')
      data[i] = ' ';
    if(data[i]=='<'){
      while(data[i]!='>'){
        if(data[i]==' ' && outputFile.back()==' '){
          i++;
          continue;
        }
        outputFile.push_back(data[i++]);
      }
    }
    else if(data[i]=='\"'){
    	outputFile.push_back(data[i++]);
      while(data[i]!='\"'){
        if(data[i]==' ' && outputFile.back()==' '){
          i++;
          continue;
        }
        outputFile.push_back(data[i++]);
      }
      outputFile.push_back(data[i]);
    }
    else if(data[i]=='\''){
    	outputFile.push_back(data[i++]);
      while(data[i]!='\''){
        if(data[i]==' ' && outputFile.back()==' '){
          i++;
          continue;
        }
        outputFile.push_back(data[i++]);
      }
      outputFile.push_back(data[i]);
    }
    else if(data[i] == ' ' && outputFile.back()==' ') continue;
  	outputFile.push_back(data[i]);
  }
  cout << endl;
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
			ret += (ASCIIbase + cnt);
		}else{
			j = i+1;
		}
			ret += data[i];
		i = j;
	}
}

bool Compressor :: deCompress(string IF){
	if(IF.empty() && inputFile.empty())	return 0;
}

bool Compressor :: printOutput(Operation op){
	string o = "";
	o = (op == DECOMPRESSED ? "" : "COM_") + inputFile;
	outstream = ofstream(o, ios::out);
	outstream << data;
}

void Compressor :: deCompressTags(){

}

void Compressor :: decompressRLE(){

}


