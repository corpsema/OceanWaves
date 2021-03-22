#include <iostream>

#include <iomanip>

#include <cctype>

#include <string>

#include <ctime>

#include <cstdlib>

#include <fstream>

using namespace std;

const int Size=50;

const int Year = 2;

struct waveStorge

{

	int year;

	int month;

	int day;

	int hour;

	int minute;

	double waveHeight;

	double waveLength;

};

int main ()

{

		double waveSteepness[Size], avSteepness[Year], totalSteepness[Year], steepestWave[Year];

		int count[Year], waveInfo[Year];

		waveStorge waveData[Size];

		ifstream wavesNumbers;

		wavesNumbers.open ("waveData.txt");

		ofstream waveExceedingLimit;

		waveExceedingLimit.open("wavesExceedingValue.txt");


			for (int i = 0; i < Size; i++)

		{

			wavesNumbers >> waveData[i].year >> waveData[i].month>> waveData[i].day >> waveData[i].hour >> waveData[i].minute >> waveData[i].waveHeight >> waveData[i].waveLength;

		}

			for (int j = 0; j < Size; j++)

		{

		count[j] = 0;

		waveSteepness[j] = (waveData[j].waveHeight / waveData[j].waveLength);

			if (waveSteepness[j] >= (1/7))

		{

			waveExceedingLimit << waveSteepness[j] << endl;

		}


			if (waveData[j].year == 2010)

		{

			count[0]++;

			totalSteepness[0] += (waveSteepness[j]);

			avSteepness[0]= totalSteepness[0]/count[0];

				if (waveSteepness[j] > steepestWave[0])

			{

				steepestWave[0] = waveSteepness[j];
				waveInfo[0] = j;
			
			}

		}

			if (waveData[j].year == 2011)

		{

			count[1]++;

			totalSteepness[1] += (waveSteepness[j]);

			avSteepness[1]= totalSteepness[1]/count[1];

				if (waveSteepness[j] > steepestWave[1])

			{

				steepestWave[1] = waveSteepness[j];
				waveInfo[1] = j;

			}

		}

			if (waveData[j].year == 2012)

		{

			count[2]++;

			totalSteepness[2] += (waveSteepness[j]);

			avSteepness[2]= totalSteepness[2]/count[2];

				if (waveSteepness[j] > steepestWave[2])

				{

					steepestWave[2] = waveSteepness[j];
					waveInfo[2] = j;

				}

		}

}

cout <<fixed<< setprecision(3) << "the steepest wave in 2010 was " << steepestWave[0] <<endl<< " and the average steepness was " << avSteepness[0]<< endl << " all the info at that point is, at day: " << waveData[waveInfo[0]].day << " at month: "<< waveData[waveInfo[0]].month << " at time: " << waveData[waveInfo[0]].hour<< ":"<<  waveData[waveInfo[0]].minute <<endl<< " the wave height is " <<  waveData[waveInfo[0]].waveHeight << " the wave length is: " <<  waveData[waveInfo[0]].waveLength;

cout << fixed<< setprecision(3) <<  "the steepest wave in 2011 was " << steepestWave[1] <<endl<< " and the average steepness was " << avSteepness[1]<< endl<< " all the info at that point is, at day: " << waveData[waveInfo[1]].day << " at month: "<< waveData[waveInfo[1]].month << " at time: " << waveData[waveInfo[1]].hour<< ":"<<  waveData[waveInfo[1]].minute << endl<<" the wave height is " <<waveData[waveInfo[1]].waveHeight << " the wave length is: " <<  waveData[waveInfo[1]].waveLength;;

cout << fixed<< setprecision(3)<< "the steepest wave in 2012 was " << steepestWave[2] << endl<<" and the average steepness was " << avSteepness[2]<< endl<< " all the info at that point is, at day: " << waveData[waveInfo[2]].day << " at month: "<< waveData[waveInfo[2]].month << " at time: " << waveData[waveInfo[2]].hour<< ":"<<  waveData[waveInfo[2]].minute <<endl<< " the wave height is " << waveData[waveInfo[2]].waveHeight << " the wave length is: " <<  waveData[waveInfo[2]].waveLength;;

wavesNumbers.close ();

waveExceedingLimit.close();

cin.get();

cin.get();

	return 0;

}
