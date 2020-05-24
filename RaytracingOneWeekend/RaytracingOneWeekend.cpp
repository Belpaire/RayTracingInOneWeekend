// RaytracingOneWeekend.cpp : Defines the entry point for the application.
//

#include "RaytracingOneWeekend.h"
#include "fstream"
#include "ray.h"

vec3 color(const ray& r) {
	vec3 unit = unit_vector(r.direction());
	double t = 0.5 * (unit.y() + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);

}


int main()
{
	int nx = 200;
	int ny = 100;
	vec3 lowerleft(-2.0,-1.0,-1.0);
	vec3 horizontal(4.0,0,0);
	vec3 vertical(0, 2, 0);
	vec3 origin(0, 0, 0);

	std::ofstream ofs("theNames.ppm");
	try {
		ofs << "P3\n" << nx << " " << ny << "\n255\n";
		for (int j = ny - 1; j >= 0;j--) {
			for (int i = 0; i < nx; i++) {
				double h = double(i) / double(nx);
				double v = double(j) / double(ny);
				auto rayToCalc = ray(origin,lowerleft+h*horizontal+v*vertical);
				vec3 vector = color(rayToCalc);
				int ir = int(255.99 * vector[0]);
				int ig = int(255.99 * vector[1]);
				int ib = int(255.99 * vector[2]);
				ofs << ir << " " << ig << " " << ib << "\n";

			}
		}
	}
	catch(int e){
		std::cout << e;
		ofs.close();
	}
}
