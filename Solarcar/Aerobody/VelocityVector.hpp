#ifndef MINISIM_VECTOR_H
#define MINISIM_VECTOR_H

#include <cmath>
#include <numbers>  // 2π = std::numbers::pi * 2

struct VelocityVector {
   public:
	/// @brief constructs a velocity vector using it's components
	///
	/// @param north_south (m/s) the North-South component of the wind vector
	/// @param east_west (m/s) the East-West component of the wind vector
	static VelocityVector from_cartesian_components(double north_south, double east_west) {
		return VelocityVector(north_south, east_west);
	}

	/// @brief constructs a velocity vector using polar form
	///
	/// @param speed (m/s) the magnitude of the velocity vector
	/// @param the (radians) direction of the velocity vector. Note 0 radians is due north, π/4
	/// radians is due east
	static VelocityVector from_polar_components(double speed, double heading) {
		return VelocityVector(          //
			speed * std::cos(heading),  // north_south
			speed * std::sin(heading)   // east_west
		);
	}

	double get_north_south() const {
		return north_south;
	}

	double get_east_west() const {
		return east_west;
	}

	/// @brief Calculate the magnitude of the vector
	double get_magnitude() const {
		return sqrt(pow(north_south, 2) + pow(east_west,2));
	}

	/// @brief Calculates the heading
	/// @note recall that 0 radians is due north, and π/4 radians is due east, and the range is
	/// [0, 2π]
	double get_heading() const {
		return tan(north_south/east_west) * 3.14159/180;
	}

	/// @brief Calculate the angle, in radians, between the two vectors
	///
	/// @return (radians) the angle between two vectors
	/// @note positive if { other } is "left" of this vector
	/// @note zero if either vector is 0
	/// @hint you might need to use the dot product
	double angle_between(const VelocityVector& other) const {
		if( get_magnitude()==0 or other.get_magnitude()==0) {
			return 0;
		}
		double dot = north_south * other.get_north_south() + east_west * other.get_east_west();
		double cose = dot / (this->get_magnitude() * other.get_magnitude());
		return acos(cose);
	}

   private:
	/// @brief (m/s) North-South component of wind vector
	double north_south;

	/// @brief (m/s) East-West component of wind vector
	double east_west;

	VelocityVector(double north_south, double east_west)
		: north_south(north_south), east_west(east_west) {}
};

/// @brief An apparent wind vector in its traditional polar coordinates
struct ApparentWindVector {
	/// @brief (m/s) Speed of wind vector
	double speed;

	/// @brief (m/s) Yaw of wind vector in radians from heading
	///
	/// @note positive yaw is starboard
	double yaw;
};

#endif  // MINISIM_VECTOR_H