// RaytracingOneWeekend.cpp : Defines the entry point for the application.
//

#include "RaytracingOneWeekend.h"
#include "fstream"

int main()
{
	int nx = 200;
	int ny = 100;
	std::ofstream ofs("theNames.ppm");
	try {
		ofs << "P3\n" << nx << " " << ny << "\n255\n";
		for (int j = ny - 1; j >= 0;j--) {
			for (int i = 0; i < nx; i++) {
				double r = double(i) / double(nx);
				double g = double(j) / double(ny);
				double b = 0.2;
				int ir = int(255.99 * r);
				int ig = int(255.99 * g);
				int ib = int(255.99 * b);
				ofs << ir << " " << ig << " " << ib << "\n";
			}
		}
	}
	catch(int e){
		std::cout << e;
		ofs.close();
	}
}
