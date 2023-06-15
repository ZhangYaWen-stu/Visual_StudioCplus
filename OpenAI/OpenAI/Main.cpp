#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ����һ����ά��
struct Point {
	int x;
	int y;
};

// �����ߵ���
class Snake {
public:
	Snake(int x, int y) {
		// ��ʼ���ߵ�λ��
		body.push_back({ x, y });
	}

	// ���ߵ�ͷ�����һ���µĵ�
	void addPoint(int x, int y) {
		body.push_back({ x, y });
	}

	// ���ߵ�β��ɾ��һ����
	void removePoint() {
		body.pop_back();
	}

	// ��ȡ�ߵ�ͷ������
	Point getHead() {
		return body.front();
	}

	// �ж����Ƿ����ĳ����
	bool contains(int x, int y) {
		for (auto p : body) {
			if (p.x == x && p.y == y) {
				return true;
			}
		}
		return false;
	}
	friend class Map;

private:
	// �ߵ����壬ʹ��һ�� vector �洢
	vector<Point> body;
};

// ������Ϸ��ͼ����
class Map {
public:
	Map(int width, int height) : width(width), height(height) {
		// ��ʼ����ͼ
		grid.resize(height);
		for (int i = 0; i < height; i++) {
			grid[i].resize(width);
		}
	}

	// ���µ�ͼ�ϵ��ߵ�λ��
	// ���µ�ͼ�ϵ��ߵ�λ��
	void updateSnake(Snake& snake) {
		// �����ԭ�������ڵ�λ��
		for (auto p : snake.body) {
			grid[p.y][p.x] = 0;
		}
		// �����ߵ�λ��
		for (auto p : snake.body) {
			grid[p.y][p.x] = 1;
		}
	}

	// �ڵ�ͼ�����һ��ʳ��
	void addFood(int x, int y) {
		grid[y][x] = 2;
	}

	// �ж�ĳ��λ�����Ƿ���ʳ��
	bool hasFood(int x, int y) {
		return grid[y][x] == 2;
	}

	// �ж�ĳ��λ���Ƿ�����ƶ���
	bool canMoveTo(int x, int y) {
		// �ж��Ƿ�Խ��
		if (x < 0 || x >= width || y < 0 || y >= height) {
			return false;
		}
		// �ж��Ƿ����ϰ���߻�ǽ�ڣ�
		return grid[y][x] == 0;
	}

	// ��ȡ��ͼ�Ŀ��
	int getWidth() {
		return width;
	}

	// ��ȡ��ͼ�ĸ߶�
	int getHeight() {
		return height;
	}

private:
	// ��ͼ�Ŀ��
	int width;
	// ��ͼ�ĸ߶�
	int height;
	// ��ͼ������0 ��ʾ�յأ�1 ��ʾ�ߣ�2 ��ʾʳ��
	vector<vector<int>> grid;
};
