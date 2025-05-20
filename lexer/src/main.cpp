#include<iostream>
#include<fstream>
#include<sstream>
#include<optional>
#include<vector>

enum class TokenType{
	RETURN,
	INT_LIT,
	SEMI,
};

struct Token{
	TokenType type;
	std::optional<std::string> value;

};

std::vector<Token> tokenize(const std::string& str){
	std::vector<Token> tokens;
	std::string buf ;
	for (int i=0; i<str.length(); i++){
		char c = str.at(i);
		if(std::isalpha(c)){
			buf.push_back(c);
			i++;
			
			while(std::isalnum(str.at(i))){
			
				buf.push_back(str.at(i));
				i++;
			}
			i--;

			if(buf == "return"){
				tokens.push_back({.type=TokenType::RETURN});
			}
			else{
				std::cerr << "messed up" << std::endl;
			}
		}
	}

	return tokens;
} 

int main(int argc, char* argv[]){
	
	if(argc < 2){
		std::cerr << "Invalid usage." << std::endl;
		std::cerr << "Syntax : work <file.work>" << std::endl;
		return EXIT_FAILURE;
	}
	
	//std::cout << argv[1] << std::endl;
	std::string contents;
	{
		std::stringstream content_stream;
		std::fstream input(argv[1], std::ios::in);
		content_stream << input.rdbuf();
		contents = content_stream.str();
	}
	
	//std::cout << contents << std::endl;
	std::vector<Token> return_val = tokenize(contents);

	std::cout << return_val << std::endl;	

	

	return EXIT_SUCCESS;

}
