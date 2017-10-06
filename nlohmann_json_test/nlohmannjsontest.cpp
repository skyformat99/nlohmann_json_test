// nlohmannjsontest.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <string>

#include "../json/src/json.hpp"
#include "custom_allocator.h"

int main()
{
	tmp::string str =	
	"{"
		"\"glossary\": "
			"{"
				"\"title\": \"example glossary\","
				"\"GlossDiv\" : "
					"{"
						"\"title\": \"S\","
						"\"GlossList\" : "
							"{"
								"\"GlossEntry\": "
									"{"
										"\"ID\": \"SGML\","
										"\"SortAs\" : \"SGML\","
										"\"GlossTerm\" : \"Standard Generalized Markup Language\","
										"\"Acronym\" : \"SGML\","
										"\"Abbrev\" : \"ISO 8879:1986\","
										"\"GlossDef\" : "
											"{"
												"\"para\": \"A meta-markup language, used to create markup languages such as DocBook.\","
												"\"GlossSeeAlso\" : [\"GML\", \"XML\"]"
											"},"
										"\"GlossSee\" : \"markup\""
									"}"
							"}"
					"}"
			"}"
	"}";

	tmp::json json;
	json.parse(str);
    return 0;
}

