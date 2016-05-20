#include "World.h"
#include "MemLeaks.h"
#include <conio.h>

World* App = nullptr;
int main(){
	ReportMemoryLeaks();

	App=new World;
	char operation[100];
	char key = 'x';
	int next = 0;
	MyString words;



	App->createWorld();
	App->Help();
	App->hero->Look();
	while (1)

	{
		Vector<MyString>strings;

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

