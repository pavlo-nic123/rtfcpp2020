#include "physix.h"

//arith overload

//Ivalue
Uvalue Ivalue:: operator* (const Rvalue& r) { return Uvalue(r.getR() * i); };
Rvalue Ivalue:: operator/ (const Uvalue& u) { return Rvalue(i / u.getU()); };
Qvalue Ivalue:: operator* (const Tvalue& t) { return Qvalue(t.getT() * i); };
Tvalue Ivalue:: operator* (const Qvalue& q) { return Tvalue(i / q.getQ()); };

//Uvalue
Ivalue Uvalue:: operator/ (const Rvalue& r) { return Ivalue(u / r.getR()); };
Rvalue Uvalue:: operator/ (const Ivalue& i) { return Rvalue(u / i.getI()); };
Cvalue Uvalue:: operator/ (const Qvalue& q) { return Cvalue(q.getQ() / u); };
Qvalue Uvalue:: operator* (const Cvalue& c) { return Qvalue(c.getC() * u); };

//Rvalue
Ivalue Rvalue:: operator/ (const Uvalue& u) { return Ivalue(u.getU() / r); };
Uvalue Rvalue:: operator* (const Ivalue& i) { return Uvalue(i.getI() * r); };

Rvalue Rvalue:: operator+ (const Rvalue& r_) { return Rvalue(r_.getR() + r); }; // sequently r = r1+r2
Rvalue Rvalue:: operator% (const Rvalue& r_) { return Rvalue((r_.getR() + r) / (r_.getR() * r)); };// parallel r = (r1+r2)/(r1*r2)

//Qvalue
Ivalue Qvalue:: operator/ (const Tvalue& t) { return Ivalue(q / t.getT()); };
Tvalue Qvalue:: operator/ (const Ivalue& i) { return Tvalue(q / i.getI()); };
Cvalue Qvalue:: operator/ (const Uvalue& u) { return Cvalue(q / u.getU()); };
Uvalue Qvalue:: operator/ (const Cvalue& c) { return Uvalue(q / c.getC()); };

//Tvalue
Ivalue Tvalue:: operator/ (const Qvalue& q) { return Ivalue(q.getQ() / t); };
Qvalue Tvalue:: operator* (const Ivalue& i) { return Qvalue(t * i.getI()); };

//Cvalue
Uvalue Cvalue:: operator* (const Qvalue& q) { return Uvalue(q.getQ() / c); };
Qvalue Cvalue:: operator* (const Uvalue& u) { return Qvalue(c / u.getU()); };

Cvalue Cvalue:: operator+ (const Cvalue& a) { return Cvalue(a.getC() + c); };// sequently c = c1+c2
Cvalue Cvalue:: operator% (const Cvalue& a) { return Cvalue((a.getC() + c) / (a.getC() * c)); };// parallel r = (c1+c2)/(c1*c2)


//output overload
ostream& operator<< (ostream& out, const Ivalue& val)
{
	out << val.getI() << " A";
	return out;
};

ostream& operator<< (ostream& out, const Uvalue& val)
{
	out << val.getU() << " V";
	return out;
};

ostream& operator<< (ostream& out, const Rvalue& val)
{
	out << val.getR() << " Ohm";
	return out;
};

ostream& operator<< (ostream& out, const Qvalue& val)
{
	out << val.getQ() << " Kl";
	return out;
};

ostream& operator<< (ostream& out, const Tvalue& val)
{
	out << val.getT() << " sec";
	return out;
};

ostream& operator<< (ostream& out, const Cvalue& val)
{
	out << val.getC() << " F";
	return out;
};