#include <iostream>
#include <string>

using namespace std;

#include "regex.h"

/*
 * Currently supports matching of:
 * '+': Matches one or more of the previous element
 * '*': Matches zero or more of the previous element
 * 'a': Matches 'a' with exactly one 'a'
 * */
class RegularExpressionMatcher {
private:
	bool validate_string(string);
	bool matches(string&, string&, int, int);
public:
	bool regex_matches(string, Regex);
};

bool RegularExpressionMatcher::validate_string(string s) {
	return true;
}

bool RegularExpressionMatcher::regex_matches(string s, Regex regex) {
	string re = regex.get_regular_expression();

	if(!validate_string(s) || !validate_string(re)) {
		return false;
	}
	
	int slen = s.length();
	int relen = re.length();

	if(relen == 0) {
		return true;
	}

	if(slen == 0) {
		return false;
	}

	return matches(s, re, 0, 0);
}

bool RegularExpressionMatcher::matches(string &s, string& re, int i, int j) {
	int slen = s.length();
	int relen = re.length();

	if(i == slen && j == relen) {
		return true;
	}

	if(i > slen || j > relen) {
		return false;
	}

	if(j+1 < relen && re[j+1] == '*') {
		if(s[i] == re[j]) {
			return matches(s, re, i, j+2) || matches(s, re, i+1, j);
		}
		return matches(s, re, i, j+2);
	}

	if(j+1 < relen && re[j+1] == '+') {
		if(s[i] == re[j]) {
			return matches(s, re, i+1, j) || matches(s, re, i+1, j+2);
		}
		return false;
	}

	if(s[i] == re[j]) {
		return matches(s, re, i+1, j+1);
	}

	return false;
}

int main(int argc, char **argv) {
	return 0;
}
