#include <iostream>
#include <vector>
#include <string>

// 04/06/2020
// Created for school
// R.P

class machine
{
  	public:
		machine(std::vector<int> memory)
		{
			// Initalize tape and memory
			this->memoryTape = memory;
			this->currentMemory = memory[0];
		}
		bool checkRules()
		{
			// Define rules here:
			while (state != "HALT")
			{
				// Check even states
				if (state == "EVEN")
				{
					switch (currentMemory)
					{
						case 1:
							state = "ODD";
							advanceMemoryTape();
							continue;
						case 0:
							return true;
					}
				}

				// Check odd states
				else if (state == "ODD")
				{
					switch (currentMemory)
					{
						case 1:
							state = "EVEN";
							advanceMemoryTape();
							continue;
						case 0:
							state = "HALT";
					}
				}
			}
			return false;
		}
 	private:
		std::vector<int> memoryTape;
		int currentMemory;
		int position = 0;
		std::string state = "EVEN";

		// Advances the memory tape
		int advanceMemoryTape()
		{
			position++;
			currentMemory = memoryTape[position];
			return position;
		}
};

int main() {
	// 0 Ends tape
	std::vector<int> memory {1,1,0};

	// Creates object and check's answer
	machine isEven(memory);
	bool answer = isEven.checkRules();

	// Outputs answer
	std::cout << "\nIs even (1 = true, 0 = false)? : " << answer;
	std::cout << "\nProgram finished.";
}

