//
//  JSONParser.hpp
//  arquitectura
//
//  Created by Catherine Castrillo González on 19/02/17.
//  Copyright © 2017 Stoycho Ivanov Atanasov. All rights reserved.
//

#ifndef JSONParser_hpp
#define JSONParser_hpp

#include <fstream>
#include <map>
#include <JSON/json.hpp>

using json = nlohmann::json;

class JSONParser {
public:
    static void guardar(const char* filename, std::map<char*, char*> valores);
    static std::map<std::string, std::string> leer(const char* filename);
	static bool toBool(std::string s);
	static int toInt(std::string s);
};
#endif /* JSONParser_hpp */
