#pragma once
#include <iostream>

using namespace std;

class Ivalue;
class Uvalue;
class Rvalue;
class Qvalue;
class Tvalue;
class Cvalue;

class Ivalue {
	float i = 0;//value
public:
	Ivalue() {};//standart construct
	Ivalue(float val) { i = val; };//modified construct
	void zero() { i = 0; };//reset value
	void set(float val) { i = val; };//set value
	float getI() const { return i; };//show value
	Uvalue operator* (const Rvalue& r);
	Rvalue operator/ (const Uvalue& u);
	Qvalue operator* (const Tvalue& t);
	Tvalue operator* (const Qvalue& q);
};

class Uvalue {
	float u = 0;
public:
	Uvalue() {};
	Uvalue(float val) { u = val; };
	void zero() { u = 0; };
	void set(float val) { u = val; };
	float getU() const { return u; };
	Ivalue operator/ (const Rvalue& r);
	Rvalue operator/ (const Ivalue& i);
	Cvalue operator/ (const Qvalue& q);
	Qvalue operator* (const Cvalue& c);
};

class Rvalue {
	float r = 0;
public:
	Rvalue() {};
	Rvalue(float val) { r = val; };
	void zero() { r = 0; };
	void set(float val) { r = val; };
	float getR() const { return r; };
	Ivalue operator/ (const Uvalue& u);
	Uvalue operator* (const Ivalue& i);

	Rvalue operator+ (const Rvalue& r);
	Rvalue operator% (const Rvalue& r);
};


class Qvalue {
	float q = 0;
public:
	Qvalue() {};
	Qvalue(float val) { q = val; };
	void zero() { q = 0; };
	void set(float val) { q = val; };
	float getQ() const { return q; };
	Ivalue operator/ (const Tvalue& t);
	Tvalue operator/ (const Ivalue& i);
	Cvalue operator/ (const Uvalue& u);
	Uvalue operator/ (const Cvalue& c);
};


class Tvalue {
	float t = 0;
public:
	Tvalue() {};
	Tvalue(float val) { t = val; };
	void zero() { t = 0; };
	void set(float val) { t = val; };
	float getT() const { return t; };
	Ivalue operator/ (const Qvalue& q);
	Qvalue operator* (const Ivalue& i);
};

class Cvalue {
	float c = 0;
public:
	Cvalue() {};
	Cvalue(float val) { c = val; };
	void zero() { c = 0; };
	void set(float val) { c = val; };
	float getC() const { return c; };
	Uvalue operator* (const Qvalue& q);
	Qvalue operator* (const Uvalue& u);

	Cvalue operator+ (const Cvalue& c);
	Cvalue operator% (const Cvalue& c);
};

//output overload dec.
ostream& operator<< (ostream& out, const Ivalue& val);
ostream& operator<< (ostream& out, const Uvalue& val);
ostream& operator<< (ostream& out, const Rvalue& val);
ostream& operator<< (ostream& out, const Qvalue& val);
ostream& operator<< (ostream& out, const Tvalue& val);
ostream& operator<< (ostream& out, const Cvalue& val);