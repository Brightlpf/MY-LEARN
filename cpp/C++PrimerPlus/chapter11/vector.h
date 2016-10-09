#ifndef __VECTOR_H_
#define __VECTOR_H_

#include <iostream>
namespace VECTOR
{
	class Vector{
		public:
			enum Mode{RECT, POL};
			static const double PI = 3.1415926;
		private:
			double x;
			double y;
			double mag;
			double ang;
			Mode mode;
			//private methods
			void set_x();
			void set_y();
			void set_mag();
			void set_ang();
		public:
			Vector();
			Vector(double n1, double n2, Mode form = RECT);
			void reset(double n1, double n2, Mode form = RECT);
			~Vector();
			double xval() const {return x;}
			double yval() const {return y;}
			double magval();
			double angval();
			void polar_mode(); //set mode to POL
			void rect_mode(); //set mode to RECT
			//operator overloading
			Vector operator+(const Vector & b) const;
			Vector operator-(const Vector & b) const;
			Vector operator-() const;
			Vector operator*(double n) const;
		//  friends
			friend Vector operator*(double n, const Vector &a);
			friend std::ostream & operator<<(std::ostream &os, Vector v);
			
	};
} //end namespace VECTOR
#endif
