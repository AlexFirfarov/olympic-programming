#include <algorithm>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

namespace NBigInt {

	class TBigInt {

		static const long long number_base = 10'000'000;
		static const size_t number_size = 7;

		std::vector<long long> numbers;

		long long getDigit(size_t i) const {
			if (i < numbers.size()) {
				return numbers[i];
			}
			else {
				return 0;
			}
		}

		void removeZeros() {
			size_t remover = numbers.size();
			for (size_t i = numbers.size() - 1; i != 0; --i) {
				if (numbers[i] != 0) break;
				remover = i;
			}
			numbers.resize(remover);
			if (numbers.empty()) numbers.push_back(0);
		}

	public:
		TBigInt();
		TBigInt(const TBigInt&) = default;

		TBigInt(long long num) {
			while (num > 0) {
				numbers.push_back(num % number_base);
				num /= number_base;
			}
			if (numbers.empty()) numbers.push_back(0);
		}

		bool Odd() const {
			return TBigInt::numbers[0] % 2;
		}

		TBigInt& operator=(const TBigInt&) = default;

		const TBigInt& operator+=(const TBigInt&);
		friend TBigInt operator+(const TBigInt&, const TBigInt&);

		const TBigInt& operator-=(const TBigInt&);
		friend TBigInt operator-(const TBigInt&, const TBigInt&);

		const TBigInt& operator*=(const TBigInt&);
		friend TBigInt operator*(const TBigInt&, const TBigInt&);

		const TBigInt& operator/=(const TBigInt&);
		friend TBigInt operator/(const TBigInt&, const TBigInt&);

		friend bool operator==(const TBigInt&, const TBigInt&);
		friend bool operator<(const TBigInt&, const TBigInt&);
		friend bool operator<=(const TBigInt&, const TBigInt&);
		friend bool operator>(const TBigInt&, const TBigInt&);

		operator bool() const {
			if ((TBigInt::numbers.size() > 1) || (TBigInt::numbers[0] > 0)) return true;
			return false;
		}

		friend std::istream& operator>>(std::istream&, TBigInt&);
		friend std::ostream& operator<<(std::ostream&, const TBigInt&);

		~TBigInt() = default;
	};

	TBigInt Pow(TBigInt, TBigInt);

}

namespace NBigInt {
	TBigInt::TBigInt() : numbers{ 0 } {}


	const TBigInt& TBigInt::operator+=(const TBigInt& rhs) {
		return ((*this) = ((*this) + rhs));
	}

	TBigInt operator+(const TBigInt& lhs, const TBigInt& rhs) {
		TBigInt result = lhs;
		if (rhs.numbers.size() > result.numbers.size()) {
			result.numbers.resize(rhs.numbers.size());
		}

		bool ost = 0;

		for (size_t i = 0; i < result.numbers.size(); ++i) {
			result.numbers[i] += (rhs.getDigit(i) + ost);

			if (result.numbers[i] >= TBigInt::number_base) {
				ost = 1;
			}
			else {
				ost = 0;
			}

			if (ost) {
				result.numbers[i] -= TBigInt::number_base;
			}
			else if (i >= rhs.numbers.size())
				break;
		}

		if (ost) result.numbers.push_back(1);

		return result;
	}


	const TBigInt& TBigInt::operator-=(const TBigInt& rhs) {
		return ((*this) = ((*this) - rhs));
	}

	TBigInt operator-(const TBigInt& lhs, const TBigInt& rhs) {
		TBigInt result = lhs;
		if (rhs > lhs) {
			throw std::invalid_argument("rhs > lhs");
		}

		bool ost = 0;

		for (size_t i = 0; i < result.numbers.size(); ++i) {
			result.numbers[i] -= (rhs.getDigit(i) + ost);

			if (result.numbers[i] < 0) {
				ost = 1;
			}
			else {
				ost = 0;
			}

			if (ost) {
				result.numbers[i] += TBigInt::number_base;
			}
			else if (i >= rhs.numbers.size())
				break;
		}
		result.removeZeros();
		return result;
	}

	const TBigInt& TBigInt::operator*=(const TBigInt& rhs) {
		return ((*this) = ((*this) * rhs));
	}


	TBigInt operator*(const TBigInt& lhs, const TBigInt& rhs) {
		size_t lhs_size = lhs.numbers.size();
		size_t rhs_size = rhs.numbers.size();

		TBigInt result;
		result.numbers.resize(lhs_size + rhs_size);

		for (size_t i = 0; i < lhs_size; ++i) {
			int ost = 0;
			for (size_t j = 0; j < rhs_size || ost; ++j) {
				result.numbers[i + j] += lhs.numbers[i] * rhs.getDigit(j) + ost;
				ost = result.numbers[i + j] / TBigInt::number_base;
				result.numbers[i + j] -= (ost * TBigInt::number_base);
			}
		}

		result.removeZeros();

		return result;
	}

	const TBigInt& TBigInt::operator/=(const TBigInt& rhs) {
		return ((*this) = ((*this) / rhs));
	}


	TBigInt operator/(const TBigInt& lhs, const TBigInt& rhs) {
		if (rhs == TBigInt(0)) {
			throw std::invalid_argument("Div 0");
		}
		size_t lhs_size = lhs.numbers.size();

		TBigInt res;
		res.numbers.resize(lhs_size);

		TBigInt cur;
		for (size_t i = lhs_size - 1; i + 1 > 0; --i) {
			cur.numbers.insert(cur.numbers.begin(), lhs.numbers[i]);
			if (!cur.numbers.back()) cur.numbers.pop_back();

			long long digit = 0, low = 0, high = TBigInt::number_base;

			while (low <= high) {
				long long middle = (low + high) / 2;
				TBigInt tmp(rhs * TBigInt(middle));
				if (tmp <= cur) {
					digit = middle;
					low = middle + 1;
				}
				else {
					high = middle - 1;
				}
			}

			res.numbers[i] = digit;
			cur -= (rhs * TBigInt(digit));
		}

		res.removeZeros();

		return res;
	}

	bool operator==(const TBigInt& lhs, const TBigInt& rhs) {
		return lhs.numbers == rhs.numbers;
	}

	bool operator<(const TBigInt& lhs, const TBigInt& rhs) {
		if (lhs.numbers.size() != rhs.numbers.size()) {
			return lhs.numbers.size() < rhs.numbers.size();
		}
		return std::lexicographical_compare(lhs.numbers.rbegin(), lhs.numbers.rend(),
			rhs.numbers.rbegin(), rhs.numbers.rend());
	}

	bool operator<=(const TBigInt& lhs, const TBigInt& rhs) {
		return (lhs < rhs) || (lhs == rhs);
	}

	bool operator>(const TBigInt& lhs, const TBigInt& rhs) {
		return !(lhs <= rhs);
	}

	std::istream& operator>>(std::istream& is, TBigInt& obj) {
		std::istream::sentry check(is);
		if (check) {
			using input_iterator = std::istreambuf_iterator<char>;

			obj.numbers.clear();

			input_iterator it(is), eos;
			bool lead_zero_flag = true;

			std::stack<char> decimal_digits;

			while (it != eos && (!isspace(*it))) {
				if ((*it) <= '9' && (*it) >= '0') {
					if (!(lead_zero_flag && *it == '0')) {
						decimal_digits.push(*it);
						lead_zero_flag = false;
					}
				}
				else {
					is.setstate(std::ios::failbit);
					break;
				}
				++it;
			}

			std::stack<char> digit_stack;

			while (!decimal_digits.empty()) {
				digit_stack.push(decimal_digits.top());

				if (digit_stack.size() == TBigInt::number_size) {
					long long digit = 0;
					while (!digit_stack.empty()) {
						digit *= 10;
						digit += (long long)(digit_stack.top() - '0');
						digit_stack.pop();
					}
					obj.numbers.push_back(digit);
				}

				decimal_digits.pop();
			}

			if (!digit_stack.empty()) {
				long long digit = 0;
				while (!digit_stack.empty()) {
					digit *= 10;
					digit += (long long)(digit_stack.top() - '0');
					digit_stack.pop();
				}
				obj.numbers.push_back(digit);
			}
			if (lead_zero_flag) obj.numbers = { 0 };
		}
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const TBigInt& obj) {
		for (auto it = obj.numbers.rbegin(); it != obj.numbers.rend(); ++it) {
			if (it != obj.numbers.rbegin()) {
				os << std::setw(TBigInt::number_size) << std::setfill('0');
			}
			os << *it;
		}
		return os;
	}

	TBigInt Pow(TBigInt num, TBigInt power) {
		if ((num == TBigInt(0)) && (power == TBigInt(0))) {
			throw std::invalid_argument("0 ^ 0");
		}
		TBigInt result(1);
		while (power) {
			if (power.Odd()) {
				result *= num;
			}
			num *= num;
			power /= TBigInt(2);
		}
		return result;
	}

}

using BigInt = NBigInt::TBigInt;

BigInt moda = 998244353;

using namespace std;

int main() {
	BigInt n;
	cin >> n;


	BigInt f = n / moda;

	n = n - (f * moda);

	cout << n;

}