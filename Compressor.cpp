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
