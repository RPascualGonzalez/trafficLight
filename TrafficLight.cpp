// we will create a traffic light with three threads

#include <iostream>
#include <thread>

using namespace std;


void trafficLight(string name);

int finalValue;
int initialValue;
int stepValue;
int numSteps;
int actualValue;

void AskValuesTrafficLight();
void StartTrafficLight();

bool TraffickLightFlags[3] = { true, false, false };

int main()
{
	AskValuesTrafficLight();
	StartTrafficLight();
}

// ----------------------------------------
void AskValuesTrafficLight()
// ----------------------------------------
{
	finalValue = 5000;
	initialValue = 0;
	stepValue = 20;
	numSteps = 10;
	actualValue = 0;
}

// ----------------------------------------
void StartTrafficLight()
// ----------------------------------------
{
	thread threadGreen(trafficLight, "Green");
	thread threadRed(trafficLight, "Red");
	thread threadOrange(trafficLight, "Orange");

	threadGreen.join();
	threadRed.join();
	threadOrange.join();
}

// ----------------------------------------
void trafficLight(string name)
// ----------------------------------------
{
	for (int value = initialValue; value < 1000; value = value + stepValue)
	{
		cout << name << "\n";
	}

}


