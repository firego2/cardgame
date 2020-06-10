#include "Smoke.h"

void Smoke::update()
{
	static int activation_counter = GLBL::FPS;
	static int delay_counter = GLBL::FPS / 2;
	activation_counter++;
	static int huh = 0;


	if (activation_counter)
	{
		dst_rect.x--;
		dst_rect.y--;
		dst_rect.w++;
		dst_rect.h++;
		delay_counter++;

		if (delay_counter >= GLBL::FPS / 7)
		{
			delay_counter = 0;

			if (current_row == 0)
			{
				current_column++;
				current_frame++;
				if (current_frame == total_frame / 2)
				{
					current_row++;
					current_column = 0;
					src_rect.x = 0;
					src_rect.y = current_row * src_rect.h;
				}
				else
					src_rect.x = current_column * src_rect.w;
			}
			else if (current_row == 1)
			{
				current_column++;
				current_frame++; 
				if (current_frame == total_frame)
				{
					current_row++;
				}
				else
					src_rect.x = current_column * src_rect.w;
			}


			huh++;
			if (huh == 130)
			{
				current_frame = 0;
				current_column = 0;
				current_row = 0;

				src_rect.x = 0;
				src_rect.y = 0;

				dst_rect.x = 0;
				dst_rect.y = 0;
				dst_rect.w = GLBL::SCREEN_WIDTH;
				dst_rect.h = GLBL::SCREEN_HEIGHT;

				huh = 0;
				activation_counter = 0;
			}
		}

	}


}
