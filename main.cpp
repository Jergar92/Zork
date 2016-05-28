#include "World.h"
#include "MemLeaks.h"
#include <conio.h>
#include <Windows.h>
World* App = nullptr;
int main(){
	ReportMemoryLeaks();

	App=new World;
	char operation[100];
	char key = 'x';
	int next = 0;
	MyString words;
	Vector<MyString>strings;
	unsigned int currentTime, lastTime = 0;


	App->createWorld();
	App->Help();





	App->hero->Look();
	while (1)
	{
		currentTime = GetTickCount();
			if (currentTime >= (lastTime + 1000)){
				lastTime = currentTime;
				for (int i = 0; i < App->container.size(); i++){
					App->container[i]->Update();
				}
			}
		if (_kbhit() != 0)
		{
			key = _getch();
			operation[next++] = key;
			printf("%c", key);
			if (key == '\r'){
				operation[--next] = '\0';
				words.Token(operation, strings);
				App->getOperation(strings);
				strings.clear();
				printf("\n");
				next = 0;
			}
			else if (key == '\b'&& next > 0){
				next--;
				next--;
			}
		}
		if ((strings[0] == "quit")){
			break;
		}
	}


	return 0;

}

