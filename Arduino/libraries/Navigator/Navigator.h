/********************************* TRICK HEADER *******************************
PURPOSE: ()
LIBRARY DEPENDENCY:
    ((Guidance/src/navigator.cpp)
         )
PROGRAMMERS:
    (((John M. Penn) (L3 Communications) (March 2015) (Trick Refresher Project)))
*******************************************************************************/

#ifndef NAVIGATOR_HH
#define NAVIGATOR_HH

#include "Razor.h"
//#include "HCSR04.h"
#include "Point.h"
#include "Arduino.h"

    class Navigator {
        public:
        Navigator(Point initial_location, Razor& _razor):
                  location(initial_location), razor(_razor)
        {}
        //void setHeading(double heading);
        void setLocation(double north, double west);
        void updateHeading();
        double getHeading();

        double distanceTo(Point& mapPoint);
        double bearingTo(Point& mapPoint);

        Point convertMapToPlatform(Point& mapPoint);
        Point convertPlatformToMap(Point& platformPoint);
        Point convertPlatformToBody(Point& platformPoint);
        Point convertBodyToPlatform(Point& bodyPoint);

        private:
        double heading;
        Point  location;
        Razor& razor;

    };
#endif
