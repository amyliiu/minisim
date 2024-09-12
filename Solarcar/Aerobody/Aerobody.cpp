#ifndef MINISIM_AEROBODY_H
#define MINISIM_AEROBODY_H

#include "Aerobody.h"
#include "VelocityVector.hpp"


using namespace std;


static ApparentWindVector get_wind(const VelocityVector& reported_wind, const VelocityVector& car_velocity) {
    double true_y = reported_wind.get_north_south() - car_velocity.get_north_south();
    double true_x = reported_wind.get_east_west() - car_velocity.get_east_west();

    double true_angle = reported_wind.get_heading() - car_velocity.get_heading();

    double speed = sqrt(pow(true_y,2) + pow(true_x,2));
};


/// @brief Gets the drag on the aerobody at a given apparent wind vector
	///
	/// @param apparent_wind an apparent wind vector with yaw and speed
	/// @param air_density (kg/m^3) The air density
	///
	/// @return the drag force, in Newtons.
/// double aerodynamic_drag(const ApparentWindVector& apparent_wind, double air_density) const;


#endif;