#ifndef REGEX
#define REGEX
#endif

class Regex {
	string re;
public:
	Regex(string regex) {
		re = regex;
	}

	string get_regular_expression() {
		return re;
	}
};
