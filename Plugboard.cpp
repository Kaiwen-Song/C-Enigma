#include "plugboard.h"

PlugBoard::PlugBoard(){
	defaultConfig = true;
	for(int i = 0; i<26; i++){
		configuration[i] = i;
	}
}

void PlugBoard::configure(char* fileDir){

	ifstream* conFILE;
	bool isConfigured;
	conFILE = fopen(fileDir, "r");
	int config[26];
	int index=0;
	if(conFILE == NULL){
		perror("error printing files");
		defaultConfig = true;
	} else {
		while(conFILE.good()){
			configuration[index] << conFILE.get();
		}
		defaultConfig = false;
		for(int i = 0; i< 26; i++){
		map[i] = configurations.indexOf(i);
			}

	}
	}

int PlugBoard::output(int input){
	if(defaultConfig)return input;
	else return fmap[input];
}

int PlugBoard::outputBack(int input){
	if(defaultConfig) return input;
	else return bmap[input];
}