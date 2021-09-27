#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>

class TDrob {
private:
	long long dividend;
	long long divider = 1;
public:
	TDrob(long long dividend, long long divider);
	TDrob(long long number);
	TDrob();

	friend TDrob operator+ (TDrob c) {
		return TDrob(c.dividend, c.divider);
	}
	friend TDrob operator- (TDrob c) {
		return TDrob(-c.dividend, c.divider);
	}
	friend TDrob operator+ (TDrob c1, TDrob c2) {
		long long lcm = c1.LCM(c1.divider, c2.divider);
		long long mult1 = lcm / c1.divider;
		long long mult2 = lcm / c2.divider;
		TDrob NewTDrob = TDrob(c1.dividend * mult1 + c2.dividend * mult2, c1.LCM(c1.divider, c2.divider));
		c1.Shrink(NewTDrob);
		return NewTDrob;
	}
	friend TDrob operator- (TDrob c1, TDrob c2) {
		return c1 + (-c2);
	}
	friend TDrob operator* (TDrob c1, TDrob c2) {
		TDrob NewTDrob = TDrob(c1.dividend * c2.dividend, c1.divider * c2.divider);
		c1.Shrink(NewTDrob);
		return NewTDrob;
	}
	friend TDrob operator/ (TDrob c1, TDrob c2) {
		TDrob NewTDrob = TDrob(c1.dividend * c2.divider, c1.divider * c2.dividend);
		c1.Normalize(NewTDrob);
		c1.Shrink(NewTDrob);
		return NewTDrob;
	}

	const TDrob& operator+= (const TDrob& right) {
		*this = *this + right;
		return *this;
	}

	const TDrob& operator-= (const TDrob& right) {
		*this = *this - right;
		return *this;
	}

	const TDrob& operator+= (const long long& right) {
		*this = *this + TDrob(right);
		return *this;
	}

	const TDrob& operator-= (const long long& right) {
		*this = *this - TDrob(right);
		return *this;
	}

	const TDrob& operator*= (const TDrob& right) {
		*this = *this * right;
		return *this;
	}

	const TDrob& operator/= (const TDrob& right) {
		*this = *this / right;
		return *this;
	}

	const TDrob& operator*= (const long long& right) {
		*this = *this * TDrob(right);
		return *this;
	}

	const TDrob& operator/= (const long long& right) {
		*this = *this / TDrob(right);
		return *this;
	}

	TDrob& operator++ () {
		*this += 1;
		return *this;
	}

	TDrob& operator-- () {
		*this -= 1;
		return *this;
	}

	friend bool operator== (const TDrob& left, const TDrob& right) {
		TDrob new1 = left;
		TDrob new2 = right;
		new1.Shrink(new1);
		new1.Shrink(new2);
		if (new1.dividend == new2.dividend && new1.divider == new2.divider) {
			return true;
		}
		else return false;
	}

	friend bool operator== (const TDrob& left, const long long& right) {
		if (left.dividend == right && left.divider == 1) {
			return true;
		}
		else return false;
	}

	friend bool operator== (const long long& left, const TDrob& right) {
		if (left == right.dividend && right.divider == 1) {
			return true;
		}
		else return false;
	}

	friend bool operator!= (const TDrob& left, const TDrob& right) {
		return !(left == right);
	}

	friend bool operator> (const TDrob& left, const TDrob& right) {
		return (left.dividend * right.divider > right.dividend * left.divider);
	}

	friend bool operator< (const TDrob& left, const TDrob& right) {
		return right > left;
	}

	friend bool operator>= (const TDrob& left, const TDrob& right) {
		return (left > right) || (left == right);
	}

	friend bool operator<= (const TDrob& left, const TDrob& right) {
		return (left < right) || (left == right);
	}


	long long GCD(long long a, long long b);
	long long LCM(long long a, long long b);

	void Shrink(TDrob& drob);
	void Normalize(TDrob& drob);

	bool IsZero(const TDrob& drob);

	double ToDouble(const TDrob& drob);

	friend std::istream& operator>> (std::istream& is, TDrob& drob) {
		is >> drob.dividend;
		drob.divider = 1;
		return is;
	}

	friend std::ostream& operator<< (std::ostream& out, const TDrob& drob) {
		if (drob.divider > 1) {
			out << '(' << drob.dividend << '/' << drob.divider << ')';
		}
		else {
			out << drob.dividend;
		}
		return out;
	}

	~TDrob() {};

};

TDrob::TDrob(long long dividend, long long divider) : dividend(dividend), divider(divider) {
}
TDrob::TDrob(long long number) : dividend(number), divider(1) {
}
TDrob::TDrob() : dividend(0), divider(1) {
}



long long TDrob::GCD(long long a, long long b) {
	long long newA = abs(a);
	long long newB = abs(b);
	while (newA != 0 && newB != 0) {
		(newA > newB ? newA %= newB : newB %= newA);
	}
	return newA + newB;
}


long long TDrob::LCM(long long a, long long b) {
	return a / TDrob::GCD(a, b) * b;
}


void TDrob::Shrink(TDrob& drob) {
	long long gcd = TDrob::GCD(drob.dividend, drob.divider);
	drob.dividend /= gcd;
	drob.divider /= gcd;
}

void TDrob::Normalize(TDrob& drob) {
	if (drob.divider < 0) {
		drob.dividend = -drob.dividend;
		drob.divider = -drob.divider;
	}
	if (drob.divider == 0) drob.divider = 1;
}

bool TDrob::IsZero(const TDrob& drob) {
	return (drob.dividend == 0 ? 1 : 0);
}

double TDrob::ToDouble(const TDrob& drob) {
	return (double)(drob.dividend) / drob.divider;
}

using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; ++i) {
		long long p, q, a, b;
		cin >> p >> q >> a >> b;

		long long w = 100 - p;
		long long f = 100 - q;

		TDrob f_ratio = TDrob(q, p);
		TDrob est_ratio = TDrob(f, w);
		long long mult_now = 1;
		TDrob gfdw = f_ratio / TDrob(b);
		TDrob needRatio = gfdw / TDrob(a);
		long long workers = 0;
		if (est_ratio < needRatio) {
			cout << -1 << '\n';
		}
		else if (est_ratio == needRatio && f_ratio != needRatio) {
			cout << -1 << '\n';
		}
		else if (est_ratio == needRatio && f_ratio == needRatio) {
			cout << 0 << '\n';
		}
		else {
			TDrob newRateSum = f_ratio;
			while (newRateSum / TDrob(mult_now) > est_ratio) {
				newRateSum += gfdw;
				mult_now += a;
				workers += 1;
			}
			cout << workers << '\n';
		}

	}

	return 0;

}