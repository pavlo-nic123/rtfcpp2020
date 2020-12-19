#include "physix.h"

int main()
{
	Ivalue i; Rvalue r; Uvalue u; Qvalue q; Tvalue t; Cvalue c;

	i.set(2); r.set(3);
	u = r * i;
	cout << u << endl;
	i.zero(); r.zero(); u.zero();

	u.set(2.5); r.set(3.5);
	i = u / r;
	cout << i << endl;
	i.zero(); r.zero(); u.zero();

	Rvalue r1(1.2), r2(2.2);
	cout << r1 + r2 << endl;
	cout << r1 % r2 << endl;

	c.set(0.00001); r.set(200000); u.set(1); t.set(0);

	i = u / r;
	for (; t.getT() < 2.1; t.set(t.getT() + 0.1))
	{

		q = t * i;
		cout << t << ",\t" << q << endl;
	}

	return 0;
}