#include "Lab2.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int num; 
		string trash; 

		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		out << "------------ ---------- --------" << endl;

		while (!in.eof()) {
			in >> num;

			if (in.fail()) {
				in.clear();
				in >> trash;
				continue;
			}

			out << setw(12) << right << oct << uppercase << num;
			out << setw(11) << right << dec << uppercase << num;
			out << setw(9) << right << hex << uppercase << num;
			out << endl;
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float num;
		float max = -std::numeric_limits<float>::max();
		string trash; 



		while (!in.eof()) {
			in >> num;
			
			if (in.fail()) {
				in.clear();
				in >> trash;
				continue;
			}

			if (max < num) {
				max = num;
			}

			out << "     " << setw(15) << showpos << internal << showpoint << setprecision(3) << fixed << num << endl;
		}

		out << "max: " << setw(15) << showpos << internal << showpoint << setprecision(3) << fixed << max  << endl;
	}
}