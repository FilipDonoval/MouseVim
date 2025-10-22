#include <iostream>
#include <windows.h>

int main()
{
	int moveAmount = 3;
	int moveDelayAmount = 1;
	POINT p;

	INPUT inputs[2] = {};
	memset(inputs, 0, sizeof(inputs));


	inputs[0].type = INPUT_MOUSE;
	inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

	inputs[1].type = INPUT_MOUSE;
	inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

	bool enterDown = false;
	SHORT prevEnterState = 0;

	bool activate = false;


	while(true)
	{
		if (GetAsyncKeyState(VK_LCONTROL))
		{
			std::cout << "ctrl ";
			if (GetAsyncKeyState(VK_LSHIFT))
			{
				std::cout << "shift ";
				if (GetAsyncKeyState('U'))
				{
					std::cout << "u ";
					if (GetAsyncKeyState('I'))
					{
						std::cout << "i ";
						if (GetAsyncKeyState('A'))
						{
							std::cout << "a ";
							std::cout << "ACTIVATED";
							activate = true;
						}
						
						if (GetAsyncKeyState('D'))
						{
							std::cout << "d ";
							std::cout << "DEACTIVATED";
							activate = false;
						}
						if (GetAsyncKeyState('X'))
						{
							std::cout << "EXIT";
							return 0;
						}
					}
				}
			}
		}

		

		if (activate)
		{


			if (GetAsyncKeyState('H'))
			{
				GetCursorPos(&p);
				//std::cout << p.x << "||" << p.y << std::endl;
				SetCursorPos(p.x - moveAmount, p.y);
				Sleep(moveDelayAmount);
				continue;
			}
			if (GetAsyncKeyState('J'))
			{
				GetCursorPos(&p);
				//std::cout << p.x << "||" << p.y << std::endl;
				SetCursorPos(p.x, p.y + moveAmount);
				Sleep(moveDelayAmount);
				continue;
			}
			if (GetAsyncKeyState('K'))
			{
				GetCursorPos(&p);
				//std::cout << p.x << "||" << p.y << std::endl;
				SetCursorPos(p.x, p.y - moveAmount);
				Sleep(moveDelayAmount);
				continue;
			}
			if (GetAsyncKeyState('L'))
			{
				GetCursorPos(&p);
				//std::cout << p.x << "||" << p.y << std::endl;
				SetCursorPos(p.x + moveAmount, p.y);
				Sleep(moveDelayAmount);
				continue;
			}
			SHORT enterState = GetAsyncKeyState(VK_RETURN);
			if ((enterState & 0x8000) && !(prevEnterState & 0x8000))
			{
				SendInput(1, inputs, sizeof(INPUT));
				SendInput(1, &inputs[1], sizeof(INPUT));
			}
			prevEnterState = enterState;


			std::cout << "Waiting...";
			Sleep(20);
		}


	}

}
