// Small example of using the GeographicLib::Geodesic class

#include <iostream>
#include <format>
#include <GeographicLib/Geodesic.hpp>
#include <GeographicLib/Geoid.hpp>

#include <GeographicLib/MagneticModel.hpp>


using namespace std;
using namespace GeographicLib;

int main() {
  const Geodesic& geod = Geodesic::WGS84();
  // Distance from JFK to LHR
  double
    lat1 = 40.6, lon1 = -73.8, // JFK Airport
    lat2 = 51.6, lon2 = -0.5;  // LHR Airport
  double s12;
  geod.Inverse(lat1, lon1, lat2, lon2, s12);
  cout << s12 / 1000 << " km\n";



  GeographicLib::Geoid g("egm2008-1","C:\\source\\Geographic-Library-Test\\runFolder");
  double lat=45.5, lon=-75.5;
  
    for (lon = -70.0; lon < 80.0; lon += 1)
          std::cout << "lat: " << lat<< " Lon: "<< lon << " MagVar: " << g(lat, lon) << "\n";
  

    //test with https://www.ngdc.noaa.gov/geomag/calculators/magcalc.shtml

    try 
    {
        MagneticModel mag("wmm2025", "C:\\source\\Geographic-Library-Test\\runFolder");
        double lat = 45.5, lon = -75.5, h = 10, t = 2026; // Mt Everest
        double Bx, By, Bz;
        mag(t, lat, lon, h, Bx, By, Bz);
        double H, F, D, I;
        MagneticModel::FieldComponents(Bx, By, Bz, H, F, D, I);
        //     * @param[out] D the declination of the field (degrees east of north).
        //     *@param[out] I the inclination of the field(degrees down from
        cout << H << " " << F << " " << D << " " << I << "\n";
        
        cout << std::format("Declination: {}\r\n", D); 

    }
    catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
        return 1;
    }



}
