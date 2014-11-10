#ifndef _PAIR_H
#define _PAIR_H


class Pair {
public:
	char *key;
	char *value;
	unsigned long int created;
	unsigned long int expires;

public:
	Pair(const char *key, const char *value);
	virtual ~Pair();

	bool operator == (const char *s) const;

	bool equals(const char *s) const;

	virtual bool valid() const;

public:
	void print(const bool pretty = false) const;

private:
	static char *_cloneStr(const char *s);

};


#endif
