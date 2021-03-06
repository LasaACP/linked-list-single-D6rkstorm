//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath> 
#include <stdlib.h>
#include "slist.h"

using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
    
};

void SimpleSortTotal(Airport* s[], int airportCount);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    Airport* airportArr[13500];
    int   airportCount;
    
    infile.open ("./USAirportCodes.csv", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            airportArr[c] = new Airport();
            infile.getline(airportArr[c]->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airportArr[c]->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airportArr[c]->latitude = atof(cNum);

            //if (!(c % 1000))
                //cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;

            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                               
            }
            */

            
            i++ ;
            c++;
        }

       


        cout << c << endl;
        airportCount = c-1;
        infile.close();
        
        /* for (int c=0; c < airportCount; c++)
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << " long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;
                cout <<"Distance between " << airportArr[c]->code << " and " << airportArr[c+1]->code << " is "
                  << distanceEarth( airportArr[c]->longitude, airportArr[c]->latitude , airportArr[c+1]->longitude, airportArr[c+1]->latitude) << endl;
            }*/




    }
    else
    {
        cout << "Error opening file";
    }
 

    string ausCode = airportArr[10656]->code;
    double ausLat = airportArr[10656]->latitude;
    double ausLong = airportArr[10656]->longitude;
    SimpleSortTotal(airportArr, airportCount);
    cout << airportArr[13428]->code << endl;
    cout << distanceEarth(airportArr[13428]->latitude, airportArr[13428]->longitude, ausLat, ausLong) << endl;
    
   // Initialize Linked List
  // List<Airport> X;
      // 
    ofstream output;
    output.open("sorted.csv");
    Airport* a;
    string write;
    for(int z = 0; z < airportCount; z++)
    {
      a = airportArr[z];
      output << "" << a->code << "," << distanceEarth(a->latitude, a->longitude, ausLat, ausLong) << "\n";
    }
    
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}



void SimpleSortTotal(Airport* aus[], int airportCount)
{
  Airport* temp;
  int ausLat = aus[10656]->latitude;
  int ausLong = aus[10656]->longitude;
  for(int i = 0; i < airportCount; i++ )
  {
    for(int j = 0; j < i; j++)
    {
      if(distanceEarth(ausLat, ausLong, aus[i]->latitude, aus[i]->longitude) < distanceEarth(ausLat, ausLong, aus[j]->latitude, aus[j]->longitude))
      {
        temp = aus[j];
        aus[j] = aus[i];
        aus[i] = temp;
      }
    }
  }
}