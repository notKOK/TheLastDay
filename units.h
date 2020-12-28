#ifndef KURS
#define KURS

using namespace sf;
using namespace std;

class Player {
	public:
		Player(string path, int x1, int y1, int x2, int y2, int positionX, int positionY, double scaleX, double scaleY);
		Image image;
		Texture texture_;
		Sprite sprite;
		float speed = 2;
		float x, y;
		int map_x, map_y;
};

class texture {
	public:
		texture(string path, int x1, int y1, int x2, int y2, int positionX, int positionY, double scaleX, double scaleY);
		Image image;
		Texture texture_;
		Sprite sprite;
};

#endif //KURS
