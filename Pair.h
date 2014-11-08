#ifndef _PAIR_H_
#define _PAIR_H_


class Pair {
public:
	char *key;
	char *value;

public:
	Pair(const char *key, const char *value);
	virtual ~Pair();

	int operator == (const char *s);

	int equals(const char *s);

private:
	static char *cloneStr(const char *s);
};


#endif
