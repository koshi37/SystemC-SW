#include "systemc.h"
#define MAX 100
#define MIN 0

// dorota.dariusz@gmail.com
// Grzegorz Paryś, Bartosz Koszałka
// grupa: środa 12:45

SC_MODULE(sliders) {
	sc_fifo_out<int> value;
	int local_var;

	void read_sliders() {
		while (1) {

			wait(50, SC_NS);
			cin >> local_var;
			value.write(local_var);
			
		}
	}

	SC_CTOR(sliders) {
		SC_THREAD(read_sliders);
	}
};

SC_MODULE(bus) {
	sc_fifo<int> sliders;
	sc_signal<int> sw_state;
	sc_signal<int> fm_out;
	sc_signal<int> am_out;

	SC_CTOR(bus) {

	}
};

SC_MODULE(CPU1) {
	sc_fifo_in<int> sliders;
	sc_out<int> sw_state;
	sc_in<int> fm_out;
	sc_in<int> am_out;

	int current = -1;
	int old = -1;
	int sw = 0;
	int saved[4] = {};
	int AM = 50;
	int FM = 50;
	bool AMSelected = false;
	bool FMSelected = false;
	bool error_flag = false;


	void task1() {
		while (1) {
			wait(1, SC_NS);
			draw_output();
			sw = sliders.read();
			sw_state.write(sw);
			current += 1;
			int fromCPU2 = 0;
			int fromHardware = 0;
			wait(10, SC_NS);
			fromCPU2 = am_out.read();
			fromHardware = fm_out.read();

			
			if (fromCPU2 == 1) {
				AMSelected = !AMSelected;
				error_flag = false;
				draw_output();
			}
			if (fromHardware == 1) {
				FMSelected = !FMSelected;
				error_flag = false;
				draw_output();
			}
			if (AMSelected && FMSelected) {
				error_flag = true;
			}

		}
	}

	void task2() {
		while (1) {
			wait(1, SC_NS);
			draw_output();
			
			if (current != old) {
				if (sw == 3 && AMSelected && AM < MAX - 1) {
					old = current;
					error_flag = false;
					AM += 1;

				}
				else if (sw == 3 && AMSelected && AM > MAX - 1) {
					error_flag = true;
				}
				if (sw == 3 && FMSelected && FM < MAX - 1) {
					old = current;
					error_flag = false;
					FM += 1;
				}
				else if (sw == 3 && FMSelected && FM > MAX - 1) {
					error_flag = true;
				}
			}
		}
	}

	void task3() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 4 && AMSelected && AM < MAX - 5) {
					old = current;
					error_flag = false;
					AM += 5;

				}
				else if (sw == 4 && AMSelected && AM > MAX - 5) {
					error_flag = true;
				}
				if (sw == 4 && FMSelected && FM < MAX - 5) {
					old = current;
					error_flag = false;
					FM += 5;
				}
				else if (sw == 4 && FMSelected && FM > MAX - 5) {
					error_flag = true;
				}
			}
		}
	}

	void task4() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 5 && AMSelected && AM < MAX - 10) {
					old = current;
					error_flag = false;
					AM += 10;

				}
				else if (sw == 5 && AMSelected && AM > MAX - 10) {
					error_flag = true;
				}
				if (sw == 5 && FMSelected && FM < MAX - 10) {
					old = current;
					error_flag = false;
					FM += 10;
				}
				else if (sw == 5 && FMSelected && FM > MAX - 10) {
					error_flag = true;
				}
			}
		}
	}


	void task5() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 6 && AMSelected && AM < MAX - 50) {
					old = current;
					error_flag = false;
					AM += 50;

				}
				else if (sw == 6 && AMSelected && AM > MAX - 50) {
					error_flag = true;
				}
				if (sw == 6 && FMSelected && FM < MAX - 50) {
					old = current;
					error_flag = false;
					FM += 50;
				}
				else if (sw == 6 && FMSelected && FM > MAX - 50) {
					error_flag = true;
				}
			}
		}
	}

	void task6() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 7 && AMSelected && AM > MIN + 1) {
					old = current;
					error_flag = false;
					AM -= 1;

				}
				else if (sw == 7 && AMSelected && AM < MIN + 1) {
					error_flag = true;
				}
				if (sw == 7 && FMSelected && FM > MIN + 1) {
					old = current;
					error_flag = false;
					FM -= 1;
				}
				else if (sw == 7 && FMSelected && FM < MIN + 1) {
					error_flag = true;
				}
			}
		}
	}

	void task7() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 8 && AMSelected && AM > MIN + 5) {
					old = current;
					error_flag = false;
					AM -= 5;

				}
				else if (sw == 8 && AMSelected && AM < MIN + 5) {
					error_flag = true;
				}
				if (sw == 8 && FMSelected && FM > MIN + 5) {
					old = current;
					error_flag = false;
					FM -= 5;
				}
				else if (sw == 8 && FMSelected && FM < MIN + 5) {
					error_flag = true;
				}
			}
		}
	}

	void task8() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 9 && AMSelected && AM > MIN + 10) {
					old = current;
					error_flag = false;
					AM -= 10;

				}
				else if (sw == 9 && AMSelected && AM < MIN + 10) {
					error_flag = true;
				}
				if (sw == 9 && FMSelected && FM > MIN + 10) {
					old = current;
					error_flag = false;
					FM -= 10;
				}
				else if (sw == 9 && FMSelected && FM < MIN + 10) {
					error_flag = true;
				}
			}
		}
	}


	void task9() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (current != old) {
				if (sw == 10 && AMSelected && AM > MIN + 50) {
					old = current;
					error_flag = false;
					AM -= 50;

				}
				else if (sw == 10 && AMSelected && AM < MIN + 50) {
					error_flag = true;
				}
				if (sw == 10 && FMSelected && FM > MIN + 50) {
					old = current;
					error_flag = false;
					FM -= 50;
				}
				else if (sw == 10 && FMSelected && FM < MIN + 50) {
					error_flag = true;
				}
			}
		}
	}


	void task10() {
		while (1) {
			wait(1, SC_NS);
			draw_output();

			if (sw == 11) {
				old = current;
				if (AMSelected) {
					saved[0] = AM;
				}
				if (FMSelected) {
					saved[0] = FM;
				}
			}

			if (sw == 12) {
				old = current;
				if (AMSelected) {
					saved[1] = AM;
				}
				if (FMSelected) {
					saved[1] = FM;
				}
			}

			if (sw == 13) {
				old = current;
				if (AMSelected) {
					saved[2] = AM;
				}
				if (FMSelected) {
					saved[2] = FM;
				}
			}

			if (sw == 14) {
				old = current;
				if (AMSelected) {
					saved[3] = AM;
				}
				if (FMSelected) {
					saved[3] = FM;
				}
			}
		}
	}



	void draw_output() {
		wait(20, SC_NS);

		system("cls"); 
		cout << "Wybor rodzaju modulacji fali nosnej:" << endl;
		cout << "1.AM, 2.FM " << endl;
		cout << "Wybor zakresu fal:" << endl;
		cout << "3. +1, 4. +5, 5. +10,  6. +50" << endl;
		cout << "7. -1, 8. -5, 9. -10, 10. -50" << endl;
		cout << "Zapamietaj fale:" << endl;
		cout << "11. S1, 12. S2, 13. S3, 14. S4" << endl;
		cout << endl;
		cout << "PROGRAM:" << endl;

		if (AMSelected) cout << "Wybrane: AM" << endl;
		if (FMSelected) cout << "Wybrane: FM" << endl;
		if (!AMSelected && !FMSelected) cout << "Wybrane: NONE" << endl;


		cout << "ERRORFLAG: " << error_flag << endl;

		cout << "AM :" << AM << ", FM: " << FM << endl;
		cout << "Zapamietane 1:" << saved[0] << endl;
		cout << "Zapamietane 2:" << saved[1] << endl;
		cout << "Zapamietane 3:" << saved[2] << endl;
		cout << "Zapamietane 4:" << saved[3] << endl;
	}


	SC_CTOR(CPU1) {
		SC_THREAD(task1);  
		SC_THREAD(task2);   
		SC_THREAD(task3);   
		SC_THREAD(task4);  
		SC_THREAD(task5);   
		SC_THREAD(task6);   
		SC_THREAD(task7);   
		SC_THREAD(task8); 
		SC_THREAD(task9);   
		SC_THREAD(task10);   
	}
};

SC_MODULE(CPU2) {
	sc_in<int> sw_state;
	sc_out<int> am_out;

	void main() {
		int state = sw_state.read();
		if (state == 1) {
			am_out.write(1);
		}
		else {
			am_out.write(0);
		}

	}

	SC_CTOR(CPU2) {
		SC_METHOD(main);
		sensitive << sw_state;
	}
};

SC_MODULE(Hardware_module) {
	sc_in<int> sw_state;
	sc_out<int> fm_out;

	void logic() {
		int state = sw_state.read();
		if (state == 2) {
			fm_out.write(1);
		}
		else {
			fm_out.write(0);
		}
	}

	SC_CTOR(Hardware_module) {
		SC_METHOD(logic);
		sensitive << sw_state;
	}
};



int sc_main(int argc, char** argv)
{
	sliders s("s");
	bus busv("b");
	CPU1 cpu1("cpu1");
	CPU2 cpu2("cpu2");
	Hardware_module hardware("hd");

	// sliders channel
	s.value(busv.sliders);

	// cpu sliders channel
	cpu1.sliders(busv.sliders);

	// sw channel
	cpu1.sw_state(busv.sw_state);
	cpu2.sw_state(busv.sw_state);
	hardware.sw_state(busv.sw_state);

	// channel for hardware
	cpu1.fm_out(busv.fm_out);
	hardware.fm_out(busv.fm_out);

	// channel for CPU
	cpu1.am_out(busv.am_out);
	cpu2.am_out(busv.am_out);



	sc_start();
	return 0;
}
