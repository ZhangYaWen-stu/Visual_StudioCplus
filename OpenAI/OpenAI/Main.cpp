#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 定义一个二维点
struct Point {
	int x;
	int y;
};

// 定义蛇的类
class Snake {
public:
	Snake(int x, int y) {
		// 初始化蛇的位置
		body.push_back({ x, y });
	}

	// 向蛇的头部添加一个新的点
	void addPoint(int x, int y) {
		body.push_back({ x, y });
	}

	// 从蛇的尾部删除一个点
	void removePoint() {
		body.pop_back();
	}

	// 获取蛇的头部坐标
	Point getHead() {
		return body.front();
	}

	// 判断蛇是否包含某个点
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
	// 蛇的身体，使用一个 vector 存储
	vector<Point> body;
};

// 定义游戏地图的类
class Map {
public:
	Map(int width, int height) : width(width), height(height) {
		// 初始化地图
		grid.resize(height);
		for (int i = 0; i < height; i++) {
			grid[i].resize(width);
		}
	}

	// 更新地图上的蛇的位置
	// 更新地图上的蛇的位置
	void updateSnake(Snake& snake) {
		// 先清空原来蛇所在的位置
		for (auto p : snake.body) {
			grid[p.y][p.x] = 0;
		}
		// 更新蛇的位置
		for (auto p : snake.body) {
			grid[p.y][p.x] = 1;
		}
	}

	// 在地图上添加一个食物
	void addFood(int x, int y) {
		grid[y][x] = 2;
	}

	// 判断某个位置上是否有食物
	bool hasFood(int x, int y) {
		return grid[y][x] == 2;
	}

	// 判断某个位置是否可以移动到
	bool canMoveTo(int x, int y) {
		// 判断是否越界
		if (x < 0 || x >= width || y < 0 || y >= height) {
			return false;
		}
		// 判断是否有障碍物（蛇或墙壁）
		return grid[y][x] == 0;
	}

	// 获取地图的宽度
	int getWidth() {
		return width;
	}

	// 获取地图的高度
	int getHeight() {
		return height;
	}

private:
	// 地图的宽度
	int width;
	// 地图的高度
	int height;
	// 地图的网格，0 表示空地，1 表示蛇，2 表示食物
	vector<vector<int>> grid;
};
