class Solution {
public:
	vector<double> convertTemperature(double celsius) {
		double Kelvin = celsius + 273.15;
		double Fahrenheit = celsius * 1.8 + 32;

		return vector<double>({ Kelvin, Fahrenheit });
	}
};