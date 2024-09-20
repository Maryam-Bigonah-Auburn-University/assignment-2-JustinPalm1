#include <iostream>;
#include <iomanip>;

using namespace std;

double convertToMPH(int minutes, int seconds);
double convertToMPH(double kph);

int main() {
	int minutes = 0,
	    seconds = 0;
	double kph = 0.0;

// Prompt the user to enter running pace in minutes and seconds
    cout << "Enter your running pace (minutes and seconds): " << endl;
    cout << "Minutes: ";
    cin >> minutes;
    cout << "Seconds: ";
    cin >> seconds;

// Convert pace to miles per hour
    double mphFromPace = convertToMPH(minutes, seconds);
    cout << fixed << setprecision(2); // Set precision for output
    cout << "Your pace in miles per hour is: " << mphFromPace << " MPH" << endl;

// Prompt the user to enter speed in kilometers per hour
    cout << "Enter your speed in kilometers per hour: ";
    cin >> kph;

// Convert speed to miles per hour
    double mphFromKPH = convertToMPH(kph);
    cout << "Your speed in miles per hour is: " << mphFromKPH << " MPH" << endl;

	return 0;
}

double convertToMPH(int minutes, int seconds) {
	// There are 3600 seconds in an hour
	return (3600.0 / ((minutes * 60) + seconds));
}

double convertToMPH(double kph) {
	return (kph / 1.61);
}
