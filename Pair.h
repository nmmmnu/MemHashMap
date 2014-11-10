#ifndef _PAIR_H_
#define _PAIR_H_


class Pair {
public:
	char *key;
	char *value;

public:
	Pair(const char *key, const char *value);
	virtual ~Pair();

	bool operator == (const char *s);

	bool equals(const char *s);

	int valid();

public:
	void print(const bool pretty = false);

private:
	static char *_cloneStr(const char *s);
};


#endif
