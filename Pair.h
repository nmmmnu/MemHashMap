#ifndef _PAIR_H
#define _PAIR_H


class Pair {
protected:
	char *key;
	char *value;

public:
	Pair(const char *key, const char *value);
	virtual ~Pair();

	const char *getKey() const;
	const char *getValue() const;

	bool operator == (const char *s) const;

	bool equals(const char *s) const;

	virtual bool valid() const;

public:
	void print(const bool pretty = false) const;

private:
	static char *_cloneStr(const char *s);

};


#endif
