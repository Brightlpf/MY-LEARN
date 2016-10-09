#include "vector.h"
#include <cmath>

using namespace std;

/*
class Vector{
		public:
			enum Mode{RECT, POL};
			static double PI = 3.1415926;
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
			double magval() const {return mag;}
			double angval() const {return ang;}
			void polar_mode(); //set mode to POL
			void rect_mode(); //set mode to RECT
			//operator overloading
			Vector operator+(const Vector & b) const;
			Vector operator-(const Vector & b) const;
			Vector operator-() const;
			Vector operator*(double n) const;
		//  friends
			friend Vector operator*(double n, const Vector &a);
			friend std::ostream & operator<<(std::ostream &os, const Vector v);
*/

namespace VECTOR{
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}
	
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}
	
	void Vector::set_ang()
	{
		if(x == 0.0 && y == 0.0)
			ang = 0.0;
		ang = atan2(y, x);
	}
	
	Vector::Vector()
	{
		mode = RECT;
		x = y = 0;
		mag = ang = 0;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if(form == RECT)
		{
			x = n1;
			y = n2;
			//set_mag();
			//set_ang();
		}
		else if (form == POL){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector.\n";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if(form == RECT)
		{
			x = n1;
			y = n2;
			//set_mag();
			//set_ang();
		}
		else if (form == POL){
			mag = n1;
			ang = n2;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector.\n";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	
	Vector::~Vector()
	{
		
	}

	double Vector::magval()  
	{
		set_mag();
		return mag;
	}
	double Vector::angval() 
	{
		set_ang();
		return ang;
	}
	void Vector::polar_mode() //set mode to POL
	{
		mode = POL;
	}
	void Vector::rect_mode() //set mode to RECT
	{
		mode = RECT;
	}
	
	Vector Vector::operator+(const Vector & b) const
	{
		Vector sum;
		
		sum.mode = RECT;
		sum.x = x + b.x;
		sum.y = y + b.y;
		//sum.set_mag();
		//sum.set_ang();
		
		return sum;
	}
	
	Vector Vector::operator-(const Vector & b) const
	{
		Vector sum;
		
		sum.mode = RECT;
		sum.x = x - b.x;
		sum.y = y - b.y;
		//sum.set_mag();
		//sum.set_ang();
		
		return sum;
	}
	
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		Vector sum;
		
		sum.mode = RECT;
		sum.x = n * x;
		sum.y = n * y;
		//sum.set_mag();
		//sum.set_ang();
		
		return sum;
	}
	
	Vector operator*(double n, const Vector &a)
	{
		Vector sum;
		
		sum.mode = a.RECT;
		sum.x = n * a.x;
		sum.y = n * a.y;
		//sum.set_mag();
		//sum.set_ang();
		
		return sum;
	}
    std::ostream & operator<<(std::ostream &os, Vector v)
	{
		if(v.mode == v.RECT)
			os << "RECT: (" << v.x << ", " << v.y << ") ";
		else
			os << "POL: " << "mag = " << v.magval() << ", ang = " << v.angval() << " ";
		return os;
	}
}
