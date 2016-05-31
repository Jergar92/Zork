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
				App->Update();
				lastTime = currentTime;
				for (int i = 0; i < App->container.size(); i++){
					if (App->container[i]->isType == MONSTER || App->container[i]->isType == PLAYER || App->container[i]->isType == SELLER){
						if (App->container[i] == nullptr){
							continue;
						}
						App->container[i]->Update();
					}
					if (App->hero->isDead == true){
						break;
					}
				}
				for (int i = 0; i < App->container.size(); i++){
				
					if (((Creature*)App->container[i])->isDead == true){
						
						delete App->container[i];
						App->container[i]=nullptr;
						App->container.erase(i);
						i--;
					}
					else if (((Item*)App->container[i])->toDestroy == true){
						delete App->container[i];
						App->container[i] = nullptr;
						App->container.erase(i);
						i--;
					}
				}
			}
		if (_kbhit() != 0)
		{
			key = _getch();
			operation[next++] = key;
			printf("%c", key);
			if (key == '\r'||next>90){
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
		if ((strings[0] == "quit") || App->hero->isDead == true){
			break;
		}
	}
	App->CleanUp();//clean most of the memory leaks
	return 0;
}

