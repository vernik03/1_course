#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


void game_window_yellow(vector<vector<int>> matrix);
void game_window_red(vector<vector<int>> matrix);


vector<vector<int>> fill_matrix(vector<vector<int>> matrix) {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			matrix[i][j] = 0;

		}
	}
	return matrix;
}


void hello_window(vector<vector<int>> matrix) {
	RenderWindow window(VideoMode(1772, 1700), "");
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)
				
				window.close();
		}

		
		window.clear(Color(32, 43, 69, 0));

		Texture texture_name;
		texture_name.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 7.png");

		Texture texture_withcomp__;
		texture_withcomp__.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 21__.png");

		Texture texture_withfriend__;
		texture_withfriend__.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 22__.png");

		Texture texture_exit__;
		texture_exit__.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 23__.png");
	

		Sprite name(texture_name);


		Sprite withcomp__(texture_withcomp__);
		withcomp__.move(488, 653);

		Sprite withfriend__(texture_withfriend__);
		withfriend__.move(488, 793);

		Sprite exit__(texture_exit__);
		exit__.move(488, 933);

		
		
		window.draw(name);

		matrix = fill_matrix(matrix);

		int hello_menuNum = 0;

		if (IntRect(488, 653, 796, 140).contains(Mouse::getPosition(window))) { window.draw(withcomp__); hello_menuNum = 1; }
		if (IntRect(488, 793, 796, 140).contains(Mouse::getPosition(window))) { window.draw(withfriend__); hello_menuNum = 2; }
		if (IntRect(488, 933, 796, 140).contains(Mouse::getPosition(window))) { window.draw(exit__); hello_menuNum = 3; }
		window.display();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (hello_menuNum == 1) {
				window.close();
				game_window_red(matrix); 
			}
			if (hello_menuNum == 2) {
				window.close();
				game_window_red(matrix);
			}
			if (hello_menuNum == 3) window.close();

		}

		

		
	}

	

}








void yellow_or_red(vector<vector<int>> matrix, int n) {

	if (n == 1)
	{
		game_window_red(matrix);
	}
	else if (n == 2)
	{
		game_window_yellow(matrix);
	}
}




int game_pause(vector<vector<int>> matrix, int n) {
	RenderWindow window(VideoMode(1772, 1700), "");
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
		}

		window.clear(Color(32, 43, 69, 0));

		
		Texture texture_menu_overlay;
		texture_menu_overlay.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 8.png");

		Texture texture_field;
		texture_field.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 1.png");

		//coins
		Texture texture_red;
		texture_red.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 17.png");

		Texture texture_yellow;
		texture_yellow.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 18.png");



		Texture texture_newgame__;
		texture_newgame__.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 24__.png");
		Texture texture_exit__;
		texture_exit__.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 23__.png");





		Sprite newgame__(texture_newgame__);
		newgame__.move(488, 653);

		Sprite exit__(texture_exit__);
		exit__.move(488, 793);

		Sprite field(texture_field);


		Sprite menu_overlay(texture_menu_overlay);
		

		//coins
		Sprite red(texture_red);


		
		int add_coin = -1;


		

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (matrix[i][j] == 1)
				{

					Sprite yellow(texture_yellow);
					yellow.move(131 + j * 216, 291 + i * 216);
					window.draw(yellow);


				}
				if (matrix[i][j] == 2)
				{

					Sprite red(texture_red);
					red.move(131 + j * 216, 291 + i * 216);
					window.draw(red);


				}

			}

		}


		window.draw(field);

		window.draw(menu_overlay);

		int pause_menuNum = 0;

		
		if (IntRect(1623, 96, 59, 59).contains(Mouse::getPosition(window))) {
			pause_menuNum = 3;
		}
		if (IntRect(488, 653, 796, 140).contains(Mouse::getPosition(window))) { window.draw(newgame__); pause_menuNum = 1; }
		if (IntRect(488, 793, 796, 140).contains(Mouse::getPosition(window))) { window.draw(exit__); pause_menuNum = 2; }
		window.display();

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (pause_menuNum == 1) {
				window.close();
				hello_window(matrix);
			}
			if (pause_menuNum == 2) {
				window.close();
				return 0;
			}
			if (pause_menuNum == 3) {
				if (n==1)
				{
					window.close();
					yellow_or_red(matrix, 2);
				}
				else if (n==2)
				{
					window.close();
					yellow_or_red(matrix, 1);
				}
				
			}
			

		}
		


	}



}











void game_window_yellow(vector<vector<int>> matrix) {
	RenderWindow window(VideoMode(1772, 1700), "");
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
		}

		window.clear(Color(32, 43, 69, 0));

		Texture texture_background;
		texture_background.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 2.png");

		Texture texture_menu_active;
		texture_menu_active.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 39.png");

		Texture texture_field;
		texture_field.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 1.png");

		//coins
		Texture texture_red;
		texture_red.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 17.png");

		Texture texture_yellow;
		texture_yellow.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 18.png");









		Sprite background(texture_background);

		Sprite field(texture_field);


		Sprite menu_active(texture_menu_active);
		menu_active.move(1597, 96);

		//coins
		Sprite red(texture_red);


		int action_menuNum = 0;
		int add_coin = -1;


		window.draw(background);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (matrix[i][j] == 1)
				{

					Sprite yellow(texture_yellow);
					yellow.move(131 + j * 216, 291 + i * 216);
					window.draw(yellow);


				}
				if (matrix[i][j] == 2)
				{

					Sprite red(texture_red);
					red.move(131 + j * 216, 291 + i * 216);
					window.draw(red);


				}

			}

		}


		window.draw(field);

		if (IntRect(1597, 96, 62.5, 62).contains(Mouse::getPosition(window))) {
			window.draw(menu_active);
			action_menuNum = 1;
		}

		if (IntRect(147, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 0;
		}

		if (IntRect(363, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 1;
		}
		if (IntRect(579, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 2;
		}
		if (IntRect(795, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 3;
		}
		if (IntRect(1011, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 4;
		}
		if (IntRect(1227, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 5;
		}
		if (IntRect(1443, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 6;
		}



		window.display();

		if (Mouse::isButtonPressed(Mouse::Left))
		{

			if (action_menuNum == 1) {
				window.close();
				game_pause(matrix, 1);

			}


			for (int j = 5; j >= 0; j--)
			{

				if (matrix[j][add_coin] == 0) {
					matrix[j][add_coin] = 1;
					window.close();
					yellow_or_red(matrix, 1);

				}
				

			}

			



		}
		
			
		

		
	}

	
	
}


void game_window_red(vector<vector<int>> matrix) {
	RenderWindow window(VideoMode(1772, 1700), "");
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
		}

		window.clear(Color(32, 43, 69, 0));

		Texture texture_background;
		texture_background.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 2.png");

		Texture texture_menu_active;
		texture_menu_active.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 39.png");

		Texture texture_field;
		texture_field.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Frame 1.png");

		//coins
		Texture texture_red;
		texture_red.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 17.png");

		Texture texture_yellow;
		texture_yellow.loadFromFile("D:\\Programming\\Visual Studio\\repos\\LABA5\\lab5\\Textures\\Group 18.png");
		





		


		Sprite background(texture_background);

		Sprite field(texture_field);


		Sprite menu_active(texture_menu_active);
		menu_active.move(1597, 96);

		//coins
		Sprite red(texture_red);

		
		int action_menuNum = 0;
		int add_coin = -1;

		
		window.draw(background);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (matrix[i][j]==1)
				{

					Sprite yellow(texture_yellow);
					yellow.move(131+j*216, 291+i*216);
					window.draw(yellow);
					
					
				}
				if (matrix[i][j] == 2)
				{

					Sprite red(texture_red);
					red.move(131 + j * 216, 291 + i * 216);
					window.draw(red);
					

				}
				
			}
			
		}


		window.draw(field);

		if (IntRect(1597, 96, 62.5, 62).contains(Mouse::getPosition(window))) {
			window.draw(menu_active);
			action_menuNum = 1;
		}

		if (IntRect(147, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 0;
		}

		if (IntRect(363, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 1;
		}
		if (IntRect(579, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 2;
		}
		if (IntRect(795, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 3;
		}
		if (IntRect(1011, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 4;
		}
		if (IntRect(1227, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 5;
		}
		if (IntRect(1443, 270, 216, 1332).contains(Mouse::getPosition(window))) {
			add_coin = 6;
		}

		

		window.display();

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (action_menuNum == 1) {
				window.close();
				game_pause(matrix, 2);
			}

			for (int j = 5; j >= 0; j--)
			{

				if (matrix[j][add_coin] == 0) {
					matrix[j][add_coin] = 2;
					window.close();
					yellow_or_red(matrix, 2);
					
				}

			}
			
			
			
			

		}

		
	}

	

}





int main()
{

	
	vector<vector<int>> main_matrix(6, vector<int>(7));
	

	/*main_matrix[2][5] = 1;
	main_matrix[1][4] = 1;
	main_matrix[3][3] = 1;
	main_matrix[1][2] = 1;
	main_matrix[5][4] = 1;
	*/
	
	/*for (int i = 0; i <6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << main_matrix[i][j] << " ";
		}
		cout << endl;
	}*/

	hello_window(main_matrix);
	
	//cout << menu_num<<endl;


	
}