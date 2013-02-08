
#include <stdio.h>
#include "ipu.h"

int main()
{
	ipu_stack_select(ipu_stack_new());

	ipu_color(0, 0, 0);
	ipu_pixel(0.5, 0.8, 0.4, 1000, 1995);
	ipu_mul(10, 10, 10);
	ipu_blur_x(20);
	ipu_blur_x(20);
	ipu_blur_x(20);

	ipu_dup();
	ipu_blur_y(5);
	ipu_blur_y(5);
	ipu_blur_y(5);
	ipu_mul(4, 4, 4);
	ipu_mix_add();

	ipu_color(0, 0, 0);
	ipu_pixel(0.8, 0.8, 0.8, 200, 1996);
	ipu_blur_x(5);
	ipu_blur_x(5);
	ipu_blur_x(5);
	ipu_blur_y(5);
	ipu_blur_y(5);
	ipu_blur_y(5);
	ipu_mul(60, 60, 60);
	ipu_mix_add();

	ipu_save_to_ppm("ipu-output");
	return 0;
}
