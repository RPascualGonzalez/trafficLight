// we will create a traffic light with three threads

#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;


void trafficLightCount (string name);
void AskValuesTrafficLight ();
void StartTrafficLight ();
void ControlTrafficLightFlags (string name);
void UpdateTrafficLight (string name);
int CalculateThreadIdentifier (string name);

int finalValue;
int initialValue;
int stepValue;
int numSteps;
int actualValue;
bool TraffickLightFlags[3] = { false, true, false };
bool lastValuePrinted { false };




int main()
{
	AskValuesTrafficLight();
	StartTrafficLight();
}

// ----------------------------------------
void AskValuesTrafficLight()
// ----------------------------------------
{
	cout << "Write  Initial value: \n";
	cin >> initialValue;
	cout << "Write  Final value: \n";
	cin >> finalValue;
	cout << "Write  Step value: \n";
	cin >> stepValue;
	cout << "Write  number of steps per thread: \n";
	cin >> numSteps;
	cout << "-------------------------- \n";
	actualValue = initialValue;
}

// ----------------------------------------
void StartTrafficLight()
// ----------------------------------------
{
	thread threadGreen(trafficLightCount, "Green");
	thread threadRed(trafficLightCount, "Red");
	thread threadOrange(trafficLightCount, "Orange");
	
	threadGreen.join();
	threadRed.join();
	threadOrange.join();
	
}

// ----------------------------------------
void trafficLightCount(string name)
// ----------------------------------------
{
	while (actualValue < finalValue)
	{
		ControlTrafficLightFlags(name);
		int stepFinalValue = actualValue + (numSteps * stepValue);
		if (stepFinalValue > finalValue) stepFinalValue = finalValue;

		for (; actualValue <= stepFinalValue; actualValue = actualValue + stepValue)
		{
			cout << actualValue << " name: " << name << "\n";
		}
		if ( finalValue < actualValue )
		{
			if (not lastValuePrinted and actualValue < (finalValue + stepValue)) {
				cout << finalValue << " name: " << name << "\n";
				lastValuePrinted = true;
			}
		}
		cout << "---------- \n";
		UpdateTrafficLight(name);
	}
	
}

// ----------------------------------------
void ControlTrafficLightFlags(string name)
// ----------------------------------------
{
	int threadIdentifier = CalculateThreadIdentifier(name);

	while (not TraffickLightFlags [threadIdentifier])
	{
		Sleep(10);
	}
}

// ----------------------------------------
void UpdateTrafficLight(string name)
// ----------------------------------------
{
	int threadIdentifier = CalculateThreadIdentifier(name);
	TraffickLightFlags[threadIdentifier] = false;
	if (threadIdentifier == 2)
	{
		TraffickLightFlags[0] = true;
	}
	else {
		TraffickLightFlags[threadIdentifier + 1] = true;
	}
}

// ----------------------------------------
int CalculateThreadIdentifier(string name)
// ----------------------------------------
{
	int result = 0;
	if (name == "Green") result = 0;
	else if (name == "Red") result = 1;
	else if (name == "Orange") result = 2;

	return result;
}

