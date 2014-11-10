#ifndef _PAIR_H_
#define _PAIR_H_


class Pair {
public:
	char *key;
	char *value;
	unsigned long int created;
	unsigned long int expires;

public:
	Pair(const char *key, const char *value, unsigned long int expires = 0);
	virtual ~Pair();

	bool operator == (const char *s);

	bool equals(const char *s);

	bool valid();

	bool expired();

public:
	void print(const bool pretty = false);

private:
	static char *_cloneStr(const char *s);
	static unsigned long int _now();

};


#endif
